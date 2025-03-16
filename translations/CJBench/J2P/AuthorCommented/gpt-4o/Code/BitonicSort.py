import numpy as np

class Main:
    class Direction:
        DESCENDING = 1
        ASCENDING = 2

    def sort(self, array):
        if len(array) == 0:
            return array

        padded_size = self.next_power_of_two(len(array))
        padded_array = np.copy(array)

        # Fill the padded part with a maximum value
        max_value = self.max(array)
        padded_array = np.pad(padded_array, (0, padded_size - len(array)), 'constant', constant_values=max_value)

        self.bitonic_sort(padded_array, 0, padded_size, self.Direction.ASCENDING)
        return padded_array[:len(array)]

    def bitonic_sort(self, array, low, cnt, direction):
        if cnt > 1:
            k = cnt // 2

            # Sort first half in ascending order
            self.bitonic_sort(array, low, k, self.Direction.ASCENDING)

            # Sort second half in descending order
            self.bitonic_sort(array, low + k, cnt - k, self.Direction.DESCENDING)

            # Merge the whole sequence in the specified direction
            self.bitonic_merge(array, low, cnt, direction)

    def bitonic_merge(self, array, low, cnt, direction):
        if cnt > 1:
            k = cnt // 2

            are_sorted = (lambda a, b: a < b) if direction == self.Direction.ASCENDING else (lambda a, b: a > b)

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
        if len(array) == 0:
            raise ValueError("Array is empty")
        return max(array)

    @staticmethod
    def swap(array, i, j):
        array[i], array[j] = array[j], array[i]

if __name__ == "__main__":
    n = int(input("Input size of the array: "))

    # Input array elements
    array = list(map(int, input("Input array elements: ").split()))

    sorter = Main()
    sorted_array = sorter.sort(array)

    # Print sorted array
    print("Sorted array:", ' '.join(map(str, sorted_array)))

# <END-OF-CODE>
