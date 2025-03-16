import sys

# The Main class contains the main method that initializes the scanner, reads input, and prints output.
class Main:
    def __init__(self):
        pass

    # The main method is the entry point of the application. It initializes the scanner, reads input, and prints output.
    def main(self):
        scanner = sys.stdin
        n = int(scanner.readline())
        arr = [int(scanner.readline()) for i in range(n)]
        k = int(scanner.readline())
        result = Main.getMinKNumsByMain(arr, k)
        for num in result:
            print(num, end=" ")
        print()
        scanner.close()

    # The getMinKNumsByMain method returns the smallest k elements from the input array.
    @staticmethod
    def getMinKNumsByMain(arr, k):
        if k < 1 or k > len(arr):
            return None
        minKth = Main.getMinKthByMain(arr, k)
        res = [0] * k
        index = 0
        for value in arr:
            if value < minKth:
                res[index] = value
                index += 1
        for i in range(index, k):
            res[i] = minKth
        return res

    # The getMinKthByMain method finds the kth smallest element in the input array using the Quickselect algorithm.
    @staticmethod
    def getMinKthByMain(arr, k):
        copyArr = Main.copyArray(arr)
        return Main.bfprt(copyArr, 0, len(copyArr) - 1, k - 1)

    # The copyArray method creates a copy of the input array.
    @staticmethod
    def copyArray(arr):
        copyArr = [0] * len(arr)
        for i in range(len(arr)):
            copyArr[i] = arr[i]
        return copyArr

    # The bfprt method is a recursive implementation of the Quickselect algorithm to find the kth smallest element in an array.
    @staticmethod
    def bfprt(arr, begin, end, i):
        if begin == end:
            return arr[begin]
        pivot = Main.medianOfMedians(arr, begin, end)
        pivotRange = Main.partition(arr, begin, end, pivot)
        if i >= pivotRange[0] and i <= pivotRange[1]:
            return arr[i]
        elif i < pivotRange[0]:
            return Main.bfprt(arr, begin, pivotRange[0] - 1, i)
        else:
            return Main.bfprt(arr, pivotRange[1] + 1, end, i)

    # The medianOfMedians method finds the median of medians of subarrays of size 5 in the input array.
    @staticmethod
    def medianOfMedians(arr, begin, end):
        num = end - begin + 1
        offset = num % 5 == 0? 0 : 1
        mArr = [0] * (num / 5 + offset)
        for i in range(len(mArr)):
            mArr[i] = Main.getMedian(arr, begin + i * 5, min(end, begin + i * 5 + 4))
        return Main.bfprt(mArr, 0, len(mArr) - 1, len(mArr) / 2)

    # The partition method partitions the input array into two parts: elements smaller than and larger than the pivot element.
    @staticmethod
    def partition(arr, begin, end, num):
        small = begin - 1
        cur = begin
        big = end + 1
        while cur!= big:
            if arr[cur] < num:
                Main.swap(arr, small + 1, cur)
                small += 1
                cur += 1
            elif arr[cur] > num:
                Main.swap(arr, big - 1, cur)
                big -= 1
            else:
                cur += 1
        return [small + 1, big - 1]

    # The getMedian method finds the median of a subarray of the input array.
    @staticmethod
    def getMedian(arr, begin, end):
        Main.insertionSort(arr, begin, end)
        sum = begin + end
        mid = sum / 2 + (sum % 2)
        return arr[mid]

    # The insertionSort method sorts a subarray of the input array using the insertion sort algorithm.
    @staticmethod
    def insertionSort(arr, begin, end):
        if arr == None or len(arr) < 2:
            return
        for i in range(begin + 1, end + 1):
            for j in range(i, begin, -1):
                if arr[j - 1] > arr[j]:
                    Main.swap(arr, j - 1, j)
                else:
                    break

    # The swap method swaps two elements in the input array.
    @staticmethod
    def swap(arr, i, j):
        temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp

# The entry point of the program.
if __name__ == "__main__":
    main = Main()
    main.main()

# 