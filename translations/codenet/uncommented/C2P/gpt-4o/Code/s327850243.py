m, n = map(int, input().split())

A = []
for i in range(m):
    row = list(map(int, input().split()))
    A.append(row)

B = list(map(int, input().split()))

S = [0] * m

for i in range(m):
    for j in range(n):
        S[i] += A[i][j] * B[j]

for i in range(m):
    print(S[i])

# <END-OF-CODE>
