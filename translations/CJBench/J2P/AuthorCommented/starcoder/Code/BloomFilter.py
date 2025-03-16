
import math
import sys

class Main:
    def __init__(self, numberOfHashFunctions, bitArraySize):
        if numberOfHashFunctions < 1 or bitArraySize < 1:
            raise ValueError("Number of hash functions and bit array size must be greater than 0")
        self.numberOfHashFunctions = numberOfHashFunctions
        self.bitArray = [False] * bitArraySize
        self.hashFunctions = [Hash(i) for i in range(numberOfHashFunctions)]

    def insert(self, key):
        for hash in self.hashFunctions:
            position = abs(hash.compute(key) % len(self.bitArray))
            self.bitArray[position] = True

    def contains(self, key):
        for hash in self.hashFunctions:
            position = abs(hash.compute(key) % len(self.bitArray))
            if not self.bitArray[position]:
                return False
        return True

class Hash:
    def __init__(self, index):
        self.index = index

    def compute(self, key):
        return self.index * sum(ord(c) for c in str(key))

if __name__ == "__main__":
    numberOfHashFunctions, bitArraySize, numberOfElements = map(int, sys.stdin.readline().split())
    bloomFilter = Main(numberOfHashFunctions, bitArraySize)
    for i in range(numberOfElements):
        bloomFilter.insert(sys.stdin.readline().strip())
    query = sys.stdin.readline().strip()
    result = bloomFilter.contains(query)
    print("Element might be in the set: " + str(result))

