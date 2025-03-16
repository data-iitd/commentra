
import sys

def out(x):
    print(x)

def getInt():
    return int(sys.stdin.readline())

def getString():
    return sys.stdin.readline().rstrip()

def max(a, b):
    if a > b:
        return a
    return b

def min(a, b):
    if a < b:
        return a
    return b

def asub(a, b):
    if a > b:
        return a - b
    return b - a

def abs(a):
    if a >= 0:
        return a
    return -a

def lowerBound(a, x):
    idx = 0
    while idx < len(a) and a[idx] < x:
        idx += 1
    return idx

def upperBound(a, x):
    idx = 0
    while idx < len(a) and a[idx] <= x:
        idx += 1
    return idx

class shop:
    def __init__(self, a, b):
        self.a = a
        self.b = b

def main():
    N, M = getInt(), getInt()
    s = []
    for i in range(N):
        a, b = getInt(), getInt()
        s.append(shop(a, b))
    s.sort(key=lambda x: x.a)

    total = 0
    for e in s:
        n = min(e.b, M)
        total += n * e.a
        M -= n
        if M == 0:
            break
    out(total)

if __name__ == "__main__":
    main()

