#include <stdio.h>

int possible(int N, int A[]);

int main() {
    int N;
    scanf("%d", &N); // Read the number of elements N from the user
    int A[N]; // Create an array A to store the elements
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]); // Read N integers from the user and store them in the array A
    }
    if (possible(N, A)) { // Call the possible method to check if the array A can be rearranged to satisfy a certain condition
        printf("YES\n"); // Print "YES" if the condition is satisfied
    } else {
        printf("NO\n"); // Print "NO" if the condition is not satisfied
    }
    return 0;
}

int possible(int N, int A[]) {
    long sum = 0; // Initialize sum to store the sum of the elements in the array A
    for (int i = 0; i < N; i++) {
        sum += A[i]; // Calculate the sum of the elements in the array A
    }
    long NS = (long)N * (N + 1) / 2; // Calculate the sum of the first N natural numbers (NS)
    if (sum % NS != 0) return 0; // Check if the sum of the array A is divisible by NS. If not, return false
    long K = sum / NS; // Calculate the value of K
    for (int i = 0; i < N; i++) {
        int j = (i == 0) ? N - 1 : i - 1; // Calculate the index of the previous element in the array A
        long d = K - (A[i] - A[j]); // Calculate the difference
        if (d < 0 || d % N != 0) return 0; // Check if the difference is negative or not divisible by N. If so, return false
    }
    return 1; // If all elements satisfy the condition, return true
}

// <END-OF-CODE>
