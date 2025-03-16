
import random

class BucketSort:
    def __init__(self):
        pass

    def sort(self, array):
        if len(array) == 0:
            return array

        min_val = min(array)
        max_val = max(array)
        number_of_buckets = self.calculate_number_of_buckets(len(array))

        buckets = self.initialize_buckets(number_of_buckets)
        self.distribute_elements_into_buckets(array, buckets, min_val, max_val, number_of_buckets)

        return self.concatenate_buckets(buckets, array)

    def calculate_number_of_buckets(self, array_length):
        return max(array_length // 10, 1)

    def initialize_buckets(self, number_of_buckets):
        return [[] for _ in range(number_of_buckets)]

    def distribute_elements_into_buckets(self, array, buckets, min_val, max_val, number_of_buckets):
        for element in array:
            bucket_index = self.hash(element, min_val, max_val, number_of_buckets)
            buckets[bucket_index].append(element)

    def concatenate_buckets(self, buckets, array):
        index = 0
        for bucket in buckets:
            bucket.sort()
            for element in bucket:
                array[index] = element
                index += 1
        return array

    def hash(self, element, min_val, max_val, number_of_buckets):
        range_ = max_val - min_val
        normalized_value = (element - min_val) / range_
        return int(normalized_value * (number_of_buckets - 1))

if __name__ == "__main__":
    n = int(input())
    array = [float(x) for x in input().split()]

    sorter = BucketSort()
    sorted_array = sorter.sort(array)

    print(" ".join(map(str, sorted_array)))

