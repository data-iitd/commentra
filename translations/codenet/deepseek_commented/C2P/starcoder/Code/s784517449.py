#include <stdio.h>

A = [0] * 1000000
n = 0

def binarySearch(key):
    left = 0
    right = n
    mid = 0
    while left < right:
        mid = (left + right) / 2
        if key == A[mid]:
            return 1
        if key > A[mid]:
            left = mid + 1
        else:
            right = mid
    return 0

def main():
    global n
    sum = 0
    q = int(input())
    for i in range(q):
        k = int(input())
        if binarySearch(k):
            sum += 1
    print(sum)

if __name__ == '__main__':
    main()

