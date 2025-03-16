#include <iostream>
using namespace std;

// Function to print the first n-1 elements of an array
void white(int n, int A[]) {
    // Loop to print the first n-1 elements of the array
    for (int i = 0; i < n - 1; i++) {
        cout << A[i] << " ";
    }
    // Print the last element of the array
    cout << A[n - 1] << endl;
}

// Function to implement insertion sort algorithm
void insertionsort(int n, int A[]) {
    // Loop to sort the array using insertion sort algorithm
    for (int i = 0; i < n; i++) {
        // Inner loop to find the position of the current element in sorted array
        for (int j = 0; j < i; j++) {
            // Swap if current element is smaller than the previous one
            if (A[i] < A[j]) {
                // Swap the elements
                swap(A[i], A[j]);
            }
        }
        // Call the white function to print the sorted array after each iteration
        white(n, A);
    }
}

// Main function to take input and call the insertion sort function
int main() {
    int n, A[100];
    // Take the size of the array as input
    cin >> n;
    // Take the elements of the array as input
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    // Call the insertion sort function to sort the array
    insertionsort(n, A);

    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
