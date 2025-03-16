
# Import modules
import sys

# Initialize scanner
sc = sys.stdin

# Function to initialize the scanner
def scanInit():
    # Set buffer capacity
    cap = 1000 * 1024
    # Allocate buffer
    buf = bytearray(cap)
    # Set buffer and capacity for scanner
    sc.buffer(buf, cap)
    # Split input on words
    sc.split(None, 1)

# Function to read an integer from standard input
def nextInt():
    # Read next token
    sc.scan()
    # Convert token to integer
    i = int(sc.token())
    return i

# Function to read a string from standard input
def nextStr():
    # Read next token
    sc.scan()
    # Return token as string
    return sc.token()

# Main function
def main():
    # Initialize scanner
    scanInit()

    # Read the first string from standard input
    s = nextStr()

    # Initialize variable c with 'a'
    c = 'a'

    # Check all characters from 'a' to 'z' in the string s
    for j in range(26):
        # Initialize variable found as false
        found = False

        # Iterate through each character in the string s
        for i in range(len(s)):
            # If current character matches c, set found to true and break the loop
            if s[i] == c:
                found = True
                break

        # If character c is not found in the string s, print it and return
        if found == False:
            print(c)
            return

        # Increment variable c
        c = chr(ord(c) + 1)

    # If no character from 'a' to 'z' is found in the string s, print "None"
    print("None")

# End of code
