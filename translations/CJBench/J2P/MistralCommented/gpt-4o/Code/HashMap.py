class Node:
    def __init__(self, key, value):
        self.key = key  # The key stored in the node
        self.value = value  # The value stored in the node
        self.next = None  # The next node in the linked list

    def get_key(self):
        return self.key

    def get_value(self):
        return self.value

    def set_value(self, value):
        self.value = value

    def get_next(self):
        return self.next

    def set_next(self, next_node):
        self.next = next_node


class LinkedList:
    def __init__(self):
        self.head = None  # Head of the linked list

    def insert(self, key, value):
        existing_node = self.find_key(key)
        if existing_node is not None:
            existing_node.set_value(value)  # Update value if key exists
            return False
        new_node = Node(key, value)
        new_node.set_next(self.head)
        self.head = new_node
        return True

    def delete(self, key):
        if self.head is None:
            return False
        if (key is None and self.head.get_key() is None) or (self.head.get_key() is not None and self.head.get_key() == key):
            self.head = self.head.get_next()
            return True
        current = self.head
        while current.get_next() is not None:
            if (key is None and current.get_next().get_key() is None) or (current.get_next().get_key() is not None and current.get_next().get_key() == key):
                current.set_next(current.get_next().get_next())
                return True
            current = current.get_next()
        return False

    def find_key(self, key):
        current = self.head
        while current is not None:
            if (key is None and current.get_key() is None) or (current.get_key() is not None and current.get_key() == key):
                return current
            current = current.get_next()
        return None

    def display(self):
        elements = []
        current = self.head
        while current is not None:
            elements.append(f"{current.get_key()}={current.get_value()}")
            current = current.get_next()
        return " -> ".join(elements) if elements else "null"


class HashMap:
    def __init__(self, hash_size):
        self.hash_size = hash_size
        self.buckets = [LinkedList() for _ in range(hash_size)]  # Initialize an empty linked list for each bucket
        self.size = 0  # Number of key-value pairs in the hash map

    def compute_hash(self, key):
        if key is None:
            return 0
        hash_value = hash(key) % self.hash_size
        return hash_value if hash_value >= 0 else hash_value + self.hash_size

    def insert(self, key, value):
        hash_value = self.compute_hash(key)
        if self.buckets[hash_value].insert(key, value):  # If the key was already present, update its value
            self.size += 1

    def delete(self, key):
        hash_value = self.compute_hash(key)
        if self.buckets[hash_value].delete(key):  # If the key was present, decrement the size
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
    data = input().splitlines()

    hash_size = int(data[0])  # Reads the size of the hash map from the input
    hash_map = HashMap(hash_size)  # Creates a new hash map with the given size

    operations = int(data[1])  # Reads the number of operations from the input

    # Performs the given operations on the hash map
    for i in range(2, 2 + operations):
        input_line = data[i].split()
        command = input_line[0]
        if command == "PUT":
            hash_map.insert(input_line[1], input_line[2])
        elif command == "GET":
            value = hash_map.search(input_line[1])
            print(value if value is not None else "NOT FOUND")
        elif command == "REMOVE":
            hash_map.delete(input_line[1])
        elif command == "CONTAINS":
            print("YES" if hash_map.search(input_line[1]) is not None else "NO")
        elif command == "SIZE":
            print(hash_map.get_size())
        elif command == "PRINT":
            hash_map.display()
        else:
            print("Invalid operation")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
