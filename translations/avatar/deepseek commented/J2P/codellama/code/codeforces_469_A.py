
import sys

n = int(input())
levels = int(input())
arr = []

for i in range(levels):
    arr.append(int(input()))

level2 = int(input())
level3 = levels + level2
arr2 = []

for i in range(levels):
    arr2.append(arr[i])

for i in range(levels, level3):
    arr2.append(int(input()))

arr3 = []
j = 0
for i in range(n):
    arr3.append(j + 1)
    j += 1

count = 0
for i in range(n):
    for x in range(level3):
        if arr3[i] == arr2[x]:
            count += 1
            break

if count == n:
    print("I become the guy.")
else:
    print("Oh, my keyboard!")

