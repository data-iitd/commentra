import numpy as np

class BitonicSort:
    class Direction:
        DESCENDING = 0
        ASCENDING = 1

    def sort(self, array):
        if len(array) == 0:
            return array

        padded_size = self.next_power_of_two(len(array))
        padded_array = np.copy(array)
        padded_array = np.pad(padded_array, (0, padded_size - len(array)), 'constant', constant_values=self.max(array))
        # Pad the array with max value to make it a power of 2 size.

        self.bitonic_sort(padded_array, 0, padded_size, self.Direction.ASCENDING)
        return padded_array[:len(array)]
        # Perform the sorting and return the sorted array.

    def bitonic_sort(self, array, low, cnt, direction):
        if cnt > 1:
            k = cnt // 2
            # If the portion has more than one element, recursively sort the left and right halves.

            self.bitonic_sort(array, low, k, self.Direction.ASCENDING)
            self.bitonic_sort(array, low + k, cnt - k, self.Direction.DESCENDING)
            # Merge the sorted halves.

            self.bitonic_merge(array, low, cnt, direction)

    def bitonic_merge(self, array, low, cnt, direction):
        if cnt > 1:
            k = cnt // 2
            # If the portion has more than one element, merge the left and right halves.

            are_sorted = (lambda a, b: a < b) if direction == self.Direction.ASCENDING else (lambda a, b: a > b)
            # Define a comparator based on the sorting direction.

            for i in range(low, low + k):
                if not are_sorted(array[i], array[i + k]):
                    self.swap(array, i, i + k)
            self.bitonic_merge(array, low, k, direction)
            # Merge the left half recursively.

            self.bitonic_merge(array, low + k, cnt - k, direction)
            # Merge the right half recursively.

    @staticmethod
    def next_power_of_two(n):
        if (n & (n - 1)) == 0:
            return n
        # If n is already a power of 2, return it.

        count = 0
        while n != 0:
            n >>= 1
            count += 1
        # Calculate the number of bits needed to represent the next power of 2.

        return 1 << count
        # Return the next power of 2 as a power of 2 raised to the calculated number of bits.

    @staticmethod
    def max(array):
        return max(array)
        # Use built-in max function to find the maximum value in the array.

    @staticmethod
    def swap(array, i, j):
        array[i], array[j] = array[j], array[i]
        # Swap the elements by unpacking.

if __name__ == "__main__":
    n = int(input())
    # Read the number of elements in the array from the standard input.

    array = list(map(int, input().split()))
    # Read each element of the array from the standard input.

    sorter = BitonicSort()
    # Instantiate the BitonicSort class to use its sorting functionality.

    sorted_array = sorter.sort(array)
    # Call the sorting method to sort the array.

    print(" ".join(map(str, sorted_array)))
    # Print each sorted element to the standard output.
    
# <END-OF-CODE>
