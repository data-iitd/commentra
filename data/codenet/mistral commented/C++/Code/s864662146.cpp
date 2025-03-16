
#include<iostream>
#include<cmath>
using namespace std;

// Initialize variables
int main() {
    int N; // Number of elements in the array
    cin >> N; // Read the number of elements from the standard input

    int A[N]; // Declare and initialize an array of size N
    for (int i = 0; i < N; i++) {
        cin >> A[i]; // Read each element of the array from the standard input
    }

    int min_element = A[0]; // Initialize minimum element variable with first element
    int max_element = A[0]; // Initialize maximum element variable with first element

    // Find minimum and maximum elements in the array
    for (int i = 0; i < N; i++) {
        if (A[i] < min_element) { // If current element is smaller than the current minimum
            min_element = A[i]; // Update minimum element
        }
        if (A[i] > max_element) { // If current element is larger than the current maximum
            max_element = A[i]; // Update maximum element
        }
    }

    // Print the difference between maximum and minimum elements
    cout << "Difference between maximum and minimum elements: " << M - m << endl;

    return 0;
}