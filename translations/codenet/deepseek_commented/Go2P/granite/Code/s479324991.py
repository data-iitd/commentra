
import sys
import bufio
import os
import math

def main():
    sc = Scanner()

    # Read the number of elements
    n = sc.nextInt()
    
    # Initialize an array to hold the float values
    arr = [0.0] * n
    
    # Read each integer and convert it to float, then store in the array
    for i in range(n):
        arr[i] = float(sc.nextInt())
    
    # Sort the array of float values
    arr.sort()
    
    # Initialize a variable to keep track of the running average
    prev = arr[0]
    
    # Iterate through the sorted array to calculate the average
    for i in range(1, n):
        prev = (prev + arr[i]) / 2
    
    # Print the final average
    print(prev)

class Scanner:
    def __init__(self):
        self.rdr = bufio.BufferedReader(bufio. InputStreamReader(sys.stdin), 1000)
        self.buf = ""
        self.p = 0

    def next(self):
        self.pre()
        start = self.p
        for ; self.p < len(self.buf); self.p++:
            if self.buf[self.p] =='':
                break
        result = self.buf[start:self.p]
        self.p++
        return result

    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return self.buf[start:]

    def nextInt(self):
        v = int(self.next())
        return v

    def nextIntArray(self):
        self.pre()
        start = self.p
        result = []
        for ; self.p < len(self.buf); self.p++:
            if self.buf[self.p] =='':
                v = int(self.buf[start:self.p])
                result.append(v)
                start = self.p + 1
        v = int(self.buf[start:self.p])
        result.append(v)

        return result

    def nextMap(self):
        self.pre()
        start = self.p
        mp = {}
        for ; self.p < len(self.buf); self.p++:
            if self.buf[self.p] =='':
                v = int(self.buf[start:self.p])
                mp[v] = True
                start = self.p + 1
        v = int(self.buf[start:self.p])
        mp[v] = True

        return mp

    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    def readLine(self):
        self.buf = ""
        while True:
            l = self.rdr.readline()
            if l == "":
                raise Exception("End of input")
            self.buf += l
            if self.buf[-1] == '\n':
                break

# Translate the above Python code to Java and end with comment "