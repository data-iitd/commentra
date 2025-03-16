A, B, C, X = map(int, input().split())

X //= 50
kosu = 0

for i in range(A + 1):
    for j in range(B + 1):
        for k in range(C + 1):
            if X == (10 * i) + (2 * j) + k:
                kosu += 1

print(kosu)
