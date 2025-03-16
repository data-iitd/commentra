

import math

class Main:
    def __init__(self, numberOfHashFunctions, bitArraySize):
        if numberOfHashFunctions < 1 or bitArraySize < 1:
            raise ValueError("Number of hash functions and bit array size must be greater than 0")
        self.numberOfHashFunctions = numberOfHashFunctions
        self.bitArraySize = bitArraySize
        self.bitArray = [False] * bitArraySize
        self.hashFunctions = [Hash(i) for i in range(numberOfHashFunctions)]

    def insert(self, key):
        for hash in self.hashFunctions:
            position = abs(hash.compute(key) % self.bitArraySize)
            self.bitArray[position] = True

    def contains(self, key):
        for hash in self.hashFunctions:
            position = abs(hash.compute(key) % self.bitArraySize)
            if not self.bitArray[position]:
                return False
        return True

class Hash:
    def __init__(self, index):
        self.index = index

    def compute(self, key):
        return self.index * sum(ord(c) for c in str(key))

if __name__ == "__main__":
    numberOfHashFunctions, bitArraySize, numberOfElements = map(int, input().split())
    bloomFilter = Main(numberOfHashFunctions, bitArraySize)
    for _ in range(numberOfElements):
        element = input()
        bloomFilter.insert(element)
    query = input()
    result = bloomFilter.contains(query)
    print(f"Element might be in the set: {result}")

