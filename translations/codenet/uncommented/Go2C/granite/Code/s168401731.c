
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *base;
    size_t len;
} Scanner;

Scanner getScanner(FILE *fp) {
    Scanner scanner;
    scanner.base = malloc(500001);
    scanner.len = 500000;
    fread(scanner.base, 1, scanner.len, fp);
    return scanner;
}

char *getNextString(Scanner *scanner) {
    char *str = scanner->base;
    scanner->base += strlen(str) + 1;
    return str;
}

int getNextInt(Scanner *scanner) {
    int num;
    sscanf(getNextString(scanner), "%d", &num);
    return num;
}

int main() {
    FILE *fp = stdin;
    FILE *wfp = stdout;

    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (argc > 2) {
            wfp = fopen(argv[2], "w");
        }
    }

    Scanner scanner = getScanner(fp);
    fprintf(wfp, "%s\n", getNextInt(&scanner) % 2 == 1? "first" : "second");
    fclose(wfp);
    return 0;
}
