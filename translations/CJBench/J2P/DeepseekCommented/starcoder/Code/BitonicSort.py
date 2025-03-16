import java.util.Arrays;
import java.util.Scanner;
import java.util.function.BiPredicate;
class Main:
    # Enum to define sorting directions
    class Direction:
        DESCENDING = 0
        ASCENDING = 1
    # Method to sort an array using bitonic sort algorithm
    def sort(self, array):
        # If the array is empty, return it as is
        if len(array) == 0:
            return array
        # Calculate the next power of two for padding the array size
        paddedSize = self.nextPowerOfTwo(len(array))
        # Copy the original array and pad it with the maximum value
        paddedArray = array.copy()
        maxValue = max(array)
        paddedArray.extend([maxValue] * (paddedSize - len(array)))
        # Perform bitonic sort on the padded array
        self.bitonicSort(paddedArray, 0, paddedSize, self.Direction.ASCENDING)
        # Return the sorted portion of the array
        return paddedArray[:len(array)]
    # Recursive method to perform bitonic sort
    def bitonicSort(self, array, low, cnt, direction):
        # Base case: if the count is greater than one, continue sorting
        if cnt > 1:
            k = cnt // 2
            # Sort the first half in ascending order
            self.bitonicSort(array, low, k, self.Direction.ASCENDING)
            # Sort the second half in descending order
            self.bitonicSort(array, low + k, cnt - k, self.Direction.DESCENDING)
            # Merge the two halves
            self.bitonicMerge(array, low, cnt, direction)
    # Method to merge two halves of the array in a bitonic sequence
    def bitonicMerge(self, array, low, cnt, direction):
        # Base case: if the count is greater than one, continue merging
        if cnt > 1:
            k = cnt // 2
            # Define the predicate for comparing elements based on direction
            areSorted = (direction == self.Direction.ASCENDING) and (lambda a, b: a < b) or (lambda a, b: a > b)
            # Compare and swap elements to ensure the correct order
            for i in range(low, low + k):
                if not areSorted(array[i], array[i + k]):
                    self.swap(array, i, i + k)
            # Recursively merge the two halves
            self.bitonicMerge(array, low, k, direction)
            self.bitonicMerge(array, low + k, cnt - k, direction)
    # Method to calculate the smallest power of two greater than or equal to n
    def nextPowerOfTwo(self, n):
        count = 0
        if (n & (n - 1)) == 0:
            return n
        while n!= 0:
            n >>= 1
            count += 1
        return 1 << count
    # Method to find the maximum element in the array
    def max(self, array):
        return max(array)
    # Method to swap two elements in an array
    def swap(self, array, i, j):
        temp = array[i]
        array[i] = array[j]
        array[j] = temp
    # Main method to read input, sort the array, and print the sorted array
    def main(self):
        scanner = Scanner(System.in)
        n = scanner.nextInt()
        array = [0] * n
        for i in range(n):
            array[i] = scanner.nextInt()
        sorter = Main()
        sortedArray = sorter.sort(array)
        for num in sortedArray:
            print(num, end=" ")
        scanner.close()

