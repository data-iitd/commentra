
import sys

class Scanner:
    def __init__(self):
        self.r = sys.stdin
        self.buf = []
        self.p = 0

    def next(self):
        self.pre()
        start = self.p
        while self.p < len(self.buf) and self.buf[self.p]!='':
            self.p += 1
        result = ''.join(self.buf[start:self.p])
        self.p += 1
        return result

    def next_line(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return ''.join(self.buf[start:])

    def next_int(self):
        return int(self.next())

    def next_int_array(self):
        self.pre()
        start = self.p
        result = []
        while self.p < len(self.buf):
            if self.buf[self.p] =='':
                result.append(int(''.join(self.buf[start:self.p])))
                start = self.p + 1
            self.p += 1
        result.append(int(''.join(self.buf[start:self.p])))
        return result

    def next_map(self):
        self.pre()
        start = self.p
        mp = {}
        while self.p < len(self.buf):
            if self.buf[self.p] =='':
                mp[int(''.join(self.buf[start:self.p]))] = True
                start = self.p + 1
            self.p += 1
        mp[int(''.join(self.buf[start:self.p]))] = True
        return mp

    def pre(self):
        if self.p >= len(self.buf):
            self.read_line()
            self.p = 0

    def read_line(self):
        self.buf = []
        while True:
            l = self.r.readline()
            if not l:
                break
            self.buf.extend(l)

# Main function where the execution starts
def main():
    sc = Scanner()
    n = sc.next_int()
    ans = 0.0
    for i in range(n):
        tmp = 1 / float(sc.next_int())
        ans += tmp
    print(1 / ans)

if __name__ == "__main__":
    main()

