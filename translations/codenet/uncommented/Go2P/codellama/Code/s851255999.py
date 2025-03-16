
import sys

n = int(sys.stdin.readline())
ws = []
for i in range(n):
    a, n = map(int, sys.stdin.readline().split())
    ws.append((a, n))

ws.sort(key=lambda x: x[1])

sum = 0
for w in ws:
    sum += w[0]
    if sum > w[1]:
        print("No")
        break
else:
    print("Yes")

