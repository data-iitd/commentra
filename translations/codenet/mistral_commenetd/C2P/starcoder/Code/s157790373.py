
#include<stdio.h>
#define LEN 300
#define TRUE 1
#define FALSE -1

def solve(i, m): # Function to check if there is a subsequence of given length'm' in the array 'A' starting from index 'i'
  if(i>n):return FALSE # Base case: If index 'i' goes beyond the size of the array 'A', return false as no subsequence can start from this index
  elif(m<0):return FALSE # Base case: If length'm' is zero, any empty subsequence of length zero can be formed from any index in the array 'A'
  elif(m==0 or m-A[i+1]==0): # Base case: If length'm' is equal to zero or the difference between the elements at index 'i+1' and 'i' is equal to'm', a subsequence of length'm' can be formed starting from index 'i'
    flag=TRUE # Setting the flag to true as a subsequence of length'm' is found
    return TRUE # Returning true to indicate that a subsequence of length'm' is found
  else: # Recursive case: If length'm' cannot be formed from the element at index 'i', check if it can be formed from the elements starting from index 'i+1'
    # Not using the element at index 'i' to form the subsequence of length'm'
    solve(i+1, m)

    # Using the element at index 'i' to form the subsequence of length'm'
    solve(i+1, m-A[i])

n=int(input()) # Reading the size of the array 'A'
A=[int(input()) for i in range(n)] # Reading the elements of the array 'A'
q=int(input()) # Reading the number of queries
for i in range(q): # Loop through all the queries
  M=int(input()) # Reading the length of subsequence to be checked in the current query
  flag=FALSE # Initializing the flag to false

  solve(0, M) # Calling the function'solve' to check if there is a subsequence of given length 'M' in the array 'A'

  if(flag==TRUE):print("yes") # If a subsequence of given length 'M' is found, print 'yes'
  else:print("no") # If no subsequence of given length 'M' is found, print 'no'

