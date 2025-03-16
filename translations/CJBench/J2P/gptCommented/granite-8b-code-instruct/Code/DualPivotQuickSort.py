
import random

def swap(array, i, j):
    array[i], array[j] = array[j], array[i]

def partition(array, left, right):
    pivot = array[right]
    i = left - 1
    for j in range(left, right):
        if array[j] < pivot:
            i += 1
            swap(array, i, j)
    swap(array, i + 1, right)
    return i + 1

def dual_pivot_quicksort(array, left, right):
    if left < right:
        pivots = partition(array, left, right)
        dual_pivot_quicksort(array, left, pivots - 1)
        dual_pivot_quicksort(array, pivots + 1, right)

def sort(array):
    dual_pivot_quicksort(array, 0, len(array) - 1)

if __name__ == "__main__":
    n = int(input())
    array = [int(x) for x in input().split()]
    sort(array)
    print(" ".join(map(str, array)))

