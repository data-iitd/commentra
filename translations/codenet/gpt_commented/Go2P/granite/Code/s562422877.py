
import sys
from itertools import accumulate

N = int(input())
A = list(map(int, input().split()))
A.sort()

print(sum(accumulate(A[i+1] - A[i] for i in range(N-1))))

