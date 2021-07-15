﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dotx64Dbg
{
    internal class LabelData
    {
        internal Label Label;
        internal NodeList.Node Node;
    }

    public partial class Assembler : IDisposable
    {
        private NodeList Nodes = new();
        public NodeList.Node Cursor { get; set; }

        internal Dotx64Dbg.Encoder Encoder;

        internal bool disposed = false;

        internal Instruction.Attributes AttribState;

        internal List<LabelData> Labels = new();


        public class NodeInstr : NodeList.NodeKind<Instruction>
        {
        }

        public class NodeData : NodeList.NodeKind<byte[]>
        {
        }

        public class NodeLabel : NodeList.NodeKind<Label>
        {

        }

        public Assembler()
        {
            Encoder = Dotx64Dbg.Encoder.Create((nuint)0);
        }

        public Assembler(nuint baseVA = 0)
        {
            Encoder = Dotx64Dbg.Encoder.Create(baseVA);
        }

        public NodeList.Node Head { get => Nodes.Head; }
        public NodeList.Node Tail { get => Nodes.Tail; }

        public NodeList GetNodes()
        {
            return Nodes;
        }

        public Label CreateLabel()
        {
            var data = new LabelData()
            {
                Label = new Label(Labels.Count),
                Node = null,
            };

            Labels.Add(data);

            return data.Label;
        }

        public Assembler BindLabel(Label label)
        {
            var labelData = Labels[label.Value];
            if (labelData.Node != null)
            {
                throw new Exception("Label is already bound, can not bind twice.");
            }

            var node = new NodeLabel() { Value = label };
            labelData.Node = node;

            Cursor = Nodes.InsertAfter(Cursor, node);

            return this;
        }

        internal Assembler CreateInstr(Mnemonic id)
        {
            var node = new NodeInstr() { Value = new Instruction(AttribState, id) };
            AttribState = Instruction.Attributes.None;
            Cursor = Nodes.InsertAfter(Cursor, node);
            return this;
        }

        internal Assembler CreateInstr(Mnemonic id, IOperand op0)
        {
            var node = new NodeInstr() { Value = new Instruction(AttribState, id, op0) };
            AttribState = Instruction.Attributes.None;
            Cursor = Nodes.InsertAfter(Cursor, node);
            return this;
        }

        internal Assembler CreateInstr(Mnemonic id, IOperand op0, IOperand op1)
        {
            var node = new NodeInstr() { Value = new Instruction(AttribState, id, op0, op1) };
            AttribState = Instruction.Attributes.None;
            Cursor = Nodes.InsertAfter(Cursor, node);
            return this;
        }

        internal Assembler CreateInstr(Mnemonic id, IOperand op0, IOperand op1, IOperand op2)
        {
            var node = new NodeInstr() { Value = new Instruction(AttribState, id, op0, op1, op2) };
            AttribState = Instruction.Attributes.None;
            Cursor = Nodes.InsertAfter(Cursor, node);
            return this;
        }

        internal Assembler CreateInstr(Mnemonic id, IOperand op0, IOperand op1, IOperand op2, IOperand op3)
        {
            var node = new NodeInstr() { Value = new Instruction(AttribState, id, op0, op1, op2, op3) };
            AttribState = Instruction.Attributes.None;
            Cursor = Nodes.InsertAfter(Cursor, node);
            return this;
        }

        public Assembler Emit(Instruction instr)
        {
            var node = new NodeInstr() { Value = instr };
            Cursor = Nodes.InsertAfter(Cursor, node);
            return this;
        }

        public Assembler Db(byte val)
        {
            var node = new NodeData() { Value = new byte[] { val } };
            Cursor = Nodes.InsertAfter(Cursor, node);
            return this;
        }

        public Assembler Dw(ushort val)
        {
            var node = new NodeData() { Value = BitConverter.GetBytes(val) };
            Cursor = Nodes.InsertAfter(Cursor, node);
            return this;
        }

        public Assembler Dw(short val)
        {
            var node = new NodeData() { Value = BitConverter.GetBytes(val) };
            Cursor = Nodes.InsertAfter(Cursor, node);
            return this;
        }

        public Assembler Dd(UInt32 val)
        {
            var node = new NodeData() { Value = BitConverter.GetBytes(val) };
            Cursor = Nodes.InsertAfter(Cursor, node);
            return this;
        }

        public Assembler Dd(Int32 val)
        {
            var node = new NodeData() { Value = BitConverter.GetBytes(val) };
            Cursor = Nodes.InsertAfter(Cursor, node);
            return this;
        }

        public Assembler Dq(UInt64 val)
        {
            var node = new NodeData() { Value = BitConverter.GetBytes(val) };
            Cursor = Nodes.InsertAfter(Cursor, node);
            return this;
        }

        public Assembler Dq(Int64 val)
        {
            var node = new NodeData() { Value = BitConverter.GetBytes(val) };
            Cursor = Nodes.InsertAfter(Cursor, node);
            return this;
        }

        public Assembler Lock()
        {
            AttribState |= Instruction.Attributes.Lock;
            return this;
        }

        public Assembler Rep()
        {
            AttribState |= Instruction.Attributes.Rep;
            return this;
        }
        public Assembler RepNe()
        {
            AttribState |= Instruction.Attributes.RepNe;
            return this;
        }

        public bool Finalize()
        {
            // Encode everything.
            var node = Head;
            while (node != null)
            {
                if (node is NodeInstr nodeInstr)
                {
                    if (!Encoder.Encode(nodeInstr.Value))
                    {
                        return false;
                    }
                }
                else if (node is NodeLabel nodeLabel)
                {
                    if (!Encoder.BindLabel(nodeLabel.Value))
                    {
                        return false;
                    }
                }
                node = node.Next;
            }

            return true;

        }

        // Public implementation of Dispose pattern callable by consumers.
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        // Protected implementation of Dispose pattern.
        protected virtual void Dispose(bool disposing)
        {
            if (disposed)
                return;

            if (disposing)
            {
                Encoder = null;
                Nodes = null;
                Labels = null;
            }

            disposed = true;
        }

        public bool RelocateTo(nuint newBaseVA)
        {
            return Encoder.RelocateTo(newBaseVA);
        }

        public byte[] GetData()
        {
            return Encoder.GetData();
        }
    }
}
