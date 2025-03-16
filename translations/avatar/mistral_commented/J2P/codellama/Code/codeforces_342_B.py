
import sys

def main():
    m, s, f = map(int, sys.stdin.readline().split())
    max_t = -1
    map = {}

    for i in range(m):
        k, a, b = map(int, sys.stdin.readline().split())
        map[k] = [a, b]
        max_t = max(max_t, k)

    actions = ""
    d = 1 if s < f else -1
    cur = s

    for t in range(1, max_t + 1):
        if t in map:
            a, b = map[t]
            if cur >= a and cur <= b or cur + d >= a and cur + d <= b:
                actions += "X"
            else:
                actions += "R" if d == 1 else "L"
                cur += d
        else:
            actions += "R" if d == 1 else "L"
            cur += d

        if cur == f:
            break

    while cur != f:
        actions += "R" if d == 1 else "L"
        cur += d

    print(actions)

if __name__ == "__main__":
    main()

