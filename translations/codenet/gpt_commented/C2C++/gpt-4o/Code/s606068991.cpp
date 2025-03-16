#include <iostream>
#include <vector>

// Function to print the array elements
void white(int n, const std::vector<int>& A) {
    for(int i = 0; i < n - 1; i++) {
        std::cout << A[i] << " "; // Print each element followed by a space
    }
    std::cout << A[n - 1] << std::endl; // Print the last element followed by a newline
}

// Function to perform insertion sort on the array
void insertionsort(int n, std::vector<int>& A) {
    for(int i = 0; i < n; i++) {
        // Compare the current element with the previous elements
        for(int j = 0; j < i; j++) {
            // If the current element is smaller, swap it with the previous element
            if(A[i] < A[j]) {
                std::swap(A[i], A[j]); // Swap the elements
            }
        }
        // Print the current state of the array after each insertion
        white(n, A);
    }
}

int main() {
    int n;
    std::vector<int> A(100); // Declare a vector for the array
    // Read the number of elements from user input
    std::cin >> n;
    // Read the elements of the array from user input
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    // Call the insertion sort function to sort the array
    insertionsort(n, A);

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
