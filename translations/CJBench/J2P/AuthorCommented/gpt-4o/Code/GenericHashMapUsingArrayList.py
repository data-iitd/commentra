class HashMap:
    class Node:
        def __init__(self, key, value):
            self.key = key
            self.value = value

    def __init__(self):
        self.buckets = [[] for _ in range(10)]
        self.size = 0

    def put(self, key, value):
        hash_index = abs(hash(key)) % len(self.buckets)
        nodes = self.buckets[hash_index]

        for node in nodes:
            if node.key == key:
                node.value = value
                return

        nodes.append(self.Node(key, value))
        self.size += 1
        if self.size / len(self.buckets) > 0.5:
            self.rehash()

    def rehash(self):
        old_buckets = self.buckets
        self.buckets = [[] for _ in range(len(old_buckets) * 2)]
        self.size = 0
        for nodes in old_buckets:
            for node in nodes:
                self.put(node.key, node.value)

    def get(self, key):
        hash_index = abs(hash(key)) % len(self.buckets)
        nodes = self.buckets[hash_index]
        for node in nodes:
            if node.key == key:
                return node.value
        return None

    def remove(self, key):
        hash_index = abs(hash(key)) % len(self.buckets)
        nodes = self.buckets[hash_index]

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
        builder = []
        builder.append("{")
        for nodes in self.buckets:
            for node in nodes:
                builder.append(f"{node.key} : {node.value}, ")
        if len(builder) > 1:
            builder[-1] = builder[-1][:-2]  # Remove trailing comma and space
        builder.append("}")
        return ''.join(builder)

if __name__ == "__main__":
    map = HashMap()
    import sys

    operations = int(sys.stdin.readline().strip())

    for _ in range(operations):
        command = sys.stdin.readline().strip().split()
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
            print(map.size)
        elif command[0].upper() == "PRINT":
            print(map)
        else:
            print("INVALID COMMAND")

# <END-OF-CODE>
