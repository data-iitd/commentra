class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val

class HashMap:
    def __init__(self):
        self.buckets = [[] for _ in range(10)]  # Initialize 10 empty buckets
        self.size = 0

    def put(self, key, value):
        hash_index = abs(hash(key) % len(self.buckets))  # Calculate the hash index
        bucket = self.buckets[hash_index]

        for node in bucket:  # Check if the key already exists
            if node.key == key:
                node.val = value  # Update the value if key exists
                return

        bucket.append(Node(key, value))  # Add new node if key does not exist
        self.size += 1

        if self.size / len(self.buckets) > 0.5:  # Check load factor
            self.rehash()

    def rehash(self):
        old_buckets = self.buckets
        self.buckets = [[] for _ in range(len(old_buckets) * 2)]  # Double the size of buckets
        self.size = 0

        for bucket in old_buckets:  # Rehash all nodes
            for node in bucket:
                self.put(node.key, node.val)

    def get(self, key):
        hash_index = abs(hash(key) % len(self.buckets))  # Calculate the hash index
        bucket = self.buckets[hash_index]

        for node in bucket:  # Search for the key
            if node.key == key:
                return node.val  # Return value if found

        return None  # Return None if not found

    def remove(self, key):
        hash_index = abs(hash(key) % len(self.buckets))  # Calculate the hash index
        bucket = self.buckets[hash_index]

        target = None
        for node in bucket:  # Search for the key to remove
            if node.key == key:
                target = node
                break

        if target:  # Remove the target node if found
            bucket.remove(target)
            self.size -= 1

    def contains_key(self, key):
        return self.get(key) is not None  # Check if key exists

    def size(self):
        return self.size  # Return the current size

    def __str__(self):
        builder = ["{"]
        for bucket in self.buckets:  # Iterate through all buckets
            for node in bucket:
                builder.append(f"{node.key} : {node.val}, ")
        if len(builder) > 1:
            builder[-1] = builder[-1][:-2]  # Remove last comma and space
        builder.append("}")
        return ''.join(builder)  # Return the string representation

if __name__ == "__main__":
    map = HashMap()  # Create a new instance of the hash map
    import sys
    input = sys.stdin.read
    data = input().strip().splitlines()

    operations = int(data[0])  # Read the number of operations

    for i in range(1, operations + 1):  # Perform each operation
        command = data[i].split()
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
