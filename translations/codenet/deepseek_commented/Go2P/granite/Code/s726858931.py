

import sys

# Initializes the scanner to read from standard input efficiently.
def scanInit():
    sys.stdin = open("input.txt", "r")

# Reads an integer from the input.
def nextInt():
    return int(input())

# Reads a string from the input.
def nextStr():
    return input()

# Main function that executes the program logic.
def main():
    scanInit()

    # Read the input string.
    s = nextStr()

    # Initialize the character to check against the string.
    c = 'a'

    # Iterate through the alphabet to find the first missing character.
    for j in range(26):
        found = False
        for i in range(len(s)):
            if s[i] == c:
                found = True
                break
        if found == False:
            print(c)
            return
        c = chr(ord(c) + 1)

    # If no missing character is found, print "None".
    print("None")

