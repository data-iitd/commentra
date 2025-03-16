def dual_pivot_quicksort(array, left, right):
    if left < right:
        pivots = partition(array, left, right)
        dual_pivot_quicksort(array, left, pivots[0] - 1)
        dual_pivot_quicksort(array, pivots[0] + 1, pivots[1] - 1)
        dual_pivot_quicksort(array, pivots[1] + 1, right)

def partition(array, left, right):
    if array[left] > array[right]:
        swap(array, left, right)
    
    pivot1 = array[left]
    pivot2 = array[right]
    pivot1_end = left + 1
    low = left + 1
    high = right - 1

    while low <= high:
        if array[low] < pivot1:
            swap(array, low, pivot1_end)
            pivot1_end += 1
        elif array[low] >= pivot2:
            while low < high and array[high] > pivot2:
                high -= 1
            swap(array, low, high)
            high -= 1
            if array[low] < pivot1:
                swap(array, low, pivot1_end)
                pivot1_end += 1
        low += 1

    pivot1_end -= 1
    high += 1
    swap(array, left, pivot1_end)
    swap(array, right, high)

    return pivot1_end, high

def swap(array, i, j):
    array[i], array[j] = array[j], array[i]

def sort(array):
    if len(array) > 1:
        dual_pivot_quicksort(array, 0, len(array) - 1)

if __name__ == "__main__":
    n = int(input())  # Read the number of elements
    array = list(map(int, input().split()))  # Read the elements into the array
    sort(array)  # Sort the array
    print(" ".join(map(str, array)))  # Print the sorted array

# <END-OF-CODE>
