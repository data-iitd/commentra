import math
import sys

N = int(input())
x = int(input())

srimeList = []
for i in range(N):
    srimeList.append(int(input()))

costList = []
for i in range(N):
    costList.append([])
    for j in range(N):
        costList[i].append(0)

for i in range(N):
    costList[i][0] = srimeList[i]
    for j in range(1, N):
        costList[i][j] = min(costList[i][j - 1], srimeList[(i - j + N) % N])

result = []
for i in range(N):
    result.append(i * x + sum(costList[i]))

print(min(result))

