
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(void){
    # Initialize minimum value of array A to a large number
    minA = pow(10,9) + 1
    num = 0

    # Read number of elements and time t from the standard input
    n, t = input().split()

    # Create a vector A of size n to store the input elements
    A = [0] * int(n)

    # Read each element of vector A from the standard input
    for i in range(int(n)):
        A[i] = int(input())
        # Check if the current element is smaller than the minimum value
        if minA > A[i]:
            # Update the minimum value of array A
            minA = A[i]
        else:
            # Calculate the difference between the current element and the minimum value
            diff = A[i] - minA

            # If the difference is equal to the previous difference, increment the count of similar differences
            if f == diff:
                num += 1
            # If the difference is greater than the previous difference, reset the count to 1 and update the previous difference
            elif f < diff:
                num = 1
                f = diff

    # Print the count of similar differences on the standard output
    print(num)
}

