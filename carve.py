import pefile
import argparse

parser = argparse.ArgumentParser(description="Tool for carving the shellcode out of a self-contained .text section.")
parser.add_argument("EXE", help="PE File to extract .text from")
parser.add_argument("--format", choices=["c", "py", "bin",], default="c", help="Format to export the shellcode")
args = parser.parse_args()

pe = pefile.PE(args.EXE)
for section in pe.sections:
        if b".text" in section.Name:
                text = section
                break
        
offset = text.PointerToRawData

with open(args.EXE, 'rb') as f:
    f.seek(offset)
    text = f.read()

    # Remove trailing null-bytes
    i = len(text) - 1
    while(True):
        if text[i] == 0:
            i -= 1
        else:
            break
    text = text[:i+1]
    f.close()

if args.format == "c":
    print("const char shellcode[] = { ", end="")
    for i in range(len(text)):
        if i == len(text) - 1:
            print(f"{hex(text[i])}", end="")
        else:
            print(f"{hex(text[i])}, ", end="")
    print(" };", end="")

if args.format == "bin":
    with open("shellcode.bin", "wb") as f:
         f.write(text)
         f.close()

if args.format == "py":
    print("shellcode = b\"", end="")
    for i in range(len(text)):
        if text[i] == 0:
             print(f"\\x{hex(text[i])[2:]}0", end="")
        else:
            print(f"\\x{hex(text[i])[2:]}", end="")
    print("\"", end="")