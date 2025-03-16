#include<stdio.h>  # Step 1: Include the standard input/output library.

def main():  # Step 2: Define the main function.
  m = ''  # Step 3: Declare a character variable 'm'.
  a, b, c = [], 0, 0  # Declare two integers 'a' and 'b', an array 'c' of size 256, and two integer variables 'i' and 'j'.

  while True:  # Step 4: Start an infinite loop using a 'while' loop with no condition.
    a, m, b = input().split()  # Step 5: Read three inputs: an integer 'a', a character 'm', and an integer 'b'.
    if m == '?':  # Step 6: Check if the character 'm' is '?'. If true, break the loop.
      break
    if m == '+':  # Step 7: Depending on the character 'm', perform the corresponding arithmetic operation and store the result in the array 'c' at index 'i'.
      c.append(int(a) + int(b))
    if m == '-':
      c.append(int(a) - int(b))
    if m == '*':
      c.append(int(a) * int(b))
    if m == '/':
      c.append(int(a) / int(b))

  for j in range(len(c)):  # Step 9: After the loop ends, start another loop to print the results stored in the array 'c' from index 0 to 'i-1'.
    print(c[j])

main()  # Step 10: Return 0 to indicate successful execution.

