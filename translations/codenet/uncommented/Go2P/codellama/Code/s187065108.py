
import sys

r, D, x = map(int, sys.stdin.readline().split())
for i in range(1, 11):
    x = r*x - D
    print(x)

