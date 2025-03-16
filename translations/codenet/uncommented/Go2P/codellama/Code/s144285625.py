
import sys

n = int(sys.stdin.readline().strip())
ar = list(map(int, sys.stdin.readline().strip().split()))
ar.sort()
sum = 0
for i in range(n):
    sum += ar[3*n-(i+1)*2]
print(sum)

