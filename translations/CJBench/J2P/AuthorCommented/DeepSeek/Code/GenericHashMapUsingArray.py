class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value

class HashMap:
    def __init__(self, capacity=16):
        self.capacity = capacity
        self.size = 0
        self.buckets = [[] for _ in range(capacity)]

    def hash_function(self, key):
        return hash(key) % self.capacity

    def put(self, key, value):
        bucket_index = self.hash_function(key)
        for node in self.buckets[bucket_index]:
            if node.key == key:
                node.value = value
                return
        self.buckets[bucket_index].append(Node(key, value))
        self.size += 1

        if self.size / self.capacity > 0.75:
            self.rehash()

    def get(self, key):
        bucket_index = self.hash_function(key)
        for node in self.buckets[bucket_index]:
            if node.key == key:
                return node.value
        return None

    def remove(self, key):
        bucket_index = self.hash_function(key)
        for i, node in enumerate(self.buckets[bucket_index]):
            if node.key == key:
                self.buckets[bucket_index].pop(i)
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
        if result != "{":
            result = result[:-2]
        result += "}"
        return result

    def rehash(self):
        old_buckets = self.buckets
        self.capacity *= 2
        self.buckets = [[] for _ in range(self.capacity)]
        self.size = 0
        for bucket in old_buckets:
            for node in bucket:
                self.put(node.key, node.value)

def main():
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

if __name__ == "__main__":
    main()
