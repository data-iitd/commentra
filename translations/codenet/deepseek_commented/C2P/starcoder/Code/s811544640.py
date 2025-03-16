# Step 1: Include necessary headers
import sys

# Step 2: Define the main function
def main():
  # Step 3: Declare variables
  a = 0
  b = 0
  c = 0

  # Step 4: Read input values
  a = int(sys.stdin.readline())
  b = int(sys.stdin.readline())
  c = int(sys.stdin.readline())

  # Step 5: Implement the if-else condition
  if b > a * c:
    print(c)
  else:
    print(b / a)

  # Step 6: Return 0 to indicate successful execution
  return 0

# Step 7: Call the main function
if __name__ == "__main__":
  main()

