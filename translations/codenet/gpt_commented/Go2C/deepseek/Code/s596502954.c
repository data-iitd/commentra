#include <stdio.h>
#include <stdlib.h>

// Function to read the next integer from input
int nextInt() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read the next float from input
double nextFloat() {
    double f;
    scanf("%lf", &f);
    return f;
}

// Function to read 'n' integers from input and store them in an array
void nextInts(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    // Read two integers, sum them, and compare the result with a third integer
    int a = nextInt();
    int b = nextInt();
    int c = nextInt();

    if (a + b >= c) {
        printf("Yes\n"); // Print "Yes" if the sum is greater than or equal to the third integer
    } else {
        printf("No\n"); // Print "No" otherwise
    }

    return 0;
}
