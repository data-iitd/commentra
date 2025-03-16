
#include <stdio.h>

# Define a custom data structure 'card' with a character and an integer.
typedef struct {
  char s;
  int v;
} card;

# Allocate memory for two arrays L and R, each with size (n+2), where n is the number of input cards.
L = [None] * (100000/2+2)
R = [None] * (100000/2+2)

# Function 'me' sorts a subarray of 'a' using merge sort algorithm.
def me(a,n,l,m,r):
  i,j,k = 0,0,0
  n1 = m-l # Number of elements to be copied to L array.
  n2=r-m # Number of elements to be copied to R array.

  # Copy elements from 'a' to L and R arrays.
  for i in range(n1):
    L[i]=a[l +i]
  for i in range(n2):
    R[i]=a[m +i]

  # Set the last elements of L and R arrays with a large value to mark the end of each array.
  L[n1].v=R[n2].v=2000000000

  # Merge sorted subarrays L and R back to 'a'.
  i=0
  j=0
  for k in range(l,r):
    # Compare elements from L and R arrays and copy smaller one to 'a'.
    if L[i].v<=R[j].v:
      a[k]=L[i]
      i+=1
    else:
      a[k]=R[j]
      j+=1

# Recursive function 'ms' to merge sort the entire array 'a'.
def ms(a , n, l,r):
  m = (l+r)/2 # Calculate the middle index 'm' of the subarray.
  # Recursively sort left and right subarrays and then merge them.
  ms(a,n,l,m)
  ms(a,n,m,r)
  # Merge sorted subarrays.
  me(a,n,l,m,r)

# Function 'partiton' partitions an array into two parts: one with elements smaller than 'x' and another with elements greater than or equal to 'x'.
def partiton(a,n,p,r):
  i,j = 0,0
  x = a[r] # Set 'x' as the last element of the array.
  i = p-1 # Index of the last element in the left subarray.

  # Iterate through the array from index p to r-1 and swap elements if they are smaller than 'x'.
  for j in range(p,r):
    if a[j].v<=x.v:
      i+=1 # Increment index of the last element in the left subarray.
      t = a[i] # Swap elements a[i] and a[j].
      a[i]=a[j]
      a[j]=t
  # Swap the last elements of the left and right subarrays.
  t = a[i+1]
  a[i+1]=a[r]
  a[r]=t
  # Return the index 'i+1' as the pivot index.
  return i+1

# Function 'qs' implements quicksort algorithm to sort the array 'a'.
def qs(a,n,p,r):
  q = 0
  # Base case: if the subarray has only one element, it is already sorted.
  if p<r:
    # Partition the array into two parts using 'partiton' function.
    q = partiton(a,n,p,r)
    # Recursively sort the left and right subarrays.
    qs(a,n,p,q-1)
    qs(a,n,q+1,r)

# Main function to read input, sort the array using merge sort and quicksort, and print the sorted array.
def main():
  n,i,v = 0,0,0
  a = [None] * 200000
  b = [None] * 200000
  s = ""
  stable = 1

  # Read the number of input cards 'n'.
  n = int(input())

  # Read input cards and initialize 'a' and 'b' arrays.
  for i in range(n):
    s,v = input().split()
    a[i].s = b[i].s = s[0] # Set the character part of 'a' and 'b' equal to the first character of the input string.
    a[i].v = b[i].v = int(v) # Set the integer part of 'a' and 'b' equal to the integer value of the input card.

  # Merge sort the 'a' array.
  ms(a,n,0,n)

  # Quick sort the 'b' array.
  qs(b,n,0,n-1)

  # Compare 'a' and 'b' arrays to check stability.
  for i in range(n):
    if a[i].s!=b[i].s:
      stable = 0

  # Print the result and the sorted array 'b'.
  if stable==1:
    print("Stable\n")
  else:
    print("Not stable\n")
  # Print the sorted array 'b'.
  for i in range(n):
    print(b[i].s,b[i].v)

if __name__ == "__main__":
  main()

