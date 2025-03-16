import sys

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.tokens = []

    def read(self):
        while not self.tokens:
            line = sys.stdin.readline()
            self.tokens = line.split()
        return self.tokens.pop(0)

    def next_int(self):
        return int(self.read())

    def read_array(self, n):
        return [self.next_int() for _ in range(n)]

class Solution:
    def solve(self, reader, writer):
        n, k = reader.next_int(), reader.next_int()
        logs_length = reader.read_array(n)

        min_length = 1
        max_length = int(1e9) + 1000

        while min_length < max_length:
            mid_length = (min_length + max_length) // 2

            if self.can_cut(mid_length, logs_length, k):
                max_length = mid_length
            else:
                min_length = mid_length + 1

        writer.write(f"{min_length}\n")

    def can_cut(self, mid_length, logs_length, k):
        cuts_needed = 0
        for log in logs_length:
            cuts_needed += (log + mid_length - 1) // mid_length - 1
        return cuts_needed <= k

if __name__ == "__main__":
    reader = InputReader(sys.stdin)
    writer = sys.stdout

    solution = Solution()
    solution.solve(reader, writer)
