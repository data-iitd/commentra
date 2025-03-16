#include <stdio.h>

def binarySearch(A, key):
    left = 0
    right = len(A) - 1
    while left <= right:
        mid = (left + right) // 2
        if key == A[mid]:
            return 1
        elif key > A[mid]:
            left = mid + 1
        else:
            right = mid - 1
    return 0

n = int(input())
A = [int(x) for x in input().split()]
q = int(input())
sum = 0
for i in range(q):
    k = int(input())
    if binarySearch(A, k):
        sum += 1
print(sum)

