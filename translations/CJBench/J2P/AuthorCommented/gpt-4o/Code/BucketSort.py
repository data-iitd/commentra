import math

class BucketSort:
    # Constant that defines the divisor for determining the number of buckets
    BUCKET_DIVISOR = 10

    def sort(self, array):
        if len(array) == 0:
            return array

        min_value = self.find_min(array)
        max_value = self.find_max(array)
        number_of_buckets = self.calculate_number_of_buckets(len(array))

        buckets = self.initialize_buckets(number_of_buckets)
        self.distribute_elements_into_buckets(array, buckets, min_value, max_value, number_of_buckets)

        return self.concatenate_buckets(buckets, array)

    def calculate_number_of_buckets(self, array_length):
        return max(array_length // self.BUCKET_DIVISOR, 1)

    def initialize_buckets(self, number_of_buckets):
        return [[] for _ in range(number_of_buckets)]

    def distribute_elements_into_buckets(self, array, buckets, min_value, max_value, number_of_buckets):
        for element in array:
            bucket_index = self.hash(element, min_value, max_value, number_of_buckets)
            buckets[bucket_index].append(element)

    def concatenate_buckets(self, buckets, array):
        index = 0
        for bucket in buckets:
            bucket.sort()
            for element in bucket:
                array[index] = element
                index += 1
        return array

    def hash(self, element, min_value, max_value, number_of_buckets):
        range_value = max_value - min_value
        normalized_value = (element - min_value) / range_value
        return int(normalized_value * (number_of_buckets - 1))

    def find_min(self, array):
        return min(array)

    def find_max(self, array):
        return max(array)

if __name__ == "__main__":
    n = int(input("Enter the number of elements: "))
    array = [float(input()) for _ in range(n)]

    sorter = BucketSort()
    sorted_array = sorter.sort(array)

    print("Sorted array:")
    print(" ".join(map(str, sorted_array)))

# <END-OF-CODE>
