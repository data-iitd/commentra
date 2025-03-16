
class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value

class Main:
    def __init__(self):
        self.buckets = [[] for _ in range(16)]
        self.size = 0

    def put(self, key, value):
        bucket_index = hash(key) % len(self.buckets)
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
        bucket_index = hash(key) % len(self.buckets)
        nodes = self.buckets[bucket_index]
        for node in nodes:
            if node.key == key:
                return node.value
        return None

    def remove(self, key):
        bucket_index = hash(key) % len(self.buckets)
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
        builder = "{"
        for nodes in self.buckets:
            for node in nodes:
                builder += str(node.key) + " : " + str(node.value) + ", "
        if len(builder) > 1:
            builder = builder[:-2]
        builder += "}"
        return builder

    def rehash(self):
        old_buckets = self.buckets
        self.buckets = [[] for _ in range(len(old_buckets) * 2)]
        self.size = 0
        for nodes in old_buckets:
            for node in nodes:
                self.put(node.key, node.value)

    def main():
        scanner = Scanner(System.in)
        hash_map = Main()
        operations = scanner.nextInt()
        scanner.nextLine()
        for i in range(operations):
            command = scanner.next()
            if command == "PUT":
                key = scanner.next()
                value = scanner.next()
                hash_map.put(key, value)
            elif command == "GET":
                key = scanner.next()
                value = hash_map.get(key)
                if value is None:
                    print("NOT FOUND")
                else:
                    print(value)
            elif command == "REMOVE":
                key = scanner.next()
                hash_map.remove(key)
            elif command == "CONTAINS":
                key = scanner.next()
                if hash_map.contains_key(key):
                    print("YES")
                else:
                    print("NO")
            elif command == "SIZE":
                print(hash_map.size())
            elif command == "PRINT":
                print(hash_map)
            else:
                print("INVALID COMMAND")
        scanner.close()

    if __name__ == "__main__":
        main()

