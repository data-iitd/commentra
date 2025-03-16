import math
import sys

class Main:
    BUCKET_DIVISOR = 10

    def sort(self, array):
        if len(array) == 0:
            return array
        min = self.find_min(array)
        max = self.find_max(array)
        number_of_buckets = self.calculate_number_of_buckets(len(array))
        buckets = self.initialize_buckets(number_of_buckets)
        self.distribute_elements_into_buckets(array, buckets, min, max, number_of_buckets)
        return self.concatenate_buckets(buckets, array)

    def calculate_number_of_buckets(self, array_length):
        return max(array_length // self.BUCKET_DIVISOR, 1)

    def initialize_buckets(self, number_of_buckets):
        buckets = []
        for i in range(number_of_buckets):
            buckets.append([])
        return buckets

    def distribute_elements_into_buckets(self, array, buckets, min, max, number_of_buckets):
        for element in array:
            bucket_index = self.hash(element, min, max, number_of_buckets)
            buckets[bucket_index].append(element)

    def concatenate_buckets(self, buckets, array):
        index = 0
        for bucket in buckets:
            bucket.sort()
            for element in bucket:
                array[index] = element
                index += 1
        return array

    def find_min(self, array):
        min = array[0]
        for element in array:
            if element < min:
                min = element
        return min

    def find_max(self, array):
        max = array[0]
        for element in array:
            if element > max:
                max = element
        return max

    def hash(self, element, min, max, number_of_buckets):
        range = max - min
        normalized_value = (element - min) / range
        return int(normalized_value * (number_of_buckets - 1))

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    array = list(map(float, sys.stdin.readline().split()))
    sorter = Main()
    sorted_array = sorter.sort(array)
    for num in sorted_array:
        print(num, end=" ")

# 