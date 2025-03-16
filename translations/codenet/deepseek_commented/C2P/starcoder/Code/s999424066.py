# Step 1: Include the standard input/output library.
import sys
# Step 2: Define the main function.
def main():
  # Step 3: Declare integer variables a, b, c, x, y.
  a = 0
  b = 0
  c = 0
  x = 0
  y = 0
  # Step 4: Read values for a, b, c, x, y from the user.
  a = int(sys.stdin.readline())
  b = int(sys.stdin.readline())
  c = int(sys.stdin.readline())
  x = int(sys.stdin.readline())
  y = int(sys.stdin.readline())
  # Step 5: Double the value of c.
  c *= 2
  # Step 6: Check if the sum of a and b is less than or equal to c.
  if (a + b <= c):
    # Step 7: If true, print the product of a and x plus the product of b and y.
    print(a * x + b * y)
  else:
    # Step 8: If false, start the else block.
    # Step 9: Check if x is less than or equal to y.
    if (x <= y):
      # Step 10: Check if b is less than or equal to c.
      if (b <= c):
        # Step 11: If true, print the product of c and x plus the product of (y-x) and b.
        print(c * x + (y - x) * b)
      else:
        # Step 12: If false, start the else block.
        # Step 13: Print the product of c and y.
        print(c * y)
    else:
      # Step 14: If x is greater than y, start the else block.
      # Step 15: Check if a is less than or equal to c.
      if (a <= c):
        # Step 16: If true, print the product of c and y plus the product of (x-y) and a.
        print(c * y + (x - y) * a)
      else:
        # Step 17: If false, start the else block.
        # Step 18: Print the product of c and x.
        print(c * x)
# Step 19: End the main function and return 0.
if __name__ == "__main__":
  main()
# 