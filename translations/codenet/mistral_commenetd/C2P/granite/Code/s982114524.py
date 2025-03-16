

# The main function is the starting point of the program
def main():
  i = 0 # Initialize i to 0
  N = 0 # Initialize N to 0
  x = 0 # Initialize x to 0

  # Prompt the user to enter a number
  N = int(input("Enter a number: "))

  # Use a for loop to iterate from 1 to N and sum up the numbers
  for i in range(1, N+1):
    x += i # Add the current value of i to x

  # Print the sum of the numbers to the console
  print("The sum of numbers from 1 to", N, "is:", x)

if __name__ == "__main__":
  main()

# 