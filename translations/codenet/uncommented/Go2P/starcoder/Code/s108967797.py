import sys

def ri():
    return int(sys.stdin.readline().strip())

def main():
    n = ri()
    a = [0.0 for i in range(n)]
    for i in range(n):
        a[i] = float(ri())
    ave = sum(a) / float(n)
    minDiff = 999999.9
    ansIndex = -1
    for i, v in enumerate(a):
        diff = abs(v - ave)
        if diff < minDiff:
            minDiff = diff
            ansIndex = i
    print(ansIndex)

main()
# 