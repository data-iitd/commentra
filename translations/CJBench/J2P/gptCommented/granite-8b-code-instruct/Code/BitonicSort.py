
import math

class Main:
    # Enum to define sorting direction
    class Direction:
        DESCENDING = 1
        ASCENDING = 2

    # Method to sort an array using Bitonic Sort
    def sort(self, array):
        # Return the original array if it's empty
        if len(array) == 0:
            return array
        # Calculate the next power of two for padding the array
        padded_size = 1 << math.ceil(math.log2(len(array)))
        # Create a padded array to accommodate the Bitonic Sort
        padded_array = array + [max(array)] * (padded_size - len(array))
        # Perform Bitonic Sort on the padded array in ascending order
        self.bitonic_sort(padded_array, 0, padded_size, Main.Direction.ASCENDING)
        # Return the sorted array, excluding the padded elements
        return padded_array[:len(array)]

    # Recursive method to perform Bitonic Sort
    def bitonic_sort(self, array, low, cnt, direction):
        # Base case: if the count is greater than 1, continue sorting
        if cnt > 1:
            k = cnt // 2
            # Sort the first half in ascending order
            self.bitonic_sort(array, low, k, Main.Direction.ASCENDING)
            # Sort the second half in descending order
            self.bitonic_sort(array, low + k, cnt - k, Main.Direction.DESCENDING)
            # Merge the two halves
            self.bitonic_merge(array, low, cnt, direction)

    # Method to merge two sorted halves of the array
    def bitonic_merge(self, array, low, cnt, direction):
        # Base case: if the count is greater than 1, continue merging
        if cnt > 1:
            k = cnt // 2
            # Define a predicate to check if elements are sorted based on the direction
            are_sorted = lambda a, b: (a < b) if direction == Main.Direction.ASCENDING else (a > b)
            # Compare and swap elements to ensure they are in the correct order
            for i in range(low, low + k):
                if not are_sorted(array[i], array[i + k]):
                    array[i], array[i + k] = array[i + k], array[i]
            # Recursively merge the first and second halves
            self.bitonic_merge(array, low, k, direction)
            self.bitonic_merge(array, low + k, cnt - k, direction)

    # Method to find the maximum element in an array
    def max(self, array):
        return max(array)

    # Main method to execute the sorting program
    def main(self):
        n = int(input("Enter the number of elements in the array: "))
        array = [int(input(f"Enter element {i + 1}: ")) for i in range(n)]
        # Create an instance of Main to access the sort method
        sorter = Main()
        # Sort the array using Bitonic Sort
        sorted_array = sorter.sort(array)
        # Print the sorted array
        print("Sorted array:", sorted_array)

# Execute the main method of the Main class
Main().main()

