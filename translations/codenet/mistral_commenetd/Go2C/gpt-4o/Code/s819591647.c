// problem_b.c
// This is the main file for problem B solution

#include <stdio.h>
#include <stdlib.h>

#define constMod 1000000007 // Constants definition

// Function to read an integer from standard input
int getInt() {
    int i;
    scanf("%d", &i);
    return i;
}

// Function to read n integers and return an array
int* getIntArray(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = getInt();
    }
    return arr;
}

// Function to calculate the greatest common divisor of a and b
int numGcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return numGcd(b, a % b);
}

// Function to calculate the least common multiple of a and b
int numLcm(int a, int b) {
    return a * (b / numGcd(a, b));
}

// Function to calculate the absolute value of an integer
int numAbs(int x) {
    return (x < 0) ? -x : x;
}

// Function to solve the problem
void solve() {
    int n = getInt();
    int m = getInt();
    int* a = getIntArray(n);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    int count = 0;
    double rate = (double)sum / (4 * m);
    for (int i = 0; i < n; i++) {
        if ((double)a[i] >= rate) {
            count++;
        }
    }

    if (count >= m) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    free(a); // Free allocated memory
}

// Main function
int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
