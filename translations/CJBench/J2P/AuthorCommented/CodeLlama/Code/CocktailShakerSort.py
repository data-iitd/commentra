
# Importing the Scanner class from the java.util package
from java.util import Scanner

# Main class implements the Cocktail Shaker Sort algorithm,
# which is a bidirectional bubble sort. It sorts the array by passing
# through it back and forth, progressively moving the largest elements
# to the end and the smallest elements to the beginning.
class Main:

    # Sorts the given array using the Cocktail Shaker Sort algorithm.
    #
    # @param <T> The type of elements in the array, which must be comparable
    # @param array The array to be sorted
    # @return The sorted array
    def sort(self, array):
        if len(array) == 0:
            return

        left = 0
        right = len(array) - 1

        while left < right:
            right = self.perform_forward_pass(array, left, right)
            left = self.perform_backward_pass(array, left, right)

    # Performs a forward pass through the array, moving larger elements to the end.
    #
    # @param <T>   The type of elements in the array, which must be comparable
    # @param array The array being sorted
    # @param left  The current left boundary of the sorting area
    # @param right The current right boundary of the sorting area
    # @return The index of the last swapped element during this pass
    def perform_forward_pass(self, array, left, right):
        last_swapped_index = left

        for i in range(left, right):
            if array[i] > array[i + 1]:
                self.swap(array, i, i + 1)
                last_swapped_index = i

        return last_swapped_index

    # Performs a backward pass through the array, moving smaller elements to the beginning.
    #
    # @param <T>   The type of elements in the array, which must be comparable
    # @param array The array being sorted
    # @param left  The current left boundary of the sorting area
    # @param right The current right boundary of the sorting area
    # @return The index of the last swapped element during this pass
    def perform_backward_pass(self, array, left, right):
        last_swapped_index = right

        for i in range(right, left, -1):
            if array[i] < array[i - 1]:
                self.swap(array, i - 1, i)
                last_swapped_index = i

        return last_swapped_index

    # Swaps two elements in the array.
    #
    # @param array The array
    # @param i Index of the first element
    # @param j Index of the second element
    def swap(self, array, i, j):
        temp = array[i]
        array[i] = array[j]
        array[j] = temp

# Reading the size of the array
scanner = Scanner(System.in)
n = scanner.nextInt()
array = [None] * n

# Reading the array elements
for i in range(n):
    array[i] = scanner.nextInt()

# Sorting the array
sorter = Main()
sorter.sort(array)

# Printing the sorted array
for num in array:
    print(num, end=" ")

scanner.close()

