// problem_b.c

#include <stdio.h>
#include <stdlib.h>

#define constMod 1000000007

// Function to read an integer from input
int getInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read an array of integers from input
int* getIntSlice(int n) {
    int* ns = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ns[i] = getInt();
    }
    return ns;
}

// Function to calculate the greatest common divisor of two integers
int numGcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return numGcd(b, a % b);
}

// Function to solve the main logic of the program
void solve() {
    int n = getInt();
    int m = getInt();
    int* a = getIntSlice(n);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        double rate = (double)sum / (4 * m);
        if ((double)a[i] >= rate) {
            count++;
        }
    }

    if (count >= m) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    free(a);
}

// Main function
int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
