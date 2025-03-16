

a, b, c = map(int, input().split())
k = int(input())

patterns = [[]]
for _ in range(k):
    patterns = [p + [i] for p in patterns for i in range(4)]

for P in patterns:
    r, g, b = a, b, c
    for i in P:
        if i == 0:
            continue
        elif i == 1:
            r *= 2
        elif i == 2:
            g *= 2
        elif i == 3:
            b *= 2
    if g > r and b > g:
        print("Yes")
        break
else:
    print("No")

