def sort(array):
    if len(array) > 1:
        dualPivotQuicksort(array, 0, len(array) - 1)

def dualPivotQuicksort(array, left, right):
    if left < right:
        pivots = partition(array, left, right)
        dualPivotQuicksort(array, left, pivots[0] - 1)
        dualPivotQuicksort(array, pivots[0] + 1, pivots[1] - 1)
        dualPivotQuicksort(array, pivots[1] + 1, right)

def partition(array, left, right):
    if array[left] > array[right]:
        array[left], array[right] = array[right], array[left]
    pivot1 = array[left]
    pivot2 = array[right]
    pivot1End = left + 1
    low = left + 1
    high = right - 1
    while low <= high:
        if array[low] < pivot1:
            array[low], array[pivot1End] = array[pivot1End], array[low]
            pivot1End += 1
        elif array[low] >= pivot2:
            while low < high and array[high] > pivot2:
                high -= 1
            array[low], array[high] = array[high], array[low]
            high -= 1
            if array[low] < pivot1:
                array[low], array[pivot1End] = array[pivot1End], array[low]
                pivot1End += 1
        low += 1
    pivot1End -= 1
    high += 1
    array[left], array[pivot1End] = array[pivot1End], array[left]
    array[right], array[high] = array[high], array[right]
    return [pivot1End, high]

if __name__ == '__main__':
    import sys
    n = int(sys.stdin.readline())
    array = [int(sys.stdin.readline()) for _ in range(n)]
    sort(array)
    for num in array:
        print(num, end=' ')

