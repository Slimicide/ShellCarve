import re
# Carried by https://www.ired.team/offensive-security/code-injection-process-injection/writing-and-compiling-shellcode-in-c
# Used during compilation by compile.bat

AlignRSP = """
; https://github.com/mattifestation/PIC_Bindshell/blob/master/PIC_Bindshell/AdjustStack.asm

; AlignRSP is a simple call stub that ensures that the stack is 16-byte aligned prior
; to calling the entry point of the payload. This is necessary because 64-bit functions
; in Windows assume that they were called with 16-byte stack alignment. When amd64
; shellcode is executed, you can't be assured that you stack is 16-byte aligned. For example,
; if your shellcode lands with 8-byte stack alignment, any call to a Win32 function will likely
; crash upon calling any ASM instruction that utilizes XMM registers (which require 16-byte)
; alignment.

AlignRSP PROC
    push rsi ; Preserve RSI since we're stomping on it
    mov rsi, rsp ; Save the value of RSP so it can be restored
    and rsp, 0FFFFFFFFFFFFFFF0h ; Align RSP to 16 bytes
    sub rsp, 020h ; Allocate homing space for ExecutePayload
    call Shellcode ; Call the entry point of the payload
    mov rsp, rsi ; Restore the original value of RSP
    pop rsi ; Restore RSI
    ret ; Return to caller
AlignRSP ENDP
"""

with open("shellcode.asm", "r") as f:
    asm = f.read().replace("INCLUDELIB LIBCMT\nINCLUDELIB OLDNAMES\n\n", "").replace("gs:96", "gs:[96]")
    asm = re.sub(";	COMDAT pdata[\s\S]*?_TEXT	SEGMENT", f"_TEXT	SEGMENT\n{AlignRSP}", asm)

with open("shellcode.asm", "w") as f:
    f.write(asm)
    f.close()