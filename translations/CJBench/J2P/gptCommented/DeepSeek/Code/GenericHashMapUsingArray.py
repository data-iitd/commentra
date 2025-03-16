class HashMap:
    # Size of the hash map
    def __init__(self):
        self.size = 0
        self.buckets = [[] for _ in range(16)]

    # Method to initialize the buckets with linked lists
    def init_buckets(self, n):
        self.buckets = [[] for _ in range(n)]

    # Method to add a key-value pair to the hash map
    def put(self, key, value):
        bucket_index = self.hash_function(key)
        bucket = self.buckets[bucket_index]
        for node in bucket:
            if node[0] == key:
                node[1] = value
                return
        bucket.append([key, value])
        self.size += 1
        if self.size / len(self.buckets) > 0.75:
            self.re_hash()

    # Method to retrieve a value by key
    def get(self, key):
        bucket_index = self.hash_function(key)
        bucket = self.buckets[bucket_index]
        for node in bucket:
            if node[0] == key:
                return node[1]
        return None

    # Method to remove a key-value pair from the hash map
    def remove(self, key):
        bucket_index = self.hash_function(key)
        bucket = self.buckets[bucket_index]
        target = None
        for node in bucket:
            if node[0] == key:
                target = node
                break
        if target:
            bucket.remove(target)
            self.size -= 1

    # Method to check if a key exists in the hash map
    def contains_key(self, key):
        return self.get(key) is not None

    # Method to get the current size of the hash map
    def size(self):
        return self.size

    # Method to convert the hash map to a string representation
    def __str__(self):
        result = "{"
        for bucket in self.buckets:
            for node in bucket:
                result += f"{node[0]} : {node[1]}, "
        if result != "{":
            result = result[:-2]
        result += "}"
        return result

    # Hash function to determine the bucket index for a given key
    def hash_function(self, key):
        return hash(key) % len(self.buckets)

    # Method to rehash the hash map when the load factor exceeds the threshold
    def re_hash(self):
        old_buckets = self.buckets
        self.init_buckets(len(old_buckets) * 2)
        self.size = 0
        for bucket in old_buckets:
            for node in bucket:
                self.put(node[0], node[1])


# Main method to run the hash map operations
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
