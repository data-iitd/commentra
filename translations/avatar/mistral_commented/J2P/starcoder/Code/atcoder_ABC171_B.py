import sys
import threading
import time

# Class to read input
class InputReader:
    # Initialize input stream
    def __init__(self, stream):
        self.stream = stream
        self.lock = threading.Lock()

    # Read a string token
    def n(self):
        with self.lock:
            return self.stream.readline().strip()

    # Read an integer
    def ni(self):
        return int(self.n())

# Class to write output
class OutputWriter:
    # Initialize output stream
    def __init__(self, stream):
        self.stream = stream
        self.lock = threading.Lock()

    # Write a string token
    def p(self, s):
        with self.lock:
            self.stream.write(s + '\n')

    # Write an integer
    def pi(self, n):
        self.p(str(n))

# Class to solve the problem
class Solution:
    # Method to solve the problem
    def solve(self, in_, out_):
        # Read input: number of elements n and the number of summands k
        n = in_.ni()
        k = in_.ni()

        # Read input array a of size n
        a = [0] * n
        for i in range(n):
            a[i] = in_.ni() # Read next element of array a

        # Sort the array a in parallel using Arrays.parallelSort()
        a.sort()

        # Calculate the answer: sum of first k elements of sorted array a
        ans = 0
        for i in range(k):
            ans += a[i]

        # Write the answer to the output stream
        out_.pi(ans)

# Main method to start the program
def main():
    # Initialize input and output streams
    in_ = InputReader(sys.stdin)
    out_ = OutputWriter(sys.stdout)

    # Create Solution object and call its solve method
    sol = Solution()
    sol.solve(in_, out_)

# Entry point of program
if __name__ == '__main__':
    main()

# 