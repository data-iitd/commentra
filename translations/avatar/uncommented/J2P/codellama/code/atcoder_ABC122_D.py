import sys

def main():
    N = int(sys.stdin.readline().strip())
    memo = [{} for _ in range(N+1)]
    for i in range(N+1):
        memo[i] = {}
    print(dfs(0, "TTT"))

def isOK(last4):
    if "AGC" in last4:
        return False
    for i in range(3):
        vals = list(last4)
        vals[i] = last4[i+1]
        vals[i+1] = last4[i]
        s = "".join(vals)
        if "AGC" in s:
            return False
    return True

def dfs(current, last3):
    if memo[current].get(last3) is not None:
        return memo[current][last3]
    if current == N:
        return 1
    result = 0
    for c in TOKENS:
        if isOK(last3 + c):
            result = (result + dfs(current + 1, last3[1:] + c)) % MOD
    memo[current][last3] = result
    return result

if __name__ == "__main__":
    main()

