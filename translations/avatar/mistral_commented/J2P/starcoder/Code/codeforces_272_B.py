
import sys

# Initialize FastReader for reading input
class Main:
    def main(self):
        # Read the number of test cases
        n = int(sys.stdin.readline())

        # Initialize an array 'a' to store the frequency of each number
        a = [0] * 33

        # Read each test case and update the frequency of the number in the array 'a'
        for i in range(n):
            num = int(sys.stdin.readline()) # Read a number
            index = self.rec(num)   # Get the index of the number in the array 'a'
            a[index] += 1             # Increment the frequency of the number in the array 'a'

        # Calculate the answer and print it
        answer = 0
        for i in range(33):
            summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1) # Calculate the sum of squares of numbers up to the current number
            answer += summ                             # Add the sum to the answer
        print(int(answer)) # Print the answer as a long integer

    # A helper method to get the index of a number in the array 'a'
    def rec(self, x):
        answer = 0

        # Calculate the index of the number in the array 'a' by counting the number of set bits in the binary representation of the number
        for k in range(31, -1, -1):
            if (x & (1 << k))!= 0: # If the k-th bit is set
                answer += 1          # Increment the answer

        return answer

# A custom InputReader class for reading input efficiently
class FastReader:
    def __init__(self):
        self.buf = sys.stdin.buffer
        self.off = 0
        self.end = 0
        self.s = 0
        self.lb = 0
        self.pos = 0

    def read(self):
        while self.s == 0:
            if self.pos == self.end:
                self.pos = self.off
                self.readNext()
            else:
                self.s = self.buf[self.pos]
                self.pos += 1
        self.s -= 1
        return self.buf[self.pos - 1]

    def readInt(self):
        c = self.read()
        while c <= 32:
            c = self.read()
        if c == -1:
            return -1
        while c > 32:
            c = self.read()
        if c == -1:
            return -1
        neg = 1
        if c == '-':
            neg = -1
            c = self.read()
        x = 0
        while c > 32:
            x = x * 10 + c - 48
            c = self.read()
        return neg * x

    def readLong(self):
        c = self.read()
        while c <= 32:
            c = self.read()
        if c == -1:
            return -1
        while c > 32:
            c = self.read()
        if c == -1:
            return -1
        neg = 1
        if c == '-':
            neg = -1
            c = self.read()
        x = 0
        while c > 32:
            x = x * 10 + c - 48
            c = self.read()
        return neg * x

    def readDouble(self):
        c = self.read()
        while c <= 32:
            c = self.read()
        if c == -1:
            return -1
        while c > 32:
            c = self.read()
        if c == -1:
            return -1
        neg = 1
        if c == '-':
            neg = -1
            c = self.read()
        x = 0
        while c > 32:
            x = x * 10 + c - 48
            c = self.read()
        return neg * x

    def readLine(self):
        s = ""
        while self.s == 0:
            if self.pos == self.end:
                self.pos = self.off
                self.readNext()
            else:
                self.s = self.buf[self.pos]
                self.pos += 1
        while self.s!= -1 and self.s!= 10:
            s += chr(self.s)
            self.s = 0
            if self.pos == self.end:
                self.pos = self.off
                self.readNext()
            else:
                self.s = self.buf[self.pos]
                self.pos += 1
        return s

    def readNext(self):
        self.off = self.pos
        self.end = self.pos + 1
        self.s = 0
        while self.end < len(self.buf) and self.s == 0:
            self.s = self.buf[self.end]
            self.end += 1

# 