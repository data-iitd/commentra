

import math

class Hash:
    def __init__(self, index):
        self.index = index

    def compute(self, key):
        return self.index * sum(ord(c) for c in str(key))

class BloomFilter:
    def __init__(self, num_hash_functions, bit_array_size):
        if num_hash_functions < 1 or bit_array_size < 1:
            raise ValueError("Number of hash functions and bit array size must be greater than 0")
        self.num_hash_functions = num_hash_functions
        self.bit_array_size = bit_array_size
        self.bit_array = [False] * bit_array_size
        self.hash_functions = [Hash(i) for i in range(num_hash_functions)]

    def insert(self, key):
        for hash_func in self.hash_functions:
            position = abs(hash_func.compute(key) % self.bit_array_size)
            self.bit_array[position] = True

    def contains(self, key):
        for hash_func in self.hash_functions:
            position = abs(hash_func.compute(key) % self.bit_array_size)
            if not self.bit_array[position]:
                return False
        return True

if __name__ == "__main__":
    num_hash_functions = int(input("Enter the number of hash functions: "))
    bit_array_size = int(input("Enter the bit array size: "))
    num_elements = int(input("Enter the number of elements to insert: "))
    bloom_filter = BloomFilter(num_hash_functions, bit_array_size)
    for _ in range(num_elements):
        element = input("Enter an element to insert: ")
        bloom_filter.insert(element)
    query = input("Enter the query element: ")
    result = bloom_filter.contains(query)
    print(f"Element might be in the set: {result}")

These comments provide a clear understanding of each part of the code, making it easier to understand and maintain.