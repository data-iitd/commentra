#include <iostream>
using namespace std;

// Function to print the array elements
void white(int n, int A[]) {
    for(int i = 0; i < n - 1; i++) {
        cout << A[i] << " "; // Print each element followed by a space
    }
    cout << A[n - 1] << endl; // Print the last element followed by a newline
}

// Function to perform insertion sort on the array
void insertionsort(int n, int A[]) {
    int i, j, a;
    for(i = 0; i < n; i++) {
        for(j = 0; j < i; j++) {
            if(A[i] < A[j]) {
                a = A[i]; 
                A[i] = A[j]; 
                A[j] = a; // Swap the elements
            }
        }
        // Print the current state of the array after each insertion
        white(n, A);
    }
}

int main() {
    int i, n, A[100]; // Declare variables for the number of elements and the array
    cin >> n; // Read the number of elements from user input
    for (i = 0; i < n; i++) {
        cin >> A[i]; // Read the elements of the array from user input
    }
    // Call the insertion sort function to sort the array
    insertionsort(n, A);

    return 0; // Return 0 to indicate successful execution
}

