# Include the input-output stream library for standard input and output operations.
# Include the vector library for using dynamic arrays.
# Include the algorithm library for using the sort function.

import sys # Use the standard library to avoid prefixing standard library components with'std::'.

N = int(input()) # Read the number of elements N from the standard input.
X = [int(x) for x in input().split()] # Read N elements into vector X and simultaneously copy them to vector Y.
Y = X[:] # Copy vector X to vector Y.
Y.sort() # Sort the vector Y in ascending order.
y = Y[N//2] # Calculate the median of the sorted vector Y. The median is the middle element for odd N, and the average of the two middle elements for even N.

for x in X: # Iterate through each element in vector X and output the appropriate median value based on the comparison with y.
  if x < y:
    print(y) # If the element in X is less than the median, output the median.
  else:
    print(y - 1) # Otherwise, output the median minus one.
  print() # Output a newline after each result.

# 