import sys
import threading
import time

class Solution:
    def solve(self, in_, out_):
        # Read the number of elements (n) and the number of smallest elements to sum (k)
        n = in_.ni()
        k = in_.ni()

        # Initialize an array to hold the input numbers
        a = [0] * n

        # Read n integers from input and store them in the array
        for i in range(n):
            a[i] = in_.ni()

        # Sort the array in parallel to arrange numbers in ascending order
        a.sort()

        # Initialize a variable to hold the sum of the smallest k elements
        ans = 0

        # Sum the first k elements of the sorted array
        for i in range(k):
            ans += a[i]

        # Output the result (sum of the smallest k elements)
        out_.println(ans)

class InputReader:
    def __init__(self, stream):
        self.reader = sys.stdin
        self.tokenizer = None
        self.stream = stream
        self.thread = threading.Thread(target=self.listen)
        self.thread.daemon = True
        self.thread.start()

    def listen(self):
        while True:
            line = self.reader.readline()
            if line == "