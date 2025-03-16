
class Main:
    def __init__(self, numberOfHashFunctions, bitArraySize):
        if numberOfHashFunctions < 1 or bitArraySize < 1:
            raise Exception("Number of hash functions and bit array size must be greater than 0")
        self.numberOfHashFunctions = numberOfHashFunctions
        self.bitArray = [0] * bitArraySize
        self.hashFunctions = []
        for i in range(numberOfHashFunctions):
            self.hashFunctions.append(Hash(i))

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
        return self.index * asciiString(str(key))


def asciiString(word):
    sum = 0
    for c in word:
        sum += ord(c)
    return sum


if __name__ == "__main__":
    scanner = Scanner(System.in)
    numberOfHashFunctions = scanner.nextInt()
    bitArraySize = scanner.nextInt()
    numberOfElements = scanner.nextInt()
    bloomFilter = Main(numberOfHashFunctions, bitArraySize)
    for i in range(numberOfElements):
        element = scanner.next()
        bloomFilter.insert(element)
    query = scanner.next()
    result = bloomFilter.contains(query)
    print("Element might be in the set: " + str(result))

