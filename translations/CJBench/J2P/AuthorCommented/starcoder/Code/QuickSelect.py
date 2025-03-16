
import sys

class Main:
    def __init__(self):
        pass

    def select(self, list, n):
        if list is None:
            raise ValueError("The list of elements must not be null.")

        if len(list) == 0:
            raise ValueError("The list of elements must not be empty.")

        if n < 0 or n >= len(list):
            raise IndexError("The index must be between 0 and the size of the list - 1.")

        index = self.selectIndex(list, 0, len(list) - 1, n)
        return list[index]

    def selectIndex(self, list, left, right, n):
        while True:
            if left == right:
                return left

            pivotIndex = self.pivot(list, left, right)
            pivotIndex = self.partition(list, left, right, pivotIndex, n)
            if n == pivotIndex:
                return n
            elif n < pivotIndex:
                right = pivotIndex - 1
            else:
                left = pivotIndex + 1

    def partition(self, list, left, right, pivotIndex, n):
        pivotValue = list[pivotIndex]
        list[pivotIndex], list[right] = list[right], list[pivotIndex]
        storeIndex = left

        for i in range(left, right):
            if list[i] < pivotValue:
                list[storeIndex], list[i] = list[i], list[storeIndex]
                storeIndex += 1

        storeIndexEq = storeIndex

        for i in range(storeIndex, right):
            if list[i] == pivotValue:
                list[storeIndexEq], list[i] = list[i], list[storeIndexEq]
                storeIndexEq += 1

        list[right], list[storeIndexEq] = list[storeIndexEq], list[right]

        return (n < storeIndex) and storeIndex or min(n, storeIndexEq)

    def pivot(self, list, left, right):
        if right - left < 5:
            return self.partition5(list, left, right)

        for i in range(left, right, 5):
            subRight = min(i + 4, right)
            median5 = self.partition5(list, i, subRight)
            list[median5], list[left + (i - left) / 5] = list[left + (i - left) / 5], list[median5]

        mid = left + (right - left) / 10 + 1
        rightIndex = left + (right - left) / 5
        return self.selectIndex(list, left, rightIndex, mid)

    def partition5(self, list, left, right):
        sublist = list[left:right + 1]
        sublist.sort()
        return left + (right - left) / 2

    def main(self):
        # Input: number of elements in the list
        n = int(raw_input().strip())

        # Input: the elements of the list
        list = []
        for i in range(n):
            list.append(int(raw_input().strip()))

        # Input: the index of the element to find
        index = int(raw_input().strip())

        # Find and print the nth smallest element
        try:
            result = self.select(list, index)
            print "The " + str(index) + "-th smallest element is: " + str(result)
        except Exception as e:
            print e.message

        return 0

# 