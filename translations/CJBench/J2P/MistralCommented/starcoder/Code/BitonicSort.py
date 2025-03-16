import java.util.Arrays;
import java.util.Scanner;
import java.util.function.BiPredicate;

class Main:
    class Direction:
        DESCENDING = 0
        ASCENDING = 1

    def sort(self, array):
        if len(array) == 0:
            # If the array is empty, return it as is.
            return array

        paddedSize = self.nextPowerOfTwo(len(array))
        paddedArray = array.copy()
        paddedArray.extend([0] * (paddedSize - len(array)))
        # Pad the array with 0 to make it a power of 2 size.

        maxValue = max(array)
        paddedArray[len(array):] = [maxValue] * (paddedSize - len(array))
        # Pad the array with maxValue to make it a power of 2 size.

        self.bitonicSort(paddedArray, 0, paddedSize, self.Direction.ASCENDING)
        return paddedArray[:len(array)]
        # Perform the sorting and return the sorted array.

    def bitonicSort(self, array, low, cnt, direction):
        if cnt > 1:
            k = cnt // 2
            # If the portion has more than one element, recursively sort the left and right halves.

            self.bitonicSort(array, low, k, self.Direction.ASCENDING)
            self.bitonicSort(array, low + k, cnt - k, self.Direction.DESCENDING)
            # Merge the sorted halves.

            self.bitonicMerge(array, low, cnt, direction)
        # Merge the sorted halves.

    def bitonicMerge(self, array, low, cnt, direction):
        if cnt > 1:
            k = cnt // 2
            # If the portion has more than one element, merge the left and right halves.

            areSorted = (direction == self.Direction.ASCENDING) and (lambda a, b: a < b) or (lambda a, b: a > b)
            # Define a comparator based on the sorting direction.

            for i in range(low, low + k):
                if not areSorted(array[i], array[i + k]):
                    # If two adjacent elements are not in the correct order, swap them.
                    array[i], array[i + k] = array[i + k], array[i]
            self.bitonicMerge(array, low, k, direction)
            # Merge the left half recursively.

            self.bitonicMerge(array, low + k, cnt - k, direction)
            # Merge the right half recursively.

    def nextPowerOfTwo(self, n):
        count = 0
        if (n & (n - 1)) == 0:
            # If n is already a power of 2, return it.
            return n

        while n!= 0:
            n >>= 1
            count += 1
        # Calculate the number of bits needed to represent the next power of 2.

        return 1 << count
        # Return the next power of 2 as a power of 2 raised to the calculated number of bits.

    def max(self, array):
        return max(array)
        # Use Python max() function to find the maximum value in the array.

    def swap(self, array, i, j):
        array[i], array[j] = array[j], array[i]
        # Swap the elements by temporarily storing one of them and assigning the other to its place.

    def main(self):
        scanner = Scanner(System.in)
        n = scanner.nextInt()
        # Read the number of elements in the array from the standard input.

        array = [0] * n
        # Allocate an array of integers of the given size.

        for i in range(n):
            array[i] = scanner.nextInt()
            # Read each element of the array from the standard input.

        sorter = Main()
        # Instantiate the Main class to use its sorting functionality.

        sortedArray = sorter.sort(array)
        # Call the sorting method to sort the array.

        for num in sortedArray:
            print(num, end=" ")
            # Print each sorted element to the standard output.

        scanner.close()
        # Close the standard input scanner.

if __name__ == "__main__":
    Main().main()
# Main method for testing the sorting functionality.

