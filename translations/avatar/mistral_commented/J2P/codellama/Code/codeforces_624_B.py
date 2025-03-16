
import array
import sys

n = int(input())
arr = array.array('l', sys.stdin.readline().split())
arr.sort()
count = arr[n-1]

for i in range(n-2, -1, -1):
    if arr[i] < arr[i+1]:
        count += arr[i]
    else:
        while arr[i] >= arr[i+1]:
            arr[i] -= 1
        if arr[i] > 0:
            count += arr[i]

print(count)

