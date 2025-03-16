class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

    def get_key(self):
        return self.key

    def get_value(self):
        return self.value

    def set_value(self, value):
        self.value = value

    def get_next(self):
        return self.next

    def set_next(self, next):
        self.next = next


class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, key, value):
        current = self.head
        while current:
            if current.get_key() == key:
                current.set_value(value)
                return False
            current = current.get_next()
        new_node = Node(key, value)
        new_node.set_next(self.head)
        self.head = new_node
        return True

    def delete(self, key):
        if not self.head:
            return False
        if self.head.get_key() == key:
            self.head = self.head.get_next()
            return True
        current = self.head
        while current.get_next():
            if current.get_next().get_key() == key:
                current.set_next(current.get_next().get_next())
                return True
            current = current.get_next()
        return False

    def find_key(self, key):
        current = self.head
        while current:
            if current.get_key() == key:
                return current
            current = current.get_next()
        return None

    def display(self):
        if not self.head:
            return "null"
        result = []
        current = self.head
        while current:
            result.append(f"{current.get_key()}={current.get_value()}")
            current = current.get_next()
        return " -> ".join(result)


class HashMap:
    def __init__(self, hash_size):
        self.hash_size = hash_size
        self.buckets = [LinkedList() for _ in range(hash_size)]
        self.size = 0

    def compute_hash(self, key):
        if key is None:
            return 0
        hash_value = hash(key) % self.hash_size
        return hash_value if hash_value >= 0 else hash_value + self.hash_size

    def insert(self, key, value):
        hash_value = self.compute_hash(key)
        if self.buckets[hash_value].insert(key, value):
            self.size += 1

    def delete(self, key):
        hash_value = self.compute_hash(key)
        if self.buckets[hash_value].delete(key):
            self.size -= 1

    def search(self, key):
        hash_value = self.compute_hash(key)
        node = self.buckets[hash_value].find_key(key)
        return node.get_value() if node else None

    def display(self):
        for i in range(self.hash_size):
            print(f"Bucket {i}: {self.buckets[i].display()}")

    def get_size(self):
        return self.size


def main():
    import sys
    input = sys.stdin.readline
    hash_size = int(input())
    hash_map = HashMap(hash_size)
    operations = int(input())
    for _ in range(operations):
        command = input().strip().split()
        if command[0] == "PUT":
            hash_map.insert(command[1], command[2])
        elif command[0] == "GET":
            value = hash_map.search(command[1])
            print(value if value else "NOT FOUND")
        elif command[0] == "REMOVE":
            hash_map.delete(command[1])
        elif command[0] == "CONTAINS":
            print("YES" if hash_map.search(command[1]) else "NO")
        elif command[0] == "SIZE":
            print(hash_map.get_size())
        elif command[0] == "PRINT":
            hash_map.display()
        else:
            print("Invalid operation")


