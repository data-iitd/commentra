import sys
import io
import os
import math

class InputReader:
    def __init__(self, input_stream):
        self.input_stream = input_stream

    def next(self):
        while not hasattr(self, 'tokenizer'):
            self.tokenizer = io.StringIO(self.input_stream.readline().strip())
        try:
            return next(self.tokenizer)
        except StopIteration:
            return None

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    inp = InputReader(input_stream)
    out = io.TextIOWrapper(output_stream, write_through=True)

    a = inp.next_int()
    b = inp.next_int()
    c = inp.next_int()
    d = inp.next_int()

    if c > b:
        print(0)
    elif a > d:
        print(0)
    elif a < c:
        print(min(b, d) - c)
    else:
        l = [a, b, c, d]
        l.sort()
        print(l[2] - l[1])

if __name__ == "__main__":
    main()
