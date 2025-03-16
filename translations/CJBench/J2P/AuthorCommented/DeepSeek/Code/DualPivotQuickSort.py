def dual_pivot_quicksort(arr, left, right):
    if left < right:
        pivots = partition(arr, left, right)
        dual_pivot_quicksort(arr, left, pivots[0] - 1)
        dual_pivot_quicksort(arr, pivots[0] + 1, pivots[1] - 1)
        dual_pivot_quicksort(arr, pivots[1] + 1, right)


def partition(arr, left, right):
    if arr[left] > arr[right]:
        arr[left], arr[right] = arr[right], arr[left]

    pivot1 = arr[left]
    pivot2 = arr[right]

    pivot1_end = left + 1
    low = left + 1
    high = right - 1

    while low <= high:
        if arr[low] < pivot1:
            arr[low], arr[pivot1_end] = arr[pivot1_end], arr[low]
            pivot1_end += 1
        elif arr[low] >= pivot2:
            while low < high and arr[high] > pivot2:
                high -= 1
            arr[low], arr[high] = arr[high], arr[low]
            high -= 1
            if arr[low] < pivot1:
                arr[low], arr[pivot1_end] = arr[pivot1_end], arr[low]
                pivot1_end += 1
        low += 1

    pivot1_end -= 1
    high += 1

    arr[left], arr[pivot1_end] = arr[pivot1_end], arr[left]
    arr[right], arr[high] = arr[high], arr[right]

    return [pivot1_end, high]


def sort(arr):
    if len(arr) > 1:
        dual_pivot_quicksort(arr, 0, len(arr) - 1)


# Example usage
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    arr = list(map(int, data[1:n+1]))

    sort(arr)

    for num in arr:
        print(num, end=" ")
