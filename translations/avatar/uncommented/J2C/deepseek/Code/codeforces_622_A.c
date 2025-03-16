#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 512000

long getValueAtIndex(long index) {
    return 1 + (index - 1) * index / 2;
}

void solve() {
    long position;
    scanf("%ld", &position);
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

int main() {
    solve();
    return 0;
}

