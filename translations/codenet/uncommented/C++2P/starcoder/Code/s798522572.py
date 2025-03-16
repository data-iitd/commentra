
N, T = map(int, raw_input().split())
A = map(int, raw_input().split())
B = [0] * N
B[1] = A[1] - A[0]
m = min(A[0], A[1])
for i in range(2, N):
    B[i] = A[i] - m
    m = min(m, A[i])
print B.count(max(B))

