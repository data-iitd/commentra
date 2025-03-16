
import sys

class Main:
    class Direction:
        DESCENDING = 0
        ASCENDING = 1

    def __init__(self):
        pass

    def sort(self, array):
        if len(array) == 0:
            return array

        padded_size = self.next_power_of_two(len(array))
        padded_array = array.copy()

        # Fill the padded part with a maximum value
        max_value = self.max(array)
        for i in range(len(array), padded_size):
            padded_array[i] = max_value

        self.bitonic_sort(padded_array, 0, padded_size, self.Direction.ASCENDING)
        return padded_array[:len(array)]

    def bitonic_sort(self, array, low, cnt, direction):
        if cnt > 1:
            k = cnt // 2

            # Sort first half in ascending order
            self.bitonic_sort(array, low, k, self.Direction.ASCENDING)

            # Sort second half in descending order
            self.bitonic_sort(array, low + k, cnt - k, self.Direction.DESCENDING)

            # Merge the whole sequence in ascending order
            self.bitonic_merge(array, low, cnt, direction)

    def bitonic_merge(self, array, low, cnt, direction):
        if cnt > 1:
            k = cnt // 2

            are_sorted = (direction == self.Direction.ASCENDING) and (lambda a, b: a < b) or (lambda a, b: a > b)

            for i in range(low, low + k):
                if not are_sorted(array[i], array[i + k]):
                    self.swap(array, i, i + k)

            self.bitonic_merge(array, low, k, direction)
            self.bitonic_merge(array, low + k, cnt - k, direction)

    def next_power_of_two(self, n):
        count = 0

        # If n is already a power of two
        if (n & (n - 1)) == 0:
            return n

        while n!= 0:
            n >>= 1
            count += 1

        return 1 << count

    def max(self, array):
        return max(array)

    def swap(self, array, i, j):
        temp = array[i]
        array[i] = array[j]
        array[j] = temp

    def main(self):
        # Input size of the array
        n = int(input())

        # Input array elements
        array = [int(x) for x in input().split()]

        sorter = Main()
        sorted_array = sorter.sort(array)

        # Print sorted array
        for num in sorted_array:
            print(num, end=' ')

if __name__ == '__main__':
    main = Main()
    main.main()

