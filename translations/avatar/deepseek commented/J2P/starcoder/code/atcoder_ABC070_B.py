
import sys

# Import necessary classes for input/output operations and utility methods

class Main:

    def __init__(self):
        self.reader = sys.stdin
        self.tokenizer = None

    def next(self):
        while self.tokenizer == None or not self.tokenizer.hasMoreTokens():
            self.tokenizer = StringTokenizer(self.reader.readLine())
        return self.tokenizer.nextToken()

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return long(self.next())

# Define a nested static class for reading input from the standard input stream

if __name__ == "__main__":
    main = Main()
    a = main.nextInt()
    b = main.nextInt()
    c = main.nextInt()
    d = main.nextInt()
    if c > b:
        print 0
    elif a > d:
        print 0
    elif a < c:
        print min(b, d) - c
    else:
        l = [a, b, c, d]
        l.sort()
        print l[2] - l[1]

# 