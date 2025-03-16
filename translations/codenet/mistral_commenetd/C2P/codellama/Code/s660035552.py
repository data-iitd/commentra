
#include<stdio.h> // Standard Input/Output Library
#include<stdlib.h> // Standard Library
#include<string.h> // String Library
#include<math.h> // Mathematical Library

# Initialize low and high arrays for quicksort
low = [0] * 200000
high = [0] * 200000

# Array 'a' to store elements after sorting
a = [0] * 200000

# Array 'b' to store elements for quicksort partitioning
b = [0] * 200000

# Function to partition the array using quicksort algorithm
def part(a,b,l,r):
  i = l - 1 # Initialize variables
  j = r
  x = b[r]

  while(1): # While loop for partitioning
    while(b[++i] < x): # Move 'i' to next smaller element
      pass
    while(i < --j and x < b[j]): # Move 'j' to previous greater element
      pass

    if(i >= j): break # If 'i' and 'j' meet, partitioning is done

    t = a[i] # Swap elements in 'a' array
    a[i] = a[j]
    a[j] = t

    t = b[i] # Swap elements in 'b' array
    b[i] = b[j]
    b[j] = t

  t = a[i] # Swap pivot with last element in 'a' array
  a[i] = a[r]
  a[r] = t

  t = b[i] # Swap pivot with last element in 'b' array
  b[i] = b[r]
  b[r] = t

  return i # Return index of pivot

# Function to perform quicksort on the array 'a'
def quicksort(a,b,n):
  l,r,v = 0,0,0 # Initialize variables
  sp = 1 # Initialize stack pointer

  low[0] = 0 # Initialize 'low' stack with base index 0
  high[0] = n - 1 # Initialize 'high' stack with top index 'n-1'

  while(sp > 0): # While stack is not empty
    sp -= 1 # Decrement stack pointer
    l = low[sp] # Get base index 'l' from stack
    r = high[sp] # Get top index 'r' from stack

    if(l >= r): # If base and top indices are same, no need to partition
      continue # Skip this iteration

    v = part(a,b,l,r) # Partition the array

    if(v - l < r - v): # If partitioning moved pivot to left, swap 'low' and 'high' indices
      low[sp] = v + 1
      high[sp] = r
      low[sp + 1] = l
      high[sp + 1] = v - 1
    else: # If partitioning moved pivot to right, swap 'low' and 'high' indices in reverse order
      low[sp] = l
      high[sp] = v - 1
      low[sp + 1] = v + 1
      high[sp + 1] = r

# Main function to read input and call quicksort
def main():
  n,m = 0,0 # Initialize variables
  i = 0 # Initialize loop variable
  a = [0] * 100006 # Initialize array 'a' of size 100006
  b = [0] * 100006 # Initialize array 'b' of size 100006
  cnt = 0 # Initialize counter for unique elements
  t = 0 # Initialize variable for temporary storage

  scanf("%d %d", &n, &m) # Read number of elements 'n' and queries 'm'

  for(i = 0;i < m;i++) scanf("%d %d", &a[i], &b[i]) # Read elements and their corresponding queries

  quicksort(a,b,m) # Call quicksort function to sort elements

  t = 0 # Initialize counter to 0
  for(i = 0;i < m;i++): # Iterate through sorted elements
    if(t <= a[i]): # If current element is greater than previous element, increment counter
      t = b[i] # Set current query as new temporary storage
      cnt += 1 # Increment counter

  printf("%d\n", cnt) # Print the number of unique queries

  return 0 # Return 0 to indicate successful execution

