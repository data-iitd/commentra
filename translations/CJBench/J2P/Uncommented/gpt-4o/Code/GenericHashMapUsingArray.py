class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value

class HashMap:
    def __init__(self):
        self.size = 0
        self.buckets = [[] for _ in range(16)]

    def hash_function(self, key):
        return hash(key) % len(self.buckets)

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
        if target:
            nodes.remove(target)
            self.size -= 1

    def contains_key(self, key):
        return self.get(key) is not None

    def get_size(self):
        return self.size

    def __str__(self):
        builder = []
        builder.append("{")
        for nodes in self.buckets:
            for node in nodes:
                builder.append(f"{node.key} : {node.value}, ")
        if builder:
            builder[-1] = builder[-1][:-2]  # Remove last comma and space
        builder.append("}")
        return ''.join(builder)

    def rehash(self):
        old_buckets = self.buckets
        self.buckets = [[] for _ in range(len(old_buckets) * 2)]
        self.size = 0
        for nodes in old_buckets:
            for node in nodes:
                self.put(node.key, node.value)

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    hash_map = HashMap()
    operations = int(data[0])
    
    for i in range(1, operations + 1):
        command = data[i].split()
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
            print(hash_map.get_size())
        elif command[0] == "PRINT":
            print(hash_map)
        else:
            print("INVALID COMMAND")

# <END-OF-CODE>
