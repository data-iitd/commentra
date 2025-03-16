
class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, key, value):
        if self.head is None:
            self.head = Node(key, value)
            return True
        else:
            current = self.head
            while current.next is not None:
                current = current.next
            current.next = Node(key, value)
            return True

    def delete(self, key):
        if self.head is None:
            return False
        if self.head.key == key:
            self.head = self.head.next
            return True
        else:
            current = self.head
            while current.next is not None:
                if current.next.key == key:
                    current.next = current.next.next
                    return True
                current = current.next
            return False

    def findKey(self, key):
        current = self.head
        while current is not None:
            if current.key == key:
                return current
            current = current.next
        return None

    def display(self):
        current = self.head
        result = ""
        while current is not None:
            result += str(current.key) + "=" + str(current.value) + " -> "
            current = current.next
        return result[:-4]

class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

class Main:
    def __init__(self, hashSize):
        self.hashSize = hashSize
        self.buckets = [LinkedList() for _ in range(hashSize)]
        self.size = 0

    def computeHash(self, key):
        if key is None:
            return 0
        hash = hash(key) % self.hashSize
        return hash if hash >= 0 else hash + self.hashSize

    def insert(self, key, value):
        hash = self.computeHash(key)
        if self.buckets[hash].insert(key, value):
            self.size += 1

    def delete(self, key):
        hash = self.computeHash(key)
        if self.buckets[hash].delete(key):
            self.size -= 1

    def search(self, key):
        hash = self.computeHash(key)
        node = self.buckets[hash].findKey(key)
        return node.value if node is not None else None

    def display(self):
        for i in range(self.hashSize):
            print("Bucket " + str(i) + ": " + self.buckets[i].display())

    def size(self):
        return self.size

if __name__ == "__main__":
    hashSize = int(input())
    hashMap = Main(hashSize)
    operations = int(input())
    for i in range(operations):
        input = input().split()
        if input[0] == "PUT":
            hashMap.insert(input[1], input[2])
        elif input[0] == "GET":
            value = hashMap.search(input[1])
            print(value if value is not None else "NOT FOUND")
        elif input[0] == "REMOVE":
            hashMap.delete(input[1])
        elif input[0] == "CONTAINS":
            print("YES" if hashMap.search(input[1]) is not None else "NO")
        elif input[0] == "SIZE":
            print(hashMap.size())
        elif input[0] == "PRINT":
            hashMap.display()
        else:
            print("Invalid operation")

