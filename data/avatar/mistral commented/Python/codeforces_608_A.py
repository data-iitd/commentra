# Importing the sys and input function from the standard library
import sys

# Assigning the stdin readline function to a variable named input
input = sys.stdin.readline

# Reading the first line of input and storing the number of test cases and the target sum in variables n and s
n, s = map(int, input().split())

# Initializing a variable c to 0
c = 0

# Iterating through the test cases using a for loop
for _ in range(n):
    # Reading the start and end time of each activity from the input
    f, t = map(int, input().split())
    
    # Calculating the difference between the end time and the difference between the target sum and start time
    x = t - (s - f)
    
    # Updating the variable c with the maximum value of x calculated in the current iteration
    if x > c:
        c = x

# Printing the final answer which is the sum of the target sum and the maximum overlap calculated
print(s + c)
