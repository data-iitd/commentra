import sys
from collections import defaultdict

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    in_reader = InputReader(input_stream)
    out_writer = PrintWriter(output_stream)
    solver = TaskD()
    solver.solve(1, in_reader, out_writer)
    out_writer.close()

class TaskD:
    def solve(self, test_number, in_reader, out_writer):
        n = in_reader.next_int()
        m = in_reader.next_int()
        a = in_reader.next_int_array(n)
        dp = defaultdict(int)
        ans = 0
        base = 0
        for i in range(n):
            base = (base - a[i] % m + m) % m
            dp[(base + a[i]) % m] += 1
            ans += dp.get(base, 0)
        out_writer.println(ans)

class InputReader:
    def __init__(self, input_stream):
        self.br = BufferedReader(InputStreamReader(input_stream))
        self.st = None

    def next_string(self):
        while self.st is None or not self.st.has_more_tokens():
            try:
                self.st = StringTokenizer(self.br.readline(), " ")
            except Exception as e:
                raise InputMismatchException()
        return self.st.next_token()

    def next_int(self):
        return int(self.next_string())

    def next_int_array(self, n):
        res = [0] * n
        for i in range(n):
            res[i] = self.next_int()
        return res

class PrintWriter:
    def __init__(self, output_stream):
        self.out = output_stream
        self.print = self.out.write

    def println(self, x):
        self.print(str(x) + '\n')

if __name__ == "__main__":
    main()
