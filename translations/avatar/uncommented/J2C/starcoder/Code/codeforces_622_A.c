#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
#include <ctype.h>
#include <float.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFERSIZE 512000

int main(int argc, char *argv[])
{
    long position = atol(argv[1]);
    long nrstSeqStartIndx = 1;
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position)
    {
        nrstSeqStartIndx *= 2;
    }
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position)
    {
        nrstSeqStartIndx++;
    }
    long startIndex = getValueAtIndex(nrstSeqStartIndx);
    printf("%ld\n", (position - startIndex) + 1);
    return 0;
}

long getValueAtIndex(long index)
{
    return 1 + ((index - 1) * index / 2);
}

