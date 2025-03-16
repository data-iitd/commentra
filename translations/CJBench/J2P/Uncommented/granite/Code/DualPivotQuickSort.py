
import random
def swap(array, i, j):
    array[i], array[j] = array[j], array[i]
def partition(array, left, right):
    pivot1 = array[left]
    pivot2 = array[right]
    pivot1End = left + 1
    low = left + 1
    high = right - 1
    while low <= high:
        if array[low] < pivot1:
            swap(array, low, pivot1End)
            pivot1End += 1
        elif array[low] >= pivot2:
            while low < high and array[high] >= pivot2:
                high -= 1
            swap(array, low, high)
            high -= 1
            if array[low] < pivot1:
                swap(array, low, pivot1End)
                pivot1End += 1
        low += 1
    pivot1End -= 1
    high += 1
    swap(array, left, pivot1End)
    swap(array, right, high)
    return [pivot1End, high]
def dualPivotQuicksort(array, left, right):
    if left < right:
        pivots = partition(array, left, right)
        dualPivotQuicksort(array, left, pivots[0] - 1)
        dualPivotQuicksort(array, pivots[0] + 1, pivots[1] - 1)
        dualPivotQuicksort(array, pivots[1] + 1, right)
def sort(array):
    if len(array) > 1:
        dualPivotQuicksort(array, 0, len(array) - 1)
if __name__ == "__main__":
    n = int(input())
    array = [int(x) for x in input().split()]
    sort(array)
    print(" ".join(map(str, array)))
