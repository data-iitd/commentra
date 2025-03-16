# Import the sys and input function from the standard library
import sys

# Set the standard input to be read from the provided input stream
input = sys.stdin.readline

# Read the number of test cases from the input
n = int(input())

# Initialize an empty list to store the given numbers
w = []

# Read the given numbers and store them in the list
for _ in range(n):
    w.append(int(input().split()[0]))

# Initialize a variable 'c' with a value of 2
c = 2

# Iterate through each number in the list 'w'
for number in w:

    # If the number is equal to 1, print the current value of 'c'
    if number == 1:
        print(c)

    # If the number is even, toggle the value of 'c'
    elif number % 2 == 0:
        c = 3 - c
        print(c)

    # If the number is odd, print the current value of 'c'
    else:
        print(c)
