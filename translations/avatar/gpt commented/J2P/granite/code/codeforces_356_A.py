
import sys
from bisect import bisect_left

def main():
    # Initialize FastReader to read input efficiently
    in_reader = FastReader(sys.stdin)

    # Read the number of elements
    n = in_reader.nextInt()

    # Create a TreeSet to keep track of available positions on the left
    left = set(range(n))

    # Initialize an array to store the answers
    answer = [0] * n

    # Read the number of queries
    q = in_reader.nextInt()

    # Process each query
    for _ in range(q):
        # Read the range [l, r] and the winning index
        l = in_reader.nextInt() - 1
        r = in_reader.nextInt() - 1
        win = in_reader.nextInt() - 1

        # Update the answer array for all positions in the range [l, r]
        for i in range(bisect_left(left, l), bisect_left(left, r) + 1):
            answer[i] = win + 1
            left.remove(i)

        # Mark the winning index as available again
        answer[win] = 0
        left.add(win)

    # Print the final answer
    print(' '.join(map(str, answer)))

# FastReader class for efficient input reading
class FastReader:
    def __init__(self, stream):
        self.stream = stream
        self.line = ""
        self.line_pos = 0

    def next(self):
        if self.line_pos == len(self.line):
            self.line = self.stream.readline()
            self.line_pos = 0
        token = ""
        while self.line_pos < len(self.line) and self.line[self.line_pos]!= " ":
            token += self.line[self.line_pos]
            self.line_pos += 1
        self.line_pos += 1
        return token

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        if self.line_pos == len(self.line):
            self.line = self.stream.readline()
            self.line_pos = 0
        line = self.line
        self.line = ""
        self.line_pos = 0
        return line

if __name__ == "__main__":
    main()

