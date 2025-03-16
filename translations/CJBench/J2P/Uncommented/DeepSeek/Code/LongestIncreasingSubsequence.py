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
        if array[i] < tail[0]:
            tail[0] = array[i]
        elif array[i] > tail[length - 1]:
            tail[length] = array[i]
            length += 1
        else:
            tail[upper_bound(tail, -1, length - 1, array[i])] = array[i]
    return length

def find_lis_len(a):
    size = len(a)
    if size == 0:
        return 0
    arr = [0] * size
    arr[0] = a[0]
    lis_ = 1
    for i in range(1, size):
        index = binary_search_between(arr, lis_ - 1, a[i])
        arr[index] = a[i]
        if index == lis_:
            lis_ += 1
    return lis_

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

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    array = [int(data[i + 1]) for i in range(n)]
    method = int(data[n + 1])
    result = 0
    if method == 1:
        result = lis(array)
    else:
        result = find_lis_len(array)
    print("The length of the longest increasing subsequence is: " + str(result))

if __name__ == "__main__":
    main()
