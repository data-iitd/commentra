
# Importing necessary packages
import sys
import math

# Constants and variables declaration
inf = 1e14

# Function to read input from standard input
def readline():
    return sys.stdin.readline().strip()

# Function to read an integer from input
def readint():
    return int(readline())

# Function to read an integer64 from input
def readint64():
    return int(readline())

# Function to read a complete line from input
def readlinearr():
    return list(map(int, readline().split()))

# Function to read all lines from input
def readlinesarr():
    lines = []
    for line in sys.stdin.readlines():
        lines.append(list(map(int, line.split())))
    return lines

# Main function
if __name__ == "__main__":
    # Setting up logging
    sys.setrecursionlimit(10**6)

    # Reading input
    n = readint()
    x = readint()

    # Initializing arrays
    a = [0] * n
    v = [0] * n
    copy(v, a)

    # Initializing answer variable
    ans = inf

    # Iterating through all possible subarrays
    for k in range(n):
        # Initializing variable to store sum of subarray elements
        kans = 0

        # Iterating through all elements of the subarray
        for i in range(n):
            # Checking if current index is out of bounds for subarray
            if i-k < 0:
                # Updating current element in subarray with minimum of itself and corresponding element from the main array
                v[i] = min(v[i], a[n+i-k])
            else:
                # Updating current element in subarray with minimum of itself and previous element in subarray
                v[i] = min(v[i], a[i-k])

            # Adding current element to the sum of subarray
            kans += v[i]

        # Updating answer with minimum of current answer and sum of subarray and multiplication of its size and x
        ans = min(ans, kans+k*x)

    # Printing the answer
    print(ans)

# -------------------------------
# Function to check if a given number is inside a given range
def in(c, a, z):
    return c >= a and c < z

# Function to convert boolean value to integer
def btoi(b):
    if b:
        return 1
    return 0

# Function to convert integer value to boolean
def itob(a):
    if a == 0:
        return False
    return True

