import sys
from itertools import product

def next_line():
    return sys.stdin.readline().strip()

def abs_value(a):
    return -a if a < 0 else a

def calc(dp, arr, A, B, C):
    cost = 0
    AA = BB = CC = 0
    memo = [0] * 4

    for i in range(len(dp)):
        memo[dp[i]] += 1
        if dp[i] == 1:
            AA += arr[i]
        elif dp[i] == 2:
            BB += arr[i]
        elif dp[i] == 3:
            CC += arr[i]

    cost += abs_value(A - AA) + abs_value(B - BB) + abs_value(C - CC)

    for i in range(1, 4):
        a = memo[i]
        if a < 1:
            cost += 10000
        else:
            cost += (a - 1) * 10

    return cost

def dfs(dp, times, arr, N, A, B, C):
    if times >= N:
        return calc(dp, arr, A, B, C)

    min_cost = float('inf')
    for i in range(4):
        dp[times] = i
        min_cost = min(min_cost, dfs(dp, times + 1, arr, N, A, B, C))
    return min_cost

def main():
    X = list(map(int, next_line().split()))
    N, A, B, C = X[0], X[1], X[2], X[3]

    arr = [int(next_line()) for _ in range(N)]
    dp = [0] * N

    ans = dfs(dp, 0, arr, N, A, B, C)
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
