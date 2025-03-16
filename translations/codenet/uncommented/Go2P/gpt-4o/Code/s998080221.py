import sys

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def solve():
    N, _ = read_ints()
    A = read_ints()
    
    max_profit = 0
    max_cnt = 0
    max_a = A[-1]
    
    for i in range(N - 2, -1, -1):
        profit = max(0, max_a - A[i])
        if max_profit < profit:
            max_profit = profit
            max_cnt = 1
        elif max_profit == profit:
            max_cnt += 1
        max_a = max(max_a, A[i])
    
    print(max_cnt)

if __name__ == "__main__":
    solve()
# <END-OF-CODE>
