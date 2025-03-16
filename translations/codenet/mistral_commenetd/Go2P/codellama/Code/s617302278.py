
# Importing required packages
import sys

# Function to read a line text from stdin and return its string
def nextLine():
    # Scanning next line from stdin
    sys.stdin.readline()
    # Returning the scanned line text
    return sys.stdin.readline().strip()

# Function to read a line text, that consists of ONLY INTEGERS DELIMITED BY SPACES, from stdin
# And then returns integers slice
def nextIntsLine():
    # Initializing empty integers slice
    ints = []
    # Reading a line text from stdin
    intsStr = nextLine()
    # Splitting the line text by space
    tmp = intsStr.split()
    # Iterating through the split text and converting each string to integer
    # and appending it to the integers slice
    for s in tmp:
        # Converting string to integer
        integer = int(s)
        # Appending integer to integers slice
        ints.append(integer)
    # Returning the integers slice
    return ints

# Function to read a line text, that consists of ONLY CHARACTERS ARRANGED CONTINUOUSLY, from stdin
# And then returns runes slice
def nextRunesLine():
    # Returning the next line text as runes slice
    return list(nextLine())

# Function to find the maximum integer among input integers
# This function needs at least 1 argument (no argument causes panic)
def max(integers):
    # Initializing maximum integer as first integer
    m = integers[0]
    # Iterating through the input integers
    for i, integer in enumerate(integers):
        # If current integer is greater than maximum integer, update maximum integer
        if i == 0:
            continue
        if m < integer:
            m = integer
    # Returning the maximum integer
    return m

# Function to find the minimum integer among input integers
# This function needs at least 1 argument (no argument causes panic)
def min(integers):
    # Initializing minimum integer as first integer
    m = integers[0]
    # Iterating through the input integers
    for i, integer in enumerate(integers):
        # If current integer is smaller than minimum integer, update minimum integer
        if i == 0:
            continue
        if m > integer:
            m = integer
    # Returning the minimum integer
    return m

# Function to calculate integer power
def powInt(a, e):
    # Checking for negative integers
    if a < 0 or e < 0:
        raise ValueError("[argument error]: PowInt does not accept negative integers")
    # Converting base and exponent to float64
    fa = float(a)
    fe = float(e)
    # Calculating the power using math.Pow
    fanswer = math.pow(fa, fe)
    # Converting the answer back to integer
    return int(fanswer)

# Function to calculate absolute value of an integer
def absInt(a):
    # Converting integer to float64
    fa = float(a)
    # Calculating the absolute value using math.Abs
    fanswer = math.fabs(fa)
    # Converting the answer back to integer
    return int(fanswer)

# Function to delete an element from a slice
def deleteElement(s, i):
    # Checking for negative index or empty slice
    if i < 0 or len(s) <= i:
        raise IndexError("[index error]")
    # Creating a new slice with zero capacity
    n = []
    # Appending elements before the index to the new slice
    n.extend(s[:i])
    # Appending elements after the index to the new slice
    n.extend(s[i+1:])
    # Returning the new slice
    return n

# Function to concatenate two slices
def concat(s, t):
    # Creating a new slice with zero capacity
    n = []
    # Appending elements of the first slice to the new slice
    n.extend(s)
    # Appending elements of the second slice to the new slice
    n.extend(t)
    # Returning the new slice
    return n

# Variable declaration and initialization
x = 0

# Main function
def main():
    # Reading integers from stdin as a line text
    tmp = nextIntsLine()
    # Assigning the first integer to variable x
    x = tmp[0]
    # Initializing sum variable as zero
    sum = 0
    # Initializing index variable as one
    i = 1
    # Looping until the sum is greater than or equal to x
    while True:
        # Adding current index to sum
        sum += i
        # Checking if sum is greater than or equal to x
        if sum >= x:
            # Breaking the loop
            break
        # Incrementing index
        i += 1
    # Printing the index
    print(i)


