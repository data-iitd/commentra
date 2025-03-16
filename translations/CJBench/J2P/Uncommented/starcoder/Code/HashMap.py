
class Main:
    def __init__(self, hashSize):
        self.hashSize = hashSize
        self.buckets = [LinkedList() for _ in range(hashSize)]
        self.size = 0

    def computeHash(self, key):
        if key == None:
            return 0
        hash = key.hashCode() % self.hashSize
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
        return node.value if node!= None else None

    def display(self):
        for i in range(self.hashSize):
            print("Bucket %d: %s" % (i, self.buckets[i].display()))

    def size(self):
        return self.size

class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, key, value):
        existingNode = self.findKey(key)
        if existingNode!= None:
            existingNode.value = value
            return False
        newNode = Node(key, value)
        newNode.next = self.head
        self.head = newNode
        return True

    def delete(self, key):
        if self.head == None:
            return False
        if (key == None and self.head.key == None) or (self.head.key!= None and self.head.key == key):
            self.head = self.head.next
            return True
        current = self.head
        while current.next!= None:
            if (key == None and current.next.key == None) or (current.next.key!= None and current.next.key == key):
                current.next = current.next.next
                return True
            current = current.next
        return False

    def findKey(self, key):
        current = self.head
        while current!= None:
            if (key == None and current.key == None) or (current.key!= None and current.key == key):
                return current
            current = current.next
        return None

    def display(self):
        sb = []
        current = self.head
        while current!= None:
            sb.append(str(current.key) + "=" + str(current.value))
            current = current.next
            if current!= None:
                sb.append(" -> ")
        return "" if len(sb) == 0 else "".join(sb)

class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

if __name__ == "__main__":
    import sys
    scanner = sys.stdin
    hashSize = int(scanner.readline())
    hashMap = Main(hashSize)
    operations = int(scanner.readline())
    for i in range(operations):
        input = scanner.readline().split(" ")
        if input[0] == "PUT":
            hashMap.insert(input[1], input[2])
        elif input[0] == "GET":
            value = hashMap.search(input[1])
            print(value if value!= None else "NOT FOUND")
        elif input[0] == "REMOVE":
            hashMap.delete(input[1])
        elif input[0] == "CONTAINS":
            print("YES" if hashMap.search(input[1])!= None else "NO")
        elif input[0] == "SIZE":
            print(hashMap.size())
        elif input[0] == "PRINT":
            hashMap.display()
        else:
            print("Invalid operation")
    scanner.close()

