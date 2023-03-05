#ifndef MEMORY_DUMP_H
#define MEMORY_DUMP_H

#include <iostream>
#include <fstream>

using namespace std;

// Function to dump memory
void dump_memory(void* start_address, void* end_address, const char* filename);

// Function to allocate memory
void* allocate_memory(size_t size);

// Function to free memory
void free_memory(void* ptr);

#endif // MEMORY_DUMP_H

// Implementation of dump_memory function
void dump_memory(void* start_address, void* end_address, const char* filename) {
ofstream file(filename, ios::out | ios::binary);
if (!file.is_open()) {
cerr << "Failed to open file for writing." << endl;
return;
}
char* start = (char*)start_address;
char* end = (char*)end_address;
int size = end - start;
file.write(start, size);
file.close();

cout << "Dumped memory from " << start_address << " to " << end_address << " to file: " << filename << endl;
}

// Implementation of allocate_memory function
void* allocate_memory(size_t size) {
void* ptr = malloc(size);
if (!ptr) {
cerr << "Failed to allocate memory." << endl;
return nullptr;
}
cout << "Allocated " << size << " bytes of memory at address: " << ptr << endl;
return ptr;
}

// Implementation of free_memory function
void free_memory(void* ptr) {
if (!ptr) {
cerr << "Pointer is null." << endl;
return;
}
free(ptr);
cout << "Freed memory at address: " << ptr << endl;
}
