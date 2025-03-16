
import sys

# Initialize a new scanner object
class Scanner:
    # Create a new scanner object
    def __init__(self):
        self.r = sys.stdin
        self.buf = []
        self.p = 0

    # Read a single token from the standard input
    def next(self):
        self.pre()
        start = self.p
        for self.p < len(self.buf):
            if self.buf[self.p] == ' ':
                break
            self.p += 1
        result = ''.join(self.buf[start:self.p])
        self.p += 1
        return result

    # Read a line from the standard input
    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return ''.join(self.buf[start:])

    # Read an integer from the standard input
    def nextInt(self):
        return int(self.next())

    # Read an array of integers from the standard input
    def nextIntArray(self):
        self.pre()
        start = self.p
        result = []
        for self.p < len(self.buf):
            if self.buf[self.p] == ' ':
                v = int(''.join(self.buf[start:self.p]))
                result.append(v)
                start = self.p + 1
            self.p += 1
        v = int(''.join(self.buf[start:self.p]))
        result.append(v)

        return result

    # Read a map from the standard input
    def nextMap(self):
        self.pre()
        start = self.p
        mp = {}
        for self.p < len(self.buf):
            if self.buf[self.p] == ' ':
                v = int(''.join(self.buf[start:self.p]))
                mp[v] = True
                start = self.p + 1
            self.p += 1
        v = int(''.join(self.buf[start:self.p]))
        mp[v] = True

        return mp

    # Prepare the scanner for the next read operation
    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    # Read a line from the standard input
    def readLine(self):
        self.buf = []
        for line in self.r:
            self.buf.extend(line)
            if not line.endswith(' '):
                break

# Initialize a new scanner object
sc = Scanner()

# Read the number of elements in the array from the standard input
n = sc.nextInt()

# Allocate memory for the array of size n
arr = [0] * n

# Read n integers from the standard input and store them in the array
for i in range(n):
    arr[i] = sc.nextInt()

# Sort the array in ascending order
arr.sort()

# Initialize a variable prev to store the previous element in the sorted array
prev = arr[0]

# Iterate through the sorted array from the second element to the last
for i in range(1, n):
    # Calculate the average of the previous and current elements
    prev = (prev + arr[i]) / 2

# Print the result to the standard output
print(prev)

