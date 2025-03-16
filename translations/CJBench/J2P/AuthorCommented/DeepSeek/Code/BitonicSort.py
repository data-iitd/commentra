import math
import sys

class Main:
    class Direction(Enum):
        DESCENDING = 1
        ASCENDING = 2

    def sort(self, array):
        if len(array) == 0:
            return array

        padded_size = self.next_power_of_two(len(array))
        padded_array = array + [max(array)] * (padded_size - len(array))

        self.bitonic_sort(padded_array, 0, len(padded_array), self.Direction.ASCENDING)
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

            are_sorted = self.Direction.ASCENDING.value if direction == self.Direction.ASCENDING else self.Direction.DESCENDING.value

            for i in range(low, low + k):
                if (are_sorted == self.Direction.ASCENDING.value and array[i] > array[i + k]) or \
                   (are_sorted == self.Direction.DESCENDING.value and array[i] < array[i + k]):
                    array[i], array[i + k] = array[i + k], array[i]

            self.bitonic_merge(array, low, k, direction)
            self.bitonic_merge(array, low + k, cnt - k, direction)

    def next_power_of_two(self, n):
        if n & (n - 1) == 0:
            return n

        count = 0
        while n != 0:
            n >>= 1
            count += 1

        return 1 << count

    @staticmethod
    def max(array):
        return max(array)

    @staticmethod
    def swap(array, i, j):
        array[i], array[j] = array[j], array[i]

    @staticmethod
    def main(args):
        import sys
        input = sys.stdin.read
        data = input().split()

        n = int(data[0])
        array = [int(x) for x in data[1:n+1]]

        sorter = Main()
        sorted_array = sorter.sort(array)

        for num in sorted_array:
            print(num, end=' ')
