import random

class Main:
    def __init__(self):
        self.random = random.Random()

    def findKthMax(self, array, k):
        if k <= 0 or k > len(array):
            raise ValueError("k must be between 1 and the size of the array")
        return self.quickSelect(array, 0, len(array) - 1, len(array) - k)

    def quickSelect(self, array, left, right, kSmallest):
        if left == right:
            return array[left]

        pivotIndex = left + self.random.randint(0, right - left)
        pivotIndex = self.partition(array, left, right, pivotIndex)

        if kSmallest == pivotIndex:
            return array[kSmallest]
        elif kSmallest < pivotIndex:
            return self.quickSelect(array, left, pivotIndex - 1, kSmallest)
        else:
            return self.quickSelect(array, pivotIndex + 1, right, kSmallest)

    def partition(self, array, left, right, pivotIndex):
        pivotValue = array[pivotIndex]
        array[pivotIndex], array[right] = array[right], array[pivotIndex]
        storeIndex = left

        for i in range(left, right):
            if array[i] < pivotValue:
                array[storeIndex], array[i] = array[i], array[storeIndex]
                storeIndex += 1

        array[storeIndex], array[right] = array[right], array[storeIndex]
        return storeIndex

    def main(self):
        import sys
        input = sys.stdin.readline

        try:
            n = int(input())

            if n <= 0:
                print("Array size must be positive.")
                return

            array = list(map(int, input().split()))

            k = int(input())

            if k <= 0 or k > n:
                print("Error: k must be between 1 and the size of the array.")
                return

            result = self.findKthMax(array, k)
            print(f"The {k}-th largest element is: {result}")
        except Exception as e:
            print(f"An error occurred: {e}")

main = Main()
main.main()
