
import sys

# Read input string from standard input
z = input()
# Assign size of the string to variable 'a'
a = len(z)

# Check if there are any consecutive identical characters in the string
for i in range(a - 1):
    # Check if current character is same as next character
    if z[i] == z[i + 1]:
        # If yes, print "Bad" and exit the program
        print("Bad")
        sys.exit(0)
# If no consecutive identical characters are found, print "Good"
print("Good")
