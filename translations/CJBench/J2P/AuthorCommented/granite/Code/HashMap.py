

class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, key, value):
        node = self.find_key(key)
        if node is not None:
            node.value = value
            return False
        new_node = Node(key, value)
        new_node.next = self.head
        self.head = new_node
        return True

    def delete(self, key):
        if self.head is None:
            return False
        if (key is None and self.head.key is None) or (self.head.key is not None and self.head.key == key):
            self.head = self.head.next
            return True
        current = self.head
        while current.next is not None:
            if (key is None and current.next.key is None) or (current.next.key is not None and current.next.key == key):
                current.next = current.next.next
                return True
            current = current.next
        return False

    def find_key(self, key):
        current = self.head
        while current is not None:
            if (key is None and current.key is None) or (current.key is not None and current.key == key):
                return current
            current = current.next
        return None

    def display(self):
        sb = ""
        current = self.head
        while current is not None:
            sb += str(current.key) + "=" + str(current.value)
            current = current.next
            if current is not None:
                sb += " -> "
        return sb if len(sb) > 0 else "null"

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
        return node.value if node is not None else None

    def display(self):
        for i in range(self.hash_size):
            print("Bucket", i, ":", self.buckets[i].display())

    def size(self):
        return self.size

if __name__ == "__main__":
    import sys
    hash_size = int(input())
    main = Main(hash_size)

    operations = int(input())
    sys.stdin.readline()  # consume newline

    for _ in range(operations):
        input_line = sys.stdin.readline().strip().split(" ")
        operation = input_line[0]
        if operation == "PUT":
            main.insert(input_line[1], input_line[2])
        elif operation == "GET":
            value = main.search(input_line[1])
            print(value if value is not None else "NOT FOUND")
        elif operation == "REMOVE":
            main.delete(input_line[1])
        elif operation == "CONTAINS":
            print("YES" if main.search(input_line[1]) is not None else "NO")
        elif operation == "SIZE":
            print(main.size())
        elif operation == "PRINT":
            main.display()
        else:
            print("Invalid operation")

