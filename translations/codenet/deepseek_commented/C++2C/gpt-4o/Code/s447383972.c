#include <stdio.h>
#include <stdlib.h>

#define N 200010

long long a[N], q[N], n, tot;

<<<<<<< HEAD
int compare(const void *a, const void *b) {
    return (*(long long *)a - *(long long *)b);
}

=======
>>>>>>> 98c87cb78a (data updated)
long long read() {
    long long x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void write(long long x) {
<<<<<<< HEAD
    if (x < 0) putchar('-'), x = -x;
=======
    if (x < 0) {
        putchar('-');
        x = -x;
    }
>>>>>>> 98c87cb78a (data updated)
    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

void writeln(long long x) {
    write(x);
    puts("");
}

<<<<<<< HEAD
=======
int compare(const void *a, const void *b) {
    return (*(long long *)a - *(long long *)b);
}

>>>>>>> 98c87cb78a (data updated)
int main() {
    n = read(); // Read the size of the array.
    for (long long i = 1; i <= n; ++i) {
        a[i] = read(); // Read the elements of the array.
    }
    qsort(a + 1, n, sizeof(long long), compare); // Sort the array.
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
    for (long long i = 1; i <= n; ++i) {
        if (a[i] == a[i + 1]) {
            q[++tot] = a[i];
            i++; // Remove duplicates from the array.
        }
    }
    writeln(q[tot] * q[tot - 1]); // Print the product of the two largest distinct elements.
    return 0;
}

// <END-OF-CODE>
