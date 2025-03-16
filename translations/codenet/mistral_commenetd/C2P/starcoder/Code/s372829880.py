
# Declare the main function
def main():
  # Declare and initialize two integer variables, x and a
  x = 0
  a = 0

  # Read data from the standard input stream and store it into x and a
  x, a = map(int, input().split())

  # Check if x is greater than or equal to a
  result = (x >= a)

  # Multiply the result by 10
  result *= 10

  # Print the result to the standard output stream
  print(result)

# Call the main function
if __name__ == "__main__":
  main()

