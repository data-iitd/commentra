import sys

# Reading input from the user
a = int(input())
ar = list(map(int, input().split()))

# Initializing max and min to 0
max = 0
min = 0

# Calculating the minimum and maximum differences between consecutive elements of the array
for i in range(a):
    max = max(ar[i] - ar[0], ar[a - 1] - ar[i])
    if i == 0:
        min = ar[i + 1] - ar[i]
    elif i == a - 1:
        min = ar[i] - ar[i - 1]
    else:
        min = min(ar[i] - ar[i - 1], ar[i + 1] - ar[i])
    print(min, max)

# 