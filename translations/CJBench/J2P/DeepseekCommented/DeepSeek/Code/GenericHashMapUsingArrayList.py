class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val

class HashMap:
    def __init__(self):
        self.buckets = [[] for _ in range(10)]
        self.size = 0

    def put(self, key, val):
        hash_value = abs(hash(key)) % len(self.buckets)
        bucket = self.buckets[hash_value]
        for node in bucket:
            if node.key == key:
                node.val = val
                return
        bucket.append(Node(key, val))
        self.size += 1
        if self.size / len(self.buckets) > 0.5:
            self.rehash()

    def rehash(self):
        old_buckets = self.buckets
        self.buckets = [[] for _ in range(len(old_buckets) * 2)]
        self.size = 0
        for bucket in old_buckets:
            for node in bucket:
                self.put(node.key, node.val)

    def get(self, key):
        hash_value = abs(hash(key)) % len(self.buckets)
        bucket = self.buckets[hash_value]
        for node in bucket:
            if node.key == key:
                return node.val
        return None

    def remove(self, key):
        hash_value = abs(hash(key)) % len(self.buckets)
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

# Command-line interface to interact with the hash map
if __name__ == "__main__":
    map = HashMap()
    import sys
    input = sys.stdin.readline
    operations = int(input().strip())
    for _ in range(operations):
        command = input().strip().split()
        command[0] = command[0].upper()
        if command[0] == "PUT":
            map.put(command[1], command[2])
        elif command[0] == "GET":
            value = map.get(command[1])
            print(value if value is not None else "NOT FOUND")
        elif command[0] == "REMOVE":
            map.remove(command[1])
        elif command[0] == "CONTAINS":
            print("YES" if map.contains_key(command[1]) else "NO")
        elif command[0] == "SIZE":
            print(map.size())
        elif command[0] == "PRINT":
            print(map)
        else:
            print("INVALID COMMAND")
