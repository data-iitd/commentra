
N = int(input())
X = [int(input()) for _ in range(N)]
Y = sorted(X)
y = Y[N//2]
for x in X:
    if x < y:
        print(y)
    else:
        print(Y[N//2 - 1])
