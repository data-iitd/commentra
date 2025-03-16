import math  # Importing the math module for mathematical operations (though not used in this code)

# Read the number of elements (not used directly in the code)
N = input()

# Read a line of input, split it into individual strings, convert them to integers, and store them in a list
XS = [int(i) for i in input().split()]

# Initialize a variable 'm' to a very large number to find the minimum later
m = 9999999999

# Iterate through possible values of 'i' from 1 to 100
for i in range(1, 101):
    # Calculate the sum of squared differences between each element in XS and the current value of 'i'
    c = sum([(x - i) ** 2 for x in XS])
    
    # If the calculated sum 'c' is less than the current minimum 'm', update 'm' with the new minimum
    if m > c:
        m = c

# Print the minimum sum of squared differences found
print(m)
