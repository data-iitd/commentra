import sys
from io import StringIO
from collections import defaultdict

class InputReader:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.tokens = StringIO().getvalue().split()

    def next_string(self):
        while not self.tokens:
            self.tokens = self.input_stream.readline().split()
        return self.tokens.pop(0)

    def next_int(self):
        return int(self.next_string())

    def next_int_array(self, n):
        return [self.next_int() for _ in range(n)]

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
            dp[(base + a[i]) % m] += 1
            ans += dp.get(base, 0)
        
        out.write(f"{ans}\n")

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    
    inp = InputReader(input_stream)
    out = sys.stdout
    
    solver = TaskD()
    solver.solve(1, inp, out)

if __name__ == "__main__":
    main()
