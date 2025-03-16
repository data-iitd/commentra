
import sys

# Initialize a new scanner to read input from standard input
sc = sys.stdin

# next reads the next line of input and returns it as a string
def next():
    return sc.readline().strip()

# nextInt reads the next line of input, converts it to an integer, and returns it
def nextInt():
    return int(next())

# nextFloat64 reads the next line of input, converts it to a float64, and returns it
def nextFloat64():
    return float(next())

# nextInts reads 'n' integers from input and returns them as a slice
def nextInts(n):
    slice = []
    for i in range(n):
        slice.append(nextInt())
    return slice

# Read two integers, sum them, and compare the result with a third integer
if nextInt() + nextInt() >= nextInt():
    print("Yes")
else:
    print("No")

