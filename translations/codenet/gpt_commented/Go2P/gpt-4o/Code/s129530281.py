import sys

# get_scanner initializes a new scanner for reading from the provided file pointer.
def get_scanner(fp):
    return fp.read().split()  # Read all input and split by whitespace

# get_next_string retrieves the next string from the scanner.
def get_next_string(scanner):
    return scanner.pop(0)  # Get the next token

# get_next_int retrieves the next integer from the scanner.
def get_next_int(scanner):
    return int(get_next_string(scanner))  # Convert the next string to an integer

# get_next_int64 retrieves the next int64 from the scanner.
def get_next_int64(scanner):
    return int(get_next_string(scanner))  # Convert the next string to int64

# get_next_uint64 retrieves the next uint64 from the scanner.
def get_next_uint64(scanner):
    return int(get_next_string(scanner))  # Convert the next string to uint64

# get_next_float64 retrieves the next float64 from the scanner.
def get_next_float64(scanner):
    return float(get_next_string(scanner))  # Convert the next string to float64

class Segment:
    def __init__(self):
        self.n = 0
        self.h = 0
        self.i = 0
        self.chunk = 0
        self.unit = []
        self.bucket = []

    # init initializes the segment structure with the given size n.
    def init(self, n):
        self.n = n
        self.unit = [1]  # Initialize unit array
        self.bucket = [[]]  # Initialize bucket array
        self.bucket[0] = [0] * n  # Initialize first bucket with zeros

        chunk = 8  # Define the chunk size
        while n > 1:
            n = (n - 1) // chunk + 1  # Reduce n based on the chunk size
            self.bucket.append([0] * n)  # Append a new bucket
            self.unit.append(self.unit[-1] * chunk)  # Update unit array
        self.h = len(self.unit)  # Set the height of the segment
        self.chunk = chunk  # Set the chunk size

    # maximize updates the segment at a given index with a new value.
    def maximize(self, index, value):
        self.bucket[0][index] = value  # Set the value in the first bucket
        for self.i in range(self.h - 1):
            s = index - index % self.chunk  # Calculate the start of the current chunk
            t = s + self.chunk  # Calculate the end of the current chunk
            if t > len(self.bucket[self.i]):
                t = len(self.bucket[self.i])  # Adjust end if it exceeds the bucket length
            parent = index // self.chunk  # Determine the parent index
            max_value = 0  # Initialize max value
            for i in range(s, t):
                if max_value < self.bucket[self.i][i]:
                    max_value = self.bucket[self.i][i]  # Find the maximum value in the current chunk
            self.bucket[self.i + 1][parent] = max_value  # Update the parent bucket with the maximum value
            index //= self.chunk  # Move to the parent index for the next iteration

    # top retrieves the index of the top value in the segment.
    def top(self):
        index = 0  # Start from the root index
        for self.i in range(self.h - 2, -1, -1):
            s = index * self.chunk  # Calculate the start of the current chunk
            t = s + self.chunk  # Calculate the end of the current chunk
            if t > len(self.bucket[self.i]):
                t = len(self.bucket[self.i])  # Adjust end if it exceeds the bucket length
            for i in range(s, t):
                if self.bucket[self.i][i] == self.bucket[self.i + 1][index]:
                    index = i  # Update index if the value matches the top value
                    break

        return index  # Return the index of the top value

def main():
    # Determine the input source: either standard input or a file specified as a command-line argument
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as fp:
            scanner = get_scanner(fp)
    else:
        scanner = get_scanner(sys.stdin)

    # Read the number of elements and operations
    n = get_next_int(scanner)
    m = get_next_int(scanner)

    # Initialize the Segment structure
    seg = Segment()
    seg.init(n)  # Initialize the segment with size n

    # Populate the segment with initial values
    for i in range(n):
        seg.maximize(i, get_next_int(scanner))  # Maximize the segment with the input values

    # Perform m operations to maximize the segment
    for i in range(m):
        seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] // 2)  # Maximize using the top value and half of the last bucket's first element

    # Calculate the final answer by summing up the values in the first bucket
    ans = sum(seg.bucket[0])  # Accumulate the values

    # Output the final result
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
