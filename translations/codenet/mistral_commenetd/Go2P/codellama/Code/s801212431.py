
# Initialize scanner
sc = bufio.Scanner(sys.stdin)

# Initialize buffer with initial size
buf = make([]byte, initialBufSize)

# Set maximum buffer size
sc.Buffer(buf, maxBufSize)

# Set scanner to scan words
sc.Split(bufio.ScanWords)

# Function to read next token as a string
def next():
    sc.Scan() # Scan next token
    return sc.Text() # Return token as string

# Function to find minimum of two integers
def min(x, y):
    # If x is greater than y, return y
    if x > y:
        return y
    else:
        # Otherwise, return x
        return x

# Main function
def main():
    # Read input string S
    S = next()

    # Initialize variables l0 and l1 to store count of '0' and '1' respectively
    l0, l1 = 0, 0

    # Iterate through each character in string S
    for i in range(len(S)):
        # If current character is '0', increment l0
        if S[i] == '0':
            l0 += 1
        else:
            # Otherwise, increment l1
            l1 += 1

    # Print result which is twice the minimum of l0 and l1
    print(2 * min(l0, l1))

# 