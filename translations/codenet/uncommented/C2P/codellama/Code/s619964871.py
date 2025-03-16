
#include <stdio.h>
#include <stdlib.h>
#define unko 1e12
def sort(a, left, middle, right):
    l_arr = [0] * (middle-left+1)
    r_arr = [0] * (right-middle+1)
    cnt = 0
    for i in range(middle-left):
        l_arr[i] = a[i+left]
    for i in range(right-middle):
        r_arr[i] = a[i+middle]
    l_arr[middle-left] = unko
    r_arr[right-middle] = unko
    l = 0
    r = 0
    for i in range(right-left):
        if l_arr[l] <= r_arr[r]:
            a[left+i] = l_arr[l]
            l += 1
        else:
            a[left+i] = r_arr[r]
            r += 1
            cnt += middle-left-l
    return cnt

def merge(a, left, right):
    if left+1 < right:
        middle = (left+right)//2
        x1 = merge(a, left, middle)
        x2 = merge(a, middle, right)
        x3 = sort(a, left, middle, right)
        return x1+x2+x3
    else:
        return 0

n = int(input())
a = [0] * n
for i in range(n):
    a[i] = int(input())
print(merge(a, 0, n))

