
import sys

def maxLeft(n):
    return n - 2 if n > 2 else 0

for _ in range(int(sys.stdin.readline())):
    n = int(sys.stdin.readline())
    print(maxLeft(n))

