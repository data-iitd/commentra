import sys

def scan_init():
    # Initialize the scanner with a large buffer to read input efficiently
    input_text = sys.stdin.read()
    sys.stdin = open(0)
    sys.stdin.write(input_text)
    sys.stdin.seek(0)
    return

def next_int():
    # Read the next integer from the input
    return int(sys.stdin.readline().strip())

def next_str():
    # Read the next string from the input
    return sys.stdin.readline().strip()

def main():
    # Initialize the scanner with a specific buffer size
    scan_init()

    # Read the input string
    s = next_str()

    # Start checking for the first missing lowercase letter from 'a'
    c = 'a'

    # Loop through all lowercase letters from 'a' to 'z'
    for _ in range(26):
        found = False  # Flag to check if the current letter is found in the input string
        # Check if the current letter exists in the input string
        for char in s:
            if char == c:
                found = True  # Set the flag to true if the letter is found
                break
        # If the letter was not found, print it and exit
        if not found:
            print(c)
            return
        c = chr(ord(c) + 1)  # Move to the next letter

    # If all letters from 'a' to 'z' are found, print "None"
    print("None")

main()
