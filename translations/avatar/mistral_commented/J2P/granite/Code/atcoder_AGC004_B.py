
import sys

# Reading input from the console
N, x = map(int, input().split())
srimeList = list(map(int, input().split()))

# Creating cost arrays of size N x N for each element in the original array
costList = [[0] * N for _ in range(N)]
for i in range(N):
    costList[i][0] = srimeList[i]
    for castNum in range(1, N):
        costList[i][castNum] = min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N])

# Calculating the result for each index and finding the minimum result
result = []
for i in range(N):
    temp = i * x
    for cost in costList[i]:
        temp += cost
    result.append(temp)

print(min(result))

