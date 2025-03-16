
import random
import sys

class Main:
    def __init__(self):
        pass

    @staticmethod
    def findKthMax(array, k):
        if k <= 0 or k > len(array):
            raise Exception("k must be between 1 and the size of the array")

        # Convert k-th largest to index for QuickSelect
        return Main.quickSelect(array, 0, len(array) - 1, len(array) - k)

    @staticmethod
    def quickSelect(array, left, right, kSmallest):
        if left == right:
            return array[left]

        # Randomly select a pivot index
        pivotIndex = left + random.randint(0, right - left)
        pivotIndex = Main.partition(array, left, right, pivotIndex)

        if kSmallest == pivotIndex:
            return array[kSmallest]
        elif kSmallest < pivotIndex:
            return Main.quickSelect(array, left, pivotIndex - 1, kSmallest)
        else:
            return Main.quickSelect(array, pivotIndex + 1, right, kSmallest)

    @staticmethod
    def partition(array, left, right, pivotIndex):
        pivotValue = array[pivotIndex]
        # Move pivot to end
        array[pivotIndex], array[right] = array[right], array[pivotIndex]
        storeIndex = left

        # Move all smaller elements to the left
        for i in range(left, right):
            if array[i] < pivotValue:
                array[storeIndex], array[i] = array[i], array[storeIndex]
                storeIndex += 1

        # Move pivot to its final place
        array[right], array[storeIndex] = array[storeIndex], array[right]
        return storeIndex

    @staticmethod
    def main():
        n = int(sys.stdin.readline().strip())

        if n <= 0:
            print("Array size must be positive.")
            return

        array = [int(sys.stdin.readline().strip()) for _ in range(n)]
        k = int(sys.stdin.readline().strip())

        if k <= 0 or k > n:
            print("Error: k must be between 1 and the size of the array.")
            return

        result = Main.findKthMax(array, k)
        print("The " + str(k) + "-th largest element is: " + str(result))

if __name__ == "__main__":
    Main.main()

