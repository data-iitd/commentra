
import math
import sys

def next_power_of_two(n):
    count = 0
    if (n & (n - 1)) == 0:
        return n
    while n != 0:
        n >>= 1
        count += 1
    return 1 << count

def max(array):
    return max(array)

def sort(array):
    if len(array) == 0:
        return array
    padded_size = next_power_of_two(len(array))
    padded_array = array[:]
    max_value = max(array)
    for i in range(len(array), padded_size):
        padded_array.append(max_value)
    bitonic_sort(padded_array, 0, padded_size, "ASCENDING")
    return padded_array[:len(array)]

def bitonic_sort(array, low, cnt, direction):
    if cnt > 1:
        k = cnt // 2
        bitonic_sort(array, low, k, "ASCENDING")
        bitonic_sort(array, low + k, cnt - k, "DESCENDING")
        bitonic_merge(array, low, cnt, direction)

def bitonic_merge(array, low, cnt, direction):
    if cnt > 1:
        k = cnt // 2
        are_sorted = (direction == "ASCENDING")
        for i in range(low, low + k):
            if not (array[i] < array[i + k] if are_sorted else array[i] > array[i + k]):
                array[i], array[i + k] = array[i + k], array[i]
        bitonic_merge(array, low, k, direction)
        bitonic_merge(array, low + k, cnt - k, direction)

def swap(array, i, j):
    array[i], array[j] = array[j], array[i]

def main():
    n = int(sys.stdin.readline())
    array = list(map(int, sys.stdin.readline().split()))
    sorted_array = sort(array)
    for num in sorted_array:
        print(num, end=" ")
    print()

if __name__ == "__main__":
    main()

