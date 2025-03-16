#include <iostream>
#include <vector>

int main() {
    // Declare and initialize variables
    int N; // Declare an integer variable named N
    std::cin >> N; // Read an integer value from the standard input and store it in N
    std::vector<int> A(N + 1); // Declare a vector named A with a size of N+1
    std::vector<int> B(N); // Declare a vector named B with a size of N

    // Read the elements of array A from the standard input
    for (int i = 0; i < N + 1; i++) {
        std::cin >> A[i]; // Read an integer value from the standard input and store it in the ith position of array A
    }

    // Read the elements of array B from the standard input
    for (int i = 0; i < N; i++) {
        std::cin >> B[i]; // Read an integer value from the standard input and store it in the ith position of array B
    }

    long ans = 0; // Initialize a variable named ans to 0

    // Nested for loop to compare each pair of elements from arrays A and B
    for (int i = 0; i < N; i++) {
        //site i
        if (A[i] >= B[i]) {
            ans += B[i]; // Add the smaller element to the answer
            A[i] -= B[i]; // Subtract the smaller element from the corresponding element in array A
            B[i] = 0; // Set the smaller element in array B to 0
        } else {
            ans += A[i]; // Add the smaller element to the answer
            B[i] -= A[i]; // Subtract the smaller element from the corresponding element in array B
            A[i] = 0; // Set the smaller element in array A to 0
        }

        //site i + 1
        if (A[i + 1] >= B[i]) {
            ans += B[i]; // Add the smaller element to the answer
            A[i + 1] -= B[i]; // Subtract the smaller element from the corresponding element in array A
            B[i] = 0; // Set the smaller element in array B to 0
        } else {
            ans += A[i + 1]; // Add the smaller element to the answer
            B[i] -= A[i + 1]; // Subtract the smaller element from the corresponding element in array B
            A[i + 1] = 0; // Set the smaller element in array A to 0
        }
    }

    // Print the final answer
    std::cout << ans << std::endl; // Print the value of the answer variable

    // Return 0 to indicate the successful execution of the program
    return 0; // Return 0 to the operating system
}

// <END-OF-CODE>
