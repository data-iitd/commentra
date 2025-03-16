
class Main:
    def __init__(self, numberOfHashFunctions, bitArraySize):
        if numberOfHashFunctions < 1 or bitArraySize < 1:
            raise Exception("Number of hash functions and bit array size must be greater than 0")
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
        return self.index * asciiString(str(key))

def asciiString(word):
    sum = 0
    for c in word:
        sum += ord(c)
    return sum

if __name__ == "__main__":
    import sys
    scanner = sys.stdin
    numberOfHashFunctions = int(scanner.readline())
    bitArraySize = int(scanner.readline())
    numberOfElements = int(scanner.readline())
    bloomFilter = Main(numberOfHashFunctions, bitArraySize)
    for i in range(numberOfElements):
        element = scanner.readline()
        bloomFilter.insert(element)
    query = scanner.readline()
    result = bloomFilter.contains(query)
    print("Element might be in the set: " + str(result))

