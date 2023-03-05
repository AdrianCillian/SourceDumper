#include <Windows.h>
#include <iostream>
#include <vector>

// Define the DLL entry point
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        // DLL is being loaded into the virtual address space of the current process
        break;
    case DLL_PROCESS_DETACH:
        // DLL is being unloaded from the virtual address space of the current process
        break;
    case DLL_THREAD_ATTACH:
        // DLL is being loaded into the virtual address space of a new thread in the current process
        break;
    case DLL_THREAD_DETACH:
        // DLL is being unloaded from the virtual address space of a thread in the current process
        break;
    }
    return TRUE;
}

// Import an icon from a resource file
HICON LoadIconFromResource(int resourceID)
{
    HINSTANCE hInstance = GetModuleHandle(NULL);
    return LoadIcon(hInstance, MAKEINTRESOURCE(resourceID));
}

// Import a class from the C++ standard library
void TestVectorClass()
{
    std::vector<int> myVector;
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);

    for (auto i = myVector.begin(); i != myVector.end(); i++)
    {
        std::cout << *i << std::endl;
    }
}

// Import a driver from Windows
BOOL EnableDebugPrivilege()
{
    HANDLE hToken = NULL;
    TOKEN_PRIVILEGES TokenPrivileges = { 0 };

    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
    {
        return FALSE;
    }

    TokenPrivileges.PrivilegeCount = 1;
    TokenPrivileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &TokenPrivileges.Privileges[0].Luid))
    {
        CloseHandle(hToken);
        return FALSE;
    }

    if (!AdjustTokenPrivileges(hToken, FALSE, &TokenPrivileges, sizeof(TOKEN_PRIVILEGES), NULL, NULL))
    {
        CloseHandle(hToken);
        return FALSE;
    }

    CloseHandle(hToken);
    return TRUE;
}

// Exported function that can be called from other programs
extern "C" __declspec(dllexport) void TestLibrary()
{
    HICON hIcon = LoadIconFromResource(IDI_APPLICATION);
    if (hIcon)
    {
        // Icon loaded successfully
        DestroyIcon(hIcon);
    }

    TestVectorClass();

    EnableDebugPrivilege();
}
