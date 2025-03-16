import sys
from io import StringIO

class InputReader:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.reader = StringIO(input_stream.read())
        self.tokenizer = None

    def next(self):
        while self.tokenizer is None or not self.tokenizer.has_more_tokens():
            self.tokenizer = self.reader.readline()
        return self.tokenizer.split()[0]

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

    def next_line(self):
        return self.reader.readline()

class Task:
    def solve(self, inp, out):
        n = inp.next_int()
        array = [0] * 1001

        for i in range(n):
            index = inp.next_int()
            array[index] += 1

        count_max = -1
        for i in range(1, len(array)):
            if count_max < array[i]:
                count_max = array[i]

        if n % 2 == 0:
            if count_max <= n // 2:
                out.write("YES\n")
            else:
                out.write("NO\n")
        else:
            if count_max <= n // 2 + 1:
                out.write("YES\n")
            else:
                out.write("NO\n")

def main():
    input_stream = StringIO("".join(sys.stdin.readlines()))
    sys.stdin = input_stream
    output_stream = StringIO()
    sys.stdout = output_stream

    inp = InputReader(input_stream)
    out = output_stream

    solver = Task()
    solver.solve(inp, out)

    sys.stdout = sys.__stdout__
    print(output_stream.getvalue())

if __name__ == "__main__":
    main()
