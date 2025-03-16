
import math

class Main:
    def __init__(self):
        self.buckets = [[] for _ in range(16)]
        self.size = 0

    def put(self, key, value):
        bucket_index = self.hash_function(key)
        nodes = self.buckets[bucket_index]
        for node in nodes:
            if node.key == key:
                node.value = value
                return
        nodes.append(Node(key, value))
        self.size += 1
        if self.size / len(self.buckets) > 0.75:
            self.rehash()

    def get(self, key):
        bucket_index = self.hash_function(key)
        nodes = self.buckets[bucket_index]
        for node in nodes:
            if node.key == key:
                return node.value
        return None

    def remove(self, key):
        bucket_index = self.hash_function(key)
        nodes = self.buckets[bucket_index]
        target = None
        for node in nodes:
            if node.key == key:
                target = node
                break
        if target is not None:
            nodes.remove(target)
            self.size -= 1

    def contains_key(self, key):
        return self.get(key) is not None

    def size(self):
        return self.size

    def __str__(self):
        builder = ""
        for nodes in self.buckets:
            for node in nodes:
                builder += str(node.key) + " : " + str(node.value) + ", "
        if len(builder) > 2:
            builder = builder[:-2]
        return "{" + builder + "}"

    def hash_function(self, key):
        return math.floor_mod(hash(key), len(self.buckets))

    def rehash(self):
        old_buckets = self.buckets
        self.buckets = [[] for _ in range(len(old_buckets) * 2)]
        self.size = 0
        for nodes in old_buckets:
            for node in nodes:
                self.put(node.key, node.value)

class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value

if __name__ == "__main__":
    import sys
    hash_map = Main()
    for line in sys.stdin:
        command, *args = line.strip().split()
        if command == "PUT":
            hash_map.put(args[0], args[1])
        elif command == "GET":
            print(hash_map.get(args[0]) or "NOT FOUND")
        elif command == "REMOVE":
            hash_map.remove(args[0])
        elif command == "CONTAINS":
            print("YES" if hash_map.contains_key(args[0]) else "NO")
        elif command == "SIZE":
            print(hash_map.size())
        elif command == "PRINT":
            print(hash_map)
        else:
            print("INVALID COMMAND")

