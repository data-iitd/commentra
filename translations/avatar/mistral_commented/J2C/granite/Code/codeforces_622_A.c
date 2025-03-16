

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512000

int main(int argc, char *argv[]) {
    long position;
    scanf("%ld", &position);
    solveHelper(position);
    return 0;
}

void solveHelper(long position) {
    long nrstSeqStartIndx = 1;
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
        nrstSeqStartIndx *= 2;
    }
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
        nrstSeqStartIndx++;
    }
    long startIndex = getValueAtIndex(nrstSeqStartIndx);
    printf("%ld\n", (position - startIndex) + 1);
}

long getValueAtIndex(long index) {
    return 1 + ((index - 1) * index / 2);
}

