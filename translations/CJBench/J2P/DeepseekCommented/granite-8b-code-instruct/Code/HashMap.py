
class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, key, value):
        current = self.head
        while current and current.key!= key:
            current = current.next
        if current:
            current.value = value
        else:
            node = Node(key, value)
            node.next = self.head
            self.head = node

    def delete(self, key):
        if self.head is None:
            return False
        if self.head.key == key:
            self.head = self.head.next
            return True
        current = self.head
        while current.next and current.next.key!= key:
            current = current.next
        if current.next:
            current.next = current.next.next
            return True
        return False

    def findKey(self, key):
        current = self.head
        while current and current.key!= key:
            current = current.next
        return current

    def display(self):
        result = []
        current = self.head
        while current:
            result.append(str(current.key) + "=" + str(current.value))
            current = current.next
        return " -> ".join(result) if result else "null"

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
        return node.value if node else None

    def display(self):
        for i in range(self.hashSize):
            print("Bucket", i, ":", self.buckets[i].display())

    def size(self):
        return self.size

if __name__ == "__main__":
    import sys
    hashSize = int(input())
    hashMap = Main(hashSize)
    operations = int(input())
    sys.stdin.readline()
    for _ in range(operations):
        input = sys.stdin.readline().split()
        if input[0] == "PUT":
            hashMap.insert(input[1], input[2])
        elif input[0] == "GET":
            value = hashMap.search(input[1])
            print(value if value else "NOT FOUND")
        elif input[0] == "REMOVE":
            hashMap.delete(input[1])
        elif input[0] == "CONTAINS":
            print("YES" if hashMap.search(input[1]) else "NO")
        elif input[0] == "SIZE":
            print(hashMap.size())
        elif input[0] == "PRINT":
            hashMap.display()
        else:
            print("Invalid operation")

