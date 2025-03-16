import math

class Main:
    BUCKET_DIVISOR = 10

    def sort(self, array):
        if len(array) == 0:
            return array

        min_val = min(array)
        max_val = max(array)
        number_of_buckets = max(len(array) // self.BUCKET_DIVISOR, 1)

        buckets = [[] for _ in range(number_of_buckets)]
        self.distribute_elements_into_buckets(array, buckets, min_val, max_val, number_of_buckets)

        return self.concatenate_buckets(buckets, array)

    def calculate_number_of_buckets(self, array_length):
        return max(array_length // self.BUCKET_DIVISOR, 1)

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
        range_val = max_val - min_val
        normalized_value = (element - min_val) / range_val
        return int(normalized_value * (number_of_buckets - 1))

    def find_min(self, array):
        min_val = array[0]
        for element in array:
            if element < min_val:
                min_val = element
        return min_val

    def find_max(self, array):
        max_val = array[0]
        for element in array:
            if element > max_val:
                max_val = element
        return max_val

    @staticmethod
    def main(args):
        import sys
        input = sys.stdin.read
        data = input().split()

        n = int(data[0])
        array = [float(x) for x in data[1:n+1]]

        sorter = Main()
        sorted_array = sorter.sort(array)

        for num in sorted_array:
            print(num, end=" ")
