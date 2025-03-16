
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <assert.h>
#include <errno.h>
#include <inttypes.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <setjmp.h>
#include <pwd.h>
#include <grp.h>
#include <signal.h>
#include <locale.h>

typedef struct {
    FILE *in;
    CharBuffer buffer;
    bool eof;
} SimpleScanner;

void initSimpleScanner(SimpleScanner *scanner, FILE *in) {
    scanner->in = in;
    scanner->buffer.limit = 0;
    scanner->eof = false;
}

char readSimpleScanner(SimpleScanner *scanner) {
    if (!scanner->buffer.hasRemaining()) {
        scanner->buffer.clear();
        int n = fread(scanner->buffer.array, sizeof(char), scanner->buffer.capacity, scanner->in);
        if (n <= 0) {
            scanner->eof = true;
            return '\0';
        }
        scanner->buffer.limit = n;
        scanner->buffer.position = 0;
    }
    return scanner->buffer.array[scanner->buffer.position++];
}

void checkEofSimpleScanner(SimpleScanner *scanner) {
    if (scanner->eof) {
        fprintf(stderr, "End of file reached\n");
        exit(EXIT_FAILURE);
    }
}

char nextCharSimpleScanner(SimpleScanner *scanner) {
    checkEofSimpleScanner(scanner);
    char b = readSimpleScanner(scanner);
    checkEofSimpleScanner(scanner);
    return b;
}

char *nextSimpleScanner(SimpleScanner *scanner) {
    char b = nextCharSimpleScanner(scanner);
    while (isspace(b)) {
        b = nextCharSimpleScanner(scanner);
    }
    StringBuilder *sb = newStringBuilder();
    while (!scanner->eof &&!isspace(b)) {
        appendStringBuilder(sb, b);
        b = readSimpleScanner(scanner);
    }
    return toStringBuilder(sb);
}

int nextIntSimpleScanner(SimpleScanner *scanner) {
    return atoi(nextSimpleScanner(scanner));
}

long nextLongSimpleScanner(SimpleScanner *scanner) {
    return atol(nextSimpleScanner(scanner));
}

double nextDoubleSimpleScanner(SimpleScanner *scanner) {
    return atof(nextSimpleScanner(scanner));
}

int main() {
    SimpleScanner scanner;
    FILE *in = stdin;
    initSimpleScanner(&scanner, in);
    int r = nextIntSimpleScanner(&scanner);
    int d = nextIntSimpleScanner(&scanner);
    long x = nextLongSimpleScanner(&scanner);
    for (int i = 0; i < 10; i++) {
        x = r * x - d;
        printf("%ld\n", x);
    }
    return 0;
}

