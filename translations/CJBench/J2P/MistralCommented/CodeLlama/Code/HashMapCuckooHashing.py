
import math

class Main:
    # Class variables
    tableSize = 0
    buckets = []
    emptySlot = -1
    size = 0
    thresh = 0

    # Constructor
    def __init__(self, tableSize):
        self.tableSize = tableSize
        self.buckets = [None] * tableSize
        self.emptySlot = -1
        self.size = 0
        self.thresh = int(math.log(tableSize) / math.log(2)) + 2
        print("Hash table created with size: " + str(tableSize))

    # Hash functions
    def hashFunction1(self, key):
        hash = key % self.tableSize
        return hash if hash >= 0 else hash + self.tableSize
        # Hash function 1

    def hashFunction2(self, key):
        hash = key // self.tableSize
        hash %= self.tableSize
        return hash if hash >= 0 else hash + self.tableSize
        # Hash function 2

    # Insert key into hash table
    def insertKey2HashTable(self, key):
        wrappedInt = key
        temp = None
        hash = 0
        loopCounter = 0

        if self.isFull():
            print("Hash table is full, rehashing...")
            self.reHashTableIncreasesTableSize()

        while loopCounter <= self.thresh:
            loopCounter += 1
            hash = self.hashFunction1(key)
            if self.buckets[hash] == None or self.buckets[hash] == self.emptySlot:
                self.buckets[hash] = wrappedInt
                self.size += 1
                print("Key " + str(key) + " inserted at index " + str(hash))
                return
            temp = self.buckets[hash]
            self.buckets[hash] = wrappedInt
            wrappedInt = temp
            hash = self.hashFunction2(temp)
            if self.buckets[hash] == None or self.buckets[hash] == self.emptySlot:
                self.buckets[hash] = wrappedInt
                self.size += 1
                print("Key " + str(key) + " rehashed and inserted at index " + str(hash))
                return
            temp = self.buckets[hash]
            self.buckets[hash] = wrappedInt
            wrappedInt = temp

        print("Infinite loop detected, rehashing...")
        self.reHashTableIncreasesTableSize()
        self.insertKey2HashTable(key)

    # Rehash table by increasing table size
    def reHashTableIncreasesTableSize(self):
        newT = Main(self.tableSize * 2)
        for i in range(self.tableSize):
            if self.buckets[i] != None and self.buckets[i] != self.emptySlot:
                newT.insertKey2HashTable(self.buckets[i])
        self.buckets = newT.buckets
        self.tableSize = newT.tableSize
        self.thresh = int(math.log(self.tableSize) / math.log(2)) + 2
        print("Hash table rehashed with size: " + str(self.tableSize))

    # Delete key from hash table
    def deleteKeyFromHashTable(self, key):
        hash = self.hashFunction1(key)
        if self.buckets[hash] == key:
            self.buckets[hash] = self.emptySlot
            self.size -= 1
            print("Key " + str(key) + " deleted from index " + str(hash))
            return
        hash = self.hashFunction2(key)
        if self.buckets[hash] == key:
            self.buckets[hash] = self.emptySlot
            self.size -= 1
            print("Key " + str(key) + " deleted from index " + str(hash))
            return
        print("Key " + str(key) + " not found.")

    # Display hash table
    def displayHashtable(self):
        for i in range(self.tableSize):
            if self.buckets[i] == None or self.buckets[i] == self.emptySlot:
                print("Bucket " + str(i) + ": Empty")
            else:
                print("Bucket " + str(i) + ": " + str(self.buckets[i]))

    # Check if hash table is full
    def isFull(self):
        for bucket in self.buckets:
            if bucket == None or bucket == self.emptySlot:
                return False
        return True

    # Main method
    def main(self):
        initialSize = int(input())
        hashMap = Main(initialSize)
        operations = int(input())
        for i in range(operations):
            command = input().split(" ")
            if command[0].upper() == "INSERT":
                hashMap.insertKey2HashTable(int(command[1]))
            elif command[0].upper() == "DELETE":
                hashMap.deleteKeyFromHashTable(int(command[1]))
            elif command[0].upper() == "DISPLAY":
                hashMap.displayHashtable()
            else:
                print("Invalid command")

if __name__ == "__main__":
    hashMap = Main(11)
    hashMap.main()
    # 