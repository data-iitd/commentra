import sys
import io
import os
import sys
import io
import os
import sys

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.reader = io.TextIOWrapper(io.BufferedReader(io.FileIO(stream)))
        self.tokenizer = None

    def next(self):
        while self.tokenizer is None or not self.tokenizer.has_more_tokens():
            line = self.reader.readline()
            if not line:
                return None
            self.tokenizer = io.StringIO(line).readline
        return self.tokenizer.next()

class PrintWriter:
    def __init__(self, stream):
        self.stream = stream
        self.writer = io.TextIOWrapper(io.BufferedWriter(io.FileIO(stream)))

    def print(self, *args, **kwargs):
        print(*args, **kwargs, file=self.writer)
        self.writer.flush()

    def close(self):
        self.writer.close()

class TaskD:
    def solve(self, test_number, inp, out):
        S = inp.next()
        score = 0

        for i in range(len(S)):
            my = 'g' if i % 2 == 0 else 'p'
            his = S[i]

            if my != his:
                score += 1 if my == 'p' else -1

        out.print(score)

def main():
    stream = sys.stdin
    out = PrintWriter(sys.stdout)
    inp = InputReader(stream)
    solver = TaskD()
    solver.solve(1, inp, out)
    out.close()

if __name__ == "__main__":
    main()

