
import sys

# Read a long integer value from the user
a = int(input())

# Read a string value from the user
b = input()

# Initialize an empty string to build the integer representation
bStr = ""

# Loop through each character in the string
for char in b:
    # If the character is not a '.', append it to bStr
    if char!= '.':
        bStr += char

# Convert the built string (bStr) to an integer
bInt = int(bStr)

# Calculate the result by multiplying 'a' with 'bInt' and dividing by 100
result = (a * bInt) // 100

# Print the result to the console
print(result)

