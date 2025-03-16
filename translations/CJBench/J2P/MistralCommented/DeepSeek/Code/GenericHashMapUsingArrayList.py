class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val

class HashMap:
    def __init__(self, capacity=10):
        self.capacity = capacity
        self.size = 0
        self.buckets = [[] for _ in range(capacity)]

    def _hash(self, key):
        return abs(hash(key)) % self.capacity

    def put(self, key, value):
        hash_value = self._hash(key)
        bucket = self.buckets[hash_value]

        for node in bucket:
            if node.key == key:
                node.val = value
                return

        bucket.append(Node(key, value))
        self.size += 1

        if self.size / self.capacity > 0.5:
            self._rehash()

    def _rehash(self):
        old_buckets = self.buckets
        self.capacity *= 2
        self.size = 0
        self.buckets = [[] for _ in range(self.capacity)]

        for bucket in old_buckets:
            for node in bucket:
                self.put(node.key, node.val)

    def get(self, key):
        hash_value = self._hash(key)
        bucket = self.buckets[hash_value]

        for node in bucket:
            if node.key == key:
                return node.val

        return None

    def remove(self, key):
        hash_value = self._hash(key)
        bucket = self.buckets[hash_value]

        target = None

        for node in bucket:
            if node.key == key:
                target = node
                break

        if target:
            bucket.remove(target)
            self.size -= 1

    def contains_key(self, key):
        return self.get(key) is not None

    def size(self):
        return self.size

    def __str__(self):
        result = "{"
        for bucket in self.buckets:
            for node in bucket:
                result += f"{node.key} : {node.val}, "
        if result != "{":
            result = result[:-2]
        result += "}"
        return result

def main():
    map = HashMap()
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    operations = int(data[0].strip())

    for i in range(1, operations + 1):
        command = data[i].split()
        cmd = command[0].upper()
        if cmd == "PUT":
            map.put(command[1], command[2])
        elif cmd == "GET":
            value = map.get(command[1])
            print(value if value is not None else "NOT FOUND")
        elif cmd == "REMOVE":
            map.remove(command[1])
        elif cmd == "CONTAINS":
            print("YES" if map.contains_key(command[1]) else "NO")
        elif cmd == "SIZE":
            print(map.size())
        elif cmd == "PRINT":
            print(map)
        else:
            print("INVALID COMMAND")

if __name__ == "__main__":
    main()
