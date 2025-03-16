import sys

# Class to read input from stdin
class MyScanner:
    def __init__(self):
        self.buffer = ""
        self.tokens = []
        self.index = 0
        self.read_input()

    def read_input(self):
        self.buffer = sys.stdin.readline()
        self.tokens = self.buffer.split()
        self.index = 0

    def has_next(self):
        return self.index < len(self.tokens)

    def next_int(self):
        self.index += 1
        return int(self.tokens[self.index - 1])

    def next_long(self):
        self.index += 1
        return int(self.tokens[self.index - 1])

    def next_double(self):
        self.index += 1
        return float(self.tokens[self.index - 1])

    def next(self):
        self.index += 1
        return self.tokens[self.index - 1]

# Class to write output to stdout
class MyWriter:
    def __init__(self):
        self.buffer = ""

    def write(self, t):
        self.buffer += str(t) + " "

    def writeln(self, t):
        self.buffer += str(t) + "\n"

    def flush(self):
        sys.stdout.write(self.buffer)
        self.buffer = ""

# Class to solve the problem
class Main:
    def __init__(self):
        self.scanner = MyScanner()
        self.writer = MyWriter()

    def solve(self):
        n = self.scanner.next_int()
        s = self.scanner.next()
        sb = ""
        for i in range(1, n):
            sb += str(abs(ord(s[i]) - ord(s[i - 1])))
        if n == 2:
            self.writer.writeln(sb[0])
            return
        s = sb
        if "1" in s:
            self.writer.writeln(self.cal(s, "1"))
        else:
            self.writer.writeln(self.cal(s, "2") * 2)

    def cal(self, s, c):
        n = len(s)
        m = n - 1
        ans = 0
        for i in range(n):
            if s[i] == c and (m & i) == i:
                ans ^= 1
        return ans

# Main method to execute the program
if __name__ == "__main__":
    main = Main()
    main.solve()

# 