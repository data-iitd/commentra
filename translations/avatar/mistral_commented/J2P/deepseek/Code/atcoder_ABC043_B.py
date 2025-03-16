import sys
import io
import os
import tokenize

class LightScanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.tokenizer = None

    def string(self):
        if self.tokenizer is None or not self.tokenizer.has_more_tokens():
            try:
                line = self.input_stream.readline()
                if line is None:
                    raise Exception("No more input")
                self.tokenizer = tokenize.tokenize(io.StringIO(line).readline)
            except Exception as e:
                raise Exception("I/O error: " + str(e))
        return self.tokenizer.get_token()

class BUnhappyHackingABCEdit:
    def solve(self, test_number, in_scanner, out_writer):
        s = in_scanner.string()
        d = []

        for c in s:
            if c == '0':
                d.append("0")
            elif c == '1':
                d.append("1")
            elif c == 'B' and d:
                d.pop()

        out_writer.write(''.join(d) + '\n')

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    in_scanner = LightScanner(input_stream)
    out_writer = io.TextIOWrapper(output_stream, write_through=True)

    test_number = 1
    solver = BUnhappyHackingABCEdit()

    solver.solve(test_number, in_scanner, out_writer)

    out_writer.flush()

if __name__ == "__main__":
    main()

