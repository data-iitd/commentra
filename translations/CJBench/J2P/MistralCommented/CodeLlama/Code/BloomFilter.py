
import math

class Hash:
    def __init__(self, index):
        self.index = index

    def compute(self, key):
        return self.index * sum(ord(c) for c in str(key))

class BloomFilter:
    def __init__(self, number_of_hash_functions, bit_array_size):
        self.number_of_hash_functions = number_of_hash_functions
        self.bit_array = [False] * bit_array_size
        self.hash_functions = [Hash(i) for i in range(number_of_hash_functions)]

    def insert(self, key):
        for hash in self.hash_functions:
            position = abs(hash.compute(key) % len(self.bit_array))
            self.bit_array[position] = True

    def contains(self, key):
        for hash in self.hash_functions:
            position = abs(hash.compute(key) % len(self.bit_array))
            if not self.bit_array[position]:
                return False
        return True

def main():
    number_of_hash_functions = int(input())
    bit_array_size = int(input())
    number_of_elements = int(input())

    bloom_filter = BloomFilter(number_of_hash_functions, bit_array_size)

    for i in range(number_of_elements):
        element = input()
        bloom_filter.insert(element)

    query = input()
    result = bloom_filter.contains(query)
    print("Element might be in the set:", result)

if __name__ == "__main__":
    main()

