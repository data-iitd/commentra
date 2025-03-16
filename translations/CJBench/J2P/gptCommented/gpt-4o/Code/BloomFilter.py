class BloomFilter:
    def __init__(self, number_of_hash_functions, bit_array_size):
        if number_of_hash_functions < 1 or bit_array_size < 1:
            raise ValueError("Number of hash functions and bit array size must be greater than 0")
        self.number_of_hash_functions = number_of_hash_functions
        self.bit_array = [0] * bit_array_size
        self.hash_functions = self.initialize_hash_functions()

    def initialize_hash_functions(self):
        return [Hash(i) for i in range(self.number_of_hash_functions)]

    def insert(self, key):
        for hash_function in self.hash_functions:
            position = abs(hash_function.compute(key) % len(self.bit_array))
            self.bit_array[position] = 1

    def contains(self, key):
        for hash_function in self.hash_functions:
            position = abs(hash_function.compute(key) % len(self.bit_array))
            if self.bit_array[position] == 0:
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
    import sys

    # Read the number of hash functions, bit array size, and number of elements to insert
    number_of_hash_functions = int(sys.stdin.readline().strip())
    bit_array_size = int(sys.stdin.readline().strip())
    number_of_elements = int(sys.stdin.readline().strip())

    # Create a new Bloom filter instance
    bloom_filter = BloomFilter(number_of_hash_functions, bit_array_size)

    # Insert elements into the Bloom filter
    for _ in range(number_of_elements):
        element = sys.stdin.readline().strip()
        bloom_filter.insert(element)

    # Read a query element to check its presence in the Bloom filter
    query = sys.stdin.readline().strip()
    result = bloom_filter.contains(query)

    # Output the result of the query
    print("Element might be in the set:", result)

# <END-OF-CODE>
