
import random

def partition(arr, begin, end):
    pivot = arr[begin]
    i = begin + 1
    for j in range(begin + 1, end + 1):
        if arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[begin], arr[i - 1] = arr[i - 1], arr[begin]
    return i - 1

def bfprt(arr, begin, end, i):
    if begin == end:
        return arr[begin]
    pivot = partition(arr, begin, end)
    if i >= begin and i <= pivot:
        return arr[i]
    elif i < begin:
        return bfprt(arr, begin, pivot - 1, i)
    else:
        return bfprt(arr, pivot + 1, end, i)

def median_of_medians(arr, begin, end):
    num = end - begin + 1
    offset = 0 if num % 5 == 0 else 1
    m_arr = [get_median(arr, begin + i * 5, min(end, begin + i * 5 + 4)) for i in range(num // 5 + offset)]
    return bfprt(m_arr, 0, len(m_arr) - 1, len(m_arr) // 2)

def get_median(arr, begin, end):
    insertion_sort(arr, begin, end)
    sum = begin + end
    mid = sum // 2 + (sum % 2)
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

def get_min_k_num_by_main(arr, k):
    if k < 1 or k > len(arr):
        return None
    min_kth = median_of_medians(arr, 0, len(arr) - 1)
    res = []
    index = 0
    for value in arr:
        if value < min_kth:
            res.append(value)
            index += 1
    for i in range(index, k):
        res.append(min_kth)
    return res

def get_min_kth_by_main(arr, k):
    copy_arr = arr[:]
    return bfprt(copy_arr, 0, len(copy_arr) - 1, k - 1)

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    k = int(input())
    res = get_min_k_num_by_main(arr, k)
    if res is None:
        print("Invalid k")
    else:
        print(" ".join(map(str, res)))

if __name__ == "__main__":
    main()

