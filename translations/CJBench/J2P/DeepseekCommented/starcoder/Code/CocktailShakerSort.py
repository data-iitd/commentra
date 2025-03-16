import sys

class Main:
    def __init__(self):
        self.scanner = sys.stdin

    def sort(self, array):
        if len(array) == 0:
            return
        left = 0
        right = len(array) - 1
        while left < right:
            right = self.performForwardPass(array, left, right)
            left = self.performBackwardPass(array, left, right)

    def performForwardPass(self, array, left, right):
        lastSwappedIndex = left
        for i in range(left, right):
            if array[i] > array[i + 1]:
                self.swap(array, i, i + 1)
                lastSwappedIndex = i
        return lastSwappedIndex

    def performBackwardPass(self, array, left, right):
        lastSwappedIndex = right
        for i in range(right, left, -1):
            if array[i] < array[i - 1]:
                self.swap(array, i - 1, i)
                lastSwappedIndex = i
        return lastSwappedIndex

    def swap(self, array, i, j):
        temp = array[i]
        array[i] = array[j]
        array[j] = temp

if __name__ == "__main__":
    main = Main()
    n = int(self.scanner.readline())
    array = []
    for i in range(n):
        array.append(int(self.scanner.readline()))
    main.sort(array)
    for num in array:
        print(num, end=" ")

