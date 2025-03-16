

import sys

def main():
    a, b, c = map(int, input().split())
    k = int(input())

    patterns = duplicate_patterns([0, 1, 2, 3], k)

    for pattern in patterns:
        r, g, b = a, b, c
        for i in range(len(pattern)):
            if pattern[i] == 0:
                continue
            elif pattern[i] == 1:
                r *= 2
            elif pattern[i] == 2:
                g *= 2
            elif pattern[i] == 3:
                b *= 2

        if g > r and b > g:
            print("Yes")
            return

    print("No")

def duplicate_patterns(elems, k):
    if k == 0:
        return [[]]

    res = []
    for e in elems:
        new_pattern = []
        for pattern in duplicate_patterns(elems, k - 1):
            new_pattern = pattern + [e]
            res.append(new_pattern)

    return res

if __name__ == "__main__":
    main()

