
#=====I/O=====

# Declare scanner and writer for input and output
sc = input
wr = print

# Function to scan an integer from input
def scanInt():
    return int(sc())

# Function to scan a 64-bit integer from input
def scanInt64():
    return int(sc())

# Function to scan multiple integers from input
def scanInts(n):
    return [int(sc()) for i in range(n)]

# Function to scan a single line of text from input
def scanText():
    return sc()

# Function to print integers to output
def printInts(*a):
    for i, e in enumerate(a):
        wr(e)
        if i != len(a)-1:
            wr(" ")
    wr("\n")

#=====main=====

# Main function where execution starts
def main():
    sc.split(" ") # Set the scanner to split input by words

    n = scanInt() # Read the number of integers

    c = scanInts(n) # Read n integers into slice c

    ans = 0 # Initialize answer variable
    c.sort() # Sort the slice of integers

    # Calculate the answer based on the sorted integers
    for i in range(n):
        ans = (ans + (n+1-i)*c[i]%mod) % mod # Update the answer using the formula

    # Print the final result after applying modular exponentiation
    wr(ans * modpow(4, n-1) % mod)

# Function to perform modular exponentiation
def modpow(a, n):
    res = 1 # Initialize result
    while n > 0:
        if n&1 == 1: # If n is odd
            res = res * a % mod # Update result
        a = a * a % mod # Square the base
        n = n >> 1 # Divide n by 2
    return res # Return the final result

# Define a constant for the modulus
mod = 1000000007

# Print the final result after applying modular exponentiation
wr(ans * modpow(4, n-1) % mod)

