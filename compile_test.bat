@echo off

cl.exe /nologo /MT /W0 /TC src\testbench.c /link /OUT:testbench.exe /SUBSYSTEM:CONSOLE /MACHINE:x64 user32.lib
del testbench.obj