#include<stdio.h>
#define LEN 300
#define TRUE 1
#define FALSE -1

# Function prototype for solve
def solve(i, m):
  # Base case: if index i exceeds the number of elements, return FALSE
  if(i > n): return FALSE
  # If the remaining sum m is negative, return FALSE
  elif(m < 0): return FALSE
  # If the remaining sum m is zero or the current element A[i] equals m, set flag to TRUE and return TRUE
  elif(m == 0 or m - A[i+1] == 0):
    flag = TRUE
    return TRUE
  else:
    # Recursive call without using the current element A[i]
    solve(i+1, m)
    # Recursive call using the current element A[i]
    solve(i+1, m-A[i])

# Global variables
n, A = 0, []
flag = FALSE

# Read the number of elements in the array
n = int(input())
# Read the elements of the array
for i in range(n): A.append(int(input()))

# Read the number of queries
q = int(input())
# Iterate over each query
for i in range(q):
  # Read the target sum for the current query
  m = int(input())
  # Initialize the flag to FALSE
  flag = FALSE

  # Call the solve function to find a subset that sums up to M
  solve(-1, m)
  # Print "yes" if a subset is found, otherwise print "no"
  if(flag == TRUE): print("yes")
  else: print("no")

