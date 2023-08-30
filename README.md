# ShellCarve
A template for easy Windows shellcode generation.

ShellCarve exists to serve as a fast C to Windows shellcode converter.

It works by carving crafted, self-contained code out of the .text section of shellcode.exe for use as generic shellcode in external processes.
Included is a test bench designed to execute extracted shellcode to ensure functionality.

# Usage
`shellcode.c` acts as a template, setting up essential functions for this to work. 

Everything below Line 22 can be modified for custom shellcode generation, MessageBoxA sits there as an example.

Considerations have to be made in order for this shellcode to execute outside of its original process (shellcode.exe).
* Strings need to be written as character arrays to ensure they remain on the stack, accessible to the shellcode.
  * Otherwise, the strings are just pointers to shellcode.exe's .data section and will crash outside of that context.
* External functions need to have their addresses resolved dynamically using _GetProcAddress and _LoadLibrary.
  * Otherwise, the functions will be called from shellcode.exe's Import Address Table and will crash outside of that context.

With that in mind:
* Compile `shellcode.c` using `compile.bat` in Visual Studio's x64 Native Tools Command Prompt.
* Use `python3 carve.py shellcode.exe --format c` to extract the shellcode for use in a C file.
* Place the extracted shellcode inside `testbench.c`.
* Compile `testbench.c` using `compile_test.bat` in Visual Studio's x64 Native Tools Command Prompt.
* Run `testbench.exe` to ensure the exported shellcode is functioning as intended.

***Note: The shellcoded generated this way is not going to be as efficient as manually written shellcode.
This is simply a tool for creating viable shellcode quickly from C code.***

# References
[Hasherezade](https://twitter.com/hasherezade): [VX-Underground - From A C Project Through Assembly To Shellcode](https://vxug.fakedoma.in/papers/VXUG/Exclusive/FromaCprojectthroughassemblytoshellcodeHasherezade.pdf)

[ired.team](https://www.ired.team/): [Condensing Hasherezade's Paper Into a Quick Reference](https://www.ired.team/offensive-security/code-injection-process-injection/writing-and-compiling-shellcode-in-c)
