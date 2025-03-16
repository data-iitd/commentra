
import sys
def main():
    # Step 1: Reading Input
    n = int(input())
    arr = list(map(int, input().split()))
    # Step 2: Reading k
    k = int(input())
    # Step 3: Finding the k smallest elements
    result = getMinKNumsByMain(arr, k)
    # Final Output
    print(" ".join(map(str, result)))
# Step 4: Handling Edge Cases
def getMinKNumsByMain(arr, k):
    if k < 1 or k > len(arr):
        return None
    # Step 5: Finding the k-th smallest element
    minKth = getMinKthByMain(arr, k)
    res = []
    index = 0
    for value in arr:
        if value < minKth:
            res.append(value)
            index += 1
    # Step 12: Filling remaining slots with the k-th smallest element
    while index!= k:
        res.append(minKth)
        index += 1
    return res
# Step 6: Copying the Array
def getMinKthByMain(arr, k):
    copyArr = arr[:]
    return bfprt(copyArr, 0, len(copyArr) - 1, k - 1)
# Step 7: Applying Main Algorithm
def bfprt(arr, begin, end, i):
    if begin == end:
        return arr[begin]
    # Step 8: Median of Medians
    pivot = medianOfMedians(arr, begin, end)
    pivotRange = partition(arr, begin, end, pivot)
    if i >= pivotRange[0] and i <= pivotRange[1]:
        return arr[i]
    elif i < pivotRange[0]:
        return bfprt(arr, begin, pivotRange[0] - 1, i)
    else:
        return bfprt(arr, pivotRange[1] + 1, end, i)
# Step 9: Median of Medians
def medianOfMedians(arr, begin, end):
    num = end - begin + 1
    offset = 0 if num % 5 == 0 else 1
    mArr = [getMedian(arr, begin + i * 5, min(end, begin + i * 5 + 4)) for i in range(num // 5 + offset)]
    return bfprt(mArr, 0, len(mArr) - 1, len(mArr) // 2)
# Step 10: Partitioning the Array
def partition(arr, begin, end, num):
    small = begin - 1
    cur = begin
    big = end + 1
    while cur!= big:
        if arr[cur] < num:
            small += 1
            swap(arr, small, cur)
            cur += 1
        elif arr[cur] > num:
            big -= 1
            swap(arr, cur, big)
        else:
            cur += 1
    return [small + 1, big - 1]
# Step 11: Getting the Median
def getMedian(arr, begin, end):
    insertionSort(arr, begin, end)
    sum = begin + end
    mid = sum // 2 + (sum % 2)
    return arr[mid]
# Step 11: Insertion Sort
def insertionSort(arr, begin, end):
    if arr is None or len(arr) < 2:
        return
    for i in range(begin + 1, end + 1):
        for j in range(i, begin, -1):
            if arr[j - 1] > arr[j]:
                swap(arr, j - 1, j)
            else:
                break
# Step 12: Swapping Elements
def swap(arr, i, j):
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp

if __name__ == "__main__":
    main()
