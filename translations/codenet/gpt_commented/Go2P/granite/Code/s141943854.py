
import sys

# Read the first line of input.
sage = sys.stdin.readline().strip()

# Use a switch statement to handle different cases based on the input value.
if sage == "1":
    # If the input is "1", print "Hello World".
    print("Hello World")
elif sage == "2":
    # If the input is "2", initialize a variable to hold the sum of two numbers.
    sum = 0
    # Loop to read two numbers from input.
    for i in range(2):
        num = int(sys.stdin.readline().strip()) # Convert the input string to an integer.
        sum += num # Add the number to the sum.
    # Print the total sum of the two numbers.
    print(sum)

