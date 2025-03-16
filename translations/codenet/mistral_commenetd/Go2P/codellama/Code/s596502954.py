
# Initialize a new scanner for reading input from stdin
sc = input().split()

# Function to read a single word as a string from the input
def next():
    return sc[0]
    # Comment: Returns the first word from the scanner

# Function to read an integer from the input
def nextInt():
    return int(sc[0])
    # Comment: Converts the first word to an integer and returns it

# Function to read a float64 from the input
def nextFloat64():
    return float(sc[0])
    # Comment: Converts the first word to a float64 and returns it

# Function to read n integers from the input and return as a slice
def nextInts(n):
    slice = []
    # Comment: Creates a slice of size n and initializes it with zero values
    for i in range(n):
        slice.append(int(sc[0]))
        # Comment: Reads the next integer from the input and assigns it to the current index of the slice
    return slice

# Main function
def main():
    # Comment: Sets the scanner to scan words instead of lines
    sc = input().split()

    # Read the first three integers from the input
    a = nextInt()
    b = nextInt()
    c = nextInt()

    # Check if the condition is true
    if a+b >= c:
        # If true, print "Yes" to the output
        print("Yes")
    else:
        # If false, print "No" to the output
        print("No")

    # End of code
   

