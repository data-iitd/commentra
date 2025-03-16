#include<stdio.h>
#include<stdlib.h>

#define I 10000 // Define a constant I with the value 10000

# Function to perform Counting Sort
def CountingSort(a, b, k):
  c = [0] * (I + 1)
  for j in range(k):
    c[a[j + 1]] += 1
  for i in range(1, I + 1):
    c[i] += c[i - 1]
  for j in range(k, 0, -1):
    b[c[a[j]]] = a[j]
    c[a[j]] -= 1

# Main function
def main():
  a, b, i, max, n = 0, 0, 0, 0, 0
  
  # Read the number of elements
  n = int(input())
  
  # Dynamically allocate memory for arrays a and b
  a = [0] * (n + 1)
  b = [0] * (n + 1)
  
  # Read elements into array a starting from index 1 to n
  for i in range(n):
    a[i + 1] = int(input())
  
  # Call CountingSort function to sort the array
  CountingSort(a, b, n)
  
  # Print the sorted elements starting from index 1 to n
  print(b[1], end = " ")
  for i in range(2, n + 1):
    print(b[i], end = " ")
  print()
  
  # Free the allocated memory
  del a
  del b
  
  return 0

