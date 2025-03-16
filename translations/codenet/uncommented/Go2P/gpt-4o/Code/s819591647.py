import sys
import math

constMod = int(1e9) + 7

def get_int():
    return int(sys.stdin.readline().strip())

def get_int_slice(n):
    return list(map(int, sys.stdin.readline().strip().split()))[:n]

def solve():
    n, m = get_int(), get_int()
    a = get_int_slice(n)

    total_sum = sum(a)

    count = sum(1 for v in a if v >= total_sum / (4 * m))

    if count >= m:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    solve()
    
# <END-OF-CODE>
