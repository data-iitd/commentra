
import math

class Main:
    # Number of hash functions to be used in the Bloom filter
    numberOfHashFunctions = 0
    # Bit array to represent the Bloom filter
    bitArray = []
    # Array to hold the hash functions
    hashFunctions = []

    # Constructor to initialize the Bloom filter with the specified number of hash functions and bit array size
    def __init__(self, numberOfHashFunctions, bitArraySize):
        # Validate input parameters to ensure they are greater than 0
        if numberOfHashFunctions < 1 or bitArraySize < 1:
            raise ValueError("Number of hash functions and bit array size must be greater than 0")
        self.numberOfHashFunctions = numberOfHashFunctions
        self.bitArray = [False] * bitArraySize
        self.hashFunctions = [Hash(i) for i in range(numberOfHashFunctions)]

    # Method to insert a key into the Bloom filter
    def insert(self, key):
        # For each hash function, compute the position and set the corresponding bit in the bit array
        for hash in self.hashFunctions:
            position = abs(hash.compute(key) % len(self.bitArray))
            self.bitArray[position] = True

    # Method to check if a key might be in the Bloom filter
    def contains(self, key):
        # For each hash function, check if the corresponding bit is set in the bit array
        for hash in self.hashFunctions:
            position = abs(hash.compute(key) % len(self.bitArray))
            if not self.bitArray[position]:
                return False # If any bit is not set, the key is definitely not in the set
        return True # If all bits are set, the key might be in the set

    # Inner class to represent a hash function
    class Hash:
        # Index of the hash function
        index = 0

        # Constructor to initialize the hash function with its index
        def __init__(self, index):
            self.index = index

        # Method to compute the hash value for a given key
        def compute(self, key):
            return self.index * asciiString(str(key))

        # Method to compute the ASCII sum of the characters in a string
        def asciiString(word):
            return sum(ord(c) for c in word)

# Main method to run the Bloom filter program
if __name__ == "__main__":
    import sys

    numberOfHashFunctions, bitArraySize, numberOfElements = map(int, sys.stdin.readline().split())

    # Create a new Bloom filter instance
    bloomFilter = Main(numberOfHashFunctions, bitArraySize)

    # Insert elements into the Bloom filter
    for _ in range(numberOfElements):
        element = sys.stdin.readline().strip()
        bloomFilter.insert(element)

    # Read a query element to check its presence in the Bloom filter
    query = sys.stdin.readline().strip()
    result = bloomFilter.contains(query)

    # Output the result of the query
    print("Element might be in the set: " + str(result))

