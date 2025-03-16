
import sys
def partition(array, low, high):
    pivot = array[high]
    i = low - 1
    for j in range(low, high):
        if array[j] <= pivot:
            i += 1
            array[i], array[j] = array[j], array[i]
    array[i + 1], array[high] = array[high], array[i + 1]
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
    for i in range((n - 2) // 2, -1, -1):
        heapify(array, i, n, low)
    for i in range(high, low, -1):
        array[low], array[i] = array[i], array[low]
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
        array[low + i], array[low + largest] = array[low + largest], array[low + i]
        heapify(array, largest, n, low)
def introspectiveSort(array, low, high, depth):
    while high - low > 16:
        if depth == 0:
            heapSort(array, low, high)
            return
        pivotIndex = partition(array, low, high)
        introspectiveSort(array, pivotIndex + 1, high, depth - 1)
        high = pivotIndex - 1
    insertionSort(array, low, high)
def main():
    n = int(input())
    array = list(map(int, input().split()))
    introspectiveSort(array, 0, n - 1, 2 * (int(sys.log2(n)) if n > 1 else 0))
    print(" ".join(map(str, array)))
if __name__ == "__main__":
    main()
