

class Hash:
    def __init__(self, index):
        self.index = index

    def compute(self, key):
        return self.index * sum(ord(c) for c in str(key))

class BloomFilter:
    def __init__(self, number_of_hash_functions, bit_array_size):
        if number_of_hash_functions < 1 or bit_array_size < 1:
            raise ValueError("Number of hash functions and bit array size must be greater than 0")
        self.number_of_hash_functions = number_of_hash_functions
        self.bit_array = [False] * bit_array_size
        self.hash_functions = [Hash(i) for i in range(number_of_hash_functions)]

    def insert(self, key):
        for hash_function in self.hash_functions:
            position = abs(hash_function.compute(key) % len(self.bit_array))
            self.bit_array[position] = True

    def contains(self, key):
        for hash_function in self.hash_functions:
            position = abs(hash_function.compute(key) % len(self.bit_array))
            if not self.bit_array[position]:
                return False
        return True

if __name__ == "__main__":
    import sys
    number_of_hash_functions, bit_array_size, number_of_elements = map(int, sys.stdin.readline().split())
    bloom_filter = BloomFilter(number_of_hash_functions, bit_array_size)
    for _ in range(number_of_elements):
        element = sys.stdin.readline().strip()
        bloom_filter.insert(element)
    query = sys.stdin.readline().strip()
    result = bloom_filter.contains(query)
    print("Element might be in the set: {}".format(result))

