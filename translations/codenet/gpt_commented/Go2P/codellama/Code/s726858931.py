
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
    sc.buffer(buf, cap) # Set the scanner's buffer
    sc.split(bufio.ScanWords) # Split the input by words
    return

# nextInt reads the next integer from the input
def nextInt():
    sc.scan() # Scan the next token
    i, e = strconv.atoi(sc.text()) # Convert the scanned text to an integer
    if e != None:
        panic(e) # Panic if there is an error during conversion
    return i # Return the integer

# nextStr reads the next string from the input
def nextStr():
    sc.scan() # Scan the next token
    return sc.text() # Return the scanned text as a string

