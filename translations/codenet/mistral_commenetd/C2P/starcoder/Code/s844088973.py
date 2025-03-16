
# Include the standard input/output library
import sys

# Start of the main function
def main():
  # Declare two integer variables K and X
  K = 0
  X = 0

  # Read two integers from the standard input and store them in variables K and X
  K = int(sys.stdin.readline())
  X = int(sys.stdin.readline())

  # Start of the for loop
  for i in range(X-K+1,X+K):
    # Print the current value of i to the standard output
    print(i, end=' ')

  # Print a newline character to move the cursor to the next line
  print()

# End of the main function with a successful return status
if __name__ == "__main__":
  main()

