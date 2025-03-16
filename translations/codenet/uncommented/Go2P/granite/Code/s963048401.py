
import sys

def Scanner():
    return sys.stdin.readline().rstrip()

def intScanner():
    return int(Scanner())

def floatScanner():
    return float(Scanner())

def stringToInt(s):
    return int(s)

mod = 1000000007

n = intScanner()
as = [intScanner() for _ in range(n)]
xs = [as[0]]
for j in range(1, n):
    idx = 0
    while idx < len(xs) and xs[idx] < as[j]:
        idx += 1
    if idx == len(xs):
        xs.append(as[j])
    else:
        xs[idx] = as[j]
print(len(xs))

