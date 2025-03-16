
class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, key, value):
        new_node = Node(key, value)
        new_node.next = self.head
        self.head = new_node

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

    def find_key(self, key):
        current = self.head
        while current is not None:
            if current.key == key:
                return current
            current = current.next
        return None

    def display(self):
        result = ""
        current = self.head
        while current is not None:
            result += str(current.key) + "=" + str(current.value)
            current = current.next
            if current is not None:
                result += " -> "
        return result


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
            print("Bucket {}: {}".format(i, self.buckets[i].display()))

    def size(self):
        return self.size


if __name__ == "__main__":
    hash_size = int(input())
    hash_map = Main(hash_size)
    operations = int(input())
    for _ in range(operations):
        input_list = input().split()
        if input_list[0] == "PUT":
            hash_map.insert(input_list[1], input_list[2])
        elif input_list[0] == "GET":
            value = hash_map.search(input_list[1])
            print(value if value is not None else "NOT FOUND")
        elif input_list[0] == "REMOVE":
            hash_map.delete(input_list[1])
        elif input_list[0] == "CONTAINS":
            value = hash_map.search(input_list[1])
            print("YES" if value is not None else "NO")
        elif input_list[0] == "SIZE":
            print(hash_map.size())
        elif input_list[0] == "PRINT":
            hash_map.display()
        else:
            print("Invalid operation")


