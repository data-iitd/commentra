import sys
import math

# Util functions
def next_int():
    return int(sys.stdin.readline().strip())

def min_int(a, b):
    return a if a < b else b

def main():
    # 'S'がN個、'c'がM個
    N, M = next_int(), next_int()
    tmp = min_int(N, M // 2)
    ans = 0
    ans += tmp
    N -= tmp
    M -= tmp * 2
    print(ans + M // 4)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
