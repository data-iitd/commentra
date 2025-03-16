class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.tokens = []

    def read(self):
        while not self.tokens:
            line = self.stream.readline()
            if not line:
                break
            self.tokens.extend(line.split())
        return self.tokens.pop(0)

    def read_int(self):
        return int(self.read())


class Solution:
    def solve(self, reader, writer):
        n = reader.read_int()
        k = reader.read_int()
        a = [reader.read_int() for _ in range(n)]
        a.sort()
        ans = sum(a[:k])
        writer.write(str(ans) + '\n')


import sys


def main():
    reader = InputReader(sys.stdin)
    writer = sys.stdout
    solution = Solution()
    solution.solve(reader, writer)


if __name__ == "__main__":
    main()
