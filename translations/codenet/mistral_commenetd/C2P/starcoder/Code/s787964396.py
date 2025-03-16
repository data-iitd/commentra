#include<stdio.h>
#include<stdlib.h>
#define I 10000

// Main function starts here
def main():
  # Declare pointers 'a' and 'b' of integer type and allocate memory for them
  a = [0] * (I+1)
  b = [0] * (I+1)
  i, max = 0, n

  # Read the number of elements 'n' from the user
  print("Enter the number of elements: ")
  n = int(input())

  # Read elements of array 'a' from the user
  print("Enter %d integers:\n" % n)
  for i in range(n):
    a[i+1] = int(input())
    # Update the maximum element if a new element is greater
    if(a[i+1] > max) max = a[i+1]

  # Call the CountingSort function to sort the array 'a' using counting sort algorithm
  CountingSort(a, b, n)

  # Print the sorted elements of array 'b'
  print(b[1], end = " ")
  for i in range(2, n+1):print(b[i], end = " ")
  print()

  # Main function ends here
  return 0

# Function to perform counting sort algorithm
def CountingSort(a, b, k):
  # Declare an array 'c' of size I to store the count of occurrences of each element
  c = [0] * (I+1)

  # Initialize all elements of array 'c' to zero
  for i in range(I+1):c[i] = 0

  # Count the occurrences of each element in array 'a' and store it in array 'c'
  for j in range(k):c[a[j+1]] += 1

  # Calculate the cumulative sum of all elements in array 'c'
  for i in range(1, I+1):c[i] += c[i-1]

  # Sort the array 'b' by placing each element 'a[j]' at its correct position in array 'b'
  for j in range(k, 0, -1):
    b[c[a[j]]] = a[j]
    c[a[j]] -= 1

# 