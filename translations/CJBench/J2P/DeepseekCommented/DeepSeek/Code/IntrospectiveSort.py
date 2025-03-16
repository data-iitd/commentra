import random

INSERTION_SORT_THRESHOLD = 16

def introspective_sort(arr, low, high, depth):
    while high - low > INSERTION_SORT_THRESHOLD:
        if depth == 0:
            heap_sort(arr, low, high)
            return
        pivot_index = partition(arr, low, high)
        introspective_sort(arr, pivot_index + 1, high, depth - 1)
        high = pivot_index - 1
    insertion_sort(arr, low, high)

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def insertion_sort(arr, low, high):
    for i in range(low + 1, high + 1):
        key = arr[i]
        j = i - 1
        while j >= low and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def heap_sort(arr, low, high):
    n = high - low + 1
    for i in range((n // 2) - 1, -1, -1):
        heapify(arr, i, n, low)
    for i in range(high, low, -1):
        arr[low], arr[i] = arr[i], arr[low]
        heapify(arr, 0, i - low, low)

def heapify(arr, i, n, low):
    left = 2 * i + 1
    right = 2 * i + 2
    largest = i
    if left < n and arr[low + left] > arr[low + largest]:
        largest = left
    if right < n and arr[low + right] > arr[low + largest]:
        largest = right
    if largest != i:
        arr[low + i], arr[low + largest] = arr[low + largest], arr[low + i]
        heapify(arr, largest, n, low)

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    introspective_sort(arr, 0, n - 1, 2 * int(math.log2(n)))
    print(" ".join(map(str, arr)))

if __name__ == "__main__":
    main()
