
import sys
import heapq

class Main:
    def __init__(self):
        self.input = sys.stdin
        self.output = sys.stdout
        self.heap = []
        self.heap_min = []
        self.sum_min = 0
        self.sum_max = 0
        self.sum_b = 0
        self.min = 0

    def read(self):
        return self.input.readline().strip()

    def write(self, s):
        self.output.write(s)

    def readInt(self):
        return int(self.read())

    def readLong(self):
        return long(self.read())

    def readFloat(self):
        return float(self.read())

    def readDouble(self):
        return float(self.read())

    def readString(self):
        return str(self.read())

    def readStrings(self):
        return self.read().split(" ")

    def readIntString(self):
        return [int(x) for x in self.readStrings()]

    def readLongString(self):
        return [long(x) for x in self.readStrings()]

    def readFloatString(self):
        return [float(x) for x in self.readStrings()]

    def readDoubleString(self):
        return [float(x) for x in self.readStrings()]

    def readStringString(self):
        return [str(x) for x in self.readStrings()]

    def writeInt(self, x):
        self.write(str(x) + "\n")

    def writeLong(self, x):
        self.write(str(x) + "\n")

    def writeFloat(self, x):
        self.write(str(x) + "\n")

    def writeDouble(self, x):
        self.write(str(x) + "\n")

    def writeString(self, x):
        self.write(str(x) + "\n")

    def writeStrings(self, x):
        self.write(" ".join(x) + "\n")

    def writeIntString(self, x):
        self.writeStrings([str(y) for y in x])

    def writeLongString(self, x):
        self.writeStrings([str(y) for y in x])

    def writeFloatString(self, x):
        self.writeStrings([str(y) for y in x])

    def writeDoubleString(self, x):
        self.writeStrings([str(y) for y in x])

    def writeStringString(self, x):
        self.writeStrings([str(y) for y in x])

    def main(self):
        t = self.readInt()
        while t > 0:
            s = self.readStrings()
            if s[0][0] == '2':
                ans = self.min
                ans *= len(self.heap_min)
                ans -= self.sum_min
                ans1 = self.min
                ans1 *= len(self.heap)
                ans1 = self.sum_max - ans1
                self.writeInt(self.min)
                self.writeLong(ans + ans1 + self.sum_b)
            else:
                in_ = int(s[1])
                self.sum_b += long(s[2])
                if in_ > self.min:
                    heapq.heappush(self.heap, in_)
                    self.sum_max += in_
                else:
                    heapq.heappush(self.heap_min, in_)
                    self.sum_min += in_
                if len(self.heap_min) > len(self.heap):
                    self.sum_max += heapq.heappop(self.heap_min)
                    self.sum_min -= heapq.heappop(self.heap_min)
                    heapq.heappush(self.heap, heapq.heappop(self.heap_min))
                if len(self.heap_min) < len(self.heap):
                    self.sum_max -= heapq.heappop(self.heap)
                    self.sum_min += heapq.heappop(self.heap)
                    heapq.heappush(self.heap_min, heapq.heappop(self.heap))
                self.min = heapq.heappop(self.heap_min)
            t -= 1

if __name__ == "__main__":
    m = Main()
    m.main()

