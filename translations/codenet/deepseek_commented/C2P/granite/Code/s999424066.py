
# Step 1: Import the standard input/output library.
import sys  # Step 2: Define the main function.
def main():  # Step 3: Declare integer variables a, b, c, x, y.
  a, b, c, x, y = map(int, sys.stdin.readline().split())  # Step 4: Read values for a, b, c, x, y from the user.
  c *= 2  # Step 5: Double the value of c.
  if a + b <= c:  # Step 6: Check if the sum of a and b is less than or equal to c.
    print(a * x + b * y)  # Step 7: If true, print the product of a and x plus the product of b and y.
  else:  # Step 8: If false, start the else block.
    if x <= y:  # Step 9: Check if x is less than or equal to y.
      if b <= c:  # Step 10: Check if b is less than or equal to c.
        print(c * x + (y - x) * b)  # Step 11: If true, print the product of c and x plus the product of (y-x) and b.
      else:  # Step 12: If false, start the else block.
        print(c * y)  # Step 13: Print the product of c and y.
    else:  # Step 14: If x is greater than y, start the else block.
      if a <= c:  # Step 15: Check if a is less than or equal to c.
        print(c * y + (x - y) * a)  # Step 16: If true, print the product of c and y plus the product of (x-y) and a.
      else:  # Step 17: If false, start the else block.
        print(c * x)  # Step 18: Print the product of c and x.
  return 0  # Step 19: End the main function and return 0.

if __name__ == '__main__':  # Step 20: Call the main function if the script is run directly.
  main()

