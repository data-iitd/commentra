from collections import defaultdict

# Class definition for the main class
class Main:
    def __init__(self):
        self.size = 0
        self.buckets = self.init_buckets(16)  # Initialize the buckets with a capacity of 16

    # Method to initialize the buckets with the given capacity
    def init_buckets(self, n):
        return defaultdict(list)  # Create a dictionary of lists for the buckets

    # Method to put a key-value pair in the hash map
    def put(self, key, value):
        bucket_index = self.hash_function(key)  # Calculate the index of the bucket where the key should be stored
        nodes = self.buckets[bucket_index]  # Get the list for the corresponding bucket

        # Search for the existing node with the same key
        for node in nodes:
            if node[0] == key:
                node[1] = value  # If found, update the value of the existing node
                return

        # If the key is not found, add a new node to the bucket
        nodes.append([key, value])
        self.size += 1

        # Check if the load factor exceeds 0.75 and resize the hash map if necessary
        if self.size / len(self.buckets) > 0.75:
            self.re_hash()

    # Method to get the value associated with the given key
    def get(self, key):
        bucket_index = self.hash_function(key)
        nodes = self.buckets[bucket_index]

        # Search for the node with the given key in the bucket
        for node in nodes:
            if node[0] == key:
                return node[1]

        # If the key is not found, return None
        return None

    # Method to remove a key-value pair from the hash map
    def remove(self, key):
        bucket_index = self.hash_function(key)
        nodes = self.buckets[bucket_index]

        # Search for the node with the given key in the bucket
        for i, node in enumerate(nodes):
            if node[0] == key:
                del nodes[i]  # Remove the node from the bucket
                self.size -= 1
                return

    # Method to check if the hash map contains a given key
    def contains_key(self, key):
        return self.get(key) is not None

    # Method to get the current size of the hash map
    def size(self):
        return self.size

    # Method to print the contents of the hash map in a readable format
    def __str__(self):
        builder = ["{"]
        for nodes in self.buckets.values():
            for node in nodes:
                builder.append(f"{node[0]} : {node[1]}, ")
        if len(builder) > 1:
            builder[-1] = builder[-1][:-2]  # Remove the trailing comma and space
        builder.append("}")
        return ''.join(builder)

    # Method to calculate the hash code for a given key and determine the index of the bucket
    def hash_function(self, key):
        return hash(key) % len(self.buckets)

    # Method to resize the hash map when the load factor exceeds 0.75
    def re_hash(self):
        old_buckets = self.buckets  # Save a reference to the old buckets
        self.buckets = self.init_buckets(len(old_buckets) * 2)  # Initialize new buckets with double the capacity
        self.size = 0  # Reset the size to 0

        # Iterate through each node in the old buckets and put it in the new hash map
        for nodes in old_buckets.values():
            for node in nodes:
                self.put(node[0], node[1])

# Main method to run the hash map implementation
if __name__ == "__main__":
    import sys

    hash_map = Main()  # Create an instance of the Main class

    operations = int(sys.stdin.readline().strip())  # Read the number of operations from the input

    # Process each operation in the input
    for _ in range(operations):
        command = sys.stdin.readline().strip().split()  # Read the command from the input
        if command[0] == "PUT":  # Handle the PUT command
            key, value = command[1], command[2]
            hash_map.put(key, value)
        elif command[0] == "GET":  # Handle the GET command
            key = command[1]
            value = hash_map.get(key)
            print(value if value is not None else "NOT FOUND")
        elif command[0] == "REMOVE":  # Handle the REMOVE command
            key = command[1]
            hash_map.remove(key)
        elif command[0] == "CONTAINS":  # Handle the CONTAINS command
            key = command[1]
            print("YES" if hash_map.contains_key(key) else "NO")
        elif command[0] == "SIZE":  # Handle the SIZE command
            print(hash_map.size)
        elif command[0] == "PRINT":  # Handle the PRINT command
            print(hash_map)
        else:
            print("INVALID COMMAND")  # Handle invalid commands

# <END-OF-CODE>
