import hashlib
import bitarray

class Hash:
    def __init__(self, index):
        self.index = index

    def compute(self, key):
        return self.index * sum(ord(c) for c in str(key))

class Main:
    def __init__(self, numberOfHashFunctions, bitArraySize):
        if numberOfHashFunctions < 1 or bitArraySize < 1:
            raise ValueError("Number of hash functions and bit array size must be greater than 0")
        self.numberOfHashFunctions = numberOfHashFunctions
        self.bitArray = bitarray.bitarray(bitArraySize)
        self.bitArray.setall(0)
        self.hashFunctions = [Hash(i) for i in range(numberOfHashFunctions)]

    def insert(self, key):
        for hash_function in self.hashFunctions:
            position = abs(hash_function.compute(key) % len(self.bitArray))
            self.bitArray[position] = 1

    def contains(self, key):
        for hash_function in self.hashFunctions:
            position = abs(hash_function.compute(key) % len(self.bitArray))
            if not self.bitArray[position]:
                return False
        return True

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    numberOfHashFunctions = int(data[0])
    bitArraySize = int(data[1])
    numberOfElements = int(data[2])

    bloomFilter = Main(numberOfHashFunctions, bitArraySize)

    for i in range(3, 3 + numberOfElements):
        element = data[i]
        bloomFilter.insert(element)

    query = data[-1]
    result = bloomFilter.contains(query)

    print("Element might be in the set: " + str(result))
