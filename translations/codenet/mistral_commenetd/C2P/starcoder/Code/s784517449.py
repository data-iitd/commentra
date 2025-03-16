#include <stdio.h>

def binarySearch(A, key, left, right):
    if left > right:
        return 0
    mid = (left + right) // 2
    if key == A[mid]:
        return 1
    elif key > A[mid]:
        return binarySearch(A, key, mid + 1, right)
    else:
        return binarySearch(A, key, left, mid - 1)

n = int(input())
A = [int(x) for x in input().split()]
q = int(input())
sum = 0
for i in range(q):
    k = int(input())
    if binarySearch(A, k, 0, n - 1):
        sum += 1
print(sum)

