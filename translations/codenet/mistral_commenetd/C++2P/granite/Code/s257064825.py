
# Initialize I/O streams
import sys

# Read input string from standard input
str = input()

# Initialize sum variable to 0
sum = 0

# Iterate through each character in the string and add its ASCII value (after converting to digit) to sum
for x in str:
    sum += ord(x) - 48

# Check if sum is divisible by 9
if sum % 9 == 0:
    print("Yes") # Output "Yes" if sum is divisible by 9
else:
    print("No") # Output "No" otherwise

