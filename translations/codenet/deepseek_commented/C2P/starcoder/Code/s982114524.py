# Include the standard input/output library
import sys

# Define the main function
def main():
  # Declare integer variables
  N = 0
  x = 0

  # Read input from the user and store it in N
  N = int(input())

  # Loop through numbers from 1 to N
  for i in range(1, N+1):
    # Add each number to x
    x += i

  # Print the final value of x
  print(x)

# Call the main function
if __name__ == "__main__":
  main()

