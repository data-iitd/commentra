
# Import the required libraries
import sys

# Initialize the buffered reader and writer for input and output
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

# Function to scan a single string from input
def scanString():
    return sys.stdin.readline().strip()

# Function to scan a slice of runes from input
def scanRunes():
    return list(scanString())

# Function to scan a single integer from input
def scanInt():
    return int(scanString())

# Function to scan a single int64 from input
def scanInt64():
    return int(scanString())

# Function to scan a single float64 from input
def scanFloat64():
    return float(scanString())

# Function to scan n integers from input and return them as a slice
def scanInts(n):
    return [scanInt() for _ in range(n)]

# Debug function to print messages to stderr
def debug(a):
    print(a, file=sys.stderr)

# Function to return the absolute value of an integer
def abs(a):
    if a < 0:
        return -a
    return a

# Function to return the minimum of two integers
def min(a, b):
    if a < b:
        return a
    return b

# Function to return the maximum of two integers
def max(a, b):
    if a > b:
        return a
    return b

# Main function where the program execution begins
def main():
    # Ensure the buffered writer flushes its content before exiting
    sys.stdout.flush()

    # Set the scanner to split input by whitespace and configure buffer size
    sys.stdin.readline()

    # Read the first string of runes (s)
    s = scanRunes()
    # Read the second string of runes (t)
    t = scanRunes()

    # Initialize a slice to hold possible answers
    ans = []
    
    # Iterate through the first string to find occurrences of the second string
    for i in range(len(s)-len(t)+1):
        f = True # Flag to check if the current position is valid
        ss = list(s) # Create a copy of the original string
        copy(ss, s) # Copy the original string into ss

        # Check if the substring of s can match t
        for j in range(len(t)):
            # If characters do not match and are not '?', set flag to false
            if s[i+j] != t[j] and s[i+j] != '?':
                f = False
                break
            else:
                # Replace '?' with the corresponding character from t
                ss[i+j] = t[j]
        # If the substring matched, replace remaining '?' with 'a' and store the result
        if f:
            ans.append("".join(ss).replace("?", "a"))
    # Sort the possible answers
    ans.sort()

    # Output the result: either the first valid answer or "UNRESTORABLE"
    if len(ans) == 0:
        print("UNRESTORABLE")
    else:
        print(ans[0])

# End of code
