
import math
import sys

# The number of hash functions used in the Bloom filter
numberOfHashFunctions = 0

# The bit array used to store the hash values
bitArray = None

# An array of hash functions
hashFunctions = []

# The size of the bit array
bitArraySize = 0

# The number of elements to be inserted into the Bloom filter
numberOfElements = 0

# The query to be checked
query = None

# The result of the query
result = False


# A class representing a hash function
class Hash:
    # The index of the hash function
    index = 0

    # Constructor for the Hash class
    def __init__(self, index):
        self.index = index

    # Computes the hash value for a given key
    def compute(self, key):
        # Hash the key using a simple hash function (ASCII value of the key's string representation)
        return self.index * asciiString(str(key))


# Computes the ASCII value of a given string
def asciiString(word):
    sum = 0
    for c in word:
        sum += ord(c)
    return sum


# Main method for running the Bloom filter example
def main():
    # Read the number of hash functions, bit array size, and number of elements to be inserted from the console
    global numberOfHashFunctions, bitArraySize, numberOfElements

    numberOfHashFunctions = int(sys.stdin.readline())
    bitArraySize = int(sys.stdin.readline())
    numberOfElements = int(sys.stdin.readline())

    # Create a new Bloom filter with the given parameters
    global bitArray, hashFunctions
    bitArray = [False] * bitArraySize
    hashFunctions = [Hash(i) for i in range(numberOfHashFunctions)]

    # Insert elements into the Bloom filter
    for i in range(numberOfElements):
        element = sys.stdin.readline()
        insert(element)

    # Read a query from the console and check if it might be in the set
    global query
    query = sys.stdin.readline()
    result = contains(query)
    print("Element might be in the set: " + str(result))


# Inserts a key into the Bloom filter
def insert(key):
    for hash in hashFunctions:
        # Compute the position in the bit array where the hash value should be set
        position = abs(hash.compute(key) % bitArraySize)

        # Set the bit at the computed position
        bitArray[position] = True


# Checks if a key is in the Bloom filter
def contains(key):
    for hash in hashFunctions:
        # Compute the position in the bit array where the hash value should be checked
        position = abs(hash.compute(key) % bitArraySize)

        # If the bit at the computed position is not set, the key is not in the set
        if not bitArray[position]:
            return False

    # If all bits are set, the key might be in the set
    return True


# Run the main method
if __name__ == "__main__":
    main()

