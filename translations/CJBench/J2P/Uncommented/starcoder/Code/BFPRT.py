import sys
import random

def getMinKNumsByMain(arr, k):
    if k < 1 or k > len(arr):
        return None
    minKth = getMinKthByMain(arr, k)
    res = []
    index = 0
    for value in arr:
        if value < minKth:
            res.append(value)
    for i in range(len(res), k):
        res.append(minKth)
    return res

def getMinKthByMain(arr, k):
    copyArr = copyArray(arr)
    return bfprt(copyArr, 0, len(copyArr) - 1, k - 1)

def copyArray(arr):
    copyArr = [0] * len(arr)
    for i in range(len(arr)):
        copyArr[i] = arr[i]
    return copyArr

def bfprt(arr, begin, end, i):
    if begin == end:
        return arr[begin]
    pivot = medianOfMedians(arr, begin, end)
    pivotRange = partition(arr, begin, end, pivot)
    if i >= pivotRange[0] and i <= pivotRange[1]:
        return arr[i]
    elif i < pivotRange[0]:
        return bfprt(arr, begin, pivotRange[0] - 1, i)
    else:
        return bfprt(arr, pivotRange[1] + 1, end, i)

def medianOfMedians(arr, begin, end):
    num = end - begin + 1
    offset = num % 5 == 0? 0 : 1
    mArr = [0] * (num / 5 + offset)
    for i in range(len(mArr)):
        mArr[i] = getMedian(arr, begin + i * 5, min(end, begin + i * 5 + 4))
    return bfprt(mArr, 0, len(mArr) - 1, len(mArr) / 2)

def partition(arr, begin, end, num):
    small = begin - 1
    cur = begin
    big = end + 1
    while cur!= big:
        if arr[cur] < num:
            swap(arr, small + 1, cur)
            small += 1
            cur += 1
        elif arr[cur] > num:
            swap(arr, big - 1, cur)
            big -= 1
        else:
            cur += 1
    return [small + 1, big - 1]

def getMedian(arr, begin, end):
    insertionSort(arr, begin, end)
    sum = begin + end
    mid = sum / 2 + (sum % 2)
    return arr[mid]

def insertionSort(arr, begin, end):
    if arr == None or len(arr) < 2:
        return
    for i in range(begin + 1, end + 1):
        for j in range(i, begin, -1):
            if arr[j - 1] > arr[j]:
                swap(arr, j - 1, j)
            else:
                break

def swap(arr, i, j):
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp

def main():
    n = int(sys.stdin.readline())
    arr = [int(sys.stdin.readline()) for i in range(n)]
    k = int(sys.stdin.readline())
    result = getMinKNumsByMain(arr, k)
    for num in result:
        print num,
    print

if __name__ == "__main__":
    main()

