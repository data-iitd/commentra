
import sys

def main():
    # Read the size of the array
    n = int(sys.stdin.readline())

    # Read the array elements
    arr = [int(x) for x in sys.stdin.readline().split()]

    # Read k (the number of smallest elements to find)
    k = int(sys.stdin.readline())

    # Compute the k smallest elements using Main
    result = get_min_k_nums_by_main(arr, k)

    # Output the result
    for num in result:
        print(num, end=" ")
    print()

def get_min_k_nums_by_main(arr, k):
    if k < 1 or k > len(arr):
        return None
    min_kth = get_min_kth_by_main(arr, k)
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
    return bfprt(copy_arr, 0, len(arr) - 1, k - 1)

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
    offset = num % 5 == 0
    m_arr = [0] * (num // 5 + offset)
    for i in range(len(m_arr)):
        m_arr[i] = get_median(arr, begin + i * 5, min(end, begin + i * 5 + 4))
    return bfprt(m_arr, 0, len(m_arr) - 1, len(m_arr) // 2)

def partition(arr, begin, end, num):
    small = begin - 1
    cur = begin
    big = end + 1
    while cur != big:
        if arr[cur] < num:
            swap(arr, small + 1, cur)
            cur += 1
            small += 1
        elif arr[cur] > num:
            swap(arr, big - 1, cur)
            big -= 1
        else:
            cur += 1
    return [small + 1, big - 1]

def get_median(arr, begin, end):
    insertion_sort(arr, begin, end)
    sum = begin + end
    mid = sum // 2 + (sum % 2)
    return arr[mid]

def insertion_sort(arr, begin, end):
    if len(arr) < 2:
        return
    for i in range(begin + 1, end + 1):
        for j in range(i, begin, -1):
            if arr[j - 1] > arr[j]:
                swap(arr, j - 1, j)
            else:
                break

def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

if __name__ == "__main__":
    main()

