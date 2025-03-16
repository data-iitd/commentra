
import sys

def main():
    # Create a new scanner to read input
    sc = Scanner()
    # Read two integers from input
    A, B = sc.nextInt(), sc.nextInt()

    # Calculate the maximum of A+B, A-B, and A*B
    mx = max(A+B, A-B)
    mx = max(mx, A*B)
    # Print the maximum value
    print(mx)

class Scanner:
    def __init__(self):
        self.r = sys.stdin.readline
        self.buf = []
        self.p = 0

    def next(self):
        self.pre()
        start = self.p
        for i in range(self.p, len(self.buf)):
            if self.buf[i] == ' ':
                break
        result = ''.join(self.buf[start:i])
        self.p = i + 1
        return result

    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return ''.join(self.buf[start:])

    def nextInt(self):
        v = int(self.next())
        return v

    def nextIntArray(self):
        self.pre()
        start = self.p
        result = []
        for i in range(self.p, len(self.buf)):
            if self.buf[i] == ' ':
                v = int(''.join(self.buf[start:i]))
                result.append(v)
                start = i + 1
        v = int(''.join(self.buf[start:i]))
        result.append(v)
        return result

    def nextMap(self):
        self.pre()
        start = self.p
        mp = {}
        for i in range(self.p, len(self.buf)):
            if self.buf[i] == ' ':
                v = int(''.join(self.buf[start:i]))
                mp[v] = True
                start = i + 1
        v = int(''.join(self.buf[start:i]))
        mp[v] = True
        return mp

    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    def readLine(self):
        self.buf = []
        while True:
            l, p, e = self.r()
            if e != None:
                raise e
            self.buf.extend(l)
            if not p:
                break

if __name__ == '__main__':
    main()

