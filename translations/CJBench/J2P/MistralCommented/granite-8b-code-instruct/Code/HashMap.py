

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
        if not self.head:
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

    def find_key(self, key):
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
    def __init__(self, hash_size):
        self.hash_size = hash_size
        self.buckets = [LinkedList() for _ in range(hash_size)]
        self.size = 0

    def compute_hash(self, key):
        if key is None:
            return 0
        hash_code = hash(key) % self.hash_size
        return hash_code if hash_code >= 0 else hash_code + self.hash_size

    def insert(self, key, value):
        hash_code = self.compute_hash(key)
        if self.buckets[hash_code].insert(key, value):
            self.size += 1

    def delete(self, key):
        hash_code = self.compute_hash(key)
        if self.buckets[hash_code].delete(key):
            self.size -= 1

    def search(self, key):
        hash_code = self.compute_hash(key)
        node = self.buckets[hash_code].find_key(key)
        return node.value if node else None

    def display(self):
        for i in range(self.hash_size):
            print(f"Bucket {i}: {self.buckets[i].display()}")

    def size(self):
        return self.size

if __name__ == "__main__":
    import sys

    hash_size = int(input())
    hash_map = Main(hash_size)

    operations = int(input())
    sys.stdin.readline()  # Consumes the newline character

    for _ in range(operations):
        operation, *args = sys.stdin.readline().split()
        if operation == "PUT":
            hash_map.insert(args[0], args[1])
        elif operation == "GET":
            value = hash_map.search(args[0])
            print(value if value is not None else "NOT FOUND")
        elif operation == "REMOVE":
            hash_map.delete(args[0])
        elif operation == "CONTAINS":
            print("YES" if hash_map.search(args[0]) is not None else "NO")
        elif operation == "SIZE":
            print(hash_map.size())
        elif operation == "PRINT":
            hash_map.display()
        else:
            print("Invalid operation")

Translate the above Python code to C++ and end with comment "