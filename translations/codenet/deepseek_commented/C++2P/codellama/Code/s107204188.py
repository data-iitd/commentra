#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(void){
    # Initialize the minimum value to a large number
    minA = pow(10,9) + 1
    # Initialize the number of ways to achieve the maximum profit
    num = 0
    
    # Read the number of elements and an unused variable 't'
    n, t, f = 0
    cin >> n >> t
    # Create a vector to store the elements
    A = [0] * n
    
    # Read the elements into the vector
    for i in range(n):
        cin >> A[i]
    
    # Iterate through the vector to find the maximum profit
    for i in range(n):
        # Update the minimum value found so far
        if minA > A[i]:
            minA = A[i]
        else:
            # Check if the current profit is equal to the maximum profit found so far
            if f == A[i] - minA:
                num += 1
            # Update the maximum profit and reset the count if a new maximum is found
            else:
                if f < A[i] - minA:
                    num = 1
                    f = A[i] - minA
    
    # Output the number of ways to achieve the maximum profit
    cout << num << endl
}

