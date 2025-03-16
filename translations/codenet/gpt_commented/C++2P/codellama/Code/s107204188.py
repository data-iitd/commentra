#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(void) {
    # Initialize minA to a value larger than any possible element in A
    minA = pow(10, 9) + 1
    num = 0 # Counter for the number of valid pairs

    n, t = 0, 0 # Declare variables for input size, threshold, and frequency
    cin >> n >> t # Read the size of the array and the threshold value
    A = [0] * n # Create a vector to store the elements of the array

    # Input the elements of the array A
    for i in range(n):
        cin >> A[i]

    # Iterate through the array to find the minimum value and count valid pairs
    for i in range(n):
        # Update minA if the current element is smaller
        if minA > A[i]:
            minA = A[i]
        else:
            # Check the difference between the current element and minA
            if f == A[i] - minA:
                num += 1 # Increment the count if the difference matches the previous one
            else if f < A[i] - minA:
                num = 1 # Reset count if a larger difference is found
                f = A[i] - minA # Update the frequency to the new difference

    # Output the total count of valid pairs
    cout << num << endl

    return 0 # Return success
}

