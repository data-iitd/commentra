
import sys

def upper_bound(ar, l, r, key):
    while l < r - 1:
        m = (l + r) // 2
        if ar[m] >= key:
            r = m
        else:
            l = m
    return r

def lis(array):
    len_ = len(array)
    if len_ == 0:
        return 0

    tail = [0] * len_
    length = 1

    tail[0] = array[0]
    for i in range(1, len_):
        # new smallest value
        if array[i] < tail[0]:
            tail[0] = array[i]
        # array[i] extends largest subsequence
        elif array[i] > tail[length - 1]:
            tail[length] = array[i]
        # array[i] will become end candidate of an existing subsequence or
        # Throw away larger elements in all LIS, to make room for upcoming grater elements than
        # array[i]
        # (and also, array[i] would have already appeared in one of LIS, identify the location
        # and replace it)
        else:
            tail[upper_bound(tail, -1, length - 1, array[i])] = array[i]

    return length

def find_lis_len(a):
    size = len(a)
    if size == 0:
        return 0
    arr = [0] * size
    arr[0] = a[0]
    lis = 1
    for i in range(1, size):
        index = binary_search_between(arr, lis - 1, a[i])
        arr[index] = a[i]
        if index == lis:
            lis += 1
    return lis

def binary_search_between(t, end, key):
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

if __name__ == "__main__":
    n = int(input())

    array = [int(i) for i in input().split()]

    method = int(input())

    result = 0
    if method == 1:
        result = lis(array)
    else:
        result = find_lis_len(array)

    print("The length of the longest increasing subsequence is: " + str(result))

