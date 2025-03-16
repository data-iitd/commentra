
import java.util.Objects;
import java.util.Scanner;

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
        self.thresh = (int) (math.log(tableSize) / math.log(2)) + 2
        print("Hash table created with size: " + str(tableSize))

    # Hash functions
    def hashFunction1(self, key):
        hash = key % self.tableSize
        return (hash < 0)? hash + self.tableSize : hash
        # Hash function 1

    def hashFunction2(self, key):
        hash = key / self.tableSize
        hash %= self.tableSize
        return (hash < 0)? hash + self.tableSize : hash
        # Hash function 2

    # Insert key into hash table
    def insertKey2HashTable(self, key):
        wrappedInt = key
        temp = 0
        hash = 0
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
                print("Key " + str(key) + " inserted at index " + str(hash))
                return
            temp = self.buckets[hash]
            self.buckets[hash] = wrappedInt
            wrappedInt = temp
            hash = self.hashFunction2(temp)
            if self.buckets[hash] == None or Objects.equals(self.buckets[hash], self.emptySlot):
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
            if self.buckets[i]!= None and not Objects.equals(self.buckets[i], self.emptySlot):
                newT.insertKey2HashTable(self.buckets[i])
        self.buckets = newT.buckets
        self.tableSize = newT.tableSize
        self.thresh = (int) (math.log(self.tableSize) / math.log(2)) + 2
        print("Hash table rehashed with size: " + str(self.tableSize))

    # Delete key from hash table
    def deleteKeyFromHashTable(self, key):
        hash = self.hashFunction1(key)
        if Objects.equals(self.buckets[hash], key):
            self.buckets[hash] = self.emptySlot
            self.size -= 1
            print("Key " + str(key) + " deleted from index " + str(hash))
            return
        hash = self.hashFunction2(key)
        if Objects.equals(self.buckets[hash], key):
            self.buckets[hash] = self.emptySlot
            self.size -= 1
            print("Key " + str(key) + " deleted from index " + str(hash))
            return
        print("Key " + str(key) + " not found.")

    # Display hash table
    def displayHashtable(self):
        for i in range(self.tableSize):
            if self.buckets[i] == None or Objects.equals(self.buckets[i], self.emptySlot):
                print("Bucket " + str(i) + ": Empty")
            else:
                print("Bucket " + str(i) + ": " + str(self.buckets[i]))

    # Check if hash table is full
    def isFull(self):
        for bucket in self.buckets:
            if bucket == None or Objects.equals(bucket, self.emptySlot):
                return False
        return True

    # Main method
    @staticmethod
    def main(args):
        scanner = Scanner(System.in)
        initialSize = scanner.nextInt()
        hashMap = Main(initialSize)
        operations = scanner.nextInt()
        scanner.nextLine()
        for i in range(operations):
            command = scanner.nextLine().split(" ")
            switch (command[0].toUpperCase()):
                case "INSERT":
                    hashMap.insertKey2HashTable(Integer.parseInt(command[1]))
                    break
                case "DELETE":
                    hashMap.deleteKeyFromHashTable(Integer.parseInt(command[1]))
                    break
                case "DISPLAY":
                    hashMap.displayHashtable()
                    break
                default:
                    print("Invalid command")
        scanner.close()

