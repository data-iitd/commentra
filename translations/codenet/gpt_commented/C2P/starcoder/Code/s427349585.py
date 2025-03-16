#include <stdio.h>

# Define a structure to represent a card with a character and an integer value
class card:
  def __init__(self, s, v):
    self.s = s
    self.v = v

# Arrays to hold the left and right halves during merge sort
L = [card(0, 0)] * (100000/2+2)
R = [card(0, 0)] * (100000/2+2)

# Merge function to combine two sorted halves of the array
def me(a, n, l, m, r):
  i, j, k
  n1 = m - l # Size of the left half
  n2 = r - m # Size of the right half

  # Copy data to temporary arrays L and R
  for i in range(n1): L[i] = a[l + i]
  for i in range(n2): R[i] = a[m + i]

  # Sentinel values to avoid out-of-bounds access
  L[n1].v = R[n2].v = 2000000000

  # Merge the temporary arrays back into the original array
  i = 0 # Index for left array
  j = 0 # Index for right array
  for k in range(l, r):
    if L[i].v <= R[j].v:
      a[k] = L[i] # Take from left if it's smaller or equal
      i += 1
    else:
      a[k] = R[j] # Take from right otherwise
      j += 1

# Merge sort function to recursively sort the array
def ms(a, n, l, r):
  m
  if l + 1 < r: # Base case: if the segment has more than one element
    m = (l + r) / 2 # Find the midpoint
    ms(a, n, l, m) # Sort the left half
    ms(a, n, m, r) # Sort the right half
    me(a, n, l, m, r) # Merge the sorted halves

# Partition function for quicksort
def partiton(a, n, p, r):
  i, j
  t, x
  x = a[r] # Choose the last element as the pivot
  i = p - 1 # Index of smaller element
  for j in range(p, r):
    if a[j].v <= x.v: # If current element is smaller than or equal to pivot
      i += 1 # Increment index of smaller element
      # Swap elements
      t = a[i]
      a[i] = a[j]
      a[j] = t
  # Swap the pivot element with the element at i + 1
  t = a[i + 1]
  a[i + 1] = a[r]
  a[r] = t
  return i + 1 # Return the partitioning index

# Quicksort function to recursively sort the array
def qs(a, n, p, r):
  q
  if p < r: # Base case: if the segment has more than one element
    q = partiton(a, n, p, r) # Partition the array
    qs(a, n, p, q - 1) # Recursively sort the left half
    qs(a, n, q + 1, r) # Recursively sort the right half

# Main function
def main():
  n, i, v
  a = [card(0, 0)] * 200000 # Arrays to hold the cards for sorting
  b = [card(0, 0)] * 200000
  s = [0] * 10 # Temporary storage for the character input
  stable = 1 # Flag to check if the sorting is stable

  # Read the number of cards
  n = int(raw_input())

  # Read the cards into both arrays a and b
  for i in range(n):
    s = raw_input().split()
    a[i].s = b[i].s = s[0] # Store the character
    a[i].v = b[i].v = int(s[1]) # Store the value

  # Perform merge sort on array a
  ms(a, n, 0, n)
  # Perform quicksort on array b
  qs(b, n, 0, n - 1)

  # Check if the sorting is stable by comparing the original and sorted arrays
  for i in range(n):
    if a[i].s!= b[i].s:
      stable = 0 # If any character differs, it's not stable

  # Output the stability result
  if stable == 1:
    print "Stable"
  else:
    print "Not stable"

  # Print the sorted array
  for i in range(n):
    print b[i].s, b[i].v

  return 0 # Return success

