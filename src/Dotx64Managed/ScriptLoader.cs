﻿using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Dotx64Dbg
{
    internal class ScriptLoader
    {
        static string ScriptBuildOutputPath;
        static Task ActiveScript;

        private static bool RunScriptCommand(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("ERROR: Missing argument <file>");
                return false;
            }

            return ExecuteScriptFile(args[1]);
        }

        private static void SetupDirectories()
        {
            string AppDataPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData), "DotX64Dbg");
            if (!Directory.Exists(AppDataPath))
            {
                Directory.CreateDirectory(AppDataPath);
            }

            ScriptBuildOutputPath = Path.Combine(AppDataPath, "Scripts");
            if (!Directory.Exists(ScriptBuildOutputPath))
            {
                Directory.CreateDirectory(ScriptBuildOutputPath);
            }
        }

        public static void Initialize()
        {
            SetupDirectories();
            Commands.Register(null, "dotscript", false, RunScriptCommand);
        }

        private static Type GetScriptClass(Assembly assembly)
        {
            // Auto-generated class from Roslyn.
            var entries = assembly.GetTypes().Where(a => a.Name == "Script").ToArray();
            if (entries.Length == 0)
            {
                throw new Exception("Assembly has no Script entry.");
            }
            return entries.First();
        }

        public static bool ExecuteScriptAssembly(Compiler.Result data)
        {
            // Make sure the stream positions are at 0.
            data.AssemblyStream.Position = 0;
            data.DebugStream.Position = 0;

            var loader = new AssemblyLoader();
            var newAssembly = loader.LoadFromStream(data.AssemblyStream, data.DebugStream);

            var scriptClass = GetScriptClass(newAssembly);
            if (scriptClass != null)
            {
#if DEBUG
                Console.WriteLine("[DEBUG] Entry class: {0}", scriptClass.Name);
#endif
            }

            // Auto-generated method from Roslyn.
            var entry = scriptClass.GetMethod("<Main>", BindingFlags.Public | BindingFlags.Static | BindingFlags.NonPublic);
            if (entry == null)
            {
                Console.WriteLine("No entrypoint defined");
                return false;
            }

#if DEBUG
            Console.WriteLine($"[DEBUG] Entrypoint {entry}");
#endif

            ActiveScript = Task.Run(delegate ()
            {
                try
                {
                    entry.Invoke(null, new object[0]);
                }
                catch (Exception ex)
                {
                    Utils.PrintException(ex);
                }

                ActiveScript = null;

                GC.Collect();
            });

            return false;
        }

        public static bool ExecuteScriptFile(string file)
        {
            var scriptName = Path.GetFileNameWithoutExtension(file);

            var stopwatch = new Stopwatch();

            Console.WriteLine("Building script '{0}'...", file);
            stopwatch.Start();

            var compiler = new Compiler(scriptName);

            var res = compiler.Compile(new string[] { file }, true);
            stopwatch.Stop();

            if (!res.Success)
            {
                Console.WriteLine("Build failed");
            }
            else
            {
                Console.WriteLine("Compiled script '{0}' in {1} ms", file, stopwatch.ElapsedMilliseconds);
                ExecuteScriptAssembly(res);
            }

            return true;
        }

        public static bool ExecuteCode(string code)
        {
            var compiler = new Compiler("script");

            Console.WriteLine($"> {code}");

            var res = compiler.Compile(code);
            if (!res.Success)
            {
                return false;
            }

            return ExecuteScriptAssembly(res);
        }

    }
}
