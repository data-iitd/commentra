
//problem_b.c
// This is the main file for problem B solution

#include <stdio.h>
#include <stdlib.h>

#define constMod 100000007 // Constants definition

int getInt() { // Function to read an integer from standard input
    int i;
    scanf("%d", &i);
    return i;
}

int* getIntSlice(int n) { // Function to read n integers and return a slice
    int* ns = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ns[i] = getInt();
    }
    return ns;
}

char* getString() { // Function to read a string from standard input
    char* s = (char*)malloc(100 * sizeof(char));
    fgets(s, 100, stdin);
    s[strlen(s) - 1] = '\0';
    return s;
}

char** getStringSlice(int n) { // Function to read n strings and return a slice
    char** ss = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        ss[i] = getString();
    }
    return ss;
}

char** getStringDoubleSlice(int m, int n) { // Function to read m strings of length n and return a 2D slice
    char*** sds = (char***)malloc(m * sizeof(char**));
    for (int i = 0; i < m; i++) {
        ss[i] = getStringSlice(n);
    }

    return sds;

}

void sortIntSlice(int* ns, int n) { // Function to sort an integer slice in ascending order
    qsort(ns, n, sizeof(int), cmpfunc);
}

void sortIntReverseSlice(int* ns, int n) { // Function to sort an integer slice in descending order
    qsort(ns, n, sizeof(int), cmpfunc_reverse);
}

int cmpfunc(const void * a, const void * b) { // Function to compare two integers for sorting
    return (*(int*)a - *(int*)b);
}

int cmpfunc_reverse(const void * a, const void * b) { // Function to compare two integers for sorting in reverse order
    return (*(int*)b - *(int*)a);
}

int numAbs(int x) { // Function to get absolute value of an integer
    if (x < 0) {
        return -x;
    }

    return x;
}

int numModPow(int a, int n, int m) { // Function to calculate a^n % m
    int result = 1;

    for (int i = 0; i < n; i++) {
        if (n % 2 == 1) {
            result = (result * a) % m;
        }

        a = (a * a) % m;
        n >>= 1;
    }

    return result;
}

int numGcd(int a, int b) { // Function to calculate the greatest common divisor of a and b
    if (b == 0) {
        return a;
    }

    return numGcd(b, a % b);
}

int numLcm(int a, int b) { // Function to calculate the least common multiple of a and b
    return a * b / numGcd(a, b);
}

int numModInv(int a, int p) { // Function to calculate the modular inverse of a modulo p
    if (a == 1) {
        return 1;
    }

    return p - numModInv(p % a, p) * (p / a) % p;
}

int* numModFrac(int n) { // Function to calculate n! modulo constMod
    int* frac = (int*)malloc((n + 1) * sizeof(int));
    frac[0] = 1;

    for (int i = 1; i <= n; i++) {
        frac[i] = i * frac[i - 1] % constMod;
    }

    return frac;
}

int numModConb(int n, int r) { // Function to calculate nCr modulo constMod
    int* frac = numModFrac(n);

    return (frac[n] / ((frac[n - r] * frac[r]) % constMod)) % constMod;
}

void solve() { // Function to solve the problem
    int n, m;
    n = getInt();
    m = getInt();
    int* a = getIntSlice(n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        float rate = (float)sum / (4 * m);
        if ((float)a[i] >= rate) {
            count++;
        }
    }

    if (count >= m) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

}

int main() { // Main function
    solve();
    return 0;
}
