#pragma once
#include <Windows.h>
#include <winternl.h>

inline FARPROC CustomGetProcAddress(HMODULE BaseAddress, char *ProcName){
    IMAGE_DOS_HEADER *DosHeader = (IMAGE_DOS_HEADER *)BaseAddress;
    IMAGE_NT_HEADERS *NtHeader  = (IMAGE_NT_HEADERS *)(DosHeader->e_lfanew + (BYTE *)BaseAddress);
    IMAGE_EXPORT_DIRECTORY *ExportDirectory = (IMAGE_EXPORT_DIRECTORY *)(NtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress + (BYTE *)BaseAddress);

    DWORD *EAT             = (DWORD *)(ExportDirectory->AddressOfFunctions    + (BYTE *)BaseAddress);
    DWORD *FunctionName    = (DWORD *)(ExportDirectory->AddressOfNames        + (BYTE *)BaseAddress);
    WORD  *FunctionOrdinal = (WORD  *)(ExportDirectory->AddressOfNameOrdinals + (BYTE *)BaseAddress);

    for(int i = 0; i < ExportDirectory->NumberOfNames; i++){
        int j = 0;
        char *CurrentFunctionName = (char *)(FunctionName[i] + (BYTE *)BaseAddress);
        for(j = 0; CurrentFunctionName[j] != '\0' && ProcName[j] != '\0'; j++){
            if(CurrentFunctionName[j] != ProcName[j]){
                break;
            }
        }
        if(CurrentFunctionName[j] == '\0' && ProcName[j] == '\0'){
            return (FARPROC)(EAT[FunctionOrdinal[i]] + (BYTE *)BaseAddress);
        }
    }
    return NULL;
}

inline HMODULE CustomGetModuleHandle(wchar_t *ModuleName){
    #if defined(_WIN64)
        PEB *ProcessEnvironmentBlock = (PEB *)__readgsqword(0x60);
    #else
        PEB *ProcessEnvironmentBlock = (PEB *)__readfsqword(0x30);
    #endif
    PEB_LDR_DATA *Loader = (PEB_LDR_DATA *)ProcessEnvironmentBlock->Ldr;
    LIST_ENTRY *ModuleList = &Loader->InMemoryOrderModuleList;
    LIST_ENTRY *CurrentEntry = ModuleList->Flink;

    if(ModuleName == NULL){
        LDR_DATA_TABLE_ENTRY *DataCurrentListEntry = (LDR_DATA_TABLE_ENTRY *)((BYTE *)CurrentEntry - sizeof(LIST_ENTRY));
        return (HMODULE)DataCurrentListEntry->DllBase;
    } else {
        while(CurrentEntry != ModuleList){
            int i = 0;
            LDR_DATA_TABLE_ENTRY *DataCurrentListEntry = (LDR_DATA_TABLE_ENTRY *)((BYTE *)CurrentEntry - sizeof(LIST_ENTRY));
            UNICODE_STRING *BaseDllName = (UNICODE_STRING *)DataCurrentListEntry->Reserved4;

            for(i = 0; BaseDllName->Buffer[i] != '\0' && ModuleName[i] != '\0'; i++){
                if(BaseDllName->Buffer[i] != ModuleName[i]){
                    break;
                }
            }
            if(BaseDllName->Buffer[i] == '\0' && ModuleName[i] == '\0'){
                return (HMODULE)DataCurrentListEntry->DllBase;
            }
            CurrentEntry = CurrentEntry->Flink;
        }
    return NULL;
    }
}