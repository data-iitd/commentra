
import sys

def upperBound(ar, l, r, key):
    while l < r - 1:
        m = (l + r) // 2
        if ar[m] >= key:
            r = m
        else:
            l = m
    return r

def lis(array):
    len = len(array)
    if len == 0:
        return 0
    tail = [0] * len
    length = 1
    tail[0] = array[0]
    for i in range(1, len):
        if array[i] < tail[0]:
            tail[0] = array[i]
        elif array[i] > tail[length - 1]:
            tail[length] = array[i]
        else:
            tail[upperBound(tail, -1, length - 1, array[i])] = array[i]
    return length

def findLISLen(a):
    size = len(a)
    if size == 0:
        return 0
    arr = [0] * size
    arr[0] = a[0]
    lis = 1
    for i in range(1, size):
        index = binarySearchBetween(arr, lis - 1, a[i])
        arr[index] = a[i]
        if index == lis:
            lis += 1
    return lis

def binarySearchBetween(t, end, key):
    left = 0
    right = end
    if key < t[0]:
        return 0
    if key > t[end]:
        return end + 1
    while left < right - 1:
        middle = (left + right) // 2
        if t[middle] < key:
            left = middle
        else:
            right = middle
    return right

def main():
    n = int(input())
    array = [0] * n
    for i in range(n):
        array[i] = int(input())
    method = int(input())
    if method == 1:
        result = lis(array)
    else:
        result = findLISLen(array)
    print("The length of the longest increasing subsequence is: " + str(result))

if __name__ == "__main__":
    main()

