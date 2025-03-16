
N = int(input())
X = list(map(int,input().split()))
Y = X[:]
Y.sort()
y = Y[N//2]
for i in range(N):
    if X[i] < y:
        print(y)
    else:
        print(Y[N//2-1])

