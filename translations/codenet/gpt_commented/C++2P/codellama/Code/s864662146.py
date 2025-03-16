#include<iostream>
#include<cmath>
using namespace std;

int main() {
    # Declare an integer N to store the number of elements
    N = 0
    
    # Read the number of elements from user input
    cin >> N
    
    # Declare an array A of size N to hold the elements
    A = [0] * N
    
    # Read N elements into the array A
    for i in range(N):
        cin >> A[i]

    # Initialize m and M to the first element of the array A
    m = A[0]
    M = A[0]
    
    # Iterate through the array to find the minimum and maximum values
    for i in range(N):
        # Update m if the current element is less than the current minimum
        if A[i] < m:
            m = A[i]
        
        # Update M if the current element is greater than the current maximum
        if A[i] > M:
            M = A[i]

    # Output the difference between the maximum and minimum values
    print(M - m)

    # Return 0 to indicate successful execution
    return 0
}
