#include <Windows.h>

int main(int argc, char *argv[]){
    // vvv Drop shellcode from carve.py here vvv
    const char shellcode[] = { 0x56, 0x48, 0x8b, 0xf4, 0x48, 0x83, 0xe4, 0xf0, 0x48, 0x83, 0xec, 0x20, 0xe8, 0x5, 0x0, 0x0, 0x0, 0x48, 0x8b, 0xe6, 0x5e, 0xc3, 0x48, 0x81, 0xec, 0xc8, 0x0, 0x0, 0x0, 0xb8, 0x4b, 0x0, 0x0, 0x0, 0x66, 0x89, 0x44, 0x24, 0x70, 0xb8, 0x45, 0x0, 0x0, 0x0, 0x66, 0x89, 0x44, 0x24, 0x72, 0xb8, 0x52, 0x0, 0x0, 0x0, 0x66, 0x89, 0x44, 0x24, 0x74, 0xb8, 0x4e, 0x0, 0x0, 0x0, 0x66, 0x89, 0x44, 0x24, 0x76, 0xb8, 0x45, 0x0, 0x0, 0x0, 0x66, 0x89, 0x44, 0x24, 0x78, 0xb8, 0x4c, 0x0, 0x0, 0x0, 0x66, 0x89, 0x44, 0x24, 0x7a, 0xb8, 0x33, 0x0, 0x0, 0x0, 0x66, 0x89, 0x44, 0x24, 0x7c, 0xb8, 0x32, 0x0, 0x0, 0x0, 0x66, 0x89, 0x44, 0x24, 0x7e, 0xb8, 0x2e, 0x0, 0x0, 0x0, 0x66, 0x89, 0x84, 0x24, 0x80, 0x0, 0x0, 0x0, 0xb8, 0x44, 0x0, 0x0, 0x0, 0x66, 0x89, 0x84, 0x24, 0x82, 0x0, 0x0, 0x0, 0xb8, 0x4c, 0x0, 0x0, 0x0, 0x66, 0x89, 0x84, 0x24, 0x84, 0x0, 0x0, 0x0, 0xb8, 0x4c, 0x0, 0x0, 0x0, 0x66, 0x89, 0x84, 0x24, 0x86, 0x0, 0x0, 0x0, 0x33, 0xc0, 0x66, 0x89, 0x84, 0x24, 0x88, 0x0, 0x0, 0x0, 0x48, 0x8d, 0x4c, 0x24, 0x70, 0xe8, 0xf3, 0x1, 0x0, 0x0, 0x48, 0x89, 0x84, 0x24, 0x90, 0x0, 0x0, 0x0, 0x48, 0x83, 0xbc, 0x24, 0x90, 0x0, 0x0, 0x0, 0x0, 0x75, 0xa, 0xb8, 0x1, 0x0, 0x0, 0x0, 0xe9, 0xce, 0x1, 0x0, 0x0, 0xc6, 0x44, 0x24, 0x50, 0x4c, 0xc6, 0x44, 0x24, 0x51, 0x6f, 0xc6, 0x44, 0x24, 0x52, 0x61, 0xc6, 0x44, 0x24, 0x53, 0x64, 0xc6, 0x44, 0x24, 0x54, 0x4c, 0xc6, 0x44, 0x24, 0x55, 0x69, 0xc6, 0x44, 0x24, 0x56, 0x62, 0xc6, 0x44, 0x24, 0x57, 0x72, 0xc6, 0x44, 0x24, 0x58, 0x61, 0xc6, 0x44, 0x24, 0x59, 0x72, 0xc6, 0x44, 0x24, 0x5a, 0x79, 0xc6, 0x44, 0x24, 0x5b, 0x41, 0xc6, 0x44, 0x24, 0x5c, 0x0, 0xc6, 0x44, 0x24, 0x60, 0x47, 0xc6, 0x44, 0x24, 0x61, 0x65, 0xc6, 0x44, 0x24, 0x62, 0x74, 0xc6, 0x44, 0x24, 0x63, 0x50, 0xc6, 0x44, 0x24, 0x64, 0x72, 0xc6, 0x44, 0x24, 0x65, 0x6f, 0xc6, 0x44, 0x24, 0x66, 0x63, 0xc6, 0x44, 0x24, 0x67, 0x41, 0xc6, 0x44, 0x24, 0x68, 0x64, 0xc6, 0x44, 0x24, 0x69, 0x64, 0xc6, 0x44, 0x24, 0x6a, 0x72, 0xc6, 0x44, 0x24, 0x6b, 0x65, 0xc6, 0x44, 0x24, 0x6c, 0x73, 0xc6, 0x44, 0x24, 0x6d, 0x73, 0xc6, 0x44, 0x24, 0x6e, 0x0, 0x48, 0x8d, 0x54, 0x24, 0x60, 0x48, 0x8b, 0x8c, 0x24, 0x90, 0x0, 0x0, 0x0, 0xe8, 0x7b, 0x2, 0x0, 0x0, 0x48, 0x89, 0x84, 0x24, 0xa0, 0x0, 0x0, 0x0, 0x48, 0x8d, 0x54, 0x24, 0x50, 0x48, 0x8b, 0x8c, 0x24, 0x90, 0x0, 0x0, 0x0, 0xff, 0x94, 0x24, 0xa0, 0x0, 0x0, 0x0, 0x48, 0x89, 0x84, 0x24, 0xa8, 0x0, 0x0, 0x0, 0xc6, 0x44, 0x24, 0x30, 0x55, 0xc6, 0x44, 0x24, 0x31, 0x73, 0xc6, 0x44, 0x24, 0x32, 0x65, 0xc6, 0x44, 0x24, 0x33, 0x72, 0xc6, 0x44, 0x24, 0x34, 0x33, 0xc6, 0x44, 0x24, 0x35, 0x32, 0xc6, 0x44, 0x24, 0x36, 0x2e, 0xc6, 0x44, 0x24, 0x37, 0x64, 0xc6, 0x44, 0x24, 0x38, 0x6c, 0xc6, 0x44, 0x24, 0x39, 0x6c, 0xc6, 0x44, 0x24, 0x3a, 0x0, 0x48, 0x8d, 0x4c, 0x24, 0x30, 0xff, 0x94, 0x24, 0xa8, 0x0, 0x0, 0x0, 0x48, 0x89, 0x84, 0x24, 0x98, 0x0, 0x0, 0x0, 0x48, 0x83, 0xbc, 0x24, 0x98, 0x0, 0x0, 0x0, 0x0, 0x75, 0xa, 0xb8, 0x1, 0x0, 0x0, 0x0, 0xe9, 0xac, 0x0, 0x0, 0x0, 0xc6, 0x44, 0x24, 0x40, 0x4d, 0xc6, 0x44, 0x24, 0x41, 0x65, 0xc6, 0x44, 0x24, 0x42, 0x73, 0xc6, 0x44, 0x24, 0x43, 0x73, 0xc6, 0x44, 0x24, 0x44, 0x61, 0xc6, 0x44, 0x24, 0x45, 0x67, 0xc6, 0x44, 0x24, 0x46, 0x65, 0xc6, 0x44, 0x24, 0x47, 0x42, 0xc6, 0x44, 0x24, 0x48, 0x6f, 0xc6, 0x44, 0x24, 0x49, 0x78, 0xc6, 0x44, 0x24, 0x4a, 0x41, 0xc6, 0x44, 0x24, 0x4b, 0x0, 0x48, 0x8d, 0x54, 0x24, 0x40, 0x48, 0x8b, 0x8c, 0x24, 0x98, 0x0, 0x0, 0x0, 0xff, 0x94, 0x24, 0xa0, 0x0, 0x0, 0x0, 0x48, 0x89, 0x84, 0x24, 0xb0, 0x0, 0x0, 0x0, 0xc6, 0x44, 0x24, 0x20, 0x53, 0xc6, 0x44, 0x24, 0x21, 0x68, 0xc6, 0x44, 0x24, 0x22, 0x65, 0xc6, 0x44, 0x24, 0x23, 0x6c, 0xc6, 0x44, 0x24, 0x24, 0x6c, 0xc6, 0x44, 0x24, 0x25, 0x63, 0xc6, 0x44, 0x24, 0x26, 0x6f, 0xc6, 0x44, 0x24, 0x27, 0x64, 0xc6, 0x44, 0x24, 0x28, 0x65, 0xc6, 0x44, 0x24, 0x29, 0x64, 0xc6, 0x44, 0x24, 0x2a, 0x21, 0xc6, 0x44, 0x24, 0x2b, 0x0, 0x45, 0x33, 0xc9, 0x4c, 0x8d, 0x44, 0x24, 0x20, 0x48, 0x8d, 0x54, 0x24, 0x20, 0x33, 0xc9, 0xff, 0x94, 0x24, 0xb0, 0x0, 0x0, 0x0, 0x33, 0xc0, 0x48, 0x81, 0xc4, 0xc8, 0x0, 0x0, 0x0, 0xc3, 0x48, 0x89, 0x4c, 0x24, 0x8, 0x48, 0x83, 0xec, 0x48, 0x65, 0x48, 0x8b, 0x4, 0x25, 0x60, 0x0, 0x0, 0x0, 0x48, 0x89, 0x44, 0x24, 0x28, 0x48, 0x8b, 0x44, 0x24, 0x28, 0x48, 0x8b, 0x40, 0x18, 0x48, 0x89, 0x44, 0x24, 0x30, 0x48, 0x8b, 0x44, 0x24, 0x30, 0x48, 0x83, 0xc0, 0x20, 0x48, 0x89, 0x44, 0x24, 0x18, 0x48, 0x8b, 0x44, 0x24, 0x18, 0x48, 0x8b, 0x0, 0x48, 0x89, 0x44, 0x24, 0x8, 0x48, 0x83, 0x7c, 0x24, 0x50, 0x0, 0x75, 0x21, 0x48, 0x8b, 0x44, 0x24, 0x8, 0x48, 0x83, 0xe8, 0x10, 0x48, 0x89, 0x44, 0x24, 0x38, 0x48, 0x8b, 0x44, 0x24, 0x38, 0x48, 0x8b, 0x40, 0x30, 0xe9, 0xda, 0x0, 0x0, 0x0, 0xe9, 0xd5, 0x0, 0x0, 0x0, 0x48, 0x8b, 0x44, 0x24, 0x18, 0x48, 0x39, 0x44, 0x24, 0x8, 0xf, 0x84, 0xc3, 0x0, 0x0, 0x0, 0xc7, 0x4, 0x24, 0x0, 0x0, 0x0, 0x0, 0x48, 0x8b, 0x44, 0x24, 0x8, 0x48, 0x83, 0xe8, 0x10, 0x48, 0x89, 0x44, 0x24, 0x20, 0x48, 0x8b, 0x44, 0x24, 0x20, 0x48, 0x83, 0xc0, 0x58, 0x48, 0x89, 0x44, 0x24, 0x10, 0xc7, 0x4, 0x24, 0x0, 0x0, 0x0, 0x0, 0xeb, 0x8, 0x8b, 0x4, 0x24, 0xff, 0xc0, 0x89, 0x4, 0x24, 0x48, 0x63, 0x4, 0x24, 0x48, 0x8b, 0x4c, 0x24, 0x10, 0x48, 0x8b, 0x49, 0x8, 0xf, 0xb7, 0x4, 0x41, 0x85, 0xc0, 0x74, 0x37, 0x48, 0x63, 0x4, 0x24, 0x48, 0x8b, 0x4c, 0x24, 0x50, 0xf, 0xb7, 0x4, 0x41, 0x85, 0xc0, 0x74, 0x26, 0x48, 0x63, 0x4, 0x24, 0x48, 0x8b, 0x4c, 0x24, 0x10, 0x48, 0x8b, 0x49, 0x8, 0xf, 0xb7, 0x4, 0x41, 0x48, 0x63, 0xc, 0x24, 0x48, 0x8b, 0x54, 0x24, 0x50, 0xf, 0xb7, 0xc, 0x4a, 0x3b, 0xc1, 0x74, 0x2, 0xeb, 0x2, 0xeb, 0xac, 0x48, 0x63, 0x4, 0x24, 0x48, 0x8b, 0x4c, 0x24, 0x10, 0x48, 0x8b, 0x49, 0x8, 0xf, 0xb7, 0x4, 0x41, 0x85, 0xc0, 0x75, 0x1c, 0x48, 0x63, 0x4, 0x24, 0x48, 0x8b, 0x4c, 0x24, 0x50, 0xf, 0xb7, 0x4, 0x41, 0x85, 0xc0, 0x75, 0xb, 0x48, 0x8b, 0x44, 0x24, 0x20, 0x48, 0x8b, 0x40, 0x30, 0xeb, 0x14, 0x48, 0x8b, 0x44, 0x24, 0x8, 0x48, 0x8b, 0x0, 0x48, 0x89, 0x44, 0x24, 0x8, 0xe9, 0x2d, 0xff, 0xff, 0xff, 0x33, 0xc0, 0x48, 0x83, 0xc4, 0x48, 0xc3, 0x48, 0x89, 0x54, 0x24, 0x10, 0x48, 0x89, 0x4c, 0x24, 0x8, 0x48, 0x83, 0xec, 0x48, 0x48, 0x8b, 0x44, 0x24, 0x50, 0x48, 0x89, 0x44, 0x24, 0x18, 0x48, 0x8b, 0x44, 0x24, 0x18, 0x48, 0x63, 0x40, 0x3c, 0x48, 0x8b, 0x4c, 0x24, 0x50, 0x48, 0x3, 0xc8, 0x48, 0x8b, 0xc1, 0x48, 0x89, 0x44, 0x24, 0x20, 0xb8, 0x8, 0x0, 0x0, 0x0, 0x48, 0x6b, 0xc0, 0x0, 0x48, 0x8b, 0x4c, 0x24, 0x20, 0x8b, 0x84, 0x1, 0x88, 0x0, 0x0, 0x0, 0x48, 0x8b, 0x4c, 0x24, 0x50, 0x48, 0x3, 0xc8, 0x48, 0x8b, 0xc1, 0x48, 0x89, 0x44, 0x24, 0x8, 0x48, 0x8b, 0x44, 0x24, 0x8, 0x8b, 0x40, 0x1c, 0x48, 0x8b, 0x4c, 0x24, 0x50, 0x48, 0x3, 0xc8, 0x48, 0x8b, 0xc1, 0x48, 0x89, 0x44, 0x24, 0x38, 0x48, 0x8b, 0x44, 0x24, 0x8, 0x8b, 0x40, 0x20, 0x48, 0x8b, 0x4c, 0x24, 0x50, 0x48, 0x3, 0xc8, 0x48, 0x8b, 0xc1, 0x48, 0x89, 0x44, 0x24, 0x28, 0x48, 0x8b, 0x44, 0x24, 0x8, 0x8b, 0x40, 0x24, 0x48, 0x8b, 0x4c, 0x24, 0x50, 0x48, 0x3, 0xc8, 0x48, 0x8b, 0xc1, 0x48, 0x89, 0x44, 0x24, 0x30, 0xc7, 0x44, 0x24, 0x4, 0x0, 0x0, 0x0, 0x0, 0xeb, 0xa, 0x8b, 0x44, 0x24, 0x4, 0xff, 0xc0, 0x89, 0x44, 0x24, 0x4, 0x48, 0x8b, 0x44, 0x24, 0x8, 0x8b, 0x40, 0x18, 0x39, 0x44, 0x24, 0x4, 0xf, 0x83, 0xc3, 0x0, 0x0, 0x0, 0xc7, 0x4, 0x24, 0x0, 0x0, 0x0, 0x0, 0x48, 0x63, 0x44, 0x24, 0x4, 0x48, 0x8b, 0x4c, 0x24, 0x28, 0x8b, 0x4, 0x81, 0x48, 0x8b, 0x4c, 0x24, 0x50, 0x48, 0x3, 0xc8, 0x48, 0x8b, 0xc1, 0x48, 0x89, 0x44, 0x24, 0x10, 0xc7, 0x4, 0x24, 0x0, 0x0, 0x0, 0x0, 0xeb, 0x8, 0x8b, 0x4, 0x24, 0xff, 0xc0, 0x89, 0x4, 0x24, 0x48, 0x63, 0x4, 0x24, 0x48, 0x8b, 0x4c, 0x24, 0x10, 0xf, 0xbe, 0x4, 0x1, 0x85, 0xc0, 0x74, 0x33, 0x48, 0x63, 0x4, 0x24, 0x48, 0x8b, 0x4c, 0x24, 0x58, 0xf, 0xbe, 0x4, 0x1, 0x85, 0xc0, 0x74, 0x22, 0x48, 0x63, 0x4, 0x24, 0x48, 0x8b, 0x4c, 0x24, 0x10, 0xf, 0xbe, 0x4, 0x1, 0x48, 0x63, 0xc, 0x24, 0x48, 0x8b, 0x54, 0x24, 0x58, 0xf, 0xbe, 0xc, 0xa, 0x3b, 0xc1, 0x74, 0x2, 0xeb, 0x2, 0xeb, 0xb4, 0x48, 0x63, 0x4, 0x24, 0x48, 0x8b, 0x4c, 0x24, 0x10, 0xf, 0xbe, 0x4, 0x1, 0x85, 0xc0, 0x75, 0x34, 0x48, 0x63, 0x4, 0x24, 0x48, 0x8b, 0x4c, 0x24, 0x58, 0xf, 0xbe, 0x4, 0x1, 0x85, 0xc0, 0x75, 0x23, 0x48, 0x63, 0x44, 0x24, 0x4, 0x48, 0x8b, 0x4c, 0x24, 0x30, 0xf, 0xb7, 0x4, 0x41, 0x48, 0x8b, 0x4c, 0x24, 0x38, 0x8b, 0x4, 0x81, 0x48, 0x8b, 0x4c, 0x24, 0x50, 0x48, 0x3, 0xc8, 0x48, 0x8b, 0xc1, 0xeb, 0x7, 0xe9, 0x21, 0xff, 0xff, 0xff, 0x33, 0xc0, 0x48, 0x83, 0xc4, 0x48, 0xc3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xab, 0x5d, 0xef, 0x64, 0x0, 0x0, 0x0, 0x0, 0xd, 0x0, 0x0, 0x0, 0x58, 0x0, 0x0, 0x0, 0x34, 0x20, 0x0, 0x0, 0x34, 0x8, 0x0, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0, 0x80, 0x0, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0, 0x79, 0x5, 0x0, 0x0, 0x2e, 0x74, 0x65, 0x78, 0x74, 0x24, 0x6d, 0x6e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0x0, 0x0, 0x1c, 0x0, 0x0, 0x0, 0x2e, 0x72, 0x64, 0x61, 0x74, 0x61, 0x0, 0x0, 0x1c, 0x20, 0x0, 0x0, 0x18, 0x0, 0x0, 0x0, 0x2e, 0x72, 0x64, 0x61, 0x74, 0x61, 0x24, 0x76, 0x6f, 0x6c, 0x74, 0x6d, 0x64, 0x0, 0x0, 0x0, 0x34, 0x20, 0x0, 0x0, 0x68, 0x0, 0x0, 0x0, 0x2e, 0x72, 0x64, 0x61, 0x74, 0x61, 0x24, 0x7a, 0x7a, 0x7a, 0x64, 0x62, 0x67 };
    
    LPVOID TestBench = VirtualAlloc(NULL, sizeof(shellcode), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    memcpy_s(TestBench, sizeof(shellcode), shellcode, sizeof(shellcode));
    ((void (*)())TestBench)();
    return 0;
}