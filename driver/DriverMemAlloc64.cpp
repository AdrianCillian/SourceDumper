#include <iostream>
#include <Windows.h>

int main()
{
    
    HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, <PID>); 

    
    HANDLE heapHandle = GetProcessHeap();

    
    DWORD_PTR baseAddress = 0;
    while (true)
    {
        
        MEMORY_BASIC_INFORMATION memoryInfo;
        if (!VirtualQueryEx(processHandle, (LPVOID)baseAddress, &memoryInfo, sizeof(memoryInfo)))
        {
            break;
        }

        
        std::cout << "Base Address: " << memoryInfo.BaseAddress << std::endl;
        std::cout << "Region Size: " << memoryInfo.RegionSize << std::endl;
        std::cout << "State: " << memoryInfo.State << std::endl;
        std::cout << "Protect: " << memoryInfo.Protect << std::endl;
        std::cout << std::endl;

        
        baseAddress += memoryInfo.RegionSize;
    }

    
    CloseHandle(processHandle);

    return 0;
}
