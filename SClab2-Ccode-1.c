#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    // Check if the file exists
    struct stat file_stat;
    if (stat(argv[1], &file_stat) != 0) {
        perror("File error");
        return -1;
    }

    // Print the size of the file in bytes
    printf("File size: %ld bytes\n", file_stat.st_size);
    return 0;
}
