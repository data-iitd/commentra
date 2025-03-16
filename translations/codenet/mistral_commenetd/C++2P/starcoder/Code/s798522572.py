# -*- coding: utf-8 -*-
# <BEGIN-OF-CODE>
# Python 2.7

# Main function starts here
def main():
  # Initialize variables
  N, T = map(int, raw_input().split()) # N is the number of elements in the array A, T is an input value

  # Read input values from the standard input
  A = map(int, raw_input().split())

  # Allocate memory for a vector B of size N
  B = [0] * N

  # Initialize variable m with the minimum value among the first two elements of array A
  m = min(A[0], A[1])

  # Set the first element of vector B with the difference between the second element of array A and the initialized value of m
  B[1] = A[1] - m

  # Iterate through the remaining elements of array A starting from the third one
  for i in range(2, N):
    # Update the value of m with the minimum value between it and the current element of array A
    m = min(m, A[i])

    # Set the current element of vector B with the difference between the current element of array A and the updated value of m
    B[i] = A[i] - m

  # Print the output value to the standard output
  print B.count(max(B))

# Start the execution if it's the main script
if __name__ == "__main__":
  main()

# 