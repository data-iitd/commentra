import sys
import io
import os
import math
import re
import array
from collections import defaultdict

class FastReader:
    def __init__(self):
        self.buffer = io.BytesIO(os.read(0, os.fstat(0).st_size))
    
    def readline(self):
        return self.buffer.readline().decode('utf-8').strip()
    
    def read(self):
        c = readchar()
        while c == ' ' or c == '\n':
            c = readchar()
        s = ''
        while c != ' ' and c != '\n':
            s += c
            c = readchar()
        return s
    
    def readint(self):
        return int(self.read())
    
    def readfloat(self):
        return float(self.read())

def readchar():
    return sys.stdin.read(1)

def main():
    sc = FastReader()
    x = sc.readint()
    count = 0
    tmp = x
    x = 0
    
    while x != 360:
        x = x + tmp
        if x > 360:
            x = x - 360
        count += 1
    
    print(count)

if __name__ == "__main__":
    main()
