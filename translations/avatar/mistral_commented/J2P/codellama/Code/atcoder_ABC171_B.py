import sys
import array

def main():
    # Initialize input and output streams
    inputStream = sys.stdin
    outputStream = sys.stdout

    # Create InputReader and PrintWriter objects
    in = InputReader(inputStream)
    out = PrintWriter(outputStream)

    # Create Solution object and call its solve method
    sol = Solution()
    sol.solve(in, out)

    # Close the output stream
    out.close()

class InputReader:
    # Initialize reader and tokenizer
    def __init__(self, stream):
        self.reader = stream
        self.tokenizer = None

    # Method to read a string token
    def n(self):
        while self.tokenizer is None or not self.tokenizer.hasMoreTokens():
            try:
                self.tokenizer = array.array('b', self.reader.readline())
            except:
                raise RuntimeError()
        return self.tokenizer.next()

    # Method to read an integer
    def ni(self):
        return int(self.n())

class Solution:
    # Method to solve the problem
    def solve(self, in, out):
        # Read input: number of elements n and the number of summands k
        n = in.ni()
        k = in.ni()

        # Read input array a of size n
        a = [in.ni() for i in range(n)]

        # Sort the array a in parallel using Arrays.parallelSort()
        a.sort()

        # Calculate the answer: sum of first k elements of sorted array a
        ans = 0
        for i in range(k):
            ans += a[i]

        # Write the answer to the output stream
        out.println(ans)

class PrintWriter:
    # Initialize writer
    def __init__(self, stream):
        self.writer = stream

    # Method to write a string to the output stream
    def println(self, s):
        self.writer.write(str(s) + '\n')

