
import sys

def readInt():
    return int(sys.stdin.readline())

def readFloat64():
    return float(sys.stdin.readline())

def readString():
    return sys.stdin.readline().strip()

def main():
    n, m = readInt(), readInt()
    a = [readInt() for _ in range(m)]
    sum_a = sum(a)
    if sum_a > n:
        print(-1)
        return
    print(n - sum_a)

