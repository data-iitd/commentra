import sys
import random
import math

def introspectiveSort(array, low, high, depth):
    while high - low > INSERTION_SORT_THRESHOLD:
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

def insertionSort(array, low, high):
    for i in range(low + 1, high + 1):
        key = array[i]
        j = i - 1
        while j >= low and array[j] > key:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key

def heapSort(array, low, high):
    n = high - low + 1
    for i in range((n / 2) - 1, -1, -1):
        heapify(array, i, n, low)
    for i in range(high, low, -1):
        swap(array, low, i)
        heapify(array, 0, i - low, low)

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

def swap(array, i, j):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp

def main():
    n = int(sys.stdin.readline())
    array = [int(sys.stdin.readline()) for i in range(n)]
    introspectiveSort(array, 0, n - 1, 2 * (int)(math.log(n) / math.log(2)))
    for num in array:
        print(num, end=' ')

if __name__ == '__main__':
    main()

