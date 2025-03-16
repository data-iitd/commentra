#include <stdio.h>

A = [0] * 1000000 # Declare an array A to hold up to 1,000,000 integers and a variable n for the number of elements

# 二分探索 (Binary Search)
def binarySearch(key):
  left = 0 # Initialize the left boundary of the search range
  right = n # Initialize the right boundary of the search range
  mid = 0 # Variable to hold the midpoint index during the search

  # Continue searching while the left boundary is less than the right boundary
  while left < right:
    mid = (left + right) // 2 # Calculate the midpoint index
    if key == A[mid]: return 1 # If the key is found, return 1
    if key > A[mid]: left = mid + 1 # If the key is greater, search in the right half
    else: right = mid # If the key is smaller, search in the left half
  return 0 # If the key is not found, return 0

n = 0 # Declare variables for iteration, number of queries, the key to search, and a sum counter
q = 0
k = 0
sum = 0

# Read the number of elements in the array
n = int(input())

# Read the elements into the array A
for i in range(n):
  A[i] = int(input())

# Read the number of queries
q = int(input())

# Process each query
for i in range(q):
  k = int(input()) # Read the key to search for
  if binarySearch(k): # Perform binary search for the key
    sum += 1 # Increment the sum if the key is found

# Output the total number of keys found in the array
print(sum)

