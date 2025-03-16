

import math


def next_power_of_two(n):
    count = 0

    # If n is already a power of two
    if (n & (n - 1)) == 0:
        return n

    while n != 0:
        n >>= 1
        count += 1

    return 1 << count


def max(array):
    return max(array)


def swap(array, i, j):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp


def bitonic_sort(array, low, cnt, direction):
    if cnt > 1:
        k = cnt // 2

        # Sort first half in ascending order
        bitonic_sort(array, low, k, "ASCENDING")

        # Sort second half in descending order
        bitonic_sort(array, low + k, cnt - k, "DESCENDING")

        # Merge the whole sequence in ascending order
        bitonic_merge(array, low, cnt, direction)


def bitonic_merge(array, low, cnt, direction):
    if cnt > 1:
        k = cnt // 2

        are_sorted = (direction == "ASCENDING")

        for i in range(low, low + k):
            if not are_sorted(array[i], array[i + k]):
                swap(array, i, i + k)

        bitonic_merge(array, low, k, direction)
        bitonic_merge(array, low + k, cnt - k, direction)


def sort(array):
    if len(array) == 0:
        return array

    padded_size = next_power_of_two(len(array))
    padded_array = array[:]

    # Fill the padded part with a maximum value
    max_value = max(array)
    padded_array.extend([max_value] * (padded_size - len(array)))

    bitonic_sort(padded_array, 0, padded_size, "ASCENDING")
    return padded_array[:len(array)]


# Test the implementation
array = [1, 3, 5, 7, 9, 2, 4, 6, 8, 10]
sorted_array = sort(array)
print(sorted_array)


# 