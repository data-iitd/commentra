import sys
from io import StringIO
from collections import defaultdict

class InputReader:
    def __init__(self, input_stream):
        self.input_stream = input_stream

    def next_string(self):
        try:
            line = self.input_stream.readline()
            if not line:
                return None
            self.line = line.strip().split()
            self.index = 0
        except:
            raise Exception("Input error")
        return self.line[self.index]

    def next_int(self):
        return int(self.next_string())

    def next_int_array(self, n):
        return [int(self.next_string()) for _ in range(n)]

class PrintWriter:
    def __init__(self, output_stream):
        self.output_stream = output_stream

    def print(self, *args, sep=' ', end='\n'):
        self.output_stream.write(sep.join(map(str, args)) + end)

    def close(self):
        pass

class TaskD:
    def solve(self, test_number, inp, out):
        n = inp.next_int()
        m = inp.next_int()

        a = inp.next_int_array(n)
        dp = defaultdict(int)

        ans = 0
        base = 0

        for i in range(n):
            base = (base - a[i] % m + m) % m
            dp[base + a[i] % m] += 1
            ans += dp[base]

        out.print(ans)

def main():
    input_stream = StringIO(sys.stdin.read())
    output_stream = sys.stdout
    inp = InputReader(input_stream)
    out = PrintWriter(output_stream)
    solver = TaskD()
    solver.solve(1, inp, out)
    out.close()

if __name__ == "__main__":
    main()
