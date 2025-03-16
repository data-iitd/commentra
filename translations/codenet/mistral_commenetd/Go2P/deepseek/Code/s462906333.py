import sys

# Constants and variables declaration
inf = 1e14

# Function to read input from standard input using buffered reader
class Scanner:
    def __init__(self, stream):
        self.reader = stream.readline
        self.buffer = []
        self.index = 0

    def next(self):
        while self.index >= len(self.buffer):
            self.buffer.append(self.reader().decode().strip())
        result = self.buffer[self.index]
        self.index += 1
        return result

    def line(self):
        return self.reader().decode().strip()

    def int(self):
        return int(self.next())

    def int64(self):
        return int(self.next())

# Main function
def main():
    # Setting up logging
    import logging
    logging.basicConfig(level=logging.DEBUG)

    # Creating a new scanner object
    scanner = Scanner(sys.stdin)

    # Reading input
    n = scanner.int()
    x = scanner.int()

    # Initializing arrays
    a = [0] * n
    v = a.copy()

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
def min(a, b):
    return a if a < b else b

# Function to check if a given number is inside a given range
def in(c, a, z):
    return c >= a and c < z

# Function to convert boolean value to integer
def btoi(b):
    return 1 if b else 0

# Function to convert integer value to boolean
def itob(a):
    return a != 0

# Call the main function
if __name__ == "__main__":
    main()
