class Node:
    def __init__(self, key, val):
        self.key = key  # Key of the node
        self.val = val  # Value of the node


class HashMap:
    def __init__(self):
        self.buckets = [[] for _ in range(10)]  # Initialize with 10 buckets
        self.size = 0  # Initialize size to 0

    def put(self, key, value):
        hash_index = abs(hash(key) % len(self.buckets))  # Calculate hash index
        nodes = self.buckets[hash_index]

        # Check if the key already exists, and update the value if it does
        for node in nodes:
            if node.key == key:
                node.val = value
                return  # Exit if the key is found and updated

        # If the key does not exist, add a new node with the key-value pair
        nodes.append(Node(key, value))
        self.size += 1  # Increment the size of the hash map

        # Check load factor and rehash if necessary
        if self.size / len(self.buckets) > 0.5:
            self.rehash()

    def rehash(self):
        old_buckets = self.buckets
        self.buckets = [[] for _ in range(len(old_buckets) * 2)]  # Create new buckets with double the size
        self.size = 0  # Reset size for the new buckets

        # Reinsert all nodes from the old buckets into the new buckets
        for nodes in old_buckets:
            for node in nodes:
                self.put(node.key, node.val)

    def get(self, key):
        hash_index = abs(hash(key) % len(self.buckets))  # Calculate hash index
        nodes = self.buckets[hash_index]

        # Search for the key in the corresponding bucket
        for node in nodes:
            if node.key == key:
                return node.val  # Return the value if the key is found
        return None  # Return None if the key is not found

    def remove(self, key):
        hash_index = abs(hash(key) % len(self.buckets))  # Calculate hash index
        nodes = self.buckets[hash_index]

        # Search for the key in the corresponding bucket
        for node in nodes:
            if node.key == key:
                nodes.remove(node)  # Remove the node if it was found
                self.size -= 1  # Decrement the size of the hash map
                return

    def contains_key(self, key):
        return self.get(key) is not None  # Return True if the key is found

    def current_size(self):
        return self.size  # Return the size

    def __str__(self):
        builder = ["{"]
        for nodes in self.buckets:
            for node in nodes:
                builder.append(f"{node.key} : {node.val}, ")
        if len(builder) > 1:
            builder[-1] = builder[-1][:-2]  # Remove the trailing comma and space
        builder.append("}")
        return ''.join(builder)  # Return the constructed string


if __name__ == "__main__":
    map = HashMap()  # Create a new hash map
    operations = int(input().strip())  # Read number of operations

    # Process each operation based on user input
    for _ in range(operations):
        command = input().split()
        if command[0].upper() == "PUT":
            map.put(command[1], command[2])  # Add key-value pair
        elif command[0].upper() == "GET":
            value = map.get(command[1])  # Retrieve value by key
            print(value if value is not None else "NOT FOUND")  # Print result
        elif command[0].upper() == "REMOVE":
            map.remove(command[1])  # Remove key-value pair
        elif command[0].upper() == "CONTAINS":
            print("YES" if map.contains_key(command[1]) else "NO")  # Check if key exists
        elif command[0].upper() == "SIZE":
            print(map.current_size())  # Print the size of the hash map
        elif command[0].upper() == "PRINT":
            print(map)  # Print the entire hash map
        else:
            print("INVALID COMMAND")  # Handle invalid commands

# <END-OF-CODE>
