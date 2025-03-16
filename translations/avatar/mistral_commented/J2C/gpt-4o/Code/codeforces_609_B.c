#include <stdio.h>

int main() {
    // Reading the first integer input n from the user
    int n;
    scanf("%d", &n);

    // Reading the second integer input m from the user
    int m;
    scanf("%d", &m);

    // Creating an integer array arr of size n to store the input integers
    int arr[n];

    // Creating an integer array gen of size 11 to store the count of each integer occurrence
    int gen[11] = {0};

    // Reading the input integers and storing them in the arr array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        // Incrementing the count of the arr[i] in the gen array
        gen[arr[i]]++;
    }

    // Calculating the answer
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int k = 1; k <= m; k++) {
            // Skipping the case when i and k are equal to avoid double counting
            if (i != k) {
                // Multiplying the count of i and k and adding it to the answer
                ans += (long long)gen[i] * gen[k];
            }
        }
    }

    // Printing the answer divided by 2
    printf("%lld\n", ans / 2);

    return 0;
}

// <END-OF-CODE>
