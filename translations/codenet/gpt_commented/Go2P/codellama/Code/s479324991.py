
import sys

def main():
    # Initialize a new scanner to read input
    sc = Scanner()

    # Read the number of elements
    n = sc.nextInt()
    # Create a list to hold the float values
    arr = [0] * n

    # Read n integers from input and convert them to float
    for i in range(n):
        arr[i] = float(sc.nextInt())

    # Sort the list of float values
    arr.sort()

    # Initialize 'prev' with the first element of the sorted list
    prev = arr[0]

    # Calculate the average of the elements iteratively
    for i in range(1, len(arr)):
        prev = (prev + arr[i]) / 2

    # Print the final computed average
    print(prev)


class Scanner:
    def __init__(self):
        self.r = sys.stdin
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
            l, p, e = self.r.readline()
            if e != None:
                raise e
            self.buf.extend(l)
            if not p:
                break


