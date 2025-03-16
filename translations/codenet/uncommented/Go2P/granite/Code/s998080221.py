
import sys
import math

def read_line():
    return sys.stdin.readline().strip()

def read_int():
    return int(read_line())

def read_ints():
    return list(map(int, read_line().split()))

def read_str():
    return read_line()

def read_strs():
    return read_line().split()

def read_str_list():
    return read_line().split()

def err(*args):
    print(*args, file=sys.stderr)

def read():
    r = []
    for line in sys.stdin.readlines():
        r.append(line.strip())
    return r

def read_int_grid(H, W):
    return [read_ints() for _ in range(H)]

def read_str_grid(H, W):
    return [read_strs() for _ in range(H)]

def solve():
    N, _ = read_ints()
    A = read_ints()
    max_profit = 0
    max_cnt = 0
    max_a = A[-1]
    for i in range(N-2, -1, -1):
        profit = max(0, max_a - A[i])
        if max_profit < profit:
            max_profit = profit
            max_cnt = 1
        elif max_profit == profit:
            max_cnt += 1
        max_a = max(max_a, A[i])
    print(max_cnt)

def main():
    solve()

if __name__ == "__main__":
    main()

