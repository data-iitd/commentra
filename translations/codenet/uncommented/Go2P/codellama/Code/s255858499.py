
import sys

a, b = map(int, sys.stdin.readline().split())

if a*b % 2 != 0:
    print("Odd")
else:
    print("Even")

