
import sys

n = int(raw_input())
k = int(raw_input())
arr = []
for i in range(n):
    arr.append(int(raw_input()))
arr.sort()
count = 0
for i in range(n):
    if arr[i] % k!= 0:
        count += 1
    else:
        if arr[i] / k not in arr:
            count += 1
print count

