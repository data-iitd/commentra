
import sys
def swap(array, i, j):
    array[i], array[j] = array[j], array[i]
def insertionSort(array, low, high):
    for i in range(low + 1, high + 1):
        key = array[i]
        j = i - 1
        while j >= low and array[j] > key:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key
def heapify(array, i, n, low):
    left = 2 * i + 1
    right = 2 * i + 2
    largest = i
    if left < n and array[low + left] > array[low + largest]:
        largest = left
    if right < n and array[low + right] > array[low + largest]:
        largest = right
    if largest!= i:
        swap(array, low + i, low + largest)
        heapify(array, largest, n, low)
def heapSort(array, low, high):
    n = high - low + 1
    for i in range((n - 1) // 2, -1, -1):
        heapify(array, i, n, low)
    for i in range(high, low, -1):
        swap(array, low, i)
        heapify(array, 0, i - low, low)
def introspectiveSort(array, low, high, depth):
    while high - low > 16:
        if depth == 0:
            heapSort(array, low, high)
            return
        pivotIndex = partition(array, low, high)
        introspectiveSort(array, pivotIndex + 1, high, depth - 1)
        high = pivotIndex - 1
    insertionSort(array, low, high)
def partition(array, low, high):
    pivot = array[high]
    i = low - 1
    for j in range(low, high):
        if array[j] <= pivot:
            i += 1
            swap(array, i, j)
    swap(array, i + 1, high)
    return i + 1
n = int(input())
array = list(map(int, input().split()))
introspectiveSort(array, 0, n - 1, 2 * (int(sys.log(n) / sys.log(2))))
print(" ".join(map(str, array)))
