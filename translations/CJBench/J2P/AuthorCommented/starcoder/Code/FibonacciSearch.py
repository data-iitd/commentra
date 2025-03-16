import sys

class Main:

    def __init__(self):
        pass

    def find(self, array, key):
        if len(array) == 0:
            raise Exception("Input array must not be empty.")
        if not self.isSorted(array):
            raise Exception("Input array must be sorted.")
        if key == None:
            raise Exception("Key must not be null.")

        fibMinus1 = 1
        fibMinus2 = 0
        fibNumber = fibMinus1 + fibMinus2
        n = len(array)

        while fibNumber < n:
            fibMinus2 = fibMinus1
            fibMinus1 = fibNumber
            fibNumber = fibMinus2 + fibMinus1

        offset = -1

        while fibNumber > 1:
            i = min(offset + fibMinus2, n - 1)

            if array[i] < key:
                fibNumber = fibMinus1
                fibMinus1 = fibMinus2
                fibMinus2 = fibNumber - fibMinus1
                offset = i
            elif array[i] > key:
                fibNumber = fibMinus2
                fibMinus1 = fibMinus1 - fibMinus2
                fibMinus2 = fibNumber - fibMinus1
            else:
                return i

        if fibMinus1 == 1 and offset + 1 < n and array[offset + 1] == key:
            return offset + 1

        return -1

    def isSorted(self, array):
        for i in range(1, len(array)):
            if array[i - 1] > array[i]:
                return False
        return True

if __name__ == "__main__":
    main = Main()
    array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    key = 10
    index = main.find(array, key)
    print(index)

