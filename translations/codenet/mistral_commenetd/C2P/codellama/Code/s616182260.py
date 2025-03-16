
#include<stdio.h>
# Declare the required arrays and their sizes
int main():
  a = [0] * 3
  b = [0] * 3
  c = [[0] * 3] * 3
  i, j = 0, 0

  # Initialize the matrix 'c' with user input
  for i in range(3):
    print("Enter the elements of row %d: " % (i+1))
    for j in range(3):
      c[i][j] = int(input())
      # Scan the three elements of each row and store them in the matrix 'c'

  # Initialize array 'a' with the first row of matrix 'c'
  for j in range(3):
    b[j] = c[0][j]
    # Store the elements of the first row of matrix 'c' in array 'b'

  # Initialize array 'a' with the difference between the corresponding elements of matrix 'c' and array 'b'
  for i in range(1, 3):
    a[i] = c[i][0] - b[0]
    # Subtract the first element of each row of matrix 'c' from the corresponding element of array 'b' and store the result in array 'a'

  # Compare each element of matrix 'c' with the corresponding elements of array 'a' and 'b'
  for i in range(3):
    for j in range(3):
      if c[i][j] != a[i] + b[j]:
        # Check if the element at position (i,j) in matrix 'c' is equal to the sum of the elements at position i in array 'a' and j in array 'b'
        print("No")
        # If not, print "No" and exit the program
        return 0

  # If all the elements in matrix 'c' match the condition, print "Yes"
  print("Yes")
  return 0

