import sys
import io
import os
import math

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    in_reader = InputReader(input_stream)
    out_writer = io.TextIOWrapper(output_stream)
    solver = CColoringColorfully()
    solver.solve(1, in_reader, out_writer)
    out_writer.flush()
    out_writer.close()

class CColoringColorfully:
    def solve(self, test_number, in_reader, out_writer):
        x = in_reader.next()
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
        out_writer.write(str(min(a1, a2)) + '\n')

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.reader = io.BufferedReader(io.InputStreamReader(stream), 32768)
        self.tokenizer = None

    def next(self):
        while self.tokenizer is None or not self.tokenizer.has_more_tokens():
            try:
                self.tokenizer = io.StringTokenizer(self.reader.readline())
            except io.IOException:
                raise RuntimeError()
        return self.tokenizer.next_token()

if __name__ == "__main__":
    main()
