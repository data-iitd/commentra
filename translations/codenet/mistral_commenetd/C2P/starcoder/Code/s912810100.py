
# Include the standard input/output library
import sys

# Start of the main function
def main():
  # Declare variables a, b, x, and y as integers
  a = 0
  b = 0
  x = 0
  y = 0

  # Read two integers from the standard input and store them in variables a and b
  a = int(sys.stdin.readline())
  b = int(sys.stdin.readline())

  # Multiply the values of variables a and b and store the result in variable x
  x = a*b

  # Add the values of variables a and b, then multiply the result by 2 and store it in variable y
  y = (a+b)*2

  # Print the values of variables x and y to the standard output, followed by a newline character
  print(x, y)

# Indicate that the main function has executed successfully
if __name__ == "__main__":
  main()

