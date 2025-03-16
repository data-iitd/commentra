
#include<stdio.h> // Standard Input/Output Library
#include<stdlib.h> // Standard Library
#include<string.h> // String Library
#include<math.h> // Mathematical Library

#define MAX 200000

// Function to partition the array using quicksort algorithm
def part(a,b,l,r):
  i = l - 1; # Initialize index 'i' for smaller elements
  j = r; # Initialize index 'j' for greater elements

  x = b[r]; # Set pivot as last element

  while(1): # While loop for partitioning
    while(b[++i] < x): # Move 'i' to next smaller element
    while(i < --j and x < b[j]): # Move 'j' to previous greater element

    if(i >= j): break; # If 'i' and 'j' meet, partitioning is done

    t = a[i]; a[i] = a[j]; a[j] = t; # Swap elements in 'a' array
    t = b[i]; b[i] = b[j]; b[j] = t; # Swap elements in 'b' array
  }

  t = a[i]; a[i] = a[r]; a[r] = t; # Swap pivot with last element in 'a' array
  t = b[i]; b[i] = b[r]; b[r] = t; # Swap pivot with last element in 'b' array
  return i; # Return index of pivot

# Function to perform quicksort on the array 'a'
def quicksort(a,b,n):
  l = 0; # Initialize base index 'l'
  r = n - 1; # Initialize top index 'r'
  v = 0; # Initialize variable for partitioning index
  sp = 0; # Initialize stack pointer

  low[sp] = l; # Initialize 'low' stack with base index 'l'
  high[sp] = r; # Initialize 'high' stack with top index 'r'
  sp++; # Increment stack pointer

  while(sp > 0): # While stack is not empty
    sp--; # Decrement stack pointer
    l = low[sp]; # Get base index 'l' from stack
    r = high[sp]; # Get top index 'r' from stack

    if(l >= r): # If base and top indices are same, no need to partition
      continue; # Skip this iteration
    v = part(a,b,l,r); # Partition the array

    if(v - l < r - v): # If partitioning moved pivot to left, swap 'low' and 'high' indices
      low[sp] = v + 1;
      high[sp++] = r;
      low[sp] = l;
      high[sp++] = v - 1;
    else: # If partitioning moved pivot to right, swap 'low' and 'high' indices in reverse order
      low[sp] = l;
      high[sp++] = v - 1;
      low[sp] = v + 1;
      high[sp++] = r;
  }

# Main function to read input and call quicksort
def main():
  n,m; # Initialize variables
  i; # Initialize loop variable
  a = [0] * MAX; # Initialize array 'a' of size 100006
  b = [0] * MAX; # Initialize array 'b' of size 100006
  cnt = 0; # Initialize counter for unique elements
  t; # Initialize variable for temporary storage

  scanf("%d %d", &n, &m); # Read number of elements 'n' and queries'm'

  for(i = 0;i < m;i++) scanf("%d %d", &a[i], &b[i]); # Read elements and their corresponding queries

  quicksort(a,b,m); # Call quicksort function to sort elements

  t = 0; # Initialize counter to 0
  for(i = 0;i < m;i++){ # Iterate through sorted elements
    if(t <= a[i]): # If current element is greater than previous element, increment counter
      t = b[i]; # Set current query as new temporary storage
      cnt++; # Increment counter
  }

  printf("%d\n", cnt); # Print the number of unique queries

  return 0; # Return 0 to indicate successful execution
}

