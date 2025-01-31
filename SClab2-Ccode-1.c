#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 256

// This program prints the size of a specified file in bytes

int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    // Validate the length of the input to avoid buffer overflows
    if (strlen(argv[1]) >= BUFSIZE - 10) {
        fprintf(stderr, "Input file path is too long.\n");
        return -1;
    }

    char cmd[BUFSIZE] = "wc -c < ";
    strcat(cmd, argv[1]); // Append the user input to the command

    // Execute the system command
    if (system(cmd) != 0) {
        fprintf(stderr, "An error occurred while executing the command.\n");
        return -1;
    }

    return 0;
}
