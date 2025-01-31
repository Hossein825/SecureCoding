#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

// Program to print the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    // Validate if the file exists
    struct stat file_stat;
    if (stat(argv[1], &file_stat) != 0) {
        fprintf(stderr, "Error: File does not exist or cannot be accessed.\n");
        return -1;
    }

    // Print the size of the file in bytes
    printf("File size: %lld bytes\n", (long long)file_stat.st_size);
    return 0;
}
