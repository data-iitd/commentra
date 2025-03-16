import sys
import io
import os
import sys
import io
import os
import sys

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    in_reader = InputReader(input_stream)
    out_writer = io.TextIOWrapper(output_stream, line_buffering=True)
    out = io.BufferedWriter(out_writer)
    solver = TaskD()
    solver.solve(1, in_reader, out)
    out.flush()

class TaskD:
    def solve(self, test_number, in_reader, out):
        S = in_reader.next()
        score = 0
        for i in range(len(S)):
            my = 'g' if i % 2 == 0 else 'p'
            his = S[i]
            if my != his:
                score += 1 if my == 'p' else -1
        out.write(str(score) + '\n')

class InputReader:
    def __init__(self, stream):
        self.reader = io.BufferedReader(stream, buffer_size=32768)
        self.tokenizer = None

    def next(self):
        while self.tokenizer is None or not self.tokenizer.has_more_tokens():
            self.tokenizer = io.StringTokenizer(self.reader.readline())
        return self.tokenizer.next_token()

if __name__ == "__main__":
    main()
