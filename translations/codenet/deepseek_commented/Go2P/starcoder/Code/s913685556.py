# Main function: Initializes a new Scanner, reads two integers A and B,
# and calculates the maximum value among A+B, A-B, and A*B. Finally, it prints the maximum value.
def main():
    sc = NewScanner()
    A, B = sc.NextInt(), sc.NextInt()

    mx = max(A+B, A-B)
    mx = max(mx, A*B)
    print(mx)

# max function: Returns the larger of two integers.
def max(a, b):
    if a < b:
        return b
    return a

# Scanner type: Wraps a bufio.Reader and provides methods to read various types of input data.
class Scanner:
    def __init__(self):
        self.r = bufio.NewReaderSize(sys.stdin, 1000)
        self.buf = []
        self.p = 0

    def Next(self):
        self.pre()
        start = self.p
        while self.p < len(self.buf):
            if self.buf[self.p] =='':
                break
            self.p += 1
        result = string(self.buf[start:self.p])
        self.p += 1
        return result

    def NextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return string(self.buf[start:])

    def NextInt(self):
        v, _ = int(self.Next()), None
        return v

    def NextInt64(self):
        v, _ = int(self.Next()), None
        return v

    def NextFloat(self):
        v, _ = float(self.Next()), None
        return v

    def NextIntArray(self):
        self.pre()
        start = self.p
        result = []
        while self.p < len(self.buf)+1:
            if self.p == len(self.buf) or self.buf[self.p] =='':
                v, _ = int(string(self.buf[start:self.p])), None
                result.append(v)
                start = self.p + 1
            self.p += 1
        return result

    def NextInt64Array(self):
        self.pre()
        start = self.p
        result = []
        while self.p < len(self.buf)+1:
            if self.p == len(self.buf) or self.buf[self.p] =='':
                v, _ = int(string(self.buf[start:self.p])), None
                result.append(v)
                start = self.p + 1
            self.p += 1
        return result

    def NextMap(self):
        self.pre()
        start = self.p
        mp = {}
        while self.p < len(self.buf):
            if self.buf[self.p] =='':
                v, _ = int(string(self.buf[start:self.p])), None
                mp[v] = True
                start = self.p + 1
            self.p += 1
        v, _ = int(string(self.buf[start:self.p])), None
        mp[v] = True
        return mp

    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    def readLine(self):
        self.buf = []
        for {
            l, p, e := self.r.ReadLine()
            if e!= nil {
                panic(e)
            }
            self.buf = append(self.buf, l...)
            if!p {
                break
            }
        }

