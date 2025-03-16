
import java.util.Objects;
import java.util.Scanner;

class Main:
    def __init__(self, tableSize):
        self.tableSize = tableSize
        self.buckets = [None] * tableSize
        self.emptySlot = -1
        self.size = 0
        self.thresh = (int) (math.log(tableSize) / math.log(2)) + 2

    def hashFunction1(self, key):
        hash = key % self.tableSize
        return (hash < 0)? hash + self.tableSize : hash

    def hashFunction2(self, key):
        hash = key / self.tableSize
        hash %= self.tableSize
        return (hash < 0)? hash + self.tableSize : hash

    def insertKey2HashTable(self, key):
        wrappedInt = key
        temp = None
        hash = None
        loopCounter = 0

        if self.isFull():
            print("Hash table is full, rehashing...")
            self.reHashTableIncreasesTableSize()

        while loopCounter <= self.thresh:
            loopCounter += 1
            hash = self.hashFunction1(key)

            if self.buckets[hash] == None or Objects.equals(self.buckets[hash], self.emptySlot):
                self.buckets[hash] = wrappedInt
                self.size += 1
                return

            temp = self.buckets[hash]
            self.buckets[hash] = wrappedInt
            wrappedInt = temp

            hash = self.hashFunction2(temp)
            if self.buckets[hash] == None or Objects.equals(self.buckets[hash], self.emptySlot):
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
            if self.buckets[i]!= None and not Objects.equals(self.buckets[i], self.emptySlot):
                newT.insertKey2HashTable(self.buckets[i])
        self.buckets = newT.buckets
        self.tableSize = newT.tableSize
        self.thresh = (int) (math.log(self.tableSize) / math.log(2)) + 2

    def deleteKeyFromHashTable(self, key):
        hash = self.hashFunction1(key)
        if Objects.equals(self.buckets[hash], key):
            self.buckets[hash] = self.emptySlot
            self.size -= 1
            return

        hash = self.hashFunction2(key)
        if Objects.equals(self.buckets[hash], key):
            self.buckets[hash] = self.emptySlot
            self.size -= 1
            return

        print("Key " + key + " not found.")

    def displayHashtable(self):
        for i in range(self.tableSize):
            if self.buckets[i] == None or Objects.equals(self.buckets[i], self.emptySlot):
                print("Bucket " + i + ": Empty")
            else:
                print("Bucket " + i + ": " + self.buckets[i])

    def isFull(self):
        for bucket in self.buckets:
            if bucket == None or Objects.equals(bucket, self.emptySlot):
                return False
        return True

if __name__ == "__main__":
    scanner = Scanner(System.in)
    initialSize = scanner.nextInt()
    hashMap = Main(initialSize)

    operations = scanner.nextInt()
    scanner.nextLine()

    for i in range(operations):
        command = scanner.nextLine().split(" ")
        if command[0].toUpperCase() == "INSERT":
            hashMap.insertKey2HashTable(Integer.parseInt(command[1]))
        elif command[0].toUpperCase() == "DELETE":
            hashMap.deleteKeyFromHashTable(Integer.parseInt(command[1]))
        elif command[0].toUpperCase() == "DISPLAY":
            hashMap.displayHashtable()
        else:
            print("Invalid command")
    scanner.close()

