
class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value

class Main:
    def __init__(self):
        self.size = 0
        self.buckets = [[] for _ in range(16)]

    def put(self, key, value):
        bucket_index = hash(key) % len(self.buckets)
        nodes = self.buckets[bucket_index]
        for node in nodes:
            if node.key == key:
                node.value = value
                return
        nodes.append(Node(key, value))
        self.size += 1

        # Rehash if load factor exceeds 0.75
        if self.size / len(self.buckets) > 0.75:
            self.rehash()

    def get(self, key):
        bucket_index = hash(key) % len(self.buckets)
        nodes = self.buckets[bucket_index]
        for node in nodes:
            if node.key == key:
                return node.value
        return None

    def remove(self, key):
        bucket_index = hash(key) % len(self.buckets)
        nodes = self.buckets[bucket_index]
        target = None
        for node in nodes:
            if node.key == key:
                target = node
                break
        if target is not None:
            nodes.remove(target)
            self.size -= 1

    def containsKey(self, key):
        return self.get(key) is not None

    def size(self):
        return self.size

    def rehash(self):
        old_buckets = self.buckets
        self.buckets = [[] for _ in range(len(old_buckets) * 2)]
        self.size = 0
        for nodes in old_buckets:
            for node in nodes:
                self.put(node.key, node.value)

    def __str__(self):
        return str(self.buckets)

if __name__ == "__main__":
    hash_map = Main()

    # Read the number of operations
    operations = int(input())

    # Perform operations
    for _ in range(operations):
        command = input().split()
        if command[0] == "PUT":
            hash_map.put(command[1], command[2])
        elif command[0] == "GET":
            value = hash_map.get(command[1])
            print(value if value is not None else "NOT FOUND")
        elif command[0] == "REMOVE":
            hash_map.remove(command[1])
        elif command[0] == "CONTAINS":
            print("YES" if hash_map.containsKey(command[1]) else "NO")
        elif command[0] == "SIZE":
            print(hash_map.size())
        elif command[0] == "PRINT":
            print(hash_map)
        else:
            print("INVALID COMMAND")

