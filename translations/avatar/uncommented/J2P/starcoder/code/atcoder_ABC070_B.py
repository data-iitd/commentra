
# <START-OF-CODE>

import sys

class InputReader:
    def __init__(self, stream):
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

def main():
    inputReader = InputReader(sys.stdin)
    a = inputReader.nextInt()
    b = inputReader.nextInt()
    c = inputReader.nextInt()
    d = inputReader.nextInt()
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

if __name__ == '__main__':
    main()

# 