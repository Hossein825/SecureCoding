#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

// This program prints the size of a specified file in bytes

int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    // Check if the file exists and access its information
    struct stat file_info;
    if (stat(argv[1], &file_info) != 0) {
        perror("Error accessing the file");
        return -1;
    }

    // Print the size of the file in bytes
    printf("The size of the file is: %ld bytes\n", file_info.st_size);

    return 0;
}
