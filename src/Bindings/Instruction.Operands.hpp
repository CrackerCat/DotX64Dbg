#pragma once

#include <cstdint>
#include <cstdlib>
#include <cstdio>

#include "Register.hpp"
#include "Mnemonic.hpp"
#include "Instruction.Operand.hpp"

namespace Dotx64Dbg {

    public ref class Operands
    {
    private:
        static int AddressSize()
        {
#ifdef _M_X64
            return 64;
#else
            return 32;
#endif
        }

    public:
        // Byte
        //////////////////////////////////////////////////////////////////////////
        static Operand::Memory^ BytePtr(Int64 disp)
        {
            return gcnew Operand::Memory(8, RegisterId::None, RegisterId::None, 0, disp);
        }

        static Operand::Memory^ BytePtr(RegisterId baseReg)
        {
            return gcnew Operand::Memory(8, baseReg, RegisterId::None, 0, 0);
        }
        static Operand::Memory^ BytePtr(Operand::Register^ baseReg)
        {
            return gcnew Operand::Memory(8, baseReg->Value, RegisterId::None, 0, 0);
        }

        static Operand::Memory^ BytePtr(RegisterId baseReg, Int64 disp)
        {
            return gcnew Operand::Memory(8, baseReg, RegisterId::None, 0, disp);
        }
        static Operand::Memory^ BytePtr(Operand::Register^ baseReg, Int64 disp)
        {
            return gcnew Operand::Memory(8, baseReg->Value, RegisterId::None, 0, disp);
        }

        static Operand::Memory^ BytePtr(RegisterId baseReg, RegisterId index)
        {
            return gcnew Operand::Memory(8, baseReg, index, 0, 0);
        }
        static Operand::Memory^ BytePtr(Operand::Register^ baseReg, Operand::Register^ index)
        {
            return gcnew Operand::Memory(8, baseReg->Value, index->Value, 0, 0);
        }

        static Operand::Memory^ BytePtr(RegisterId baseReg, RegisterId index, Int64 disp)
        {
            return gcnew Operand::Memory(8, baseReg, index, 0, disp);
        }
        static Operand::Memory^ BytePtr(Operand::Register^ baseReg, Operand::Register^ index, Int64 disp)
        {
            return gcnew Operand::Memory(8, baseReg->Value, index->Value, 0, disp);
        }

        static Operand::Memory^ BytePtr(RegisterId baseReg, RegisterId index, Int32 scale, Int64 disp)
        {
            return gcnew Operand::Memory(8, baseReg, index, scale, disp);
        }
        static Operand::Memory^ BytePtr(Operand::Register^ baseReg, Operand::Register^ index, Int32 scale, Int64 disp)
        {
            return gcnew Operand::Memory(8, baseReg->Value, index->Value, scale, disp);
        }

        // Word
        //////////////////////////////////////////////////////////////////////////
        static Operand::Memory^ WordPtr(Int64 disp)
        {
            return gcnew Operand::Memory(16, RegisterId::None, RegisterId::None, 0, disp);
        }

        static Operand::Memory^ WordPtr(RegisterId baseReg)
        {
            return gcnew Operand::Memory(16, baseReg, RegisterId::None, 0, 0);
        }
        static Operand::Memory^ WordPtr(Operand::Register^ baseReg)
        {
            return gcnew Operand::Memory(16, baseReg->Value, RegisterId::None, 0, 0);
        }

        static Operand::Memory^ WordPtr(RegisterId baseReg, Int64 disp)
        {
            return gcnew Operand::Memory(16, baseReg, RegisterId::None, 0, disp);
        }
        static Operand::Memory^ WordPtr(Operand::Register^ baseReg, Int64 disp)
        {
            return gcnew Operand::Memory(16, baseReg->Value, RegisterId::None, 0, disp);
        }

        static Operand::Memory^ WordPtr(RegisterId baseReg, RegisterId index)
        {
            return gcnew Operand::Memory(16, baseReg, index, 0, 0);
        }
        static Operand::Memory^ WordPtr(Operand::Register^ baseReg, Operand::Register^ index)
        {
            return gcnew Operand::Memory(16, baseReg->Value, index->Value, 0, 0);
        }

        static Operand::Memory^ WordPtr(RegisterId baseReg, RegisterId index, Int64 disp)
        {
            return gcnew Operand::Memory(16, baseReg, index, 0, disp);
        }
        static Operand::Memory^ WordPtr(Operand::Register^ baseReg, Operand::Register^ index, Int64 disp)
        {
            return gcnew Operand::Memory(16, baseReg->Value, index->Value, 0, disp);
        }

        static Operand::Memory^ WordPtr(RegisterId baseReg, RegisterId index, Int32 scale, Int64 disp)
        {
            return gcnew Operand::Memory(16, baseReg, index, scale, disp);
        }
        static Operand::Memory^ WordPtr(Operand::Register^ baseReg, Operand::Register^ index, Int32 scale, Int64 disp)
        {
            return gcnew Operand::Memory(16, baseReg->Value, index->Value, scale, disp);
        }

        // Dword
        //////////////////////////////////////////////////////////////////////////
        static Operand::Memory^ DwordPtr(Int64 disp)
        {
            return gcnew Operand::Memory(32, RegisterId::None, RegisterId::None, 0, disp);
        }

        static Operand::Memory^ DwordPtr(RegisterId baseReg)
        {
            return gcnew Operand::Memory(32, baseReg, RegisterId::None, 0, 0);
        }
        static Operand::Memory^ DwordPtr(Operand::Register^ baseReg)
        {
            return gcnew Operand::Memory(32, baseReg->Value, RegisterId::None, 0, 0);
        }

        static Operand::Memory^ DwordPtr(RegisterId baseReg, Int64 disp)
        {
            return gcnew Operand::Memory(32, baseReg, RegisterId::None, 0, disp);
        }
        static Operand::Memory^ DwordPtr(Operand::Register^ baseReg, Int64 disp)
        {
            return gcnew Operand::Memory(32, baseReg->Value, RegisterId::None, 0, disp);
        }

        static Operand::Memory^ DwordPtr(RegisterId baseReg, RegisterId index)
        {
            return gcnew Operand::Memory(32, baseReg, index, 0, 0);
        }
        static Operand::Memory^ DwordPtr(Operand::Register^ baseReg, Operand::Register^ index)
        {
            return gcnew Operand::Memory(32, baseReg->Value, index->Value, 0, 0);
        }

        static Operand::Memory^ DwordPtr(RegisterId baseReg, RegisterId index, Int64 disp)
        {
            return gcnew Operand::Memory(32, baseReg, index, 0, disp);
        }
        static Operand::Memory^ DwordPtr(Operand::Register^ baseReg, Operand::Register^ index, Int64 disp)
        {
            return gcnew Operand::Memory(32, baseReg->Value, index->Value, 0, disp);
        }

        static Operand::Memory^ DwordPtr(RegisterId baseReg, RegisterId index, Int32 scale, Int64 disp)
        {
            return gcnew Operand::Memory(32, baseReg, index, scale, disp);
        }
        static Operand::Memory^ DwordPtr(Operand::Register^ baseReg, Operand::Register^ index, Int32 scale, Int64 disp)
        {
            return gcnew Operand::Memory(32, baseReg->Value, index->Value, scale, disp);
        }

        // Qword
        //////////////////////////////////////////////////////////////////////////
        static Operand::Memory^ QwordPtr(Int64 disp)
        {
            return gcnew Operand::Memory(64, RegisterId::None, RegisterId::None, 0, disp);
        }
        static Operand::Memory^ QwordPtr(RegisterId baseReg)
        {
            return gcnew Operand::Memory(64, baseReg, RegisterId::None, 0, 0);
        }
        static Operand::Memory^ QwordPtr(Operand::Register^ baseReg)
        {
            return gcnew Operand::Memory(64, baseReg->Value, RegisterId::None, 0, 0);
        }

        static Operand::Memory^ QwordPtr(RegisterId baseReg, Int64 disp)
        {
            return gcnew Operand::Memory(64, baseReg, RegisterId::None, 0, disp);
        }
        static Operand::Memory^ QwordPtr(Operand::Register^ baseReg, Int64 disp)
        {
            return gcnew Operand::Memory(64, baseReg->Value, RegisterId::None, 0, disp);
        }

        static Operand::Memory^ QwordPtr(RegisterId baseReg, RegisterId index)
        {
            return gcnew Operand::Memory(64, baseReg, index, 0, 0);
        }
        static Operand::Memory^ QwordPtr(Operand::Register^ baseReg, Operand::Register^ index)
        {
            return gcnew Operand::Memory(64, baseReg->Value, index->Value, 0, 0);
        }

        static Operand::Memory^ QwordPtr(RegisterId baseReg, RegisterId index, Int64 disp)
        {
            return gcnew Operand::Memory(64, baseReg, index, 0, disp);
        }
        static Operand::Memory^ QwordPtr(Operand::Register^ baseReg, Operand::Register^ index, Int64 disp)
        {
            return gcnew Operand::Memory(64, baseReg->Value, index->Value, 0, disp);
        }

        static Operand::Memory^ QwordPtr(RegisterId baseReg, RegisterId index, Int32 scale, Int64 disp)
        {
            return gcnew Operand::Memory(64, baseReg, index, scale, disp);
        }
        static Operand::Memory^ QwordPtr(Operand::Register^ baseReg, Operand::Register^ index, Int32 scale, Int64 disp)
        {
            return gcnew Operand::Memory(64, baseReg->Value, index->Value, scale, disp);
        }

        // Tword
        //////////////////////////////////////////////////////////////////////////
        static Operand::Memory^ TwordPtr(Int64 disp)
        {
            return gcnew Operand::Memory(80, RegisterId::None, RegisterId::None, 0, disp);
        }
        static Operand::Memory^ TwordPtr(RegisterId baseReg)
        {
            return gcnew Operand::Memory(80, baseReg, RegisterId::None, 0, 0);
        }
        static Operand::Memory^ TwordPtr(Operand::Register^ baseReg)
        {
            return gcnew Operand::Memory(80, baseReg->Value, RegisterId::None, 0, 0);
        }

        static Operand::Memory^ TwordPtr(RegisterId baseReg, Int64 disp)
        {
            return gcnew Operand::Memory(80, baseReg, RegisterId::None, 0, disp);
        }
        static Operand::Memory^ TwordPtr(Operand::Register^ baseReg, Int64 disp)
        {
            return gcnew Operand::Memory(80, baseReg->Value, RegisterId::None, 0, disp);
        }

        static Operand::Memory^ TwordPtr(RegisterId baseReg, RegisterId index)
        {
            return gcnew Operand::Memory(80, baseReg, index, 0, 0);
        }
        static Operand::Memory^ TwordPtr(Operand::Register^ baseReg, Operand::Register^ index)
        {
            return gcnew Operand::Memory(80, baseReg->Value, index->Value, 0, 0);
        }

        static Operand::Memory^ TwordPtr(RegisterId baseReg, RegisterId index, Int64 disp)
        {
            return gcnew Operand::Memory(80, baseReg, index, 0, disp);
        }
        static Operand::Memory^ TwordPtr(Operand::Register^ baseReg, Operand::Register^ index, Int64 disp)
        {
            return gcnew Operand::Memory(80, baseReg->Value, index->Value, 0, disp);
        }

        static Operand::Memory^ TwordPtr(RegisterId baseReg, RegisterId index, Int32 scale, Int64 disp)
        {
            return gcnew Operand::Memory(80, baseReg, index, scale, disp);
        }
        static Operand::Memory^ TwordPtr(Operand::Register^ baseReg, Operand::Register^ index, Int32 scale, Int64 disp)
        {
            return gcnew Operand::Memory(80, baseReg->Value, index->Value, scale, disp);
        }

        // Xmmword
        //////////////////////////////////////////////////////////////////////////
        static Operand::Memory^ XmmwordPtr(Int64 disp)
        {
            return gcnew Operand::Memory(128, RegisterId::None, RegisterId::None, 0, disp);
        }
        static Operand::Memory^ XmmwordPtr(RegisterId baseReg)
        {
            return gcnew Operand::Memory(128, baseReg, RegisterId::None, 0, 0);
        }
        static Operand::Memory^ XmmwordPtr(Operand::Register^ baseReg)
        {
            return gcnew Operand::Memory(128, baseReg->Value, RegisterId::None, 0, 0);
        }

        static Operand::Memory^ XmmwordPtr(RegisterId baseReg, Int64 disp)
        {
            return gcnew Operand::Memory(128, baseReg, RegisterId::None, 0, disp);
        }
        static Operand::Memory^ XmmwordPtr(Operand::Register^ baseReg, Int64 disp)
        {
            return gcnew Operand::Memory(128, baseReg->Value, RegisterId::None, 0, disp);
        }

        static Operand::Memory^ XmmwordPtr(RegisterId baseReg, RegisterId index)
        {
            return gcnew Operand::Memory(128, baseReg, index, 0, 0);
        }
        static Operand::Memory^ XmmwordPtr(Operand::Register^ baseReg, Operand::Register^ index)
        {
            return gcnew Operand::Memory(128, baseReg->Value, index->Value, 0, 0);
        }

        static Operand::Memory^ XmmwordPtr(RegisterId baseReg, RegisterId index, Int64 disp)
        {
            return gcnew Operand::Memory(128, baseReg, index, 0, disp);
        }
        static Operand::Memory^ XmmwordPtr(Operand::Register^ baseReg, Operand::Register^ index, Int64 disp)
        {
            return gcnew Operand::Memory(128, baseReg->Value, index->Value, 0, disp);
        }

        static Operand::Memory^ XmmwordPtr(RegisterId baseReg, RegisterId index, Int32 scale, Int64 disp)
        {
            return gcnew Operand::Memory(128, baseReg, index, scale, disp);
        }
        static Operand::Memory^ XmmwordPtr(Operand::Register^ baseReg, Operand::Register^ index, Int32 scale, Int64 disp)
        {
            return gcnew Operand::Memory(128, baseReg->Value, index->Value, scale, disp);
        }

        // Ymmword
        //////////////////////////////////////////////////////////////////////////
        static Operand::Memory^ YmmwordPtr(Int64 disp)
        {
            return gcnew Operand::Memory(256, RegisterId::None, RegisterId::None, 0, disp);
        }
        static Operand::Memory^ YmmwordPtr(RegisterId baseReg)
        {
            return gcnew Operand::Memory(256, baseReg, RegisterId::None, 0, 0);
        }
        static Operand::Memory^ YmmwordPtr(Operand::Register^ baseReg)
        {
            return gcnew Operand::Memory(256, baseReg->Value, RegisterId::None, 0, 0);
        }

        static Operand::Memory^ YmmwordPtr(RegisterId baseReg, Int64 disp)
        {
            return gcnew Operand::Memory(256, baseReg, RegisterId::None, 0, disp);
        }
        static Operand::Memory^ YmmwordPtr(Operand::Register^ baseReg, Int64 disp)
        {
            return gcnew Operand::Memory(256, baseReg->Value, RegisterId::None, 0, disp);
        }

        static Operand::Memory^ YmmwordPtr(RegisterId baseReg, RegisterId index)
        {
            return gcnew Operand::Memory(256, baseReg, index, 0, 0);
        }
        static Operand::Memory^ YmmwordPtr(Operand::Register^ baseReg, Operand::Register^ index)
        {
            return gcnew Operand::Memory(256, baseReg->Value, index->Value, 0, 0);
        }

        static Operand::Memory^ YmmwordPtr(RegisterId baseReg, RegisterId index, Int64 disp)
        {
            return gcnew Operand::Memory(256, baseReg, index, 0, disp);
        }
        static Operand::Memory^ YmmwordPtr(Operand::Register^ baseReg, Operand::Register^ index, Int64 disp)
        {
            return gcnew Operand::Memory(256, baseReg->Value, index->Value, 0, disp);
        }

        static Operand::Memory^ YmmwordPtr(RegisterId baseReg, RegisterId index, Int32 scale, Int64 disp)
        {
            return gcnew Operand::Memory(256, baseReg, index, scale, disp);
        }
        static Operand::Memory^ YmmwordPtr(Operand::Register^ baseReg, Operand::Register^ index, Int32 scale, Int64 disp)
        {
            return gcnew Operand::Memory(256, baseReg->Value, index->Value, scale, disp);
        }

        // Zmmword
        //////////////////////////////////////////////////////////////////////////
        static Operand::Memory^ ZmmwordPtr(Int64 disp)
        {
            return gcnew Operand::Memory(512, RegisterId::None, RegisterId::None, 0, disp);
        }
        static Operand::Memory^ ZmmwordPtr(RegisterId baseReg)
        {
            return gcnew Operand::Memory(512, baseReg, RegisterId::None, 0, 0);
        }
        static Operand::Memory^ ZmmwordPtr(Operand::Register^ baseReg)
        {
            return gcnew Operand::Memory(512, baseReg->Value, RegisterId::None, 0, 0);
        }

        static Operand::Memory^ ZmmwordPtr(RegisterId baseReg, Int64 disp)
        {
            return gcnew Operand::Memory(512, baseReg, RegisterId::None, 0, disp);
        }
        static Operand::Memory^ ZmmwordPtr(Operand::Register^ baseReg, Int64 disp)
        {
            return gcnew Operand::Memory(512, baseReg->Value, RegisterId::None, 0, disp);
        }

        static Operand::Memory^ ZmmwordPtr(RegisterId baseReg, RegisterId index)
        {
            return gcnew Operand::Memory(512, baseReg, index, 0, 0);
        }
        static Operand::Memory^ ZmmwordPtr(Operand::Register^ baseReg, Operand::Register^ index)
        {
            return gcnew Operand::Memory(512, baseReg->Value, index->Value, 0, 0);
        }

        static Operand::Memory^ ZmmwordPtr(RegisterId baseReg, RegisterId index, Int64 disp)
        {
            return gcnew Operand::Memory(512, baseReg, index, 0, disp);
        }
        static Operand::Memory^ ZmmwordPtr(Operand::Register^ baseReg, Operand::Register^ index, Int64 disp)
        {
            return gcnew Operand::Memory(512, baseReg->Value, index->Value, 0, disp);
        }

        static Operand::Memory^ ZmmwordPtr(RegisterId baseReg, RegisterId index, Int32 scale, Int64 disp)
        {
            return gcnew Operand::Memory(512, baseReg, index, scale, disp);
        }
        static Operand::Memory^ ZmmwordPtr(Operand::Register^ baseReg, Operand::Register^ index, Int32 scale, Int64 disp)
        {
            return gcnew Operand::Memory(512, baseReg->Value, index->Value, scale, disp);
        }

        // Host
        //////////////////////////////////////////////////////////////////////////
        static Operand::Memory^ Ptr(Int64 disp)
        {
            return gcnew Operand::Memory(AddressSize(), RegisterId::None, RegisterId::None, 0, disp);
        }
        static Operand::Memory^ Ptr(RegisterId baseReg)
        {
            return gcnew Operand::Memory(AddressSize(), baseReg, RegisterId::None, 0, 0);
        }
        static Operand::Memory^ Ptr(Operand::Register^ baseReg)
        {
            return gcnew Operand::Memory(AddressSize(), baseReg->Value, RegisterId::None, 0, 0);
        }

        static Operand::Memory^ Ptr(RegisterId baseReg, Int64 disp)
        {
            return gcnew Operand::Memory(AddressSize(), baseReg, RegisterId::None, 0, disp);
        }
        static Operand::Memory^ Ptr(Operand::Register^ baseReg, Int64 disp)
        {
            return gcnew Operand::Memory(AddressSize(), baseReg->Value, RegisterId::None, 0, disp);
        }

        static Operand::Memory^ Ptr(RegisterId baseReg, RegisterId index)
        {
            return gcnew Operand::Memory(AddressSize(), baseReg, index, 0, 0);
        }
        static Operand::Memory^ Ptr(Operand::Register^ baseReg, Operand::Register^ index)
        {
            return gcnew Operand::Memory(AddressSize(), baseReg->Value, index->Value, 0, 0);
        }

        static Operand::Memory^ Ptr(RegisterId baseReg, RegisterId index, Int64 disp)
        {
            return gcnew Operand::Memory(AddressSize(), baseReg, index, 0, disp);
        }
        static Operand::Memory^ Ptr(Operand::Register^ baseReg, Operand::Register^ index, Int64 disp)
        {
            return gcnew Operand::Memory(AddressSize(), baseReg->Value, index->Value, 0, disp);
        }

        static Operand::Memory^ Ptr(RegisterId baseReg, RegisterId index, Int32 scale, Int64 disp)
        {
            return gcnew Operand::Memory(AddressSize(), baseReg, index, scale, disp);
        }
        static Operand::Memory^ Ptr(Operand::Register^ baseReg, Operand::Register^ index, Int32 scale, Int64 disp)
        {
            return gcnew Operand::Memory(AddressSize(), baseReg->Value, index->Value, scale, disp);
        }

    public:
        // General purpose registers  8-bit
        static initonly Operand::Register^ Al = gcnew Operand::Register(RegisterId::Al);
        static initonly Operand::Register^ Cl = gcnew Operand::Register(RegisterId::Cl);
        static initonly Operand::Register^ Dl = gcnew Operand::Register(RegisterId::Dl);
        static initonly Operand::Register^ Bl = gcnew Operand::Register(RegisterId::Bl);
        static initonly Operand::Register^ Ah = gcnew Operand::Register(RegisterId::Ah);
        static initonly Operand::Register^ Ch = gcnew Operand::Register(RegisterId::Ch);
        static initonly Operand::Register^ Dh = gcnew Operand::Register(RegisterId::Dh);
        static initonly Operand::Register^ Bh = gcnew Operand::Register(RegisterId::Bh);
        static initonly Operand::Register^ Spl = gcnew Operand::Register(RegisterId::Spl);
        static initonly Operand::Register^ Bpl = gcnew Operand::Register(RegisterId::Bpl);
        static initonly Operand::Register^ Sil = gcnew Operand::Register(RegisterId::Sil);
        static initonly Operand::Register^ Dil = gcnew Operand::Register(RegisterId::Dil);
#if _M_X64
        static initonly Operand::Register^ R8b = gcnew Operand::Register(RegisterId::R8b);
        static initonly Operand::Register^ R9b = gcnew Operand::Register(RegisterId::R9b);
        static initonly Operand::Register^ R10b = gcnew Operand::Register(RegisterId::R10b);
        static initonly Operand::Register^ R11b = gcnew Operand::Register(RegisterId::R11b);
        static initonly Operand::Register^ R12b = gcnew Operand::Register(RegisterId::R12b);
        static initonly Operand::Register^ R13b = gcnew Operand::Register(RegisterId::R13b);
        static initonly Operand::Register^ R14b = gcnew Operand::Register(RegisterId::R14b);
        static initonly Operand::Register^ R15b = gcnew Operand::Register(RegisterId::R15b);
#endif
        // General purpose registers 16-bit
        static initonly Operand::Register^ Ax = gcnew Operand::Register(RegisterId::Ax);
        static initonly Operand::Register^ Cx = gcnew Operand::Register(RegisterId::Cx);
        static initonly Operand::Register^ Dx = gcnew Operand::Register(RegisterId::Dx);
        static initonly Operand::Register^ Bx = gcnew Operand::Register(RegisterId::Bx);
        static initonly Operand::Register^ Sp = gcnew Operand::Register(RegisterId::Sp);
        static initonly Operand::Register^ Bp = gcnew Operand::Register(RegisterId::Bp);
        static initonly Operand::Register^ Si = gcnew Operand::Register(RegisterId::Si);
        static initonly Operand::Register^ Di = gcnew Operand::Register(RegisterId::Di);
#if _M_X64
        static initonly Operand::Register^ R8w = gcnew Operand::Register(RegisterId::R8w);
        static initonly Operand::Register^ R9w = gcnew Operand::Register(RegisterId::R9w);
        static initonly Operand::Register^ R10w = gcnew Operand::Register(RegisterId::R10w);
        static initonly Operand::Register^ R11w = gcnew Operand::Register(RegisterId::R11w);
        static initonly Operand::Register^ R12w = gcnew Operand::Register(RegisterId::R12w);
        static initonly Operand::Register^ R13w = gcnew Operand::Register(RegisterId::R13w);
        static initonly Operand::Register^ R14w = gcnew Operand::Register(RegisterId::R14w);
        static initonly Operand::Register^ R15w = gcnew Operand::Register(RegisterId::R15w);
#endif
        // General purpose registers 32-bit
        static initonly Operand::Register^ Eax = gcnew Operand::Register(RegisterId::Eax);
        static initonly Operand::Register^ Ecx = gcnew Operand::Register(RegisterId::Ecx);
        static initonly Operand::Register^ Edx = gcnew Operand::Register(RegisterId::Edx);
        static initonly Operand::Register^ Ebx = gcnew Operand::Register(RegisterId::Ebx);
        static initonly Operand::Register^ Esp = gcnew Operand::Register(RegisterId::Esp);
        static initonly Operand::Register^ Ebp = gcnew Operand::Register(RegisterId::Ebp);
        static initonly Operand::Register^ Esi = gcnew Operand::Register(RegisterId::Esi);
        static initonly Operand::Register^ Edi = gcnew Operand::Register(RegisterId::Edi);
        static initonly Operand::Register^ R8d = gcnew Operand::Register(RegisterId::R8d);
        static initonly Operand::Register^ R9d = gcnew Operand::Register(RegisterId::R9d);
        static initonly Operand::Register^ R10d = gcnew Operand::Register(RegisterId::R10d);
        static initonly Operand::Register^ R11d = gcnew Operand::Register(RegisterId::R11d);
        static initonly Operand::Register^ R12d = gcnew Operand::Register(RegisterId::R12d);
        static initonly Operand::Register^ R13d = gcnew Operand::Register(RegisterId::R13d);
        static initonly Operand::Register^ R14d = gcnew Operand::Register(RegisterId::R14d);
        static initonly Operand::Register^ R15d = gcnew Operand::Register(RegisterId::R15d);

#if _M_X64
        // General purpose registers 64-bit
        static initonly Operand::Register^ Rax = gcnew Operand::Register(RegisterId::Rax);
        static initonly Operand::Register^ Rcx = gcnew Operand::Register(RegisterId::Rcx);
        static initonly Operand::Register^ Rdx = gcnew Operand::Register(RegisterId::Rdx);
        static initonly Operand::Register^ Rbx = gcnew Operand::Register(RegisterId::Rbx);
        static initonly Operand::Register^ Rsp = gcnew Operand::Register(RegisterId::Rsp);
        static initonly Operand::Register^ Rbp = gcnew Operand::Register(RegisterId::Rbp);
        static initonly Operand::Register^ Rsi = gcnew Operand::Register(RegisterId::Rsi);
        static initonly Operand::Register^ Rdi = gcnew Operand::Register(RegisterId::Rdi);
        static initonly Operand::Register^ R8 = gcnew Operand::Register(RegisterId::R8);
        static initonly Operand::Register^ R9 = gcnew Operand::Register(RegisterId::R9);
        static initonly Operand::Register^ R10 = gcnew Operand::Register(RegisterId::R10);
        static initonly Operand::Register^ R11 = gcnew Operand::Register(RegisterId::R11);
        static initonly Operand::Register^ R12 = gcnew Operand::Register(RegisterId::R12);
        static initonly Operand::Register^ R13 = gcnew Operand::Register(RegisterId::R13);
        static initonly Operand::Register^ R14 = gcnew Operand::Register(RegisterId::R14);
        static initonly Operand::Register^ R15 = gcnew Operand::Register(RegisterId::R15);
#endif
        // Floating point legacy registers
        static initonly Operand::Register^ St0 = gcnew Operand::Register(RegisterId::St0);
        static initonly Operand::Register^ St1 = gcnew Operand::Register(RegisterId::St1);
        static initonly Operand::Register^ St2 = gcnew Operand::Register(RegisterId::St2);
        static initonly Operand::Register^ St3 = gcnew Operand::Register(RegisterId::St3);
        static initonly Operand::Register^ St4 = gcnew Operand::Register(RegisterId::St4);
        static initonly Operand::Register^ St5 = gcnew Operand::Register(RegisterId::St5);
        static initonly Operand::Register^ St6 = gcnew Operand::Register(RegisterId::St6);
        static initonly Operand::Register^ St7 = gcnew Operand::Register(RegisterId::St7);
        static initonly Operand::Register^ X87Control = gcnew Operand::Register(RegisterId::X87Control);
        static initonly Operand::Register^ X87Status = gcnew Operand::Register(RegisterId::X87Status);
        static initonly Operand::Register^ X87Tag = gcnew Operand::Register(RegisterId::X87Tag);
        // Floating point multimedia registers
        static initonly Operand::Register^ Mm0 = gcnew Operand::Register(RegisterId::Mm0);
        static initonly Operand::Register^ Mm1 = gcnew Operand::Register(RegisterId::Mm1);
        static initonly Operand::Register^ Mm2 = gcnew Operand::Register(RegisterId::Mm2);
        static initonly Operand::Register^ Mm3 = gcnew Operand::Register(RegisterId::Mm3);
        static initonly Operand::Register^ Mm4 = gcnew Operand::Register(RegisterId::Mm4);
        static initonly Operand::Register^ Mm5 = gcnew Operand::Register(RegisterId::Mm5);
        static initonly Operand::Register^ Mm6 = gcnew Operand::Register(RegisterId::Mm6);
        static initonly Operand::Register^ Mm7 = gcnew Operand::Register(RegisterId::Mm7);
        // Floating point vector registers 128-bit
        static initonly Operand::Register^ Xmm0 = gcnew Operand::Register(RegisterId::Xmm0);
        static initonly Operand::Register^ Xmm1 = gcnew Operand::Register(RegisterId::Xmm1);
        static initonly Operand::Register^ Xmm2 = gcnew Operand::Register(RegisterId::Xmm2);
        static initonly Operand::Register^ Xmm3 = gcnew Operand::Register(RegisterId::Xmm3);
        static initonly Operand::Register^ Xmm4 = gcnew Operand::Register(RegisterId::Xmm4);
        static initonly Operand::Register^ Xmm5 = gcnew Operand::Register(RegisterId::Xmm5);
        static initonly Operand::Register^ Xmm6 = gcnew Operand::Register(RegisterId::Xmm6);
        static initonly Operand::Register^ Xmm7 = gcnew Operand::Register(RegisterId::Xmm7);
        static initonly Operand::Register^ Xmm8 = gcnew Operand::Register(RegisterId::Xmm8);
        static initonly Operand::Register^ Xmm9 = gcnew Operand::Register(RegisterId::Xmm9);
        static initonly Operand::Register^ Xmm10 = gcnew Operand::Register(RegisterId::Xmm10);
        static initonly Operand::Register^ Xmm11 = gcnew Operand::Register(RegisterId::Xmm11);
        static initonly Operand::Register^ Xmm12 = gcnew Operand::Register(RegisterId::Xmm12);
        static initonly Operand::Register^ Xmm13 = gcnew Operand::Register(RegisterId::Xmm13);
        static initonly Operand::Register^ Xmm14 = gcnew Operand::Register(RegisterId::Xmm14);
        static initonly Operand::Register^ Xmm15 = gcnew Operand::Register(RegisterId::Xmm15);
        static initonly Operand::Register^ Xmm16 = gcnew Operand::Register(RegisterId::Xmm16);
        static initonly Operand::Register^ Xmm17 = gcnew Operand::Register(RegisterId::Xmm17);
        static initonly Operand::Register^ Xmm18 = gcnew Operand::Register(RegisterId::Xmm18);
        static initonly Operand::Register^ Xmm19 = gcnew Operand::Register(RegisterId::Xmm19);
        static initonly Operand::Register^ Xmm20 = gcnew Operand::Register(RegisterId::Xmm20);
        static initonly Operand::Register^ Xmm21 = gcnew Operand::Register(RegisterId::Xmm21);
        static initonly Operand::Register^ Xmm22 = gcnew Operand::Register(RegisterId::Xmm22);
        static initonly Operand::Register^ Xmm23 = gcnew Operand::Register(RegisterId::Xmm23);
        static initonly Operand::Register^ Xmm24 = gcnew Operand::Register(RegisterId::Xmm24);
        static initonly Operand::Register^ Xmm25 = gcnew Operand::Register(RegisterId::Xmm25);
        static initonly Operand::Register^ Xmm26 = gcnew Operand::Register(RegisterId::Xmm26);
        static initonly Operand::Register^ Xmm27 = gcnew Operand::Register(RegisterId::Xmm27);
        static initonly Operand::Register^ Xmm28 = gcnew Operand::Register(RegisterId::Xmm28);
        static initonly Operand::Register^ Xmm29 = gcnew Operand::Register(RegisterId::Xmm29);
        static initonly Operand::Register^ Xmm30 = gcnew Operand::Register(RegisterId::Xmm30);
        static initonly Operand::Register^ Xmm31 = gcnew Operand::Register(RegisterId::Xmm31);
        // Floating point vector registers 256-bit
        static initonly Operand::Register^ Ymm0 = gcnew Operand::Register(RegisterId::Ymm0);
        static initonly Operand::Register^ Ymm1 = gcnew Operand::Register(RegisterId::Ymm1);
        static initonly Operand::Register^ Ymm2 = gcnew Operand::Register(RegisterId::Ymm2);
        static initonly Operand::Register^ Ymm3 = gcnew Operand::Register(RegisterId::Ymm3);
        static initonly Operand::Register^ Ymm4 = gcnew Operand::Register(RegisterId::Ymm4);
        static initonly Operand::Register^ Ymm5 = gcnew Operand::Register(RegisterId::Ymm5);
        static initonly Operand::Register^ Ymm6 = gcnew Operand::Register(RegisterId::Ymm6);
        static initonly Operand::Register^ Ymm7 = gcnew Operand::Register(RegisterId::Ymm7);
        static initonly Operand::Register^ Ymm8 = gcnew Operand::Register(RegisterId::Ymm8);
        static initonly Operand::Register^ Ymm9 = gcnew Operand::Register(RegisterId::Ymm9);
        static initonly Operand::Register^ Ymm10 = gcnew Operand::Register(RegisterId::Ymm10);
        static initonly Operand::Register^ Ymm11 = gcnew Operand::Register(RegisterId::Ymm11);
        static initonly Operand::Register^ Ymm12 = gcnew Operand::Register(RegisterId::Ymm12);
        static initonly Operand::Register^ Ymm13 = gcnew Operand::Register(RegisterId::Ymm13);
        static initonly Operand::Register^ Ymm14 = gcnew Operand::Register(RegisterId::Ymm14);
        static initonly Operand::Register^ Ymm15 = gcnew Operand::Register(RegisterId::Ymm15);
        static initonly Operand::Register^ Ymm16 = gcnew Operand::Register(RegisterId::Ymm16);
        static initonly Operand::Register^ Ymm17 = gcnew Operand::Register(RegisterId::Ymm17);
        static initonly Operand::Register^ Ymm18 = gcnew Operand::Register(RegisterId::Ymm18);
        static initonly Operand::Register^ Ymm19 = gcnew Operand::Register(RegisterId::Ymm19);
        static initonly Operand::Register^ Ymm20 = gcnew Operand::Register(RegisterId::Ymm20);
        static initonly Operand::Register^ Ymm21 = gcnew Operand::Register(RegisterId::Ymm21);
        static initonly Operand::Register^ Ymm22 = gcnew Operand::Register(RegisterId::Ymm22);
        static initonly Operand::Register^ Ymm23 = gcnew Operand::Register(RegisterId::Ymm23);
        static initonly Operand::Register^ Ymm24 = gcnew Operand::Register(RegisterId::Ymm24);
        static initonly Operand::Register^ Ymm25 = gcnew Operand::Register(RegisterId::Ymm25);
        static initonly Operand::Register^ Ymm26 = gcnew Operand::Register(RegisterId::Ymm26);
        static initonly Operand::Register^ Ymm27 = gcnew Operand::Register(RegisterId::Ymm27);
        static initonly Operand::Register^ Ymm28 = gcnew Operand::Register(RegisterId::Ymm28);
        static initonly Operand::Register^ Ymm29 = gcnew Operand::Register(RegisterId::Ymm29);
        static initonly Operand::Register^ Ymm30 = gcnew Operand::Register(RegisterId::Ymm30);
        static initonly Operand::Register^ Ymm31 = gcnew Operand::Register(RegisterId::Ymm31);
        // Floating point vector registers 512-bit
        static initonly Operand::Register^ Zmm0 = gcnew Operand::Register(RegisterId::Zmm0);
        static initonly Operand::Register^ Zmm1 = gcnew Operand::Register(RegisterId::Zmm1);
        static initonly Operand::Register^ Zmm2 = gcnew Operand::Register(RegisterId::Zmm2);
        static initonly Operand::Register^ Zmm3 = gcnew Operand::Register(RegisterId::Zmm3);
        static initonly Operand::Register^ Zmm4 = gcnew Operand::Register(RegisterId::Zmm4);
        static initonly Operand::Register^ Zmm5 = gcnew Operand::Register(RegisterId::Zmm5);
        static initonly Operand::Register^ Zmm6 = gcnew Operand::Register(RegisterId::Zmm6);
        static initonly Operand::Register^ Zmm7 = gcnew Operand::Register(RegisterId::Zmm7);
        static initonly Operand::Register^ Zmm8 = gcnew Operand::Register(RegisterId::Zmm8);
        static initonly Operand::Register^ Zmm9 = gcnew Operand::Register(RegisterId::Zmm9);
        static initonly Operand::Register^ Zmm10 = gcnew Operand::Register(RegisterId::Zmm10);
        static initonly Operand::Register^ Zmm11 = gcnew Operand::Register(RegisterId::Zmm11);
        static initonly Operand::Register^ Zmm12 = gcnew Operand::Register(RegisterId::Zmm12);
        static initonly Operand::Register^ Zmm13 = gcnew Operand::Register(RegisterId::Zmm13);
        static initonly Operand::Register^ Zmm14 = gcnew Operand::Register(RegisterId::Zmm14);
        static initonly Operand::Register^ Zmm15 = gcnew Operand::Register(RegisterId::Zmm15);
        static initonly Operand::Register^ Zmm16 = gcnew Operand::Register(RegisterId::Zmm16);
        static initonly Operand::Register^ Zmm17 = gcnew Operand::Register(RegisterId::Zmm17);
        static initonly Operand::Register^ Zmm18 = gcnew Operand::Register(RegisterId::Zmm18);
        static initonly Operand::Register^ Zmm19 = gcnew Operand::Register(RegisterId::Zmm19);
        static initonly Operand::Register^ Zmm20 = gcnew Operand::Register(RegisterId::Zmm20);
        static initonly Operand::Register^ Zmm21 = gcnew Operand::Register(RegisterId::Zmm21);
        static initonly Operand::Register^ Zmm22 = gcnew Operand::Register(RegisterId::Zmm22);
        static initonly Operand::Register^ Zmm23 = gcnew Operand::Register(RegisterId::Zmm23);
        static initonly Operand::Register^ Zmm24 = gcnew Operand::Register(RegisterId::Zmm24);
        static initonly Operand::Register^ Zmm25 = gcnew Operand::Register(RegisterId::Zmm25);
        static initonly Operand::Register^ Zmm26 = gcnew Operand::Register(RegisterId::Zmm26);
        static initonly Operand::Register^ Zmm27 = gcnew Operand::Register(RegisterId::Zmm27);
        static initonly Operand::Register^ Zmm28 = gcnew Operand::Register(RegisterId::Zmm28);
        static initonly Operand::Register^ Zmm29 = gcnew Operand::Register(RegisterId::Zmm29);
        static initonly Operand::Register^ Zmm30 = gcnew Operand::Register(RegisterId::Zmm30);
        static initonly Operand::Register^ Zmm31 = gcnew Operand::Register(RegisterId::Zmm31);
        // Flags registers
        static initonly Operand::Register^ Flags = gcnew Operand::Register(RegisterId::Flags);
        static initonly Operand::Register^ EFlags = gcnew Operand::Register(RegisterId::EFlags);
        static initonly Operand::Register^ RFlags = gcnew Operand::Register(RegisterId::RFlags);
        // Instruction-pointer registers
        static initonly Operand::Register^ Ip = gcnew Operand::Register(RegisterId::Ip);
        static initonly Operand::Register^ Eip = gcnew Operand::Register(RegisterId::Eip);
        static initonly Operand::Register^ Rip = gcnew Operand::Register(RegisterId::Rip);
        // Segment registers
        static initonly Operand::Register^ Es = gcnew Operand::Register(RegisterId::Es);
        static initonly Operand::Register^ Cs = gcnew Operand::Register(RegisterId::Cs);
        static initonly Operand::Register^ Ss = gcnew Operand::Register(RegisterId::Ss);
        static initonly Operand::Register^ Ds = gcnew Operand::Register(RegisterId::Ds);
        static initonly Operand::Register^ Fs = gcnew Operand::Register(RegisterId::Fs);
        static initonly Operand::Register^ Gs = gcnew Operand::Register(RegisterId::Gs);
        // Table registers
        static initonly Operand::Register^ Gdtr = gcnew Operand::Register(RegisterId::Gdtr);
        static initonly Operand::Register^ Ldtr = gcnew Operand::Register(RegisterId::Ldtr);
        static initonly Operand::Register^ Idtr = gcnew Operand::Register(RegisterId::Idtr);
        static initonly Operand::Register^ Tr = gcnew Operand::Register(RegisterId::Tr);
        // Test registers
        static initonly Operand::Register^ Tr0 = gcnew Operand::Register(RegisterId::Tr0);
        static initonly Operand::Register^ Tr1 = gcnew Operand::Register(RegisterId::Tr1);
        static initonly Operand::Register^ Tr2 = gcnew Operand::Register(RegisterId::Tr2);
        static initonly Operand::Register^ Tr3 = gcnew Operand::Register(RegisterId::Tr3);
        static initonly Operand::Register^ Tr4 = gcnew Operand::Register(RegisterId::Tr4);
        static initonly Operand::Register^ Tr5 = gcnew Operand::Register(RegisterId::Tr5);
        static initonly Operand::Register^ Tr6 = gcnew Operand::Register(RegisterId::Tr6);
        static initonly Operand::Register^ Tr7 = gcnew Operand::Register(RegisterId::Tr7);
        // Control registers
        static initonly Operand::Register^ Cr0 = gcnew Operand::Register(RegisterId::Cr0);
        static initonly Operand::Register^ Cr1 = gcnew Operand::Register(RegisterId::Cr1);
        static initonly Operand::Register^ Cr2 = gcnew Operand::Register(RegisterId::Cr2);
        static initonly Operand::Register^ Cr3 = gcnew Operand::Register(RegisterId::Cr3);
        static initonly Operand::Register^ Cr4 = gcnew Operand::Register(RegisterId::Cr4);
        static initonly Operand::Register^ Cr5 = gcnew Operand::Register(RegisterId::Cr5);
        static initonly Operand::Register^ Cr6 = gcnew Operand::Register(RegisterId::Cr6);
        static initonly Operand::Register^ Cr7 = gcnew Operand::Register(RegisterId::Cr7);
        static initonly Operand::Register^ Cr8 = gcnew Operand::Register(RegisterId::Cr8);
        static initonly Operand::Register^ Cr9 = gcnew Operand::Register(RegisterId::Cr9);
        static initonly Operand::Register^ Cr10 = gcnew Operand::Register(RegisterId::Cr10);
        static initonly Operand::Register^ Cr11 = gcnew Operand::Register(RegisterId::Cr11);
        static initonly Operand::Register^ Cr12 = gcnew Operand::Register(RegisterId::Cr12);
        static initonly Operand::Register^ Cr13 = gcnew Operand::Register(RegisterId::Cr13);
        static initonly Operand::Register^ Cr14 = gcnew Operand::Register(RegisterId::Cr14);
        static initonly Operand::Register^ Cr15 = gcnew Operand::Register(RegisterId::Cr15);
        // Debug registers
        static initonly Operand::Register^ Dr0 = gcnew Operand::Register(RegisterId::Dr0);
        static initonly Operand::Register^ Dr1 = gcnew Operand::Register(RegisterId::Dr1);
        static initonly Operand::Register^ Dr2 = gcnew Operand::Register(RegisterId::Dr2);
        static initonly Operand::Register^ Dr3 = gcnew Operand::Register(RegisterId::Dr3);
        static initonly Operand::Register^ Dr4 = gcnew Operand::Register(RegisterId::Dr4);
        static initonly Operand::Register^ Dr5 = gcnew Operand::Register(RegisterId::Dr5);
        static initonly Operand::Register^ Dr6 = gcnew Operand::Register(RegisterId::Dr6);
        static initonly Operand::Register^ Dr7 = gcnew Operand::Register(RegisterId::Dr7);
        static initonly Operand::Register^ Dr8 = gcnew Operand::Register(RegisterId::Dr8);
        static initonly Operand::Register^ Dr9 = gcnew Operand::Register(RegisterId::Dr9);
        static initonly Operand::Register^ Dr10 = gcnew Operand::Register(RegisterId::Dr10);
        static initonly Operand::Register^ Dr11 = gcnew Operand::Register(RegisterId::Dr11);
        static initonly Operand::Register^ Dr12 = gcnew Operand::Register(RegisterId::Dr12);
        static initonly Operand::Register^ Dr13 = gcnew Operand::Register(RegisterId::Dr13);
        static initonly Operand::Register^ Dr14 = gcnew Operand::Register(RegisterId::Dr14);
        static initonly Operand::Register^ Dr15 = gcnew Operand::Register(RegisterId::Dr15);
        // Mask registers
        static initonly Operand::Register^ K0 = gcnew Operand::Register(RegisterId::K0);
        static initonly Operand::Register^ K1 = gcnew Operand::Register(RegisterId::K1);
        static initonly Operand::Register^ K2 = gcnew Operand::Register(RegisterId::K2);
        static initonly Operand::Register^ K3 = gcnew Operand::Register(RegisterId::K3);
        static initonly Operand::Register^ K4 = gcnew Operand::Register(RegisterId::K4);
        static initonly Operand::Register^ K5 = gcnew Operand::Register(RegisterId::K5);
        static initonly Operand::Register^ K6 = gcnew Operand::Register(RegisterId::K6);
        static initonly Operand::Register^ K7 = gcnew Operand::Register(RegisterId::K7);
        // Bound registers
        static initonly Operand::Register^ Bnd0 = gcnew Operand::Register(RegisterId::Bnd0);
        static initonly Operand::Register^ Bnd1 = gcnew Operand::Register(RegisterId::Bnd1);
        static initonly Operand::Register^ Bnd2 = gcnew Operand::Register(RegisterId::Bnd2);
        static initonly Operand::Register^ Bnd3 = gcnew Operand::Register(RegisterId::Bnd3);
        static initonly Operand::Register^ BndCfg = gcnew Operand::Register(RegisterId::BndCfg);
        static initonly Operand::Register^ BndStatus = gcnew Operand::Register(RegisterId::BndStatus);
        // Uncategorized
        static initonly Operand::Register^ Mxcsr = gcnew Operand::Register(RegisterId::Mxcsr);
        static initonly Operand::Register^ Pkru = gcnew Operand::Register(RegisterId::Pkru);
        static initonly Operand::Register^ Xcr0 = gcnew Operand::Register(RegisterId::Xcr0);
        // Host specific
        static initonly Operand::Register^ Nax = gcnew Operand::Register(RegisterId::Nax);
        static initonly Operand::Register^ Ncx = gcnew Operand::Register(RegisterId::Ncx);
        static initonly Operand::Register^ Ndx = gcnew Operand::Register(RegisterId::Ndx);
        static initonly Operand::Register^ Nbx = gcnew Operand::Register(RegisterId::Nbx);
        static initonly Operand::Register^ Nsp = gcnew Operand::Register(RegisterId::Nsp);
        static initonly Operand::Register^ Nbp = gcnew Operand::Register(RegisterId::Nbp);
        static initonly Operand::Register^ Nsi = gcnew Operand::Register(RegisterId::Nsi);
        static initonly Operand::Register^ Ndi = gcnew Operand::Register(RegisterId::Ndi);
        static initonly Operand::Register^ Nip = gcnew Operand::Register(RegisterId::Nip);
        static initonly Operand::Register^ NFlags = gcnew Operand::Register(RegisterId::NFlags);

        static Operand::Register^ Reg(RegisterId reg)
        {
            return gcnew Operand::Register(reg);
        }

    public:
        static Operand::Immediate^ Imm(Int64 val)
        {
            return gcnew Operand::Immediate(val);
        }
    };

}
