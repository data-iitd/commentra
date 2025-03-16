import sys
import io
import os
import tokenize

class InputReader:
    def __init__(self, input_stream):
        self.input_stream = input_stream

    def next(self):
        while True:
            token = self.input_stream.readline()
            if token:
                return token.strip()
            else:
                break

class TaskD:
    def solve(self, test_number, in_reader, out_writer):
        S = in_reader.next()
        score = 0
        for i in range(len(S)):
            my = 'g' if i % 2 == 0 else 'p'
            his = S[i]
            if my != his:
                score += 1 if my == 'p' else -1
        out_writer.write(str(score) + '\n')

def main():
    input_stream = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
    output_stream = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')
    in_reader = InputReader(input_stream)
    out_writer = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')
    solver = TaskD()
    solver.solve(1, in_reader, out_writer)

if __name__ == "__main__":
    main()
