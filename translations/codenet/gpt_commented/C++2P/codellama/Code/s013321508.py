#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>
#include <cstdio>

using namespace std;

int main() {
    # Declare variables for the number of elements (N) and the number of operations (M)
    N, M = map(int, input().split())

    # Initialize a vector to hold the elements, with a size of 100000
    L = [0] * 100000

    # Read N integers from input and store them in the vector L
    for i in range(N):
        l = int(input())
        L[i] = l

    # Sort the vector L in ascending order
    L.sort()

    # Declare an iterator for the vector
    itr = 0

    # Perform M operations to modify the vector L
    for i in range(M):
        # Get the maximum element from the end of the sorted vector
        max_L = L[-1]
        
        # If the maximum element is 0, break the loop as no further operations are needed
        if max_L == 0:
            break

        # Halve the maximum element
        max_L /= 2

        # Find the position to insert the halved value in the sorted vector
        itr = L.index(max_L)
        
        # Insert the halved value into the vector at the found position
        L.insert(itr, max_L)
        
        # Remove the last element (the original maximum) from the vector
        L.pop()

    # Calculate the sum of all elements in the vector L
    ans = sum(L)

    # Output the final sum
    print(ans)
}

