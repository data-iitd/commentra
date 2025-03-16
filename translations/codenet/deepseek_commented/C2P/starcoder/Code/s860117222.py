# Include the standard input/output library
import sys

# Define the main function
def main():
  # Read three long long integers from the user
  a = int(sys.stdin.readline())
  b = int(sys.stdin.readline())
  c = int(sys.stdin.readline())

  # Calculate the difference between c and the sum of a and b
  d = c - (a + b)

  # Check if the difference is positive and satisfies the specific condition
  if (d > 0) and ((4 * a * b) < d * d):
    # Print "Yes" if the condition is met
    print("Yes")
  else:
    # Print "No" otherwise
    print("No")

# Call the main function
if __name__ == "__main__":
  main()

