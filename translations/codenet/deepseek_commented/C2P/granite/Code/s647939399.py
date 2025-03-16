
# Step 1: Import the standard input/output library.
import sys

# Step 2: Define the main function.
def main():
  # Step 3: Declare a character variable'm'.
  m = ""
  # Step 4: Start an infinite loop using a 'for' loop with no condition.
  while True:
    # Step 5: Read three inputs: an integer 'a', a character'm', and an integer 'b'.
    a, m, b = sys.stdin.readline().split()
    a = int(a)
    b = int(b)
    # Step 6: Check if the character'm' is '?'. If true, break the loop.
    if m == "?":
      break
    # Step 7: Depending on the character'm', perform the corresponding arithmetic operation and store the result in the array 'c' at index 'i'.
    if m == "+":
      c[i] = a + b
    if m == "-":
      c[i] = a - b
    if m == "*":
      c[i] = a * b
    if m == "/":
      c[i] = a / b
  # Step 9: After the loop ends, start another loop to print the results stored in the array 'c' from index 0 to 'i-1'.
  for j in range(i):
    # Step 10: Return 0 to indicate successful execution.
    print(c[j])

# Step 11: Call the main function.
if __name__ == "__main__":
  main()

