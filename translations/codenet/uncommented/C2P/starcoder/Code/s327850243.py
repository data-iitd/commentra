
m,n=map(int,input().split())
A=[list(map(int,input().split())) for i in range(m)]
B=list(map(int,input().split()))
S=[0]*m
for i in range(m):
    for j in range(n):
        S[i]=S[i]+A[i][j]*B[j]
for i in range(m):
    print(S[i])

