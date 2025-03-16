
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buf;
    size_t size;
} Console;

Console *newConsole() {
    Console *con = (Console *)malloc(sizeof(Console));
    con->buf = (char *)malloc(1024 * sizeof(char));
    con->size = 1024;
    return con;
}

void printf(Console *con, const char *format,...) {
    va_list args;
    va_start(args, format);
    vsnprintf(con->buf, con->size, format, args);
    va_end(args);
    printf("%s", con->buf);
}

void println(Console *con, const char *s) {
    printf("%s\n", s);
}

void flush(Console *con) {
    fflush(stdout);
}

void closeConsole(Console *con) {
    free(con->buf);
    free(con);
}

void printList(int *list, int size) {
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            printf("%d", list[i]);
        } else {
            printf(" %d", list[i]);
        }
    }
    printf("\n");
}

int main() {
    Console *con = newConsole();
    char **lines = (char **)malloc(4 * sizeof(char *));
    for (int i = 0; i < 4; i++) {
        lines[i] = (char *)malloc(1024 * sizeof(char));
    }

    // Read multiple lines of input from stdin.
    for (int i = 0; i < 4; i++) {
        fgets(lines[i], 1024, stdin);
    }

    // Process the input and generate the output.
    //...

    // Print the output.
    //...

    // Clean up.
    for (int i = 0; i < 4; i++) {
        free(lines[i]);
    }
    free(lines);
    closeConsole(con);

    return 0;
}

// 