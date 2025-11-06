
#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 256, "SharedMemory");
    if (hMapFile == NULL) {
        printf("Could not create file mapping. Error: %d\n", GetLastError());
        return 1;
    }
    LPVOID pBuf = MapViewOfFile(hMapFile, FILE_MAP_WRITE, 0, 0, 0);
    if (pBuf == NULL) {
        printf("Could not map view of file. Error: %d\n", GetLastError());
        CloseHandle(hMapFile);
        return 1;
    }
    sprintf((char*)pBuf, "Hello from Writer Process!");

    printf("Data written to shared memory: 'Hello from Writer Process!'\n");
    getchar();

    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);

    return 0;
}

