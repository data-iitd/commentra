#include <vector>
#include <iostream>
#include <algorithm>

# Declare global variables
n = 0 # n: number of elements
k = 0 # k: size of the subset
t = 0 # t: temporary variable for input
vec = [] # Vector to store the input elements
ans = 1000000001 # Initialize ans to a large value to find the minimum difference

def main():
    # Read the number of elements (n) and the size of the subset (k)
    n, k = map(int, input().split())

    # Read n integers from input and store them in the vector
    for i in range(n):
        t = int(input()) # Read each integer
        vec.append(t) # Add the integer to the vector

    # Sort the vector in non-decreasing order
    vec.sort()

    # Iterate through the sorted vector to find the minimum difference
    for i in range(n - k + 1):
        # Calculate the difference between the maximum and minimum of the current subset of size k
        diff = vec[i + k - 1] - vec[i]
        
        # Update the minimum difference found so far
        if diff < ans:
            ans = diff # Update ans if a smaller difference is found

    # Output the minimum difference found
    print(ans)

if __name__ == "__main__":
    main()

