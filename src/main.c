#include "lexer.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseFile(char *path);

void parseHtml(char *source);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [html]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    parseFile(argv[1]);

    return 0;
}

void parseFile(char *path) {
    FILE *fptr = fopen(path, "rb");
    if (fptr == NULL) {
        int errNumber = errno;
        char *errName = strerror(errNumber);
        printf("File opening error: %s\n", errName);
        exit(EXIT_FAILURE);
    }

    /**  get the number of character of the file */
    fseek(fptr, 0, SEEK_END);
    size_t fsize = ftell(fptr);
    rewind(fptr);

    /**
     * allocate the space of the characters plus the space for the null
     * terminator
     * */
    char *source = malloc(fsize + 1);
    fread(source, fsize, 1, fptr);
    fclose(fptr);
    source[fsize] = 0;

    parseHtml(source);
}

void parseHtml(char *source) { Token *tokens = scanToken(source); }
