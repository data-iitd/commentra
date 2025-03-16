class DualPivotQuickSort:
    @staticmethod
    def sort(array):
        if len(array) > 1:
            DualPivotQuickSort.dual_pivot_quicksort(array, 0, len(array) - 1)

    @staticmethod
    def dual_pivot_quicksort(array, left, right):
        if left < right:
            pivots = DualPivotQuickSort.partition(array, left, right)
            DualPivotQuickSort.dual_pivot_quicksort(array, left, pivots[0] - 1)
            DualPivotQuickSort.dual_pivot_quicksort(array, pivots[0] + 1, pivots[1] - 1)
            DualPivotQuickSort.dual_pivot_quicksort(array, pivots[1] + 1, right)

    @staticmethod
    def partition(array, left, right):
        if array[left] > array[right]:
            DualPivotQuickSort.swap(array, left, right)

        pivot1 = array[left]
        pivot2 = array[right]

        pivot1_end = left + 1
        low = left + 1
        high = right - 1

        while low <= high:
            if array[low] < pivot1:
                DualPivotQuickSort.swap(array, low, pivot1_end)
                pivot1_end += 1
            elif array[low] >= pivot2:
                while low < high and array[high] > pivot2:
                    high -= 1
                DualPivotQuickSort.swap(array, low, high)
                high -= 1

                if array[low] < pivot1:
                    DualPivotQuickSort.swap(array, low, pivot1_end)
                    pivot1_end += 1
            low += 1

        pivot1_end -= 1
        high += 1

        DualPivotQuickSort.swap(array, left, pivot1_end)
        DualPivotQuickSort.swap(array, right, high)

        return pivot1_end, high

    @staticmethod
    def swap(array, i, j):
        array[i], array[j] = array[j], array[i]


if __name__ == "__main__":
    n = int(input("Enter the size of the array: "))
    array = list(map(int, input("Enter the elements of the array: ").split()))

    DualPivotQuickSort.sort(array)

    print("Sorted array:", ' '.join(map(str, array)))

# <END-OF-CODE>
