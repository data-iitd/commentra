
import sys
import math

# Initialize scanner and read the first line
sc = Scanner()
sc.readln() # Read the first line

# Main function
def main():
    # Read the first two integers from the input
    AB = sc.nextInts()
    A = AB[0]
    B = AB[1]

    # Check if the sum of A and B is even
    if (A+B)%2 == 0:
        # If it is, print the result (the average)
        print((A + B) // 2)
        return
    # If the sum is odd, print "IMPOSSIBLE"
    print("IMPOSSIBLE")

# Scanner type definition
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
            break
        self.cur = 0
        self.buf = rbuf[0].split(" ")

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

    def nextInts(self):
        self.readln()
        res = [int(i) for i in self.buf]
        self.resetCur()
        return res

# Function to calculate the number of digits in an integer
def digits(x):
    return len(str(x))

# Function to calculate the power of a number
def powInt(x, p):
    result = 1
    for i in range(p):
        result *= x
    return result

# Function to find the maximum of two integers
def max(x, y):
    return max(x, y)

# Function to find the minimum of two integers
def min(x, y):
    return min(x, y)

# Function to calculate the absolute value of an integer
def abs(x):
    return abs(x)

# Function to print the values of variables
def varDump(*value):
    for v in value:
        print("#%v" % v)

# Function to print "Yes"
def yes():
    print("Yes")

# Function to print "No"
def no():
    print("No")

# Pair type definition
class Pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second

# Queue type definition
class Queue:
    def __init__(self):
        self.v = []

    def Push(self, v):
        self.v.append(v)

    def Pop(self):
        r = self.v[0]
        self.v = self.v[1:]
        return r

    def Front(self):
        return self.v[0]

    def Empty(self):
        return len(self.v) == 0

# Translate the above Go code to Python and end with comment "