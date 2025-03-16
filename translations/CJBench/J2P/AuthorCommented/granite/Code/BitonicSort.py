

import math
import sys

class Direction:
    DESCENDING = 1
    ASCENDING = 2

def next_power_of_two(n):
    count = 0
    if (n & (n - 1)) == 0:
        return n
    while n!= 0:
        n >>= 1
        count += 1
    return 1 << count

def max(array):
    return max(array)

def swap(array, i, j):
    array[i], array[j] = array[j], array[i]

def bitonic_sort(array, low, cnt, direction):
    if cnt > 1:
        k = cnt // 2
        bitonic_sort(array, low, k, Direction.ASCENDING)
        bitonic_sort(array, low + k, cnt - k, Direction.DESCENDING)
        bitonic_merge(array, low, cnt, direction)

def bitonic_merge(array, low, cnt, direction):
    if cnt > 1:
        k = cnt // 2
        are_sorted = (direction == Direction.ASCENDING)
        for i in range(low, low + k):
            if are_sorted(array[i], array[i + k]):
                swap(array, i, i + k)
        bitonic_merge(array, low, k, direction)
        bitonic_merge(array, low + k, cnt - k, direction)

def sort(array):
    if len(array) == 0:
        return array
    padded_size = next_power_of_two(len(array))
    padded_array = array + [max(array)] * (padded_size - len(array))
    bitonic_sort(padded_array, 0, padded_size, Direction.ASCENDING)
    return padded_array[:len(array)]

if __name__ == "__main__":
    n = int(input())
    array = list(map(int, input().split()))
    sorted_array = sort(array)
    print(" ".join(map(str, sorted_array)))

