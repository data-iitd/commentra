import sys
import io
import os
import tokenize

class InputReader:
    def __init__(self, stream):
        self.stream = stream

    def next(self):
        while True:
            b = self.stream.read(1)
            if b == ' ' or b == '\n' or b == '\r' or b == '\t':
                continue
            else:
                break
        s = b
        while True:
            b = self.stream.read(1)
            if b != ' ' and b != '\n' and b != '\r' and b != '\t':
                s += b
            else:
                break
        return s

class CColoringColorfully:
    def solve(self, testNumber, inp, out):
        x = inp.next()
        a = list(x)
        b = list(x)
        a1 = 0
        a2 = 0

        for i in range(1, len(x)):
            if a[i] == a[i - 1]:
                a1 += 1
                a[i] = '0' if a[i] == '1' else '1'

        for i in range(len(x) - 1, 0, -1):
            if b[i] == b[i - 1]:
                a2 += 1
                b[i - 1] = '0' if b[i - 1] == '1' else '1'

        out.write(str(min(a1, a2)) + '\n')

def main():
    stream = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
    inp = InputReader(stream)
    out = io.StringIO()

    solver = CColoringColorfully()
    solver.solve(1, inp, out)

    print(out.getvalue(), end='')

if __name__ == "__main__":
    main()

