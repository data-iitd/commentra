
#include<stdio.h>
# Declare variables
int main():
  char m
  int a, b, c[256]
  int i, j

  # Initialize array c with zeros
  for i in range(0, 256):
    c[i] = 0

  # Read input values of a, m, and b from the user
  for i in range(0, 256):
    scanf("%d %c %d",&a, &m, &b)

    # Check if the user has entered '?' to terminate the loop
    if m == '?':
      break

    # Perform arithmetic operations based on the operator m
    if m == '+':
      c[i] = a + b # Store the result of addition in the array c
    if m == '-':
      c[i] = a - b # Store the result of subtraction in the array c
    if m == '*':
      c[i] = a * b # Store the result of multiplication in the array c
    if m == '/':
      c[i] = a / b # Store the result of division in the array c

  # Print the results of the arithmetic operations
  for j in range(0, i):
    printf("%d\n",c[j])

  return(0)

