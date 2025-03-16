#include<stdio.h>

# Function to perform linear search on an array
def linearsearch(S, n, key):
  i = 0; # Initialize index for searching
  count = 0; # Initialize count to track if the key is found

  # Loop until the key is found or the end of the array is reached
  while( S[i]!= key ):
    i = i + 1; # Move to the next index
    # If the index exceeds the size of the array, the key is not found
    if( i >= n  ):
      count = 1; # Set count to indicate the key was not found
      return count; # Return count
  return count; # Return count (0 if key is found)

def main():
  i, j, n, q, S[10000], T[10000]; # Declare variables and arrays
  count = 0; # Initialize count for missing keys
  key; # Initialize key for searching

  # Read the number of elements in the first array
  n = int(input())
  # Read the elements into the first array S
  for i in range(n):
    S[i] = int(input())

  # Read the number of queries
  q = int(input())
  # Read the elements into the second array T (the keys to search for)
  for j in range(q):
    T[j] = int(input())
 
  # Loop through each key in T to check if it exists in S
  for j in range(q):
    key = T[j]; # Get the current key to search
    # If the key is not found in S, increment the count
    if(linearsearch(S, n, key) == 0):
      count = count + 1; # Increment count for each missing key

  # Print the total count of keys that were not found in S
  print(count)
  
  return 0; # Exit the program

