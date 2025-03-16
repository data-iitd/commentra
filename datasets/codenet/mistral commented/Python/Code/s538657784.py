# Import the math module for square root calculation
import math

# Take an integer input from the user and assign it to the variable N
N = int(input())

# Calculate the square root of N and assign the integer part of the result to the variable sqN
sqN = int(math.sqrt(N))

# Initialize the loop variable i to 0
for i in range(sqN):
  # Check if N is divisible by sqN-i
  if N % (sqN-i) == 0:
    # Calculate and print the number of rows in the square pyramid
    print(int(N/(sqN-i)+sqN-i)-2)
    # Break the loop if the condition is met
    break
