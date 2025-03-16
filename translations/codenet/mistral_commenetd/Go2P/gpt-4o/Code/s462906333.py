# Importing necessary packages
import sys

# Constants and variables declaration
inf = int(1e14)

# Function to read input from standard input
class Scanner:
    def __init__(self):
        self.buffer = sys.stdin.read().splitlines()
        self.index = 0

    def next(self):
        if self.index < len(self.buffer):
            token = self.buffer[self.index].split()
            self.index += 1
            return token
        return []

    def int(self):
        return int(self.next()[0])

# Main function
def main():
    # Creating a new scanner object
    next = Scanner()

    # Reading input
    n = next.int()
    x = next.int()

    # Initializing arrays
    a = [0] * n
    v = [0] * n

    # Initializing answer variable
    ans = inf

    # Iterating through all possible subarrays
    for k in range(n):
        # Initializing variable to store sum of subarray elements
        kans = 0

        # Iterating through all elements of the subarray
        for i in range(n):
            # Checking if current index is out of bounds for subarray
            if i - k < 0:
                # Updating current element in subarray with minimum of itself and corresponding element from the main array
                v[i] = min(v[i], a[n + i - k])
            else:
                # Updating current element in subarray with minimum of itself and previous element in subarray
                v[i] = min(v[i], a[i - k])

            # Adding current element to the sum of subarray
            kans += v[i]

        # Updating answer with minimum of current answer and sum of subarray and multiplication of its size and x
        ans = min(ans, kans + k * x)

    # Printing the answer
    print(ans)

# Helper functions
def min_value(*args):
    return min(args)

# Function to check if a given number is inside a given range
def in_range(c, a, z):
    return a <= c < z

# Function to convert boolean value to integer
def btoi(b):
    return 1 if b else 0

# Function to convert integer value to boolean
def itob(a):
    return a != 0

if __name__ == "__main__":
    main()

# <END-OF-CODE>
