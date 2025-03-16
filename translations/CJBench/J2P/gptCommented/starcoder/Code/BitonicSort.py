import java.util.Arrays;
import java.util.Scanner;
import java.util.function.BiPredicate;

class Main:
    # Enum to define sorting direction
    class Direction:
        DESCENDING = 0
        ASCENDING = 1

    # Method to sort an array using Bitonic Sort
    def sort(self, array):
        # Return the original array if it's empty
        if len(array) == 0:
            return array
        # Calculate the next power of two for padding the array
        paddedSize = self.nextPowerOfTwo(len(array))
        # Create a padded array to accommodate the Bitonic Sort
        paddedArray = array.copy()
        # Find the maximum value in the original array
        maxValue = max(array)
        # Fill the padded part of the array with the maximum value
        paddedArray[len(array):] = [maxValue] * (paddedSize - len(array))
        # Perform Bitonic Sort on the padded array in ascending order
        self.bitonicSort(paddedArray, 0, paddedSize, self.Direction.ASCENDING)
        # Return the sorted array, excluding the padded elements
        return paddedArray[:len(array)]

    # Recursive method to perform Bitonic Sort
    def bitonicSort(self, array, low, cnt, direction):
        # Base case: if the count is greater than 1, continue sorting
        if cnt > 1:
            k = cnt // 2
            # Sort the first half in ascending order
            self.bitonicSort(array, low, k, self.Direction.ASCENDING)
            # Sort the second half in descending order
            self.bitonicSort(array, low + k, cnt - k, self.Direction.DESCENDING)
            # Merge the two halves
            self.bitonicMerge(array, low, cnt, direction)

    # Method to merge two sorted halves of the array
    def bitonicMerge(self, array, low, cnt, direction):
        # Base case: if the count is greater than 1, continue merging
        if cnt > 1:
            k = cnt // 2
            # Define a predicate to check if elements are sorted based on the direction
            areSorted = (direction == self.Direction.ASCENDING) and (lambda a, b: a < b) or (lambda a, b: a > b)
            # Compare and swap elements to ensure they are in the correct order
            for i in range(low, low + k):
                if not areSorted(array[i], array[i + k]):
                    self.swap(array, i, i + k)
            # Recursively merge the first and second halves
            self.bitonicMerge(array, low, k, direction)
            self.bitonicMerge(array, low + k, cnt - k, direction)

    # Method to find the next power of two greater than or equal to n
    def nextPowerOfTwo(self, n):
        count = 0
        # If n is already a power of two, return it
        if (n & (n - 1)) == 0:
            return n
        # Calculate the next power of two
        while n!= 0:
            n >>= 1
            count += 1
        return 1 << count

    # Method to find the maximum element in an array
    def max(self, array):
        return max(array)

    # Method to swap two elements in an array
    def swap(self, array, i, j):
        temp = array[i]
        array[i] = array[j]
        array[j] = temp

    # Main method to execute the sorting program
    def main(self):
        scanner = Scanner(System.in)
        # Read the number of elements in the array
        n = scanner.nextInt()
        array = [0] * n
        # Read the elements of the array from user input
        for i in range(n):
            array[i] = scanner.nextInt()
        # Create an instance of Main to access the sort method
        sorter = Main()
        # Sort the array using Bitonic Sort
        sortedArray = sorter.sort(array)
        # Print the sorted array
        for num in sortedArray:
            print(num, end=" ")
        # Close the scanner to prevent resource leaks
        scanner.close()

# 