class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value

class HashMap:
    def __init__(self, size=16):
        self.init_buckets(size)
        self.size = 0

    def init_buckets(self, n):
        self.buckets = [[] for _ in range(n)]

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
            self.re_hash()

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
        result = "{"
        for nodes in self.buckets:
            for node in nodes:
                result += f"{node.key} : {node.value}, "
        if result != "{":
            result = result[:-2]
        result += "}"
        return result

    def hash_function(self, key):
        return hash(key) % len(self.buckets)

    def re_hash(self):
        old_buckets = self.buckets
        self.init_buckets(len(old_buckets) * 2)
        self.size = 0
        for nodes in old_buckets:
            for node in nodes:
                self.put(node.key, node.value)

if __name__ == "__main__":
    hash_map = HashMap()
    import sys
    input = sys.stdin.read
    data = input().split()
    i = 0
    while i < len(data):
        command = data[i]
        i += 1
        if command == "PUT":
            key = data[i]
            value = data[i + 1]
            i += 2
            hash_map.put(key, value)
        elif command == "GET":
            key = data[i]
            i += 1
            value = hash_map.get(key)
            print(value if value is not None else "NOT FOUND")
        elif command == "REMOVE":
            key = data[i]
            i += 1
            hash_map.remove(key)
        elif command == "CONTAINS":
            key = data[i]
            i += 1
            print("YES" if hash_map.contains_key(key) else "NO")
        elif command == "SIZE":
            print(hash_map.size())
        elif command == "PRINT":
            print(hash_map)
        else:
            print("INVALID COMMAND")
