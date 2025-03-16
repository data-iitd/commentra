
import random
def get_min_k_nums_by_main(arr, k):
    if k < 1 or k > len(arr):
        return None
    min_kth = get_min_kth_by_main(arr, k)
    res = []
    for value in arr:
        if value < min_kth:
            res.append(value)
    while len(res) < k:
        res.append(min_kth)
    return res
def get_min_kth_by_main(arr, k):
    copy_arr = arr[:]
    return bfprt(copy_arr, 0, len(copy_arr) - 1, k - 1)
def bfprt(arr, begin, end, i):
    if begin == end:
        return arr[begin]
    pivot = median_of_medians(arr, begin, end)
    pivot_range = partition(arr, begin, end, pivot)
    if i >= pivot_range[0] and i <= pivot_range[1]:
        return arr[i]
    elif i < pivot_range[0]:
        return bfprt(arr, begin, pivot_range[0] - 1, i)
    else:
        return bfprt(arr, pivot_range[1] + 1, end, i)
def median_of_medians(arr, begin, end):
    num = end - begin + 1
    offset = 0 if num % 5 == 0 else 1
    m_arr = [get_median(arr, begin + i * 5, min(end, begin + i * 5 + 4)) for i in range(num // 5 + offset)]
    return bfprt(m_arr, 0, len(m_arr) - 1, len(m_arr) // 2)
def partition(arr, begin, end, num):
    small = begin - 1
    cur = begin
    big = end + 1
    while cur!= big:
        if arr[cur] < num:
            small += 1
            arr[small], arr[cur] = arr[cur], arr[small]
            cur += 1
        elif arr[cur] > num:
            big -= 1
            arr[cur], arr[big] = arr[big], arr[cur]
        else:
            cur += 1
    return [small + 1, big - 1]
def get_median(arr, begin, end):
    insertion_sort(arr, begin, end)
    sum = begin + end
    mid = sum // 2 + sum % 2
    return arr[mid]
def insertion_sort(arr, begin, end):
    if arr is None or len(arr) < 2:
        return
    for i in range(begin + 1, end + 1):
        for j in range(i, begin, -1):
            if arr[j - 1] > arr[j]:
                arr[j - 1], arr[j] = arr[j], arr[j - 1]
            else:
                break
