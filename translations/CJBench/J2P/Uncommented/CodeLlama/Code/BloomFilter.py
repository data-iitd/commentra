
import math
import sys

class Hash:
    def __init__(self, index):
        self.index = index

    def compute(self, key):
        return self.index * sum([ord(c) for c in key])

class BloomFilter:
    def __init__(self, number_of_hash_functions, bit_array_size):
        self.number_of_hash_functions = number_of_hash_functions
        self.bit_array = [0] * bit_array_size
        self.hash_functions = [Hash(i) for i in range(number_of_hash_functions)]

    def insert(self, key):
        for hash in self.hash_functions:
            position = abs(hash.compute(key) % len(self.bit_array))
            self.bit_array[position] = 1

    def contains(self, key):
        for hash in self.hash_functions:
            position = abs(hash.compute(key) % len(self.bit_array))
            if self.bit_array[position] == 0:
                return False
        return True

if __name__ == "__main__":
    number_of_hash_functions, bit_array_size, number_of_elements = map(int, sys.stdin.readline().split())
    bloom_filter = BloomFilter(number_of_hash_functions, bit_array_size)
    for _ in range(number_of_elements):
        element = sys.stdin.readline().strip()
        bloom_filter.insert(element)
    query = sys.stdin.readline().strip()
    result = bloom_filter.contains(query)
    print("Element might be in the set:", result)

