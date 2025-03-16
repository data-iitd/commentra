# Import necessary modules
import sys

# get_next_string function returns the next word as a string
def get_next_string(scanner):
    return next(scanner)

# get_next_int function returns the next integer from the scanner
def get_next_int(scanner):
    return int(get_next_string(scanner))

# get_next_int64 function returns the next 64-bit integer from the scanner
def get_next_int64(scanner):
    return int(get_next_string(scanner))

# get_next_uint64 function returns the next 64-bit unsigned integer from the scanner
def get_next_uint64(scanner):
    return int(get_next_string(scanner))

# get_next_float64 function returns the next 64-bit floating-point number from the scanner
def get_next_float64(scanner):
    return float(get_next_string(scanner))

# Segment class represents a segment tree data structure
class Segment:
    def __init__(self, n):
        self.n = n
        self.h = 0
        self.i = 0
        self.chunk = 0
        self.unit = [1]
        self.bucket = [[]]
        self.init(n)

    # init function initializes the Segment class with the given size n
    def init(self, n):
        self.bucket[0] = [0] * n
        chunk = 8
        while n > 1:
            n = (n - 1) // chunk + 1
            self.bucket.append([0] * n)
            self.unit.append(self.unit[-1] * chunk)
        self.h = len(self.unit)
        self.chunk = chunk

    # maximize function updates the segment tree with the given index and value
    def maximize(self, index, value):
        self.bucket[0][index] = value
        for self.i in range(self.h - 1):
            s = index - index % self.chunk
            t = s + self.chunk
            if t > len(self.bucket[self.i]):
                t = len(self.bucket[self.i])
            parent = index // self.chunk
            max_value = 0
            for i in range(s, t):
                if max_value < self.bucket[self.i][i]:
                    max_value = self.bucket[self.i][i]
            self.bucket[self.i + 1][parent] = max_value
            index //= self.chunk

    # top function returns the index of the maximum value in the current segment
    def top(self):
        index = 0
        for self.i in range(self.h - 2, -1, -1):
            s = index * self.chunk
            t = s + self.chunk
            if t > len(self.bucket[self.i]):
                t = len(self.bucket[self.i])
            for i in range(s, t):
                if self.bucket[self.i][i] == self.bucket[self.i + 1][index]:
                    index = i
                    break
        return index

# main function is the entry point of the program
def main():
    # Open the standard input file if a command-line argument is provided
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as fp:
            scanner = iter(fp.read().split())
    else:
        scanner = iter(sys.stdin.read().split())

    # Read the first two integers from the input
    n = get_next_int(scanner)
    m = get_next_int(scanner)

    # Initialize the Segment class with the given size n
    seg = Segment(n)

    # Process the input data by maximizing the segments
    for i in range(n):
        seg.maximize(i, get_next_int(scanner))
    for i in range(m):
        seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] // 2)

    # Calculate the answer and print it to the output
    ans = sum(seg.bucket[0])
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
