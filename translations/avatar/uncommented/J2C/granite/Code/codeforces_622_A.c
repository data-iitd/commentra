
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include <errno.h>
#include <float.h>
#include <inttypes.h>
#include <stdint.h>
#include <unistd.h>

#define BUFFERSIZE 512000

typedef struct Scanner {
    BufferedReader *reader;
    StringTokenizer *tokenizer;
} Scanner;

typedef struct PrintWriter {
    BufferedOutputStream *out;
} PrintWriter;

Scanner *sc;
PrintWriter *out;

long getValueAtIndex(long index) {
    return 1 + ( ( index - 1 ) * index / 2 );
}

void solve() {
    long position = sc->nextLong();
    long nrstSeqStartIndx = 1;
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
        nrstSeqStartIndx *= 2;
    }
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
        nrstSeqStartIndx++;
    }
    long startIndex = getValueAtIndex(nrstSeqStartIndx);
    out->println((position - startIndex) + 1);
}

int main(int argc, char **argv) {
    FILE *infile = stdin;
    FILE *outfile = stdout;
    sc = (Scanner *)malloc(sizeof(Scanner));
    sc->reader = new BufferedReader(new InputStreamReader(infile), BUFFERSIZE);
    sc->tokenizer = new StringTokenizer("");
    out = (PrintWriter *)malloc(sizeof(PrintWriter));
    out->out = new BufferedOutputStream(outfile, BUFFERSIZE);
    solve();
    out->close();
    return 0;
}

