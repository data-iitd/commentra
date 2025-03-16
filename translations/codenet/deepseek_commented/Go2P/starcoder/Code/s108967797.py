import sys

def ri():
    return int(sys.stdin.readline())

def ave(s):
    sum = 0
    for v in s:
        sum += v
    return float(sum) / float(len(s))

def diff(a, b):
    if a > b:
        return a - b
    return b - a

def main():
    n = ri()
    a = []
    for i in range(n):
        a.append(ri())
    ave = ave(a)
    minDiff = 999999.9
    ansIndex = -1
    for i, v in enumerate(a):
        diff = diff(v, ave)
        if diff < minDiff:
            minDiff = diff
            ansIndex = i
    print(ansIndex)

main()

