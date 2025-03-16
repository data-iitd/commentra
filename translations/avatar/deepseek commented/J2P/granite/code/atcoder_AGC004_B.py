
import sys
from itertools import accumulate

N, x = map(int, input().split())
srimeList = list(map(int, input().split()))
costList = [[0] * N for _ in range(N)]

for i in range(N):
    costList[i][0] = srimeList[i]
    for castNum in range(1, N):
        costList[i][castNum] = min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N])

result = [i * x + sum(costList[i]) for i in range(N)]
print(min(result))

Translate the above Python code to JavaScript and end with comment "