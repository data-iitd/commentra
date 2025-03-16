
import sys

class Main:
    def __init__(self, numberOfHashFunctions, bitArraySize):
        if numberOfHashFunctions < 1 or bitArraySize < 1:
            raise ValueError("Number of hash functions and bit array size must be greater than 0")
        self.numberOfHashFunctions = numberOfHashFunctions
        self.bitArray = [0] * bitArraySize
        self.hashFunctions = [Hash(i) for i in range(numberOfHashFunctions)]

    def insert(self, key):
        for hash in self.hashFunctions:
            position = abs(hash.compute(key) % len(self.bitArray))
            self.bitArray[position] = 1

    def contains(self, key):
        for hash in self.hashFunctions:
            position = abs(hash.compute(key) % len(self.bitArray))
            if self.bitArray[position] == 0:
                return False
        return True

class Hash:
    def __init__(self, index):
        self.index = index

    def compute(self, key):
        return self.index * sum(ord(c) for c in str(key))

if __name__ == "__main__":
    numberOfHashFunctions = int(sys.stdin.readline())
    bitArraySize = int(sys.stdin.readline())
    numberOfElements = int(sys.stdin.readline())

    bloomFilter = Main(numberOfHashFunctions, bitArraySize)

    for i in range(numberOfElements):
        element = sys.stdin.readline().strip()
        bloomFilter.insert(element)

    query = sys.stdin.readline().strip()
    result = bloomFilter.contains(query)

    print("Element might be in the set:", result)

