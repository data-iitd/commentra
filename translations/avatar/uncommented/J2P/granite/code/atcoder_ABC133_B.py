
import math
import sys

N, D = map(int, input().split())
vectors = [list(map(int, input().split())) for _ in range(N)]

answer = 0
for i in range(N - 1):
    for j in range(i + 1, N):
        dist = 0
        for d in range(D):
            x = vectors[i][d] - vectors[j][d]
            dist += x * x
        sq = math.sqrt(dist)
        if abs(sq - math.floor(sq)) < 0.001:
            answer += 1

print(answer)

