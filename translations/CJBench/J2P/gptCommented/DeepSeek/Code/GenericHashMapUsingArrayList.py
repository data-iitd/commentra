class HashMap:
    class Node:
        def __init__(self, key, value):
            self.key = key
            self.value = value

    def __init__(self):
        self.size = 0
        self.capacity = 10
        self.buckets = [[] for _ in range(self.capacity)]

    def _hash(self, key):
        return abs(hash(key)) % self.capacity

    def put(self, key, value):
        hash_index = self._hash(key)
        for node in self.buckets[hash_index]:
            if node.key == key:
                node.value = value
                return
        self.buckets[hash_index].append(self.Node(key, value))
        self.size += 1
        if self.size / self.capacity > 0.5:
            self._rehash()

    def _rehash(self):
        old_buckets = self.buckets
        self.capacity *= 2
        self.buckets = [[] for _ in range(self.capacity)]
        self.size = 0
        for bucket in old_buckets:
            for node in bucket:
                self.put(node.key, node.value)

    def get(self, key):
        hash_index = self._hash(key)
        for node in self.buckets[hash_index]:
            if node.key == key:
                return node.value
        return None

    def remove(self, key):
        hash_index = self._hash(key)
        for i, node in enumerate(self.buckets[hash_index]):
            if node.key == key:
                del self.buckets[hash_index][i]
                self.size -= 1
                return

    def contains_key(self, key):
        return self.get(key) is not None

    def __len__(self):
        return self.size

    def __str__(self):
        result = "{"
        for bucket in self.buckets:
            for node in bucket:
                result += f"{node.key} : {node.value}, "
        if result != "{":
            result = result[:-2] + "}"
        else:
            result += "}"
        return result


if __name__ == "__main__":
    map = HashMap()
    import sys
    input = sys.stdin.read
    data = input().split()
    operations = int(data[0])
    index = 1
    for i in range(operations):
        command = data[index].split()
        if command[0].upper() == "PUT":
            map.put(command[1], command[2])
        elif command[0].upper() == "GET":
            value = map.get(command[1])
            print(value if value is not None else "NOT FOUND")
        elif command[0].upper() == "REMOVE":
            map.remove(command[1])
        elif command[0].upper() == "CONTAINS":
            print("YES" if map.contains_key(command[1]) else "NO")
        elif command[0].upper() == "SIZE":
            print(len(map))
        elif command[0].upper() == "PRINT":
            print(map)
        index += 1
