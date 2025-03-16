import hashlib
import bitarray

class BloomFilter:
    def __init__(self, numberOfHashFunctions, bitArraySize):
        if numberOfHashFunctions < 1 or bitArraySize < 1:
            raise ValueError("Number of hash functions and bit array size must be greater than 0")

        self.numberOfHashFunctions = numberOfHashFunctions
        self.bitArray = bitarray.bitarray(bitArraySize)
        self.bitArray.setall(0)
        self.hashFunctions = [Hash(i) for i in range(numberOfHashFunctions)]

    def insert(self, key):
        for hash_function in self.hashFunctions:
            position = abs(hash_function.compute(key)) % len(self.bitArray)
            self.bitArray[position] = 1

    def contains(self, key):
        for hash_function in self.hashFunctions:
            position = abs(hash_function.compute(key)) % len(self.bitArray)
            if not self.bitArray[position]:
                return False
        return True

class Hash:
    def __init__(self, index):
        self.index = index

    def compute(self, key):
        # Hash the key using a simple hash function (ASCII value of the key's string representation)
        return self.index * sum(ord(c) for c in str(key))

if __name__ == "__main__":
    # Read the number of hash functions, bit array size, and number of elements to be inserted from the console
    numberOfHashFunctions = int(input())
    bitArraySize = int(input())
    numberOfElements = int(input())

    # Create a new Bloom filter with the given parameters
    bloomFilter = BloomFilter(numberOfHashFunctions, bitArraySize)

    # Insert elements into the Bloom filter
    for _ in range(numberOfElements):
        element = input()
        bloomFilter.insert(element)

    # Read a query from the console and check if it might be in the set
    query = input()
    result = bloomFilter.contains(query)
    print("Element might be in the set:", result)
