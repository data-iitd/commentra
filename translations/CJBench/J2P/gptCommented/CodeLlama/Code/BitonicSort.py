
import math

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
        padded_size = self.next_power_of_two(len(array))
        # Create a padded array to accommodate the Bitonic Sort
        padded_array = array[:]
        # Fill the padded part of the array with the maximum value
        padded_array.extend([max(array)] * (padded_size - len(array)))
        # Perform Bitonic Sort on the padded array in ascending order
        self.bitonic_sort(padded_array, 0, padded_size, self.Direction.ASCENDING)
        # Return the sorted array, excluding the padded elements
        return padded_array[:len(array)]

    # Recursive method to perform Bitonic Sort
    def bitonic_sort(self, array, low, cnt, direction):
        # Base case: if the count is greater than 1, continue sorting
        if cnt > 1:
            k = cnt // 2
            # Sort the first half in ascending order
            self.bitonic_sort(array, low, k, self.Direction.ASCENDING)
            # Sort the second half in descending order
            self.bitonic_sort(array, low + k, cnt - k, self.Direction.DESCENDING)
            # Merge the two halves
            self.bitonic_merge(array, low, cnt, direction)

    # Method to merge two sorted halves of the array
    def bitonic_merge(self, array, low, cnt, direction):
        # Base case: if the count is greater than 1, continue merging
        if cnt > 1:
            k = cnt // 2
            # Define a predicate to check if elements are sorted based on the direction
            are_sorted = (direction == self.Direction.ASCENDING) and (lambda a, b: a < b) or (lambda a, b: a > b)
            # Compare and swap elements to ensure they are in the correct order
            for i in range(low, low + k):
                if not are_sorted(array[i], array[i + k]):
                    array[i], array[i + k] = array[i + k], array[i]
            # Recursively merge the first and second halves
            self.bitonic_merge(array, low, k, direction)
            self.bitonic_merge(array, low + k, cnt - k, direction)

    # Method to find the next power of two greater than or equal to n
    def next_power_of_two(self, n):
        count = 0
        # If n is already a power of two, return it
        if (n & (n - 1)) == 0:
            return n
        # Calculate the next power of two
        while n != 0:
            n >>= 1
            count += 1
        return 1 << count

    # Method to find the maximum element in an array
    def max(self, array):
        return max(array)

    # Method to swap two elements in an array
    def swap(self, array, i, j):
        array[i], array[j] = array[j], array[i]

    # Main method to execute the sorting program
    def main(self):
        # Read the number of elements in the array
        n = int(input())
        array = list(map(int, input().split()))
        # Create an instance of Main to access the sort method
        sorter = Main()
        # Sort the array using Bitonic Sort
        sorted_array = sorter.sort(array)
        # Print the sorted array
        print(*sorted_array)

if __name__ == "__main__":
    Main().main()

