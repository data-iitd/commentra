#include <stdio.h>
#include <stdlib.h>

#define constMod 1000000007

// Function to read an integer from standard input
int getInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read an array of integers from standard input
int* getIntSlice(int n) {
    int* ns = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ns[i] = getInt();
    }
    return ns;
}

// Function to solve the problem
void solve() {
    int n = getInt();
    int m = getInt();
    int* a = getIntSlice(n);

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

    free(a); // Free the allocated memory
}

// Main function
int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
