
import sys

def ri():
    return int(sys.stdin.readline().strip())

def ave(s):
    return sum(s) / len(s)

def diff(a, b):
    if a > b:
        return a - b
    return b - a

n = ri()
a = [float(sys.stdin.readline().strip()) for _ in range(n)]

ave = ave(a)

minDiff = 999999.9
ansIndex = -1
for i, v in enumerate(a):
    diff = diff(v, ave)
    if diff < minDiff:
        minDiff = diff
        ansIndex = i

print(ansIndex)

