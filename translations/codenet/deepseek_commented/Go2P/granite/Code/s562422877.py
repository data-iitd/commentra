
import sys
from itertools import accumulate

N = int(input())
A = list(map(int, input().split()))
A.sort()

ans = sum(accumulate(A[1:])))
print(ans)

