#include<stdio.h>

int main():
  A = [100] # An array of integers with a maximum size of 100
  n = 0 # The number of elements in the array
  i, j, t, sw = 0, mini = 0 # Variables used in the sorting algorithm

  print("Enter the number of elements: ")
  scanf("%d", &n) # Read the number of elements from the standard input

  print("Enter %d integers:\n", n)
  for i in range(n): # Read %d integers from the standard input and store them in the array A
    scanf("%d", &A[i])

  print("Sorting the array using Selection Sort algorithm:\n")
  for i in range(n): # The outer loop runs n times
    mini = i # Initialize mini as i
    for j in range(i, n): # The inner loop finds the minimum element in the unsorted part of the array
      if A[j] < A[mini]: # If A[j] is smaller than A[mini], update mini
        mini = j

    t = A[i] # Swap A[i] with the minimum element
    A[i] = A[mini]
    A[mini] = t

    if i != mini: sw += 1 # Increment sw only if a swap is made

  print("Sorted array: ")
  for i in range(n): # Print the sorted array to the standard output
    if i: print(" ", end="")
    print(A[i], end="")
  print()

  print("Number of swaps: %d\n", sw)

  return 0

