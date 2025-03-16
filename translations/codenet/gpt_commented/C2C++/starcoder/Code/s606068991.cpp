#include<iostream>
using namespace std;

// Function to print the array elements
void white(int n, int A[]) {
    int i;
    // Loop through the array elements except the last one
    for(i = 0; i < n - 1; i++) {
        cout << A[i] << " "; // Print each element followed by a space
    }
    cout << A[i] << endl; // Print the last element followed by a newline
}

// Function to perform insertion sort on the array
void insertionsort(int n, int A[]) {
    int i, j, a;
    // Loop through each element in the array
    for(i = 0; i < n; i++) {
        // Compare the current element with the previous elements
        for(j = 0; j < i; j++) {
            // If the current element is smaller, swap it with the previous element
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
    // Read the number of elements from user input
    cin >> n;
    // Read the elements of the array from user input
    for (i = 0; i < n; i++) {
        cin >> A[i];
    }
    // Call the insertion sort function to sort the array
    insertionsort(n, A);

    return 0; // Return 0 to indicate successful execution
}
