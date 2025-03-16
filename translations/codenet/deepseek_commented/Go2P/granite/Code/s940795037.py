
import sys
import bufio
import string

def main():
    sc = Scanner() # Initialize a new Scanner instance

    n = sc.nextInt() # Read an integer n from the standard input
    ans = 0.0 # Initialize a variable ans to 0.0
    for i in range(n): # Enter a loop that runs n times
        tmp = 1 / float(sc.nextInt()) # Read an integer, convert it to a float, and divide 1 by this value
        ans += tmp # Add this result to ans
    print(1 / ans) # Calculate the reciprocal of ans and print it

class Scanner:
    def __init__(self):
        self.rdr = bufio.BufferedReader(bufio. InputStreamReader(sys.stdin), 1000) # Create a new buffered reader with a size of 1000
        self.buf = ""
        self.p = 0

    def next(self): # Read the next token from the input
        self.pre()
        start = self.p
        while self.p < len(self.buf):
            if self.buf[self.p] =='':
                break
            self.p += 1
        result = self.buf[start:self.p]
        self.p += 1
        return result

    def nextLine(self): # Read the next line from the input
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return self.buf[start:]

    def nextInt(self): # Read the next integer from the input
        return int(self.next())

    def nextIntArray(self): # Read the next array of integers from the input
        self.pre()
        start = self.p
        result = []
        while self.p < len(self.buf):
            if self.buf[self.p] =='':
                result.append(int(self.buf[start:self.p]))
                start = self.p + 1
            self.p += 1
        result.append(int(self.buf[start:self.p]))
        return result

    def nextMap(self): # Read the next map of integers from the input
        self.pre()
        start = self.p
        mp = {}
        while self.p < len(self.buf):
            if self.buf[self.p] =='':
                mp[int(self.buf[start:self.p])] = True
                start = self.p + 1
            self.p += 1
        mp[int(self.buf[start:self.p])] = True
        return mp

    def pre(self): # Ensure that there are bytes available to read
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    def readLine(self): # Read the next line from the input and store it in the buffer
        self.buf = ""
        while True:
            l = self.rdr.readline()
            if not l:
                break
            self.buf += l

