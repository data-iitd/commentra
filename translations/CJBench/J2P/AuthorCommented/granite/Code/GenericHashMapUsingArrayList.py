

class Main:
    def __init__(self):
        self.buckets = [[] for _ in range(10)]
        self.size = 0

    def put(self, key, value):
        hash = abs(hash(key)) % len(self.buckets)
        for i, node in enumerate(self.buckets[hash]):
            if node.key == key:
                self.buckets[hash][i] = Node(key, value)
                return
        self.buckets[hash].append(Node(key, value))
        self.size += 1
        if self.size / len(self.buckets) > 0.5:
            self.rehash()

    def rehash(self):
        old_buckets = self.buckets
        self.buckets = [[] for _ in range(len(old_buckets) * 2)]
        self.size = 0
        for nodes in old_buckets:
            for node in nodes:
                self.put(node.key, node.val)

    def get(self, key):
        hash = abs(hash(key)) % len(self.buckets)
        for node in self.buckets[hash]:
            if node.key == key:
                return node.val
        return None

    def remove(self, key):
        hash = abs(hash(key)) % len(self.buckets)
        for i, node in enumerate(self.buckets[hash]):
            if node.key == key:
                del self.buckets[hash][i]
                self.size -= 1
                return

    def contains_key(self, key):
        return self.get(key) is not None

    def size(self):
        return self.size

    def __str__(self):
        result = "{"
        for nodes in self.buckets:
            for node in nodes:
                result += f"{node.key} : {node.val}, "
        # Remove trailing comma and space if there are any elements
        if len(result) > 1:
            result = result[:-2]
        result += "}"
        return result

class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val

if __name__ == "__main__":
    operations = int(input().strip())

    map = Main()

    for _ in range(operations):
        command = input().strip().split(" ")
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
            print(map.size())
        elif command[0].upper() == "PRINT":
            print(map)
        else:
            print("INVALID COMMAND")

