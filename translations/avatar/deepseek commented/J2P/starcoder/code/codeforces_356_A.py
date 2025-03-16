
# <START-OF-CODE>
import sys

class Main:
    def __init__(self):
        self.input = sys.stdin
        self.output = sys.stdout

    def readLine(self):
        return self.input.readline().strip()

    def readInt(self):
        return int(self.readLine())

    def readLong(self):
        return long(self.readLine())

    def readFloat(self):
        return float(self.readLine())

    def readDouble(self):
        return float(self.readLine())

    def readString(self):
        return str(self.readLine())

    def readStrings(self):
        return self.readLine().split(" ")

    def readInt1D(self):
        return [int(x) for x in self.readStrings()]

    def readInt2D(self):
        return [self.readInt1D() for _ in range(self.readInt())]

    def readLong1D(self):
        return [long(x) for x in self.readStrings()]

    def readLong2D(self):
        return [self.readLong1D() for _ in range(self.readInt())]

    def readFloat1D(self):
        return [float(x) for x in self.readStrings()]

    def readFloat2D(self):
        return [self.readFloat1D() for _ in range(self.readInt())]

    def readDouble1D(self):
        return [float(x) for x in self.readStrings()]

    def readDouble2D(self):
        return [self.readDouble1D() for _ in range(self.readInt())]

    def readString1D(self):
        return [str(x) for x in self.readStrings()]

    def readString2D(self):
        return [self.readString1D() for _ in range(self.readInt())]

    def write(self, s):
        self.output.write(str(s))
        self.output.write("\n")

    def write1D(self, v):
        self.write(" ".join(map(str, v)))

    def write2D(self, v):
        self.write(len(v))
        self.write("\n")
        for x in v:
            self.write1D(x)

    def __call__(self):
        n = self.readInt()
        left = set(range(n))
        answer = [0] * n
        q = self.readInt()
        while q > 0:
            l = self.readInt() - 1
            r = self.readInt() - 1
            win = self.readInt()
            while left and left.pop() <= r:
                curr = left.pop()
                answer[curr] = win
            answer[win - 1] = 0
            left.add(win - 1)
            q -= 1
        self.write(" ".join(map(str, answer)))

if __name__ == "__main__":
    m = Main()
    m()
# 