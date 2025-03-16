
import sys
import math

class Main:
    def __init__(self):
        pass

    def sort(self, array):
        if len(array) == 0:
            # If the array is empty, return it as is.
            return array

        padded_size = 2 ** math.ceil(math.log2(len(array)))
        padded_array = array + [max(array)] * (padded_size - len(array))
        # Pad the array with the maximum value to make it a power of 2 size.

        self.bitonic_sort(padded_array, 0, padded_size, "ascending")
        return padded_array[:len(array)]
        # Perform the sorting and return the sorted array.

    def bitonic_sort(self, array, low, cnt, direction):
        if cnt > 1:
            k = cnt // 2
            # If the portion has more than one element, recursively sort the left and right halves.

            self.bitonic_sort(array, low, k, "ascending")
            self.bitonic_sort(array, low + k, cnt - k, "descending")
            # Merge the sorted halves.

            self.bitonic_merge(array, low, cnt, direction)

    def bitonic_merge(self, array, low, cnt, direction):
        if cnt > 1:
            k = cnt // 2
            # If the portion has more than one element, merge the left and right halves.

            are_sorted = self.are_sorted(array[low:low + k], array[low + k:low + 2 * k], direction)
            # Define a comparator based on the sorting direction.

            for i in range(low, low + k):
                if not are_sorted[i - low]:
                    # If two adjacent elements are not in the correct order, swap them.
                    array[i], array[i + k] = array[i + k], array[i]

            self.bitonic_merge(array, low, k, direction)
            # Merge the left half recursively.

            self.bitonic_merge(array, low + k, cnt - k, direction)
            # Merge the right half recursively.

    def are_sorted(self, left, right, direction):
        if direction == "ascending":
            return [left[i] < right[i] for i in range(len(left))]
        else:
            return [left[i] > right[i] for i in range(len(left))]

    def next_power_of_two(self, n):
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
        # Use Python built-in max function to find the maximum value in the array.

    def swap(self, array, i, j):
        array[i], array[j] = array[j], array[i]
        # Swap the elements by temporarily storing one of them and assigning the other to its place.

if __name__ == "__main__":
    n = int(input())
    # Read the number of elements in the array from the standard input.

    array = [int(x) for x in input().split()]
    # Read each element of the array from the standard input.

    sorter = Main()
    # Instantiate the Main class to use its sorting functionality.

    sorted_array = sorter.sort(array)
    # Call the sorting method to sort the array.

    print(" ".join(map(str, sorted_array)))
    # Print each sorted element to the standard output.

