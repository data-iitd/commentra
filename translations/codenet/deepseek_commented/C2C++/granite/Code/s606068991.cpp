
#include<iostream>

// Function to print the array elements
void white(int n, int A[]) {
    int i;
    for (i = 0; i < n - 1; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << A[i] << std::endl;
}

// Function to perform insertion sort on the array
void insertionsort(int n, int A[]) {
    int i, j, a;
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (A[i] < A[j]) {
                // Swap A[i] and A[j]
                a = A[i];
                A[i] = A[j];
                A[j] = a;
            }
        }
        // Print the array after each insertion
        white(n, A);
    }
}

// Main function to handle input and call the sorting function
int main() {
    int i, n, A[100];
    std::cin >> n;
    for (i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    insertionsort(n, A);

    return 0;
}
