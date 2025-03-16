
import sys

a, b, c = map(int, input().split())
k = int(input())

patterns = DuplicatePatterns([0, 1, 2, 3], k)

for P in patterns:
    r, g, b = a, b, c
    for i in range(len(P)):
        if P[i] == 0:
            continue
        elif P[i] == 1:
            r *= 2
        elif P[i] == 2:
            g *= 2
        elif P[i] == 3:
            b *= 2

    if g > r and b > g:
        print("Yes")
        sys.exit(0)

print("No")

