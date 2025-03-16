import sys
from io import StringIO

class InputReader:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.reader = StringIO(input_stream.read())
        self.tokenizer = None

    def next(self):
        while self.tokenizer is None or not self.tokenizer.has_more_tokens():
            self.tokenizer = self.tokenizer_new(self.reader.readline())
        return self.tokenizer.next_token()

    @staticmethod
    def tokenizer_new(line):
        return Tokenizer(line)

class Tokenizer:
    def __init__(self, line):
        self.tokens = line.split()
        self.index = 0

    def has_more_tokens(self):
        return self.index < len(self.tokens)

    def next_token(self):
        token = self.tokens[self.index]
        self.index += 1
        return token

class TaskB:
    def solve(self, test_number, inp, out):
        x = inp.next()
        s = []
        c = 0
        for i in range(len(x)):
            s.append(x[i])
            while len(s) > 1:
                p = s.pop()
                q = s.pop()
                if (p == '1' and q == '0') or (p == '0' and q == '1'):
                    c += 1
                    continue
                else:
                    s.append(q)
                    s.append(p)
                    break
        out.println(c * 2)

def main():
    input_stream = StringIO(sys.stdin.read())
    output_stream = sys.stdout
    inp = InputReader(input_stream)
    out = PrintWriter(output_stream)
    solver = TaskB()
    solver.solve(1, inp, out)
    out.close()

if __name__ == "__main__":
    main()
