
# <START-OF-CODE>

import sys

class CColoringColorfully:
    def solve(self, testNumber, in, out):
        x = in.next()
        a = x
        b = x
        a1 = 0
        a2 = 0
        for i in range(1, len(x)):
            if a[i] == a[i-1]:
                if a[i] == '1':
                    a = a[:i] + '0' + a[i+1:]
                else:
                    a = a[:i] + '1' + a[i+1:]
                a1 += 1
        for i in range(len(x)-1, 0, -1):
            if b[i] == b[i-1]:
                if b[i-1] == '1':
                    b = b[:i-1] + '0' + b[i:]
                else:
                    b = b[:i-1] + '1' + b[i:]
                a2 += 1
        out.println(min(a1, a2))

class InputReader:
    def __init__(self, stream):
        self.reader = BufferedReader(InputStreamReader(stream), 32768)
        self.tokenizer = None

    def next(self):
        while self.tokenizer == None or not self.tokenizer.hasMoreTokens():
            try:
                self.tokenizer = StringTokenizer(self.reader.readLine())
            except IOException as e:
                raise RuntimeException(e)
        return self.tokenizer.nextToken()

if __name__ == '__main__':
    solver = CColoringColorfully()
    solver.solve(1, InputReader(sys.stdin), PrintWriter(sys.stdout))

# 