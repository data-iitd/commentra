
# Initialize a new scanner to read input from standard input
sc = input()

# Scanner function reads a line of input and returns it as a string
def Scanner():
    return sc

# intScanner function reads an integer from input and returns it
def intScanner():
    return int(Scanner())

# floatScanner function reads a float64 from input and returns it
def floatScanner():
    return float(Scanner())

# stringToInt converts a string to an integer
def stringToInt(s):
    return int(s)

# Declare a variable for the modulus value
mod = 1000000007

# Create a buffer for the scanner with a size limit defined by mod
buf = []

# Set the scanner to split input by whitespace
sc.split()

# Read the number of elements
n = intScanner()

# Initialize a slice to hold the integers
as = []

# Read n integers from input
for i in range(n):
    as.append(intScanner())

# Initialize a slice to hold the unique sorted integers
xs = [as[0]]

# Iterate through the input integers starting from the second element
for j in range(1, n):
    # Use binary search to find the position to insert the current integer
    idx = bisect.bisect(xs, as[j])
    
    # If the index is equal to the length of xs, append the integer
    if idx == len(xs):
        xs.append(as[j])
    else:
        # Otherwise, replace the existing integer at the found index
        xs[idx] = as[j]

# Print the number of unique integers found
print(len(xs))

