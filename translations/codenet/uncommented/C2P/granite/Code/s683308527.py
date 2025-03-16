
import sys

n = int(input())
while n > 0:
    s = sys.stdin.readline()
    while "Hoshino" in s:
        s = s.replace("Hoshino", "a" * 6, 1)
    print(s, end="")
    n -= 1

# 