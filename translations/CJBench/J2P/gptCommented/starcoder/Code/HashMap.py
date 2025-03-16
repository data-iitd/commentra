import sys

class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, key, value):
        node = Node(key, value)
        if self.head is None:
            self.head = node
            return True
        current = self.head
        while current.next is not None:
            current = current.next
        current.next = node
        return True

    def delete(self, key):
        if self.head is None:
            return False
        if self.head.key == key:
            self.head = self.head.next
            return True
        current = self.head
        while current.next is not None:
            if current.next.key == key:
                current.next = current.next.next
                return True
            current = current.next
        return False

    def findKey(self, key):
        if self.head is None:
            return None
        if self.head.key == key:
            return self.head
        current = self.head
        while current.next is not None:
            if current.next.key == key:
                return current.next
            current = current.next
        return None

    def display(self):
        if self.head is None:
            return "null"
        current = self.head
        sb = []
        while current is not None:
            sb.append(str(current.key) + "=" + str(current.value))
            current = current.next
        return " -> ".join(sb)

class Main:
    def __init__(self, hashSize):
        self.hashSize = hashSize
        self.buckets = [LinkedList() for _ in range(hashSize)]
        self.size = 0

    def computeHash(self, key):
        if key is None:
            return 0
        hash = key.hashCode() % self.hashSize
        return hash if hash >= 0 else hash + self.hashSize

    def insert(self, key, value):
        hash = self.computeHash(key)
        if self.buckets[hash].insert(key, value):
            self.size += 1
            return True
        return False

    def delete(self, key):
        hash = self.computeHash(key)
        if self.buckets[hash].delete(key):
            self.size -= 1
            return True
        return False

    def search(self, key):
        hash = self.computeHash(key)
        node = self.buckets[hash].findKey(key)
        return node.value if node is not None else None

    def display(self):
        for i in range(self.hashSize):
            print("Bucket", i, ":", self.buckets[i].display())

    def size(self):
        return self.size

if __name__ == "__main__":
    hashSize = int(sys.stdin.readline().strip())
    hashMap = Main(hashSize)
    operations = int(sys.stdin.readline().strip())
    for i in range(operations):
        input = sys.stdin.readline().strip().split(" ")
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

