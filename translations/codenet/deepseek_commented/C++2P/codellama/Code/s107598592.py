#include<iostream>  # Include the input-output stream library for standard input and output operations.
#include<vector>    # Include the vector library for using dynamic arrays.
#include<algorithm> # Include the algorithm library for using the sort function.

using namespace std; # Use the standard namespace to avoid prefixing standard library components with 'std::'.

def main():
  N = int(input()) # Read the number of elements N from the standard input.
  X = [0] * N # Declare two vectors X and Y of size N to store the elements.
  Y = [0] * N
  
  # Read N elements into vector X and simultaneously copy them to vector Y.
  for i in range(N):
    X[i] = int(input())
    Y[i] = X[i]
  
  # Sort the vector Y in ascending order.
  Y.sort()
  
  # Calculate the median of the sorted vector Y. The median is the middle element for odd N, and the average of the two middle elements for even N.
  y = Y[N//2]
  
  # Iterate through each element in vector X and output the appropriate median value based on the comparison with y.
  for i in range(N):
    if X[i] < y:
      print(y) # If the element in X is less than the median, output the median.
    else:
      print(y - 1) # Otherwise, output the median minus one.
    print() # Output a newline after each result.
  
  return 0 # Return 0 to indicate successful execution.

