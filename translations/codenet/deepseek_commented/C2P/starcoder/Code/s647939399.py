# Step 1: Include the standard input/output library.
import sys

# Step 2: Define the main function.
def main():
  # Step 3: Declare a character variable'm'.
  m = None

  # Step 4: Declare two integers 'a' and 'b', an array 'c' of size 256, and two integer variables 'i' and 'j'.
  a = None
  b = None
  c = [None]*256
  i = None
  j = None

  # Step 5: Start an infinite loop using a 'for' loop with no condition.
  while True:
    # Step 6: Read three inputs: an integer 'a', a character'm', and an integer 'b'.
    a, m, b = map(int, input().split())

    # Step 7: Depending on the character'm', perform the corresponding arithmetic operation and store the result in the array 'c' at index 'i'.
    if m == '?':
      break
    if m == '+':
      c[i] = a + b
    if m == '-':
      c[i] = a - b
    if m == '*':
      c[i] = a * b
    if m == '/':
      c[i] = a / b

    # Step 9: After the loop ends, start another loop to print the results stored in the array 'c' from index 0 to 'i-1'.
    for j in range(i):
      print(c[j])

  # Step 10: Return 0 to indicate successful execution.
  return 0

# Step 11: Call the main function.
if __name__ == "__main__":
  main()

# 