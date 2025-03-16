

class Main:
    def __init__(self, tableSize):
        self.buckets = [None] * tableSize
        self.tableSize = tableSize
        self.emptySlot = None
        self.size = 0
        self.thresh = int(math.log(tableSize) / math.log(2)) + 2

    def hashFunction1(self, key):
        hash = key % self.tableSize
        return hash if hash >= 0 else hash + self.tableSize

    def hashFunction2(self, key):
        hash = key // self.tableSize
        hash %= self.tableSize
        return hash if hash >= 0 else hash + self.tableSize

    def insertKey2HashTable(self, key):
        wrappedInt = key
        temp = None
        hash = self.hashFunction1(key)
        if self.isFull():
            print("Hash table is full, rehashing...")
            self.reHashTableIncreasesTableSize()
        while self.loopCounter <= self.thresh:
            self.loopCounter += 1
            if self.buckets[hash] is None or self.buckets[hash] == self.emptySlot:
                self.buckets[hash] = wrappedInt
                self.size += 1
                return
            temp = self.buckets[hash]
            self.buckets[hash] = wrappedInt
            wrappedInt = temp
            hash = self.hashFunction2(temp)
            if self.buckets[hash] is None or self.buckets[hash] == self.emptySlot:
                self.buckets[hash] = wrappedInt
                self.size += 1
                return
            temp = self.buckets[hash]
            self.buckets[hash] = wrappedInt
            wrappedInt = temp
        print("Infinite loop detected, rehashing...")
        self.reHashTableIncreasesTableSize()
        self.insertKey2HashTable(key)

    def reHashTableIncreasesTableSize(self):
        newT = Main(self.tableSize * 2)
        for i in range(self.tableSize):
            if self.buckets[i] is not None and self.buckets[i]!= self.emptySlot:
                newT.insertKey2HashTable(self.buckets[i])
        self.buckets = newT.buckets
        self.tableSize = newT.tableSize
        self.thresh = int(math.log(self.tableSize) / math.log(2)) + 2

    def deleteKeyFromHashTable(self, key):
        hash = self.hashFunction1(key)
        if self.buckets[hash] == key:
            self.buckets[hash] = self.emptySlot
            self.size -= 1
            return
        hash = self.hashFunction2(key)
        if self.buckets[hash] == key:
            self.buckets[hash] = self.emptySlot
            self.size -= 1
            return
        print("Key", key, "not found.")

    def displayHashtable(self):
        for i in range(self.tableSize):
            if self.buckets[i] is None or self.buckets[i] == self.emptySlot:
                print("Bucket", i, ": Empty")
            else:
                print("Bucket", i, ":", self.buckets[i])

    def isFull(self):
        for bucket in self.buckets:
            if bucket is None or bucket == self.emptySlot:
                return False
        return True

if __name__ == "__main__":
    import math
    import sys
    initialSize = int(input())
    hashMap = Main(initialSize)
    operations = int(input())
    sys.stdin.readline()
    for i in range(operations):
        command = sys.stdin.readline().split()
        if command[0].upper() == "INSERT":
            hashMap.insertKey2HashTable(int(command[1]))
        elif command[0].upper() == "DELETE":
            hashMap.deleteKeyFromHashTable(int(command[1]))
        elif command[0].upper() == "DISPLAY":
            hashMap.displayHashtable()
        else:
            print("Invalid command")
