import sys
import io
import os

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.buffer = io.BytesIO()
        self.writable = "x"
        self.write = self.buffer.write

    def read(self):
        while True:
            b = os.read(self.stream, 1024)
            if not b:
                break
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(0)
        return self.buffer.read()

    def readline(self):
        while True:
            b = os.read(self.stream, 1024)
            if not b:
                break
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(0)
        return self.buffer.readline()

    def __iter__(self):
        while True:
            b = os.read(self.stream, 1024)
            if not b:
                break
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(0)
        return iter(self.buffer.readline().split())

    def next(self):
        return self.readline()

class CColoringColorfully:
    def solve(self, testNumber, inp, out):
        x = inp.readline().decode().strip()
        a = list(x)
        b = list(x)
        a1 = 0
        a2 = 0
        for i in range(1, len(x)):
            if a[i] == a[i - 1]:
                a[i] = '1' if a[i] == '0' else '0'
                a1 += 1
        for i in range(len(x) - 1, 0, -1):
            if b[i] == b[i - 1]:
                b[i - 1] = '1' if b[i - 1] == '0' else '0'
                a2 += 1
        out.write(str(min(a1, a2)) + '\n')

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    inp = InputReader(input_stream)
    out = io.TextIOWrapper(output_stream, write_through=True)
    solver = CColoringColorfully()
    test_number = 1
    solver.solve(test_number, inp, out)
    out.flush()

if __name__ == "__main__":
    main()
