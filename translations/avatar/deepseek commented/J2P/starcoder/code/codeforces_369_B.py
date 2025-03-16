import sys; # Importing necessary classes for array operations and input handling
import math; # Importing necessary classes for input handling

def getPoints(n, k, l, r, sAll, sk):
    ans = [l] * n; # Initializing an array to store the result
    for i in range(n - k): # Iterating through the remaining elements
        ans[i] = r; # Filling the array with the upper bound value 'r'
    
    # Subtracting the initial points for the first group and the remaining elements
    sAll -= sk + (n - k) * l;
    sk -= k * l;
    
    # Distributing the remaining points to the first group until sk is zero
    while sk > 0:
        idx = n - 1; # Starting from the last element in the array
        while sk > 0 and idx >= n - k:
            ans[idx] += 1; # Incrementing the points and moving to the previous element
            sk -= 1; # Decrementing the remaining points to distribute
        idx -= 1; # Moving to the previous element
    # Distributing the remaining points to the remaining elements until sAll is zero
    while sAll > 0:
        idx = 0; # Starting from the first element in the array
        while sAll > 0 and idx < n - k:
            ans[idx] += 1; # Incrementing the points and moving to the next element
            sAll -= 1; # Decrementing the remaining points to distribute
        idx += 1; # Moving to the next element
    return ans; # Returning the result array

if __name__ == "__main__":
    n = int(input()); # Reading the number of elements
    k = int(input()); # Reading the number of elements in the first group
    l = int(input()); # Reading the lower bound for the points
    r = int(input()); # Reading the upper bound for the points
    sAll = int(input()); # Reading the total sum of points
    sk = int(input()); # Reading the sum of points for the first group
    ans = getPoints(n, k, l, r, sAll, sk); # Calling the getPoints method to compute the result
    for num in ans: # Iterating through the result array to print each element
        print(num, end=" "); # Printing each element followed by a space

