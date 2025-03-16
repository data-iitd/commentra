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

    def set_next(self, next_node):
        self.next = next_node


class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, key, value):
        existing_node = self.find_key(key)
        if existing_node:
            existing_node.set_value(value)
            return False
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
            if current:
                result.append(" -> ")
        return "".join(result)


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
        hash_index = self.compute_hash(key)
        if self.buckets[hash_index].insert(key, value):
            self.size += 1

    def delete(self, key):
        hash_index = self.compute_hash(key)
        if self.buckets[hash_index].delete(key):
            self.size -= 1

    def search(self, key):
        hash_index = self.compute_hash(key)
        node = self.buckets[hash_index].find_key(key)
        return node.get_value() if node else None

    def display(self):
        for i in range(self.hash_size):
            print(f"Bucket {i}: {self.buckets[i].display()}")

    def get_size(self):
        return self.size


def main():
    import sys
    input_lines = sys.stdin.readlines()
    hash_size = int(input_lines[0].strip())
    hash_map = HashMap(hash_size)
    operations = int(input_lines[1].strip())

    line_index = 2
    for _ in range(operations):
        input_line = input_lines[line_index].strip().split()
        operation = input_line[0]
        line_index += 1
        if operation == "PUT":
            hash_map.insert(input_line[1], input_line[2])
        elif operation == "GET":
            value = hash_map.search(input_line[1])
            print(value if value is not None else "NOT FOUND")
        elif operation == "REMOVE":
            hash_map.delete(input_line[1])
        elif operation == "CONTAINS":
            print("YES" if hash_map.search(input_line[1]) is not None else "NO")
        elif operation == "SIZE":
            print(hash_map.get_size())
        elif operation == "PRINT":
            hash_map.display()
        else:
            print("Invalid operation")


if __name__ == "__main__":
    main()
