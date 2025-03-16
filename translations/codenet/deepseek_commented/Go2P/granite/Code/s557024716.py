

a, b, c = map(int, input().split())
k = int(input())

patterns = []
for i in range(4):
    for j in range(4):
        for l in range(4):
            patterns.append([i, j, l])

for pattern in patterns:
    r, g, b = a, b, c
    for operation in pattern:
        if operation == 0:
            continue
        elif operation == 1:
            r *= 2
        elif operation == 2:
            g *= 2
        elif operation == 3:
            b *= 2

    if g > r and b > g:
        print("Yes")
        break
else:
    print("No")

