#include <Windows.h>
#include "shellcode.h"

#pragma comment(linker, "/entry:Shellcode")

int Shellcode(void){

    HMODULE(WINAPI *_LoadLibrary)(LPCSTR lpLibFileName);
    FARPROC(WINAPI *_GetProcAddress)(HMODULE hModule, LPCSTR lpProcName);

    wchar_t Resolve_Kernel32[]    = { 'K', 'E', 'R', 'N', 'E', 'L', '3', '2', '.', 'D', 'L', 'L', '\0' };

    HMODULE hKernel32 = CustomGetModuleHandle(Resolve_Kernel32);
    if(hKernel32 == NULL){
        return 1;
    }

    char Resolve_LoadLibrary[]    = { 'L', 'o', 'a', 'd', 'L', 'i', 'b', 'r', 'a', 'r', 'y', 'A', '\0' };
    char Resolve_GetProcAddress[] = { 'G', 'e', 't', 'P', 'r', 'o', 'c', 'A', 'd', 'd', 'r', 'e', 's', 's', '\0' };

    _GetProcAddress = CustomGetProcAddress(hKernel32, Resolve_GetProcAddress);
    _LoadLibrary = _GetProcAddress(hKernel32, Resolve_LoadLibrary);

    // Everything below here can be replaced to create different shellcode for different functions.
    // Strings must be written as character arrays to remain accessible on the stack.
    // Create a function prototype, make sure its DLL is loaded, get its VA with GetProcAddress, call it.
    // Example MessageBoxA.

    int(WINAPI *_MessageBoxA)(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
    char Resolve_User32[] = { 'U', 's', 'e', 'r', '3', '2', '.', 'd', 'l', 'l', '\0' };

    HMODULE hUser32 = _LoadLibrary(Resolve_User32);
    if(hUser32 == NULL){
        return 1;
    }
    
    char Resolve_MessageBox[] = { 'M', 'e', 's', 's', 'a', 'g', 'e', 'B', 'o', 'x', 'A', '\0' };
    _MessageBoxA = _GetProcAddress(hUser32, Resolve_MessageBox);

    char Message[] = { 'S', 'h', 'e', 'l', 'l', 'c', 'o', 'd', 'e', 'd', '!', '\0' };    
    _MessageBoxA(NULL, Message, Message, MB_OK);

    return 0;
}
