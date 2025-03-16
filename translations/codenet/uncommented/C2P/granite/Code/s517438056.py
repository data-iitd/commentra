
import math

N, D = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(N)]

k = 0
for i in range(N - 1):
    for j in range(i + 1, N):
        m = 0
        for n in range(D):
            m += (matrix[i][n] - matrix[j][n]) ** 2
        l = math.sqrt(m)
        if l.is_integer():
            k += 1

print(k)

