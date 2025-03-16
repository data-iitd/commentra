
# Include the standard input/output library
import sys

# The main function is the entry point of the program
def main():
  # Declare variables i, a, b, s of integer type
  i = 0
  a = 0
  b = 0
  s = 0

  # Declare an array count of size 4 to store the count of each number
  count = [0, 0, 0, 0]

  # Initialize the count array with zeros
  for i in range(0, 4):
    count[i] = 0

  # Read three pairs of numbers from the user and update the count array accordingly
  for i in range(0, 3):
    a, b = map(int, input().split()) # Read two numbers a and b from the user
    count[a-1] += 1 # Increment the count of number a in the count array
    count[b-1] += 1 # Increment the count of number b in the count array

  # Calculate the product of all counts in the count array
  s = 1
  for i in range(0, 4):
    s *= count[i]

  # Check if the product of all counts is equal to 4
  if s == 4:
    print("YES") # If yes, print "YES" to the console
  else:
    print("NO") # Else, print "NO" to the console

# Call the main function
if __name__ == "__main__":
  main()

