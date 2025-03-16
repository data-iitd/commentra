#include <assert.h>
#include <stdio.h>
#include <limits.h>

typedef struct TSize // Define a structure for size
{
    int r;
    int c;
} TSize;

void TSize_init(TSize* size, int Ar, int Ac) // Constructor with arguments
{
    size->r = Ar;
    size->c = Ac;
}

void TSize_default_init(TSize* size) // Default constructor
{
    size->r = 0;
    size->c = 0;
}

typedef struct TMcmSolver // Define a structure for Memoized Chain Multiplication Calculator
{
    // ...
} TMcmSolver;

// Additional functions for TMcmSolver would go here

