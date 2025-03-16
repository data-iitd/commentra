# Import the sys module for input operations
import sys

# Read input from the user
s = sys.stdin.readline().strip()  # Read a line of input and remove any trailing whitespace

# Initialize variables to store the positions of 'A' and 'Z'
a, z = -1, -1  # Use -1 to indicate that 'A' or 'Z' has not been found

# The first loop iterates through the string to find the position of the first occurrence of 'A'
for i in range(len(s)):
    if s[i] == 'A':
        a = i  # Assign the position of 'A' to variable 'a' and break the loop
        break

# The second loop iterates through the string in reverse to find the position of the last occurrence of 'Z'
for i in range(len(s) - 1, -1, -1):
    if s[i] == 'Z':
        z = i  # Assign the position of 'Z' to variable 'z' and break the loop
        break

# Calculate the length of the substring between the first 'A' and the last 'Z' and print it
if a != -1 and z != -1:  # Check if both 'A' and 'Z' were found
    print(z - a + 1)
else:
    print(0)  # If either 'A' or 'Z' was not found, print 0

# End of the code
# <END-OF-CODE>
