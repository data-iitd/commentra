import sys
from typing import List, TypeVar, Generic

T = TypeVar('T', bound='Comparable')

class Comparable:
    def __lt__(self, other):
        return NotImplemented

class BucketSort(Generic[T]):
    BUCKET_DIVISOR = 10

    def sort(self, array: List[T]) -> List[T]:
        if len(array) == 0:
            return array
        min_val = self.find_min(array)
        max_val = self.find_max(array)
        number_of_buckets = self.calculate_number_of_buckets(len(array))
        buckets = self.initialize_buckets(number_of_buckets)
        self.distribute_elements_into_buckets(array, buckets, min_val, max_val, number_of_buckets)
        return self.concatenate_buckets(buckets, array)

    def calculate_number_of_buckets(self, array_length: int) -> int:
        return max(array_length // self.BUCKET_DIVISOR, 1)

    def initialize_buckets(self, number_of_buckets: int) -> List[List[T]]:
        return [[] for _ in range(number_of_buckets)]

    def distribute_elements_into_buckets(self, array: List[T], buckets: List[List[T]], min_val: T, max_val: T, number_of_buckets: int):
        for element in array:
            bucket_index = self.hash(element, min_val, max_val, number_of_buckets)
            buckets[bucket_index].append(element)

    def concatenate_buckets(self, buckets: List[List[T]], array: List[T]) -> List[T]:
        index = 0
        for bucket in buckets:
            bucket.sort()
            for element in bucket:
                array[index] = element
                index += 1
        return array

    def hash(self, element: T, min_val: T, max_val: T, number_of_buckets: int) -> int:
        range_val = max_val - min_val
        normalized_value = (element - min_val) / range_val
        return int(normalized_value * (number_of_buckets - 1))

    def find_min(self, array: List[T]) -> T:
        return min(array)

    def find_max(self, array: List[T]) -> T:
        return max(array)

if __name__ == "__main__":
    n = int(input())
    array = [float(input()) for _ in range(n)]
    sorter = BucketSort[float]()
    sorted_array = sorter.sort(array)
    print(" ".join(map(str, sorted_array)))

# <END-OF-CODE>
