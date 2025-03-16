
class Main:
    def __init__(self, tableSize):
        self.tableSize = tableSize
        self.buckets = [None] * tableSize
        self.emptySlot = -2147483648
        self.size = 0
        self.thresh = (int)(math.log(tableSize) / math.log(2)) + 2

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
        loopCounter = 0

        if self.isFull():
            print("Hash table is full, rehashing...")
            self.reHashTableIncreasesTableSize()

        while loopCounter <= self.thresh:
            loopCounter += 1
            if self.buckets[hash] == None or self.buckets[hash] == self.emptySlot:
                self.buckets[hash] = wrappedInt
                self.size += 1
                return

            temp = self.buckets[hash]
            self.buckets[hash] = wrappedInt
            wrappedInt = temp

            hash = self.hashFunction2(temp)
            if self.buckets[hash] == None or self.buckets[hash] == self.emptySlot:
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
            if self.buckets[i] != None and self.buckets[i] != self.emptySlot:
                newT.insertKey2HashTable(self.buckets[i])
        self.buckets = newT.buckets
        self.tableSize = newT.tableSize
        self.thresh = (int)(math.log(self.tableSize) / math.log(2)) + 2

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

        print("Key " + str(key) + " not found.")

    def displayHashtable(self):
        for i in range(self.tableSize):
            if self.buckets[i] == None or self.buckets[i] == self.emptySlot:
                print("Bucket " + str(i) + ": Empty")
            else:
                print("Bucket " + str(i) + ": " + str(self.buckets[i]))

    def isFull(self):
        for bucket in self.buckets:
            if bucket == None or bucket == self.emptySlot:
                return False
        return True


if __name__ == "__main__":
    scanner = input()
    initialSize = int(scanner)
    hashMap = Main(initialSize)

    scanner = input()
    operations = int(scanner)

    for i in range(operations):
        scanner = input()
        command = scanner.split(" ")
        if command[0].upper() == "INSERT":
            hashMap.insertKey2HashTable(int(command[1]))
        elif command[0].upper() == "DELETE":
            hashMap.deleteKeyFromHashTable(int(command[1]))
        elif command[0].upper() == "DISPLAY":
            hashMap.displayHashtable()
        else:
            print("Invalid command")

    print("