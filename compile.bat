@echo off

cl.exe /nologo /FA /GS- /W0 /c src\shellcode.c /link /OUT:shellcode.exe /SUBSYSTEM:WINDOWS /MACHINE:x64 kernel32.lib
python3 shellfix.py shellcode.asm
ml64.exe /nologo shellcode.asm /link /SUBSYSTEM:WINDOWS /entry:AlignRSP
del mllink$.lnk
del shellcode.asm
del shellcode.obj