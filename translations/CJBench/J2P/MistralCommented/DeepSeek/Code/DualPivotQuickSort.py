def sort(array):
    if len(array) > 1:
        dual_pivot_quicksort(array, 0, len(array) - 1)

def dual_pivot_quicksort(array, left, right):
    if left < right:
        pivots = partition(array, left, right)
        dual_pivot_quicksort(array, left, pivots[0] - 1)
        dual_pivot_quicksort(array, pivots[0] + 1, pivots[1] - 1)
        dual_pivot_quicksort(array, pivots[1] + 1, right)

def partition(array, left, right):
    if array[left] > array[right]:
        array[left], array[right] = array[right], array[left]
    pivot1 = array[left]
    pivot2 = array[right]
    pivot1_end = left + 1
    low = left + 1
    high = right - 1

    while low <= high:
        if array[low] < pivot1:
            array[low], array[pivot1_end] = array[pivot1_end], array[low]
            pivot1_end += 1
        elif array[low] >= pivot2:
            while low < high and array[high] > pivot2:
                array[low], array[high] = array[high], array[low]
                high -= 1
            array[low], array[high] = array[high], array[low]
            high -= 1
            if array[low] < pivot1:
                array[low], array[pivot1_end] = array[pivot1_end], array[low]
                pivot1_end += 1
        low += 1

    pivot1_end -= 1
    high += 1
    array[left], array[pivot1_end] = array[pivot1_end], array[left]
    array[right], array[high] = array[high], array[right]

    return [pivot1_end, high]

def swap(array, i, j):
    array[i], array[j] = array[j], array[i]

def main():
    n = int(input())
    array = list(map(int, input().split()))
    sort(array)
    print(" ".join(map(str, array)))

main()

