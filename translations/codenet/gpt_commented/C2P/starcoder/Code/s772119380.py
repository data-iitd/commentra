#include <stdio.h>

def bubble_sort(a):
    n = len(a)
    d = 0
    for i in range(n):
        for j in range(n - 1, i, -1):
            if a[j] < a[j - 1]:
                a[j], a[j - 1] = a[j - 1], a[j]
                d += 1
    return d

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    d = bubble_sort(a)
    print(' '.join(map(str, a)))
    print(d)

