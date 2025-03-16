
# Import the math library
import math

# Read an integer value from the standard input
n = int(input())

# Start a for loop that iterates from 1 to n
for i in range(1,n+1):
  x = i # Assign the value of i to variable x
  s = str(x) # Convert integer x to string s

  # Check if x is divisible by 3 or its last digit is 3
  if (x % 3 == 0 or x % 10 == 3):
    print(" " + str(i), end="") # If true, print space followed by i
    continue # Skip the rest of the loop body and move to the next iteration
  else:
    # If x is not divisible by 3 and its last digit is not 3
    k = len(s) # Get the size of string s

    # Start a while loop that runs as long as the size of string s is greater than 0
    while (k > 0):
      k = k - 1 # Decrease the size of string s by 1
      j = math.pow(10,k) # Calculate the value of the power of 10 raised to the power of the current digit position

      # Check if the digit in the current position of x is 3
      if ((x / j) % 10 == 3):
        print(" " + str(i), end="") # If true, print space followed by i
        break # Exit the while loop and move to the next iteration of the for loop

print() # Print a newline character after the loop is finished

# 