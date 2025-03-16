
import sys

def main():
    m = int(sys.stdin.readline().split()[1])
    s = int(sys.stdin.readline().split()[2])
    f = int(sys.stdin.readline().split()[3])
    maxT = -1
    map = {}
    while m > 0:
        mth = sys.stdin.readline().split()
        k = int(mth[0])
        map[k] = [int(mth[1]), int(mth[2])]
        maxT = max(maxT, k)
        m -= 1
    actions = ""
    M = "R" if s < f else "L"
    d = 1 if s < f else -1
    cur = s
    a = -1
    b = -1
    for t in range(1, maxT + 1):
        if map.get(t) is not None:
            a = map[t][0]
            b = map[t][1]
        if map.get(t) is not None and (cur >= a and cur <= b or cur + d >= a and cur + d <= b):
            actions += "X"
        else:
            actions += M
        cur += d
        if cur == f:
            break
    while cur != f:
        actions += M
        cur += d
    print(actions)


if __name__ == "__main__":
    main()


