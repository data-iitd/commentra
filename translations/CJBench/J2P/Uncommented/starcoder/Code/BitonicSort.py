
import sys
import math

class Main:
    def __init__(self):
        self.DESCENDING = 0
        self.ASCENDING = 1

    def sort(self, array):
        if len(array) == 0:
            return array
        paddedSize = self.nextPowerOfTwo(len(array))
        paddedArray = array + [0] * (paddedSize - len(array))
        maxValue = self.max(array)
        for i in range(len(array), paddedSize):
            paddedArray[i] = maxValue
        self.bitonicSort(paddedArray, 0, paddedSize, self.ASCENDING)
        return paddedArray[:len(array)]

    def bitonicSort(self, array, low, cnt, direction):
        if cnt > 1:
            k = cnt / 2
            self.bitonicSort(array, low, k, self.ASCENDING)
            self.bitonicSort(array, low + k, cnt - k, self.DESCENDING)
            self.bitonicMerge(array, low, cnt, direction)

    def bitonicMerge(self, array, low, cnt, direction):
        if cnt > 1:
            k = cnt / 2
            areSorted = (direction == self.ASCENDING) and (lambda a, b: a < b) or (lambda a, b: a > b)
            for i in range(low, low + k):
                if not areSorted(array[i], array[i + k]):
                    self.swap(array, i, i + k)
            self.bitonicMerge(array, low, k, direction)
            self.bitonicMerge(array, low + k, cnt - k, direction)

    def nextPowerOfTwo(self, n):
        count = 0
        if (n & (n - 1)) == 0:
            return n
        while n!= 0:
            n >>= 1
            count += 1
        return 1 << count

    def max(self, array):
        return max(array)

    def swap(self, array, i, j):
        temp = array[i]
        array[i] = array[j]
        array[j] = temp

    def main(self):
        scanner = sys.stdin
        n = int(scanner.readline())
        array = [int(scanner.readline()) for i in range(n)]
        sorter = Main()
        sortedArray = sorter.sort(array)
        for num in sortedArray:
            print(num, end=' ')
        print()

    def __repr__(self):
        return 'Main.py'

if __name__ == '__main__':
    Main().main()

