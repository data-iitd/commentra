
class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val

class Main:
    def __init__(self):
        self.buckets = [[] for _ in range(10)]
        self.size = 0

    def put(self, key, val):
        hash = abs(hash(key) % len(self.buckets))
        nodes = self.buckets[hash]
        for node in nodes:
            if node.key == key:
                node.val = val
                return
        nodes.append(Node(key, val))
        self.size += 1
        if self.size / len(self.buckets) > 0.5:
            self.reHash()

    def reHash(self):
        oldBuckets = self.buckets
        self.buckets = [[] for _ in range(len(oldBuckets) * 2)]
        self.size = 0
        for nodes in oldBuckets:
            for node in nodes:
                self.put(node.key, node.val)

    def get(self, key):
        hash = abs(hash(key) % len(self.buckets))
        nodes = self.buckets[hash]
        for node in nodes:
            if node.key == key:
                return node.val
        return None

    def remove(self, key):
        hash = abs(hash(key) % len(self.buckets))
        nodes = self.buckets[hash]
        target = None
        for node in nodes:
            if node.key == key:
                target = node
                break
        if target is not None:
            nodes.remove(target)
            self.size -= 1

    def containsKey(self, key):
        return self.get(key) is not None

    def size(self):
        return self.size

    def __str__(self):
        builder = ""
        builder += "{"
        for nodes in self.buckets:
            for node in nodes:
                builder += str(node.key) + " : " + str(node.val) + ", "
        if len(builder) > 1:
            builder = builder[:-2]
        builder += "}"
        return builder

if __name__ == "__main__":
    map = Main()
    sc = input()
    operations = int(sc.strip())
    for i in range(operations):
        command = input().split()
        if command[0].upper() == "PUT":
            map.put(command[1], command[2])
        elif command[0].upper() == "GET":
            value = map.get(command[1])
            print(value if value is not None else "NOT FOUND")
        elif command[0].upper() == "REMOVE":
            map.remove(command[1])
        elif command[0].upper() == "CONTAINS":
            print("YES" if map.containsKey(command[1]) else "NO")
        elif command[0].upper() == "SIZE":
            print(map.size())
        elif command[0].upper() == "PRINT":
            print(map)
        else:
            print("INVALID COMMAND")
    sc.close()
