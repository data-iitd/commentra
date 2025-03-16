import array
import math
from typing import List, TypeVar, Callable, Any

T = TypeVar('T', bound=Comparable)

class Main:
    class Direction(Enum):
        DESCENDING = 1
        ASCENDING = 2

    def sort(self, array: List[T]) -> List[T]:
        if len(array) == 0:
            return array
        padded_size = self.next_power_of_two(len(array))
        padded_array = array + [max(array)] * (padded_size - len(array))
        self.bitonic_sort(padded_array, 0, padded_size, self.Direction.ASCENDING)
        return padded_array[:len(array)]

    def bitonic_sort(self, array: List[T], low: int, cnt: int, direction: Direction) -> None:
        if cnt > 1:
            k = cnt // 2
            self.bitonic_sort(array, low, k, self.Direction.ASCENDING)
            self.bitonic_sort(array, low + k, cnt - k, self.Direction.DESCENDING)
            self.bitonic_merge(array, low, cnt, direction)

    def bitonic_merge(self, array: List[T], low: int, cnt: int, direction: Direction) -> None:
        if cnt > 1:
            k = cnt // 2
            are_sorted = (lambda a, b: a < b) if direction == self.Direction.ASCENDING else (lambda a, b: a > b)
            for i in range(low, low + k):
                if not are_sorted(array[i], array[i + k]):
                    array[i], array[i + k] = array[i + k], array[i]
            self.bitonic_merge(array, low, k, direction)
            self.bitonic_merge(array, low + k, cnt - k, direction)

    @staticmethod
    def next_power_of_two(n: int) -> int:
        if n & (n - 1) == 0:
            return n
        count = 0
        while n != 0:
            n >>= 1
            count += 1
        return 1 << count

    @staticmethod
    def max(array: List[T]) -> T:
        return max(array)

    @staticmethod
    def swap(array: List[T], i: int, j: int) -> None:
        array[i], array[j] = array[j], array[i]

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    array = [int(x) for x in data[1:n+1]]
    sorter = Main()
    sorted_array = sorter.sort(array)
    print(" ".join(map(str, sorted_array)))
