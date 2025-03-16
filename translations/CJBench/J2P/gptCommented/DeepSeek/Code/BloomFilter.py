import hashlib
import bitarray

class BloomFilter:
    def __init__(self, num_hash_functions, bit_array_size):
        if num_hash_functions < 1 or bit_array_size < 1:
            raise ValueError("Number of hash functions and bit array size must be greater than 0")
        self.num_hash_functions = num_hash_functions
        self.bit_array_size = bit_array_size
        self.bit_array = bitarray.bitarray(bit_array_size)
        self.bit_array.setall(0)
        self.hash_functions = [HashFunction(i) for i in range(num_hash_functions)]

    def insert(self, key):
        for hash_function in self.hash_functions:
            position = abs(hash_function.compute(key)) % self.bit_array_size
            self.bit_array[position] = 1

    def contains(self, key):
        for hash_function in self.hash_functions:
            position = abs(hash_function.compute(key)) % self.bit_array_size
            if not self.bit_array[position]:
                return False
        return True

    class HashFunction:
        def __init__(self, index):
            self.index = index

        def compute(self, key):
            return self.index * sum(ord(c) for c in str(key))

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    
    num_hash_functions = int(data[0])
    bit_array_size = int(data[1])
    num_elements = int(data[2])
    
    bloom_filter = BloomFilter(num_hash_functions, bit_array_size)
    
    for i in range(3, 3 + num_elements):
        bloom_filter.insert(data[i])
    
    query = data[-1]
    result = bloom_filter.contains(query)
    
    print("Element might be in the set:", result)
