
import sys

h, n = map(int, input().split())
a = sum(map(int, input().split()))

if h > a:
    print("No")
else:
    print("Yes")
