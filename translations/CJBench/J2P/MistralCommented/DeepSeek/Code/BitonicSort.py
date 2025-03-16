import sys
import math

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
            self.bitonic_sort(array, low, k, self.Direction.ASCENDING)
            self.bitonic_sort(array, low + k, cnt - k, self.Direction.DESCENDING)
            self.bitonic_merge(array, low, cnt, direction)

    def bitonic_merge(self, array, low, cnt, direction):
        if cnt > 1:
            k = cnt // 2
            for i in range(low, low + k):
                if (direction == self.Direction.ASCENDING and array[i] > array[i + k]) or \
                   (direction == self.Direction.DESCENDING and array[i] < array[i + k]):
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
        n = int(input().strip())
        array = list(map(int, input().strip().split()))
        sorter = Main()
        sorted_array = sorter.sort(array)
        print(" ".join(map(str, sorted_array)))

if __name__ == "__main__":
    Main.main(sys.argv)
