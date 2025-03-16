import sys

class Main:
    def __init__(self):
        self.scanner = sys.stdin

    def find(self, array, key):
        # Check if the array is empty and throw an exception if it is
        if len(array) == 0:
            raise Exception("Input array must not be empty.")
        # Check if the array is sorted and throw an exception if it is not
        if not self.isSorted(array):
            raise Exception("Input array must be sorted.")
        # Check if the key is null and throw an exception if it is
        if key == None:
            raise Exception("Key must not be null.")
        # Calculate Fibonacci numbers to determine the range to search within the array
        fibMinus1 = 1
        fibMinus2 = 0
        fibNumber = fibMinus1 + fibMinus2
        n = len(array)
        while fibNumber < n:
            fibMinus2 = fibMinus1
            fibMinus1 = fibNumber
            fibNumber = fibMinus2 + fibMinus1
        # Perform a search similar to binary search but using Fibonacci numbers to reduce the number of comparisons
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
        # Check if the key is found at the next position after the offset
        if fibMinus1 == 1 and offset + 1 < n and array[offset + 1] == key:
            return offset + 1
        # Return -1 if the key is not found in the array
        return -1

    def isSorted(self, array):
        for i in range(1, len(array)):
            if array[i - 1] > array[i]:
                return False
        return True

    def main(self):
        # Read the size of the array
        n = int(self.scanner.readline())
        # Create an array of size n to store the integers
        array = [0] * n
        # Read n integers into the array
        for i in range(n):
            array[i] = int(self.scanner.readline())
        # Read the key to be searched for in the array
        key = int(self.scanner.readline())
        # Call the find method to find the index of the key in the array
        index = self.find(array, key)
        # Print the index of the key in the array
        print(index)

if __name__ == "__main__":
    main = Main()
    main.main()

