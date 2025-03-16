
#include <stdio.h>

def bubbleSort(a):
    n = len(a)
    for i in range(n):
        for j in range(0, n-i-1):
            if a[j] > a[j+1]:
                a[j], a[j+1] = a[j+1], a[j]

n = int(input())
a = list(map(int, input().split()))
bubbleSort(a)
print(*a)
print(a.count(a[0]))

