#include <iostream>
#include <string>

# Function to check certain conditions based on input values x and y
def check(x, y):
    # Check if y is an even number
    if y % 2 == 0:
        # Calculate t as half of y minus x
        t = (int)(0.5*y) - x
        
        # Check if t is non-negative and if (x - t) is also non-negative
        if t >= 0 and (x-t) >= 0:
            return "Yes" # Return "Yes" if both conditions are satisfied
    return "No" # Return "No" if y is odd or conditions are not satisfied

# Read input values for x and y
x, y = input().split()

# Call the check function and print the result
print(check(int(x), int(y)))

# 