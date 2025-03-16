import sys
import io
import os
import array
import bisect

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.buffer = io.BytesIO()
        self.pointer = 0
        self.line = None

    def next(self):
        while self.line is None or self.line == '':
            self.line = self.stream.readline().decode('utf-8')
            self.pointer = 0
        result = self.line
        self.line = None
        return result

    def read_int(self):
        return int(self.next().strip())

    def read_ints(self):
        return list(map(int, self.next().strip().split()))

class Solution:
    def solve(self, reader, writer):
        n, k = reader.read_ints()
        a = reader.read_ints()
        a.sort()
        ans = sum(a[:k])
        writer.write(f"{ans}\n")

def main():
    input_stream = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
    output_stream = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')
    reader = InputReader(input_stream)
    writer = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')
    solution = Solution()
    solution.solve(reader, writer)
    writer.flush()

if __name__ == "__main__":
    main()
