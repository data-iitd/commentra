
# This class provides a method to select the n-th smallest element from a list of comparable elements.
class Main:
    # Private constructor to prevent instantiation of the class.
    def __init__(self):
        pass

    # Method to select the n-th smallest element from a list of comparable elements.
    @staticmethod
    def select(list, n):
        if list is None:
            raise ValueError("The list of elements must not be null.")
        if len(list) == 0:
            raise ValueError("The list of elements must not be empty.")
        if n < 0 or n >= len(list):
            raise IndexError("The index must be between 0 and the size of the list - 1.")
        return Main.selectIndex(list, n)

    # Recursive helper method to find the index of the n-th smallest element.
    @staticmethod
    def selectIndex(list, n):
        return Main.selectIndex(list, 0, len(list) - 1, n)

    # Recursive helper method to find the index of the n-th smallest element using partitioning.
    @staticmethod
    def selectIndex(list, left, right, n):
        while True:
            pivotIndex = Main.pivot(list, left, right)
            pivotIndexPartitioned = Main.partition(list, left, right, pivotIndex, n)
            if n == pivotIndexPartitioned:
                return n
            elif n < pivotIndexPartitioned:
                right = pivotIndexPartitioned - 1
            else:
                left = pivotIndexPartitioned + 1

    # Helper method to partition the list around a randomly chosen pivot.
    @staticmethod
    def partition(list, left, right, pivotIndex, n):
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
        return (n < storeIndex) * storeIndex or min(n, storeIndexEq)

    # Helper method to find a good pivot index using the median of five elements.
    @staticmethod
    def pivot(list, left, right):
        if right - left < 5:
            return Main.partition5(list, left, right)
        for i in range(left, right, 5):
            subRight = min(i + 4, right)
            median5 = Main.partition5(list, i, subRight)
            list[median5], list[left + (i - left) // 5] = list[left + (i - left) // 5], list[median5]
        mid = left + (right - left) // 10 + 1
        rightIndex = left + (right - left) // 5
        return Main.selectIndex(list, left, rightIndex, mid)

    # Helper method to partition the list around a simple pivot (the middle element).
    @staticmethod
    def partition5(list, left, right):
        sublist = list[left:right + 1]
        sublist.sort()
        return left + (right - left) // 2

    # Main method to read input and test the select method.
    @staticmethod
    def main():
        n = int(input())
        list = list(map(int, input().split()))
        index = int(input())
        try:
            result = Main.select(list, index)
            print("The " + str(index) + "-th smallest element is: " + str(result))
        except Exception as e:
            print(e.args[0])


if __name__ == "__main__":
    Main.main()


