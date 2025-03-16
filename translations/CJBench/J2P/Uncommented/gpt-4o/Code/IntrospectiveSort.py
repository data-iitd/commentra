import math

INSERTION_SORT_THRESHOLD = 16

def introspective_sort(array, low, high, depth):
    while high - low > INSERTION_SORT_THRESHOLD:
        if depth == 0:
            heap_sort(array, low, high)
            return
        pivot_index = partition(array, low, high)
        introspective_sort(array, pivot_index + 1, high, depth - 1)
        high = pivot_index - 1
    insertion_sort(array, low, high)

def partition(array, low, high):
    pivot = array[high]
    i = low - 1
    for j in range(low, high):
        if array[j] <= pivot:
            i += 1
            swap(array, i, j)
    swap(array, i + 1, high)
    return i + 1

def insertion_sort(array, low, high):
    for i in range(low + 1, high + 1):
        key = array[i]
        j = i - 1
        while j >= low and array[j] > key:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key

def heap_sort(array, low, high):
    n = high - low + 1
    for i in range(n // 2 - 1, -1, -1):
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
    if largest != i:
        swap(array, low + i, low + largest)
        heapify(array, largest, n, low)

def swap(array, i, j):
    array[i], array[j] = array[j], array[i]

if __name__ == "__main__":
    n = int(input())
    array = list(map(int, input().split()))
    introspective_sort(array, 0, len(array) - 1, 2 * int(math.log(len(array), 2)))
    print(" ".join(map(str, array)))

# <END-OF-CODE>
