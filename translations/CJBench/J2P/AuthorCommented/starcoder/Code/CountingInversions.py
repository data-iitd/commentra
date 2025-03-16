
import sys

class Main:
    def __init__(self):
        pass

    @staticmethod
    def countInversions(arr):
        return mergeSortAndCount(arr, 0, len(arr) - 1)

    @staticmethod
    def mergeSortAndCount(arr, left, right):
        if left >= right:
            return 0

        mid = left + (right - left) / 2
        inversions = 0

        inversions += Main.mergeSortAndCount(arr, left, mid)
        inversions += Main.mergeSortAndCount(arr, mid + 1, right)
        inversions += Main.mergeAndCount(arr, left, mid, right)
        return inversions

    @staticmethod
    def mergeAndCount(arr, left, mid, right):
        leftArr = arr[left:mid + 1]
        rightArr = arr[mid + 1:right + 1]

        i = 0
        j = 0
        k = left
        inversions = 0

        while i < len(leftArr) and j < len(rightArr):
            if leftArr[i] <= rightArr[j]:
                arr[k] = leftArr[i]
                i += 1
            else:
                arr[k] = rightArr[j]
                j += 1
                inversions += mid + 1 - left - i
            k += 1

        while i < len(leftArr):
            arr[k] = leftArr[i]
            i += 1
            k += 1

        while j < len(rightArr):
            arr[k] = rightArr[j]
            j += 1
            k += 1

        return inversions

if __name__ == "__main__":
    # Input size of array
    n = int(raw_input().strip())
    arr = [int(arr_temp) for arr_temp in raw_input().strip().split(' ')]

    # Count inversions
    result = Main.countInversions(arr)

    # Output result
    print "Number of inversions: " + str(result)

