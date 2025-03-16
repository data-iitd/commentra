# Define a function to check the string
def check_string(z):
    # Get the size of the input string
    a = len(z)
    
    # Check for consecutive identical characters in the string
    for i in range(a - 1):
        # If two consecutive characters are the same, return "Bad"
        if z[i] == z[i + 1]:
            return "Bad"
    
    # If no consecutive identical characters were found, return "Good"
    return "Good"

# Optimize input/output operations
import sys
input = sys.stdin.read

# Read the input string
z = input().strip()

# Call the function and print the result
print(check_string(z))

# <END-OF-CODE>
