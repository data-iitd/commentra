
#include<stdio.h>

# Function to perform linear search on an array
def linearsearch(S, n, key):
  i = 0 # Initialize index variable i to 0
  count = 0 # Initialize count variable to 0

  # Search for the key in the array S until it is found or the end of the array is reached
  while( S[i] != key ):
    i += 1 # Increment i by 1 for each iteration
    if( i >= n ): # Check if the end of the array has been reached
      count = 1 # Set count to 1 if key is not found in the array
      return count # Return count to the calling function

  # If key is found, return 0 to indicate that it was found
  return 0

# Main function to read input and call linearsearch function
def main():
  i, j, n, q, S, T = 0, 0, 0, 0, [], [] # Declare and initialize variables
  count = 0 # Initialize count variable to 0

  # Read the size of the array S from the user
  print("Enter the size of the array S: ")
  n = int(input())

  # Read the elements of array S from the user
  print("Enter %d integers for array S:\n" % n)
  for i in range(n):
    print("Enter integer S[%d]: " % i)
    S.append(int(input()))

  # Read the number of queries from the user
  print("Enter the number of queries: ")
  q = int(input())

  # Read the elements of array T from the user
  print("Enter %d integers for array T:\n" % q)
  for j in range(q):
    print("Enter integer T[%d]: " % j)
    T.append(int(input()))

  # Call linearsearch function for each element of array T and increment count if key is not found
  for j in range(q):
    key = T[j] # Assign the current element of array T to key variable
    if(linearsearch(S, n, key) == 1): # Call linearsearch function and check if count is 1 (key not found)
      count += 1 # Increment count if key is not found

  # Print the final count to the user
  print("Number of integers in array S that are not present in array T: %d\n" % count)

  # Return 0 to indicate successful execution of the program
  return 0

