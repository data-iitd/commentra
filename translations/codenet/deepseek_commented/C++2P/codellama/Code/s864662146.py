#include<iostream>  # Include the iostream library for input and output operations
#include<cmath>     # Include the cmath library for mathematical operations
using namespace std; # Use the standard namespace to avoid prefixing standard library names with 'std::'

int main():
    N = 0 # Declare an integer variable N and initialize it to 0
    cin >> N # Read an integer value from the standard input and store it in N
    A = [0] * N # Declare an array A of size N
    for i in range(N): cin >> A[i] # Read N integers from the standard input and store them in the array A

    m = A[0] # Initialize the variable m to the first element of the array A
    M = A[0] # Initialize the variable M to the first element of the array A
    for i in range(N): # Start a loop that iterates through the array A
        if A[i] < m: m = A[i] # If the current element is less than m, update m to the current element
        if A[i] > M: M = A[i] # If the current element is greater than M, update M to the current element

    print(M - m) # Print the difference between the maximum and minimum values in the array A

    return 0 # Return 0 to indicate successful execution

