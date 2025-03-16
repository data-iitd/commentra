
// Define the TSize structure
typedef struct
{
    int r;
    int c;
} TSize;

TSize TSizeCreate(int Ar, int Ac)
{
    TSize t;
    t.r = Ar;
    t.c = Ac;
    return t;
}

TSize TSizeDefault()
{
    return TSizeCreate(0, 0);
}

// 