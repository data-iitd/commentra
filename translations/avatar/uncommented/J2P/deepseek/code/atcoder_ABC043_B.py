import sys
import io
import os
import re

def main():
    input_stream = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
    output_stream = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')
    in_ = LightScanner(input_stream)
    out = io.TextIOWrapper(output_stream)
    solver = BUnhappyHackingABCEdit()
    solver.solve(1, in_, out)
    out.flush()

class BUnhappyHackingABCEdit:
    def solve(self, test_number, in_, out):
        s = in_.string()
        d = []
        for c in s:
            if c == '0':
                d.append('0')
            elif c == '1':
                d.append('1')
            elif c == 'B':
                if d:
                    d.pop()
        out.write(''.join(d))

class LightScanner:
    def __init__(self, input_stream):
        self.reader = io.TextIOWrapper(input_stream, encoding='utf-8')
        self.tokens = []

    def string(self):
        while not self.tokens:
            self.tokens = self.reader.readline().split()
        token = self.tokens[0]
        self.tokens = self.tokens[1:]
        return token

if __name__ == '__main__':
    main()
