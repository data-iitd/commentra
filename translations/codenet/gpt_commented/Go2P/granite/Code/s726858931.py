
import sys

# Initialize a new scanner to read input from standard input
sc = bufio.Scanner(sys.stdin)

def main():
    # Initialize the scanner with a specific buffer size
    scanInit()

    # Read the input string
    s = nextStr()

    # Start checking for the first missing lowercase letter from 'a'
    c = 'a'

    # Loop through all lowercase letters from 'a' to 'z'
    for j in range(26):
        found = False # Flag to check if the current letter is found in the input string
        # Check if the current letter exists in the input string
        for i in range(len(s)):
            if s[i] == c:
                found = True # Set the flag to true if the letter is found
                break
        # If the letter was not found, print it and exit
        if found == False:
            print(c)
            return
        c = chr(ord(c) + 1) # Move to the next letter

    # If all letters from 'a' to 'z' are found, print "None"
    print("None")

# ---- readfunc

# scanInit initializes the scanner with a large buffer to read input efficiently
def scanInit():
    const cap = 1000 * 1024 # Define the buffer capacity
    buf = bytearray(cap) # Create a buffer of the specified capacity
    sc.buffer = buf # Set the scanner's buffer
    sc.buffer_size = cap # Set the scanner's buffer size
    sc.bytes_read = 0 # Reset the bytes read counter
    sc.bytes_to_read = cap # Set the bytes to read
    sc.token_len = 0 # Reset the token length
    sc.token_start = 0 # Reset the token start position
    return

# nextInt reads the next integer from the input
def nextInt():
    sc.scan() # Scan the next token
    i = int(sc.token()) # Convert the scanned token to an integer
    return i # Return the integer

# nextStr reads the next string from the input
def nextStr():
    sc.scan() # Scan the next token
    return sc.token().decode() # Return the scanned token as a string

