#include <iostream>

using namespace std;

int main() {
const int num_blocks = 5 + rand() % 6; // Randomly choose between 5 and 10 blocks
const int block_size = 120 * 1024; // Block size in bytes (120 KB)
  // Allocate memory for an array of num_blocks pointers to char
char** blocks = new char*[num_blocks];

// Allocate memory for each block and assign it to the array
for (int i = 0; i < num_blocks; i++) {
    blocks[i] = new char[block_size];

    // Initialize the block with some data (just for illustration)
    for (int j = 0; j < block_size; j++) {
        blocks[i][j] = rand() % 256;
    }
}

// Print some information about the allocated memory
cout << "Allocated " << num_blocks << " blocks of " << block_size << " bytes each." << endl;
cout << "Total allocated memory: " << num_blocks * block_size / 1024 << " KB." << endl;

// Deallocate memory for each block
for (int i = 0; i < num_blocks; i++) {
    delete[] blocks[i];
}

// Deallocate memory for the array of pointers
delete[] blocks;

return 0;

}
