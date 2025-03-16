N = int(input())
X = list(map(int, input().split()))
Y = X.copy()

Y.sort()

y = Y[N // 2]

for i in range(N):
    if X[i] < Y[N // 2]:
        print(Y[N // 2])
    else:
        print(Y[N // 2 - 1])
        break
    print()

print("<END-OF-CODE>")