
import sys
import math

# Initialize a new scanner object
class Scanner:
    def __init__(self):
        self.r = sys.stdin
        self.buf = []
        self.p = 0

    # Read a single token from the standard input
    def next(self):
        self.pre()
        start = self.p
        while self.p < len(self.buf) and self.buf[self.p]!='':
            self.p += 1
        result = ''.join(self.buf[start:self.p])
        self.p += 1
        return result

    # Read a line from the standard input
    def next_line(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return ''.join(self.buf[start:])

    # Read an integer from the standard input
    def next_int(self):
        v = int(self.next())
        return v

    # Read an array of integers from the standard input
    def next_int_array(self):
        self.pre()
        start = self.p
        result = []
        while self.p < len(self.buf):
            if self.buf[self.p] =='':
                v = int(''.join(self.buf[start:self.p]))
                result.append(v)
                start = self.p + 1
            else:
                self.p += 1
        v = int(''.join(self.buf[start:self.p]))
        result.append(v)

        return result

    # Read a map from the standard input
    def next_map(self):
        self.pre()
        start = self.p
        mp = {}
        while self.p < len(self.buf):
            if self.buf[self.p] =='':
                v = int(''.join(self.buf[start:self.p]))
                mp[v] = True
                start = self.p + 1
            else:
                self.p += 1
        v = int(''.join(self.buf[start:self.p]))
        mp[v] = True

        return mp

    # Prepare the scanner for the next read operation
    def pre(self):
        if self.p >= len(self.buf):
            self.read_line()
            self.p = 0

    # Read a line from the standard input
    def read_line(self):
        self.buf = []
        while True:
            l = self.r.readline()
            if l == '':
                break
            self.buf.extend(l)

# Initialize a new scanner object
sc = Scanner()

# Read the number of elements in the array from the standard input
n = sc.next_int()

# Allocate memory for the array of size n
arr = [0] * n

# Read n integers from the standard input and store them in the array
for i in range(n):
    arr[i] = sc.next_int()

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

# End of code
