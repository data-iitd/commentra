import sys

# Read an integer from the input.
def next_int():
    return int(sys.stdin.readline().strip())

# Read a string from the input.
def next_str():
    return sys.stdin.readline().strip()

# Main function that executes the program logic.
def main():
    # Read the input string.
    s = next_str()

    # Initialize the character to check against the string.
    c = 'a'

    # Iterate through the alphabet to find the first missing character.
    while True:
        found = False
        for char in s:
            if char == c:
                found = True
                break
        if not found:
            print(c)
            return
        c = chr(ord(c) + 1)

    # If no missing character is found, print "None".
    print("None")

