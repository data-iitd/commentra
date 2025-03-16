
import sys

def main():
    sc = Scanner()

    # Read the number of elements
    n = sc.nextInt()
    
    # Initialize an array to hold the float values
    arr = [0] * n
    
    # Read each integer and convert it to float64, then store in the array
    for i in range(n):
        arr[i] = float(sc.nextInt())
    
    # Sort the array of float64 values
    arr.sort()
    
    # Initialize a variable to keep track of the running average
    prev = arr[0]
    
    # Iterate through the sorted array to calculate the average
    for i in range(1, len(arr)):
        prev = (prev + arr[i]) / 2
    
    # Print the final average
    print(prev)

class Scanner:
    def __init__(self):
        self.r = sys.stdin
        self.buf = []
        self.p = 0

    def next(self):
        self.pre()
        start = self.p
        for self.p in range(self.p, len(self.buf)):
            if self.buf[self.p] == ' ':
                break
        result = ''.join(self.buf[start:self.p])
        self.p += 1
        return result

    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return ''.join(self.buf[start:])

    def nextInt(self):
        return int(self.next())

    def nextIntArray(self):
        self.pre()
        start = self.p
        result = []
        for self.p in range(self.p, len(self.buf)):
            if self.buf[self.p] == ' ':
                result.append(int(''.join(self.buf[start:self.p])))
                start = self.p + 1
        result.append(int(''.join(self.buf[start:self.p])))

        return result

    def nextMap(self):
        self.pre()
        start = self.p
        mp = {}
        for self.p in range(self.p, len(self.buf)):
            if self.buf[self.p] == ' ':
                mp[int(''.join(self.buf[start:self.p]))] = True
                start = self.p + 1
        mp[int(''.join(self.buf[start:self.p]))] = True

        return mp

    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    def readLine(self):
        self.buf = []
        for line in self.r:
            self.buf.extend(line)
            if not line.endswith('\n'):
                break

# 