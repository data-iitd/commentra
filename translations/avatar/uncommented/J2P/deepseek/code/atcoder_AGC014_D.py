import sys
from io import StringIO

class MyScanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.tokens = None

    def next(self):
        while self.tokens is None or not self.tokens:
            self.tokens = self.input_stream.readline().split()
        token = self.tokens[0]
        self.tokens.pop(0)
        return token

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

    def next_line(self):
        return self.input_stream.readline().strip()

def max_matching(v, p, g):
    a = 0
    o = 0
    for w in g[v]:
        if w == p:
            continue
        r = max_matching(w, v, g)
        a += r // 2
        o += r % 2
    return 2 * a + min(1, o) + 1

def main():
    input_stream = StringIO(sys.stdin.read())
    scanner = MyScanner(input_stream)
    n = scanner.next_int()
    g = [[] for _ in range(n)]
    for _ in range(n - 1):
        a = scanner.next_int() - 1
        b = scanner.next_int() - 1
        g[a].append(b)
        g[b].append(a)
    m = max_matching(0, -1, g) // 2
    print("Second" if 2 * m == n else "First")

if __name__ == "__main__":
    main()
