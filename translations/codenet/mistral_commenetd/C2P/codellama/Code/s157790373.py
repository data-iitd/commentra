
#include<stdio.h>
#define LEN 300
#define TRUE 1
#define FALSE -1

def solve(i, m): # Function to check if there is a subsequence of given length 'm' in the array 'A' starting from index 'i'
  # Base case: If index 'i' goes beyond the size of the array 'A', return false as no subsequence can start from this index
  if i>n:
    return FALSE

  # Base case: If length 'm' is zero, any empty subsequence of length zero can be formed from any index in the array 'A'
  elif m<0:
    return FALSE

  # Base case: If length 'm' is equal to zero or the difference between the elements at index 'i+1' and 'i' is equal to 'm', a subsequence of length 'm' can be formed starting from index 'i'
  elif m==0 or m-A[i+1]==0:
    global flag # Setting the flag to true as a subsequence of length 'm' is found
    flag=TRUE
    return TRUE # Returning true to indicate that a subsequence of length 'm' is found

  # Recursive case: If length 'm' cannot be formed from the element at index 'i', check if it can be formed from the elements starting from index 'i+1'
  else:
    # Not using the element at index 'i' to form the subsequence of length 'm'
    solve(i+1, m)

    # Using the element at index 'i' to form the subsequence of length 'm'
    solve(i+1, m-A[i])

n, A = [], [] # 'n' is the size of the array 'A' and 'A' is the array to be checked
flag = FALSE # Flag to check if a subsequence of given length 'm' is found

n = int(input()) # Reading the size of the array 'A'
for i in range(n):
  A.append(int(input())) # Reading the elements of the array 'A'

q = int(input()) # Reading the number of queries
for i in range(q): # Loop through all the queries
  M = int(input()) # Reading the length of subsequence to be checked in the current query
  flag = FALSE # Initializing the flag to false

  solve(0, M) # Calling the function 'solve' to check if there is a subsequence of given length 'M' in the array 'A'

  if flag == TRUE:
    print("yes") # If a subsequence of given length 'M' is found, print 'yes'
  else:
    print("no") # If no subsequence of given length 'M' is found, print 'no'

