#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A helper function to print output
void out(int x, ...) {
    va_list args;
    va_start(args, x);
    printf("%d", x);
    while (x = va_arg(args, int)) {
        printf(" %d", x);
    }
    printf("\n");
    va_end(args);
}

// Function to read an integer from the standard input
int getInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a string from the standard input
char *getString() {
    char *s = malloc(1000000);
    scanf("%s", s);
    return s;
}

// Main function
int main() {
    // Initialize the scanner for reading input
    // sc.Split(bufio.ScanWords)
    // sc.Buffer([]byte{}, 1000000)

    // Read the number of elements 'n' and the number of queries 'q' from the standard input
    int n = getInt();
    int q = getInt();

    // Initialize a Fenwick Tree of size 'n'
    int *fw = malloc(sizeof(int) * n);
    memset(fw, 0, sizeof(int) * n);

    // Iterate through each element and add it to the Fenwick Tree
    for (int i = 0; i < n; i++) {
        // Read an integer 'a' from the standard input and add it to the Fenwick Tree at index 'i'
        int a = getInt();
        fw[i] += a;
    }

    // Iterate through each query
    for (int i = 0; i < q; i++) {
        // Read an integer 't' from the standard input to determine the type of query
        int t = getInt();

        // If the query is of type 0, read two integers 'p' and 'x' from the standard input and add 'x' to the Fenwick Tree at index 'p'
        if (t == 0) {
            int p = getInt();
            int x = getInt();
            fw[p] += x;
        } else { // If the query is of type 1, read two integers 'l' and 'r' from the standard input and print the sum of elements in the range [l, r]
            int l = getInt();
            int r = getInt();
            // Call the Sum function of the Fenwick Tree to get the sum of elements in the range [l, r]
            out(fw[r] - fw[l]);
        }
    }

    // ** copy from here to your source code **
    //
    // fenwick tree
    //  1. go lang have no generics, so implement int(long long)
    //  data type only.
    //  2. do not care overflow
    //

    // BIT :
    typedef struct {
        int n;
        int *data;
    } BIT;

    // FenwickTree :
    BIT *FenwickTree(int n) {
        BIT *ret = malloc(sizeof(BIT));
        ret->n = n;
        ret->data = malloc(sizeof(int) * n);
        memset(ret->data, 0, sizeof(int) * n);
        return ret;
    }

    // Add :
    void Add(BIT *b, int p, int x) {
        p++;
        for (; p <= b->n; p += p & -p) {
            b->data[p - 1] += x;
        }
    }

    // Sum :
    int Sum(BIT *b, int l, int r) {
        return b->data[r] - b->data[l];
    }

    // ** copy from here to your source code **
    //
    // fenwick tree
    //  1. go lang have no generics, so implement int(long long)
    //  data type only.
    //  2. do not care overflow
    //

    // BIT :
    typedef struct {
        int n;
        int *data;
    } BIT;

    // FenwickTree :
    BIT *FenwickTree(int n) {
        BIT *ret = malloc(sizeof(BIT));
        ret->n = n;
        ret->data = malloc(sizeof(int) * n);
        memset(ret->data, 0, sizeof(int) * n);
        return ret;
    }

    // Add :
    void Add(BIT *b, int p, int x) {
        p++;
        for (; p <= b->n; p += p & -p) {
            b->data[p - 1] += x;
        }
    }

    // Sum :
    int Sum(BIT *b, int l, int r) {
        return b->data[r] - b->data[l];
    }

    // ** copy from here to your source code **
    //
    // fenwick tree
    //  1. go lang have no generics, so implement int(long long)
    //  data type only.
    //  2. do not care overflow
    //

    // BIT :
    typedef struct {
        int n;
        int *data;
    } BIT;

    // FenwickTree :
    BIT *FenwickTree(int n) {
        BIT *ret = malloc(sizeof(BIT));
        ret->n = n;
        ret->data = malloc(sizeof(int) * n);
        memset(ret->data, 0, sizeof(int) * n);
        return ret;
    }

    // Add :
    void Add(BIT *b, int p, int x) {
        p++;
        for (; p <= b->n; p += p & -p) {
            b->data[p - 1] += x;
        }
    }

    // Sum :
    int Sum(BIT *b, int l, int r) {
        return b->data[r] - b->data[l];
    }

    // ** copy from here to your source code **
    //
    // fenwick tree
    //  1. go lang have no generics, so implement int(long long)
    //  data type only.
    //  2. do not care overflow
    //

    // BIT :
    typedef struct {
        int n;
        int *data;
    } BIT;

    // FenwickTree :
    BIT *FenwickTree(int n) {
        BIT *ret = malloc(sizeof(BIT));
        ret->n = n;
        ret->data = malloc(sizeof(int) * n);
        memset(ret->data, 0, sizeof(int) * n);
        return ret;
    }

    // Add :
    void Add(BIT *b, int p, int x) {
        p++;
        for (; p <= b->n; p += p & -p) {
            b->data[p - 1] += x;
        }
    }

    // Sum :
    int Sum(BIT *b, int l, int r) {
        return b->data[r] - b->data[l];
    }

    // ** copy from here to your source code **
    //
    // fenwick tree
    //  1. go lang have no generics, so implement int(long long)
    //  data type only.
    //  2. do not care overflow
    //

    // BIT :
    typedef struct {
        int n;
        int *data;
    } BIT;

    // FenwickTree :
    BIT *FenwickTree(int n) {
        BIT *ret = malloc(sizeof(BIT));
        ret->n = n;
        ret->data = malloc(sizeof(int) * n);
        memset(ret->data, 0, sizeof(int) * n);
        return ret;
    }

    // Add :
    void Add(BIT *b, int p, int x) {
        p++;
        for (; p <= b->n; p += p & -p) {
            b->data[p - 1] += x;
        }
    }

    // Sum :
    int Sum(BIT *b, int l, int r) {
        return b->data[r] - b->data[l];
    }

    // ** copy from here to your source code **
    //
    // fenwick tree
    //  1. go lang have no generics, so implement int(long long)
    //  data type only.
    //  2. do not care overflow
    //

    // BIT :
    typedef struct {
        int n;
        int *data;
    } BIT;

    // FenwickTree :
    BIT *FenwickTree(int n) {
        BIT *ret = malloc(sizeof(BIT));
        ret->n = n;
        ret->data = malloc(sizeof(int) * n);
        memset(ret->data, 0, sizeof(int) * n);
        return ret;
    }

    // Add :
    void Add(BIT *b, int p, int x) {
        p++;
        for (; p <= b->n; p += p & -p) {
            b->data[p - 1] += x;
        }
    }

    // Sum :
    int Sum(BIT *b, int l, int r) {
        return b->data[r] - b->data[l];
    }

    // ** copy from here to your source code **
    //
    // fenwick tree
    //  1. go lang have no generics, so implement int(long long)
    //  data type only.
    //  2. do not care overflow
    //

    // BIT :
    typedef struct {
        int n;
        int *data;
    } BIT;

    // FenwickTree :
    BIT *FenwickTree(int n) {
        BIT *ret = malloc(sizeof(BIT));
        ret->n = n;
        ret->data = malloc(sizeof(int) * n);
        memset(ret->data, 0, sizeof(int) * n);
        return ret;
    }

    // Add :
    void Add(BIT *b, int p, int x) {
        p++;
        for (; p <= b->n; p += p & -p) {
            b->data[p - 1] += x;
        }
    }

    // Sum :
    int Sum(BIT *b, int l, int r) {
        return b->data[r] - b->data[l];
    }

    // ** copy from here to your source code **
    //
    // fenwick tree
    //  1. go lang have no generics, so implement int(long long)
    //  data type only.
    //  2. do not care overflow
    //

    // BIT :
    typedef struct {
        int n;
        int *data;
    } BIT;

    // FenwickTree :
    BIT *FenwickTree(int n) {
        BIT *ret = malloc(sizeof(BIT));
        ret->n = n;
        ret->data = malloc(sizeof(int) * n);
        memset(ret->data, 0, sizeof(int) * n);
        return ret;
    }

    // Add :
    void Add(BIT *b, int p, int x) {
        p++;
        for (; p <= b->n; p += p & -p) {
            b->data[p - 1] += x;
        }
    }

    // Sum :
    int Sum(BIT *b, int l, int r) {
        return b->data[r] - b->data[l];
    }

    // ** copy from here to your source code **
    //
    // fenwick tree
    //  1. go lang have no generics, so implement int(long long)
    //  data type only.
    //  2. do not care overflow
    //

    // BIT :
    typedef struct {
        int n;
        int *data;
    } BIT;

    // FenwickTree :
    BIT *FenwickTree(int n) {
        BIT *ret = malloc(sizeof(BIT));
        ret->n = n;
        ret->data = malloc(sizeof(int) * n);
        memset(ret->data, 0, sizeof(int) * n);
        return ret;
    }

    // Add :
    void Add(BIT *b, int p, int x) {
        p++;
        for (; p <= b->n; p += p & -p) {
            b->data[p - 1] += x;
        }
    }

    // Sum :
    int Sum(BIT *b, int l, int r) {
        return b->data[r] - b->data[l];
    }

    // ** copy from here to your source code **
    //
    // fenwick tree
    //  1. go lang have no generics, so implement int(long long)
    //  data type only.
    //  2. do not care overflow
    //

    // BIT :
    typedef struct {
        int n;
        int *data;
    } BIT;

    // FenwickTree :
    BIT *FenwickTree(int n) {
        BIT *ret = malloc(sizeof(BIT));
        ret->n = n;
        ret->data = malloc(sizeof(int) * n);
        memset(ret->data, 0, sizeof(int) * n);
        return ret;
    }

    // Add :
    void Add(BIT *b, int p, int x) {
        p++;
        for (; p <= b->n; p += p & -p) {
            b->data[p - 1] += x;
        }
    }

    // Sum :
    int Sum(BIT *b, int l, int r) {
        return b->data[r] - b->data[l];
    }

    // ** copy from here to your source code **
    //
    // fenwick tree
    //  1. go lang have no generics, so implement int(long long)
    //  data type only.
    //  2. do not care overflow
    //

    // BIT :
    typedef struct {
        int n;
        int *data;
    } BIT;

    // FenwickTree :
    BIT *FenwickTree(int n) {
        BIT *ret = malloc(si