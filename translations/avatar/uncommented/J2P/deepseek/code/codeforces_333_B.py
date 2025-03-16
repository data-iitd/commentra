import sys
from io import StringIO

class FastReader:
    def __init__(self, input):
        self.input = input
        self.lines = self.input.split('\n')
        self.index = 0

    def next(self):
        while self.index < len(self.lines) and not self.lines[self.index]:
            self.index += 1
        if self.index >= len(self.lines):
            return None
        line = self.lines[self.index]
        self.index += 1
        return line.split()

    def nextInt(self):
        return int(self.next()[0])

    def nextLong(self):
        return int(self.next()[0])

    def nextDouble(self):
        return float(self.next()[0])

    def nextLine(self):
        if self.index >= len(self.lines):
            return None
        line = self.lines[self.index]
        self.index += 1
        return line

# Mock input for testing
input_text = """4 2
2 2
3 3"""

# Create a FastReader instance with the mock input
in_ = FastReader(input_text)
out = StringIO()

def main():
    n = in_.nextInt()
    m = in_.nextInt()
    banned_rows = set()
    banned_cols = set()
    for _ in range(m):
        r = in_.nextInt()
        if 1 < r < n:
            banned_rows.add(r)
        c = in_.nextInt()
        if 1 < c < n:
            banned_cols.add(c)
    answer = (n - 2) * 2
    answer -= len(banned_rows)
    answer -= len(banned_cols)
    if n % 2 != 0:
        mid = (n + 1) // 2
        if mid not in banned_rows and mid not in banned_cols:
            answer -= 1
    out.write(str(answer) + '\n')
    out.flush()

if __name__ == "__main__":
    main()

# Print the output
print(out.getvalue())
