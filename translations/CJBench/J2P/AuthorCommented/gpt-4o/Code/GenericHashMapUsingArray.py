class Node:
    """Represents a key-value pair (node) in the hash map."""
    def __init__(self, key, value):
        self.key = key
        self.value = value


class HashMap:
    """A generic implementation of a hash map using an array of linked lists for collision resolution."""
    
    def __init__(self, initial_capacity=16):
        self.size = 0  # Total number of key-value pairs
        self.buckets = [[] for _ in range(initial_capacity)]  # Array of linked lists (buckets)

    def put(self, key, value):
        """Associates the specified value with the specified key in this map."""
        bucket_index = self.hash_function(key)
        nodes = self.buckets[bucket_index]
        
        for node in nodes:
            if node.key == key:
                node.value = value
                return
        
        nodes.append(Node(key, value))
        self.size += 1

        # Rehash if load factor exceeds 0.75
        if self.size / len(self.buckets) > 0.75:
            self.rehash()

    def get(self, key):
        """Returns the value to which the specified key is mapped, or None if no mapping exists."""
        bucket_index = self.hash_function(key)
        nodes = self.buckets[bucket_index]
        
        for node in nodes:
            if node.key == key:
                return node.value
        
        return None

    def remove(self, key):
        """Removes the mapping for the specified key from this map if present."""
        bucket_index = self.hash_function(key)
        nodes = self.buckets[bucket_index]
        
        for node in nodes:
            if node.key == key:
                nodes.remove(node)
                self.size -= 1
                return

    def contains_key(self, key):
        """Returns true if this map contains a mapping for the specified key."""
        return self.get(key) is not None

    def size(self):
        """Returns the number of key-value pairs in this map."""
        return self.size

    def __str__(self):
        """Returns a string representation of the hash map."""
        items = []
        for nodes in self.buckets:
            for node in nodes:
                items.append(f"{node.key} : {node.value}")
        return "{" + ", ".join(items) + "}"

    def hash_function(self, key):
        """Computes the bucket index for the given key."""
        return hash(key) % len(self.buckets)

    def rehash(self):
        """Rehashes the map by doubling the number of buckets and reinserting all entries."""
        old_buckets = self.buckets
        self.buckets = [[] for _ in range(len(old_buckets) * 2)]
        self.size = 0
        
        for nodes in old_buckets:
            for node in nodes:
                self.put(node.key, node.value)


def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    hash_map = HashMap()
    
    # Read the number of operations
    operations = int(data[0])
    
    # Perform operations
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
            print(hash_map.size)
        elif command[0] == "PRINT":
            print(hash_map)
        else:
            print("INVALID COMMAND")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
