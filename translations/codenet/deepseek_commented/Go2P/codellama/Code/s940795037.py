
import sys

def main():
    sc = Scanner() # Initialize a new Scanner instance

    n = sc.nextInt() # Read an integer n from the standard input
    ans = 0.0       # Initialize a variable ans to 0.0
    for i in range(n): # Enter a loop that runs n times
        tmp = 1 / float(sc.nextInt()) # Read an integer, convert it to a float, and divide 1 by this value
        ans += tmp                       # Add this result to ans
    print(1/ans) # Calculate the reciprocal of ans and print it

class Scanner:
    def __init__(self):
        self.r = sys.stdin
        self.buf = []
        self.p = 0

    def next(self): # Read the next token from the input
        self.pre()
        start = self.p
        for ; self.p < len(self.buf); self.p++:
            if self.buf[self.p] == ' ':
                break
        result = ''.join(self.buf[start:self.p])
        self.p++
        return result

    def nextLine(self): # Read the next line from the input
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return ''.join(self.buf[start:])

    def nextInt(self): # Read the next integer from the input
        v, _ = int(self.next())
        return v

    def nextIntArray(self): # Read the next array of integers from the input
        self.pre()
        start = self.p
        result = []
        for ; self.p < len(self.buf); self.p++:
            if self.buf[self.p] == ' ':
                v, _ = int(''.join(self.buf[start:self.p]))
                result.append(v)
                start = self.p + 1
        v, _ = int(''.join(self.buf[start:self.p]))
        result.append(v)

        return result

    def nextMap(self): # Read the next map of integers from the input
        self.pre()
        start = self.p
        mp = {}
        for ; self.p < len(self.buf); self.p++:
            if self.buf[self.p] == ' ':
                v, _ = int(''.join(self.buf[start:self.p]))
                mp[v] = True
                start = self.p + 1
        v, _ = int(''.join(self.buf[start:self.p]))
        mp[v] = True

        return mp

    def pre(self): # Ensure that there are bytes available to read
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    def readLine(self): # Read the next line from the input and store it in the buffer
        self.buf = []
        for line in self.r:
            self.buf.extend(line)

if __name__ == '__main__':
    main()

