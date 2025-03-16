# Import necessary modules
import sys

# Function to read an integer from standard input
def next_int():
    return int(sys.stdin.readline().strip())

# Function to read a string from standard input
def next_str():
    return sys.stdin.readline().strip()

# Main function
def main():
    # Read the first string from standard input
    s = next_str()

    # Initialize variable c with 'a'
    c = ord('a')

    # Check all characters from 'a' to 'z' in the string s
    for j in range(26):
        # Initialize variable found as False
        found = False

        # Iterate through each character in the string s
        for char in s:
            # If current character matches c, set found to True and break the loop
            if ord(char) == c:
                found = True
                break

        # If character c is not found in the string s, print it and return
        if not found:
            print(chr(c))
            return

        # Increment variable c
        c += 1

    # If no character from 'a' to 'z' is found in the string s, print "None"
    print("None")

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
