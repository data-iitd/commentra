import math
import sys

# Reading input from the console
N = int(input())
x = int(input())

srimeList = [] # Creating an empty list to store the elements

# Reading elements of the array and adding them to the list
for i in range(N):
    srimeList.append(int(input()))

costList = [] # Creating an empty list to store the cost arrays

# Creating cost arrays of size N x N for each element in the original array
for i in range(N):
    costList.append([0] * N)

# Filling the cost arrays with the minimum cost for each index and each cast number
for i in range(N):
    costList[i][0] = srimeList[i] # Setting the first element of the cost array to the original element
    for castNum in range(1, N):
        costList[i][castNum] = min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N])

result = [] # Creating an empty list to store the final result

# Calculating the result for each index and adding it to the list
for i in range(N):
    temp = i * x # Multiplying the index with the multiplier
    for cost in costList[i]: # Iterating through the cost array and adding the costs
        temp += cost
    result.append(temp)

# Printing the minimum result
print(min(result))

