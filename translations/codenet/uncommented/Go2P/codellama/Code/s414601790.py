
import sys

n, s = sys.stdin.readline().split()
n = int(n)
s = list(s)

max = 0
cnt = 0
for r in s:
    if r == 'I':
        cnt += 1
    else:
        cnt -= 1

    if cnt > max:
        max = cnt

print(max)

