import sys
from collections import defaultdict

class TaskD:
    def solve(self, test_number, in_stream, out_stream):
        n = int(in_stream.readline().strip())
        m = int(in_stream.readline().strip())
        a = list(map(int, in_stream.readline().strip().split()))
        
        dp = defaultdict(int)
        ans = 0
        base = 0
        
        for i in range(n):
            base = (base - a[i] % m + m) % m
            dp[(base + a[i]) % m] += 1
            ans += dp[base]
        
        out_stream.write(f"{ans}\n")

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    solver = TaskD()
    solver.solve(1, input_stream, output_stream)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
