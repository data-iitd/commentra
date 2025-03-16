
# Scanner to read input in a word-by-word manner
sc = input().split()

# Converts a scanned string to an integer
def scanInt():
    return int(sc[0])

# Reads a single word from the input
def scanString():
    return sc[0]

# Reads a slice of integers from input
def scanInts(n):
    sl = []
    for i in range(n):
        sl.append(scanInt())
    return sl

# Reads a slice of strings from input
def scanStrings(n):
    sl = []
    for i in range(n):
        sl.append(scanString())
    return sl

# Initializes the scanner to split input words
def init():
    sc = input().split()

# Main function to execute the program
def main():
    # Read initial values for r, D, and x
    r, D, x = scanInt(), scanInt(), scanInt()
    
    # Loop to calculate and print the values of x for 10 iterations
    for i in range(1, 11):
        x = r*x - D
        print(x)

# END-OF-CODE