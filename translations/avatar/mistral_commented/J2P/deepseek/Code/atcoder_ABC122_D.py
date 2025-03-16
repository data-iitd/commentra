MOD = 1000000007
TOKENS = ["A", "C", "G", "T"]

def is_ok(last4):
    if "AGC" in last4:
        return False
    for i in range(3):
        vals = list(last4)
        vals[i], vals[i + 1] = vals[i + 1], vals[i]
        if "AGC" in "".join(vals):
            return False
    return True

def dfs(current, last3, memo, N):
    if (current, last3) in memo:
        return memo[(current, last3)]
    if current == N:
        return 1
    result = 0
    for c in TOKENS:
        if is_ok(last3 + c):
            result = (result + dfs(current + 1, last3[1:] + c, memo, N)) % MOD
    memo[(current, last3)] = result
    return result

def calc(N):
    memo = {}
    return dfs(0, "TTT", memo, N)

# Read input from stdin
import sys
input_line = sys.stdin.readline().strip()
N = int(input_line)

# Output the result
print(calc(N))
