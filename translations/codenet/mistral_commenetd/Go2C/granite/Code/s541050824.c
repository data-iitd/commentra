
// Importing required packages
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initializing variables
FILE *reader = stdin;
FILE *writer = stdout;

// Translating the Go code to C
int main() {
    char buf[1024];
    int n = fread(buf, 1, 1024, reader);
    char *p = buf;
    while (*p!= '\n') {
        p++;
    }
    *p = '\0';
    char *s = buf;
    char *t = strchr(s,'');
    if (t == NULL) {
        return 1;
    }
    *t = '\0';
    int x = atoi(s);
    int y = atoi(t + 1);
    printf("%d %d\n", x, y);
    return 0;
}
