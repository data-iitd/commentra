import bitarray
from bitarray import bitarray

class BloomFilter:
    def __init__(self, number_of_hash_functions, bit_array_size):
        if number_of_hash_functions < 1 or bit_array_size < 1:
            raise ValueError("Number of hash functions and bit array size must be greater than 0")
        self.number_of_hash_functions = number_of_hash_functions
        self.bit_array = bitarray(bit_array_size)
        self.bit_array.setall(0)
        self.hash_functions = [Hash(i) for i in range(number_of_hash_functions)]

    def insert(self, key):
        for hash_function in self.hash_functions:
            position = abs(hash_function.compute(key) % len(self.bit_array))
            self.bit_array[position] = 1

    def contains(self, key):
        for hash_function in self.hash_functions:
            position = abs(hash_function.compute(key) % len(self.bit_array))
            if not self.bit_array[position]:
                return False
        return True

class Hash:
    def __init__(self, index):
        self.index = index

    def compute(self, key):
        return self.index * self.ascii_string(str(key))

    def ascii_string(self, word):
        return sum(ord(c) for c in word)

if __name__ == "__main__":
    number_of_hash_functions = int(input())
    bit_array_size = int(input())
    number_of_elements = int(input())

    bloom_filter = BloomFilter(number_of_hash_functions, bit_array_size)

    for _ in range(number_of_elements):
        element = input()
        bloom_filter.insert(element)

    query = input()
    result = bloom_filter.contains(query)

    print("Element might be in the set:", result)

# <END-OF-CODE>
