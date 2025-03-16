
import sys

class Main:
    def __init__(self):
        pass

    def find(self, array, key):
        if len(array) == 0:
            raise Exception("Input array must not be empty.")
        if not self.is_sorted(array):
            raise Exception("Input array must be sorted.")
        if key is None:
            raise Exception("Key must not be null.")

        fib_minus_1 = 1
        fib_minus_2 = 0
        fib_number = fib_minus_1 + fib_minus_2
        n = len(array)

        while fib_number < n:
            fib_minus_2 = fib_minus_1
            fib_minus_1 = fib_number
            fib_number = fib_minus_2 + fib_minus_1

        offset = -1

        while fib_number > 1:
            i = min(offset + fib_minus_2, n - 1)

            if array[i] < key:
                fib_number = fib_minus_1
                fib_minus_1 = fib_minus_2
                fib_minus_2 = fib_number - fib_minus_1
                offset = i
            elif array[i] > key:
                fib_number = fib_minus_2
                fib_minus_1 = fib_minus_1 - fib_minus_2
                fib_minus_2 = fib_number - fib_minus_1
            else:
                return i

        if fib_minus_1 == 1 and offset + 1 < n and array[offset + 1] == key:
            return offset + 1

        return -1

    def is_sorted(self, array):
        for i in range(1, len(array)):
            if array[i - 1] > array[i]:
                return False
        return True

if __name__ == "__main__":
    n = int(input())
    array = list(map(int, input().split()))
    key = int(input())

    searcher = Main()
    index = searcher.find(array, key)

    print(index)

