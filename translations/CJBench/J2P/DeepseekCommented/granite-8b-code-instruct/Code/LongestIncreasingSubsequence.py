
import bisect

def upper_bound(ar, l, r, key):
    while l < r - 1:
        m = (l + r) // 2
        if ar[m] >= key:
            r = m
        else:
            l = m
    return r

def lis(array):
    len_array = len(array)
    if len_array == 0:
        return 0
    tail = [array[0]]
    length = 1
    for i in range(1, len_array):
        if array[i] < tail[0]:
            tail[0] = array[i]
        elif array[i] > tail[length - 1]:
            tail.append(array[i])
            length += 1
        else:
            tail[upper_bound(tail, -1, length - 1, array[i])] = array[i]
    return length

def find_lis_len(a):
    size = len(a)
    if size == 0:
        return 0
    arr = [a[0]]
    lis = 1
    for i in range(1, size):
        index = bisect.bisect_left(arr, a[i])
        arr[index] = a[i]
        if index == lis:
            lis += 1
    return lis

def main():
    n = int(input())
    array = list(map(int, input().split()))
    method = int(input())
    if method == 1:
        result = lis(array)
    else:
        result = find_lis_len(array)
    print("The length of the longest increasing subsequence is:", result)

if __name__ == "__main__":
    main()

