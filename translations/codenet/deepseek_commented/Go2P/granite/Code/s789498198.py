
import sys

# Main function of the program
def main():
    # Read two integers A and B from standard input
    AB = sc.nextInts()
    A = AB[0]
    B = AB[1]

    # Check if the sum of A and B is even
    if (A+B)%2 == 0:
        # If even, print the average of A and B
        print((A + B) // 2)
        return
    # If not even, print "IMPOSSIBLE"
    print("IMPOSSIBLE")

# Initialize the scanner with default settings
sc = Scanner()

# Scanner class for reading input efficiently
class Scanner:
    buf = []
    cur = 0
    r = None

    def __init__(self):
        self.r = bufio.BufferedReader(sys.stdin)

    def readln(self):
        rbuf = []
        for line in self.r:
            rbuf.append(line)
        self.cur = 0
        self.buf = line.split(" ")

    def isFull(self):
        if self.cur == len(self.buf):
            return True
        return False

    def resetCur(self):
        self.cur = 0

    def next(self):
        if self.cur == 0:
            self.readln()
        res = self.buf[self.cur]
        self.cur += 1
        if self.isFull():
            self.resetCur()
        return res

    def nexts(self):
        self.readln()
        self.resetCur()
        return self.buf

    def nextInt(self):
        if self.cur == 0:
            self.readln()
        res = int(self.buf[self.cur])
        self.cur += 1
        if self.isFull():
            self.resetCur()
        return res

    def nextInts(self):
        self.readln()
        res = [int(i) for i in self.buf]
        self.resetCur()
        return res

    def nextFloat(self):
        if self.cur == 0:
            self.readln()
        res = float(self.buf[self.cur])
        self.cur += 1
        if self.isFull():
            self.resetCur()
        return res

    def nextFloats(self):
        self.readln()
        res = [float(i) for i in self.buf]
        self.resetCur()
        return res

# Calculate the number of digits in an integer
def digits(x):
    return len(str(x))

# Calculate x raised to the power of p
def powInt(x, p):
    result = 1
    for i in range(p):
        result *= x
    return result

# Return the maximum of two integers
def max(x, y):
    return max(x, y)

# Return the minimum of two integers
def min(x, y):
    return min(x, y)

# Return the absolute value of an integer
def abs(x):
    return abs(x)

# Print the variable in a debug-friendly format
def varDump(*value):
    for v in value:
        print(v)

# Print "Yes" to standard output
def yes():
    print("Yes")

# Print "No" to standard output
def no():
    print("No")

# Pair class to hold two integers
class Pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second

# Queue class to hold a list of Pairs
class Queue:
    def __init__(self):
        self.v = []

    def push(self, v):
        self.v.append(v)

    def pop(self):
        r = self.v[0]
        self.v = self.v[1:]
        return r

    def front(self):
        return self.v[0]

    def empty(self):
        return len(self.v) == 0

# Translate the above Go code to Python and end with comment "