
class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value

class Main:
    def __init__(self):
        self.size = 0
        self.buckets = [[] for _ in range(16)]

    def hash_function(self, key):
        return hash(key) % len(self.buckets)

    def put(self, key, value):
        bucket_index = self.hash_function(key)
        bucket = self.buckets[bucket_index]
        for node in bucket:
            if node.key == key:
                node.value = value
                return
        bucket.append(Node(key, value))
        self.size += 1
        if self.size / len(self.buckets) > 0.75:
            self.rehash()

    def get(self, key):
        bucket_index = self.hash_function(key)
        bucket = self.buckets[bucket_index]
        for node in bucket:
            if node.key == key:
                return node.value
        return None

    def remove(self, key):
        bucket_index = self.hash_function(key)
        bucket = self.buckets[bucket_index]
        for i, node in enumerate(bucket):
            if node.key == key:
                del bucket[i]
                self.size -= 1
                return

    def contains_key(self, key):
        return self.get(key) is not None

    def size(self):
        return self.size

    def __str__(self):
        result = "{"
        for bucket in self.buckets:
            for node in bucket:
                result += f"{node.key} : {node.value}, "
        if len(result) > 1:
            result = result[:-2]
        result += "}"
        return result

    def rehash(self):
        old_buckets = self.buckets
        self.buckets = [[] for _ in range(len(old_buckets) * 2)]
        self.size = 0
        for bucket in old_buckets:
            for node in bucket:
                self.put(node.key, node.value)

if __name__ == "__main__":
    import sys
    operations = int(input())
    hash_map = Main()
    for _ in range(operations):
        command = input().split()
        if command[0] == "PUT":
            key, value = command[1], command[2]
            hash_map.put(key, value)
        elif command[0] == "GET":
            key = command[1]
            value = hash_map.get(key)
            print(value if value is not None else "NOT FOUND")
        elif command[0] == "REMOVE":
            key = command[1]
            hash_map.remove(key)
        elif command[0] == "CONTAINS":
            key = command[1]
            print("YES" if hash_map.contains_key(key) else "NO")
        elif command[0] == "SIZE":
            print(hash_map.size())
        elif command[0] == "PRINT":
            print(hash_map)
        else:
            print("INVALID COMMAND")

