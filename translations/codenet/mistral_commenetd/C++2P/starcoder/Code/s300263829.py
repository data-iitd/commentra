
# Include the iostream library for input and output operations
from sys import stdin, stdout # Use the standard input and output streams for input and output operations

# Declare the main function
def main():
  # Declare two integer variables a and b
  a = int(stdin.readline().rstrip())
  b = int(stdin.readline().rstrip())
  # Read two integers from the standard input and assign them to variables a and b
  # Multiply the values of variables a and b and print the result to the standard output
  stdout.write(str(a * b) + '\n')

# Execute the main function
if __name__ == '__main__':
  main()

