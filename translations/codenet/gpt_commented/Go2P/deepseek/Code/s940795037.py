import sys

class Scanner:
    def __init__(self):
        self.r = sys.stdin
        self.buf = ""
        self.p = 0

    def next(self):
        while self.p >= len(self.buf):
            self.buf = self.r.readline()
            self.p = 0
        start = self.p
        self.p = self.buf.find(' ', start)
        if self.p == -1:
            result = self.buf[start:]
            self.p = len(self.buf)
        else:
            result = self.buf[start:self.p]
            self.p += 1
        return result

    def next_line(self):
        if self.p >= len(self.buf):
            self.buf = self.r.readline()
            self.p = 0
        start = self.p
        self.p = len(self.buf)
        return self.buf[start:]

    def next_int(self):
        return int(self.next())

    def next_int_array(self):
        line = self.next_line()
        parts = line.split()
        return [int(part) for part in parts]

    def next_map(self):
        line = self.next_line()
        parts = line.split()
        mp = {}
        for part in parts:
            v = int(part)
            mp[v] = True
        return mp

# Main function where the execution starts
def main():
    sc = Scanner()
    n = sc.next_int()
    ans = 0.0

    for i in range(n):
        tmp = 1 / sc.next_int()
        ans += tmp

    print(1 / ans)

main()
