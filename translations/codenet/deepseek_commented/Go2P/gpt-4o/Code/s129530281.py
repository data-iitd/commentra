import sys

# get_scanner initializes a new scanner that reads from the given file pointer.
def get_scanner(fp):
    return fp.read().split()

# get_next_string reads the next word from the scanner.
def get_next_string(scanner):
    return scanner.pop(0)

# get_next_int converts the next word to an integer.
def get_next_int(scanner):
    return int(get_next_string(scanner))

# get_next_int64 converts the next word to a 64-bit integer.
def get_next_int64(scanner):
    return int(get_next_string(scanner))

# get_next_uint64 converts the next word to an unsigned 64-bit integer.
def get_next_uint64(scanner):
    return int(get_next_string(scanner))

# get_next_float64 converts the next word to a floating-point number.
def get_next_float64(scanner):
    return float(get_next_string(scanner))

# Main function handles file input, initializes a segment tree, and processes the input to compute an answer.
def main():
    fp = sys.stdin
    if len(sys.argv) > 1:
        fp = open(sys.argv[1])
    
    scanner = get_scanner(fp.read().split())
    
    # Read the number of elements (n) and the number of operations (m).
    n = get_next_int(scanner)
    m = get_next_int(scanner)

    # Initialize the segment tree.
    seg = Segment()
    seg.init(n)

    # Populate the segment tree with initial values.
    for i in range(n):
        seg.maximize(i, get_next_int(scanner))

    # Perform the specified number of operations on the segment tree.
    for i in range(m):
        seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1)

    # Calculate the sum of the values in the root bucket of the segment tree.
    ans = sum(seg.bucket[0])

    # Write the result to the standard output.
    print(ans)

# Segment class represents a segment tree and includes methods to initialize it and update/query it.
class Segment:
    def __init__(self):
        self.n = 0
        self.h = 0
        self.i = 0
        self.chunk = 0
        self.unit = []
        self.bucket = []

    # init initializes the segment tree with a given size n.
    def init(self, n):
        self.n = n
        self.unit = [1]
        self.bucket = [[]]
        self.bucket[0] = [0] * n

        chunk = 8
        while n > 1:
            n = (n - 1) // chunk + 1
            self.bucket.append([0] * n)
            self.unit.append(self.unit[-1] * chunk)
        self.h = len(self.unit)
        self.chunk = chunk

    # maximize updates the value at a given index in the segment tree.
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

    # top returns the index of the maximum value in the segment tree.
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

if __name__ == "__main__":
    main()

# <END-OF-CODE>
