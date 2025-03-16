
import math


def next_power_of_two(n):
    count = 0
    if (n & (n - 1)) == 0:
        # If n is already a power of 2, return it.
        return n
    while n != 0:
        n >>= 1
        count += 1
    # Calculate the number of bits needed to represent the next power of 2.

    return 1 << count
    # Return the next power of 2 as a power of 2 raised to the calculated number of bits.


def max(array):
    return max(array)
    # Use Python's built-in max function to find the maximum value in the array.


def swap(array, i, j):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp
    # Swap the elements by temporarily storing one of them and assigning the other to its place.


def bitonic_sort(array, low, cnt, direction):
    if cnt > 1:
        k = cnt // 2
        # If the portion has more than one element, recursively sort the left and right halves.

        bitonic_sort(array, low, k, Direction.ASCENDING)
        bitonic_sort(array, low + k, cnt - k, Direction.DESCENDING)
        # Merge the sorted halves.

        bitonic_merge(array, low, cnt, direction)


def bitonic_merge(array, low, cnt, direction):
    if cnt > 1:
        k = cnt // 2
        # If the portion has more than one element, merge the left and right halves.

        if direction == Direction.ASCENDING:
            are_sorted = lambda a, b: a < b
            # Define a comparator based on the sorting direction.
        else:
            are_sorted = lambda a, b: a > b

        for i in range(low, low + k):
            if not are_sorted(array[i], array[i + k]):
                # If two adjacent elements are not in the correct order, swap them.
                swap(array, i, i + k)

        bitonic_merge(array, low, k, direction)
        # Merge the left half recursively.

        bitonic_merge(array, low + k, cnt - k, direction)
        # Merge the right half recursively.


class Direction(Enum):
    DESCENDING = 0
    ASCENDING = 1


class Main:
    def sort(self, array):
        if len(array) == 0:
            # If the array is empty, return it as is.
            return array

        padded_size = next_power_of_two(len(array))
        padded_array = array[:]
        max_value = max(array)
        padded_array.extend([max_value] * (padded_size - len(array)))
        # Pad the array with maxValue to make it a power of 2 size.

        bitonic_sort(padded_array, 0, padded_size, Direction.ASCENDING)
        return padded_array[:len(array)]
        # Perform the sorting and return the sorted array.


if __name__ == "__main__":
    n = int(input())
    # Read the number of elements in the array from the standard input.

    array = list(map(int, input().split()))
    # Allocate an array of integers of the given size.

    sorter = Main()
    # Instantiate the Main class to use its sorting functionality.

    sorted_array = sorter.sort(array)
    # Call the sorting method to sort the array.

    for num in sorted_array:
        print(num, end=" ")
        # Print each sorted element to the standard output.

    print()
    # Print a newline at the end of the output.

