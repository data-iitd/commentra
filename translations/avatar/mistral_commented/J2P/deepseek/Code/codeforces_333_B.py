import sys
import io
import os
import math
from collections import defaultdict, deque, Counter

class FastReader:
    def __init__(self):
        self.buffer = io.BytesIO(os.read(0, os.fstat(0).st_size))

    def readline(self):
        return self.buffer.readline().decode('utf-8').strip()

    def read(self):
        return self.buffer.read().decode('utf-8').strip()

    def readline_ints(self):
        return list(map(int, self.readline().split()))

    def read_ints(self):
        return list(map(int, self.read().split()))

class FastWriter:
    def __init__(self):
        self.output = io.StringIO()

    def write(self, data):
        self.output.write(data)

    def writeline(self, data):
        self.output.write(data + '\n')

    def flush(self):
        sys.stdout.write(self.output.getvalue())
        self.output.truncate(0)
        self.output.seek(0)

fast_reader = FastReader()
fast_writer = FastWriter()

def main():
    n = fast_reader.readline_ints()[0]
    m = fast_reader.readline_ints()[0]

    banned_rows = set()
    banned_cols = set()

    for _ in range(m):
        r = fast_reader.readline_ints()[0]
        if 1 < r < n:
            banned_rows.add(r)

        c = fast_reader.readline_ints()[0]
        if 1 < c < n:
            banned_cols.add(c)

    answer = (n - 2) * 2
    answer -= len(banned_rows)
    answer -= len(banned_cols)

    if n % 2 != 0:
        mid = (n + 1) // 2
        if mid not in banned_rows and mid not in banned_cols:
            answer -= 1

    fast_writer.writeline(str(answer))
    fast_writer.flush()

if __name__ == "__main__":
    main()

