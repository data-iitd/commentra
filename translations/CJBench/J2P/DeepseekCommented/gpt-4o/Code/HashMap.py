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
        existing_node = self.find_key(key)
        if existing_node is not None:
            existing_node.set_value(value)
            return False
        new_node = Node(key, value)
        new_node.set_next(self.head)
        self.head = new_node
        return True

    def delete(self, key):
        if self.head is None:
            return False
        if self.head.get_key() == key:
            self.head = self.head.get_next()
            return True
        current = self.head
        while current.get_next() is not None:
            if current.get_next().get_key() == key:
                current.set_next(current.get_next().get_next())
                return True
            current = current.get_next()
        return False

    def find_key(self, key):
        current = self.head
        while current is not None:
            if current.get_key() == key:
                return current
            current = current.get_next()
        return None

    def display(self):
        sb = []
        current = self.head
        while current is not None:
            sb.append(f"{current.get_key()}={current.get_value()}")
            current = current.get_next()
            if current is not None:
                sb.append(" -> ")
        return "".join(sb) if sb else "null"


class HashMap:
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
        return node.get_value() if node is not None else None

    def display(self):
        for i in range(self.hash_size):
            print(f"Bucket {i}: {self.buckets[i].display()}")

    def get_size(self):
        return self.size


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    hash_size = int(data[0])
    hash_map = HashMap(hash_size)
    operations = int(data[1])
    index = 2
    for _ in range(operations):
        operation = data[index]
        index += 1
        if operation == "PUT":
            key = data[index]
            value = data[index + 1]
            hash_map.insert(key, value)
            index += 2
        elif operation == "GET":
            key = data[index]
            value = hash_map.search(key)
            print(value if value is not None else "NOT FOUND")
            index += 1
        elif operation == "REMOVE":
            key = data[index]
            hash_map.delete(key)
            index += 1
        elif operation == "CONTAINS":
            key = data[index]
            print("YES" if hash_map.search(key) is not None else "NO")
            index += 1
        elif operation == "SIZE":
            print(hash_map.get_size())
        elif operation == "PRINT":
            hash_map.display()
        else:
            print("Invalid operation")


main()
