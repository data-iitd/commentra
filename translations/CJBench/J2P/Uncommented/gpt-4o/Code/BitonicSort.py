import numpy as np

class Direction:
    DESCENDING = 0
    ASCENDING = 1

class BitonicSorter:
    def sort(self, array):
        if len(array) == 0:
            return array
        padded_size = self.next_power_of_two(len(array))
        padded_array = np.copy(array)  # Use numpy for array manipulation
        padded_array = np.pad(padded_array, (0, padded_size - len(array)), 'constant', constant_values=self.max(array))
        self.bitonic_sort(padded_array, 0, padded_size, Direction.ASCENDING)
        return padded_array[:len(array)]

    def bitonic_sort(self, array, low, cnt, direction):
        if cnt > 1:
            k = cnt // 2
            self.bitonic_sort(array, low, k, Direction.ASCENDING)
            self.bitonic_sort(array, low + k, cnt - k, Direction.DESCENDING)
            self.bitonic_merge(array, low, cnt, direction)

    def bitonic_merge(self, array, low, cnt, direction):
        if cnt > 1:
            k = cnt // 2
            are_sorted = (lambda a, b: a < b) if direction == Direction.ASCENDING else (lambda a, b: a > b)
            for i in range(low, low + k):
                if not are_sorted(array[i], array[i + k]):
                    self.swap(array, i, i + k)
            self.bitonic_merge(array, low, k, direction)
            self.bitonic_merge(array, low + k, cnt - k, direction)

    @staticmethod
    def next_power_of_two(n):
        if (n & (n - 1)) == 0:
            return n
        count = 0
        while n != 0:
            n >>= 1
            count += 1
        return 1 << count

    @staticmethod
    def max(array):
        return np.max(array)

    @staticmethod
    def swap(array, i, j):
        array[i], array[j] = array[j], array[i]

if __name__ == "__main__":
    n = int(input())
    array = list(map(int, input().split()))
    sorter = BitonicSorter()
    sorted_array = sorter.sort(array)
    print(" ".join(map(str, sorted_array)))

# <END-OF-CODE>
