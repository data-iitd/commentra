
import sys
from bisect import bisect_left

N = int(input())
X = list(map(int, input().split()))
Y = sorted(X)
y = Y[N // 2]

for x in X:
    if x < y:
        print(y)
    else:
        print(y - 1)
print("