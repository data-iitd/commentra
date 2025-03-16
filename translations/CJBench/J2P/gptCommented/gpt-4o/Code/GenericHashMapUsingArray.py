class Node:
    def __init__(self, key, value):
        self.key = key  # Key of the node
        self.value = value  # Value of the node


class HashMap:
    def __init__(self):
        self.size = 0  # Initialize size to 0
        self.buckets = [[] for _ in range(16)]  # Initialize buckets with a size of 16

    def hash_function(self, key):
        return hash(key) % len(self.buckets)  # Return the index using modulo operation

    def put(self, key, value):
        bucket_index = self.hash_function(key)  # Get the index of the bucket for the key
        nodes = self.buckets[bucket_index]  # Get the linked list at that bucket
        # Check if the key already exists in the bucket
        for node in nodes:
            if node.key == key:
                node.value = value  # Update the value if the key exists
                return
        # Add a new node if the key does not exist
        nodes.append(Node(key, value))
        self.size += 1  # Increment the size of the hash map
        # Check load factor and rehash if necessary
        if self.size / len(self.buckets) > 0.75:
            self.rehash()  # Rehash if the load factor exceeds 0.75

    def get(self, key):
        bucket_index = self.hash_function(key)  # Get the index of the bucket for the key
        nodes = self.buckets[bucket_index]  # Get the linked list at that bucket
        # Search for the key in the bucket
        for node in nodes:
            if node.key == key:
                return node.value  # Return the value if the key is found
        return None  # Return None if the key is not found

    def remove(self, key):
        bucket_index = self.hash_function(key)  # Get the index of the bucket for the key
        nodes = self.buckets[bucket_index]  # Get the linked list at that bucket
        target = None  # Variable to hold the target node for removal
        # Search for the key in the bucket
        for node in nodes:
            if node.key == key:
                target = node  # Found the target node
                break
        # Remove the target node if it exists
        if target is not None:
            nodes.remove(target)  # Remove the node from the linked list
            self.size -= 1  # Decrement the size of the hash map

    def contains_key(self, key):
        return self.get(key) is not None  # Return True if the key is found, False otherwise

    def get_size(self):
        return self.size  # Return the size of the hash map

    def __str__(self):
        builder = ["{"]
        # Iterate through each bucket and its nodes
        for nodes in self.buckets:
            for node in nodes:
                builder.append(f"{node.key} : {node.value}, ")  # Append key-value pairs
        # Remove the trailing comma and space if there are any elements
        if len(builder) > 1:
            builder[-1] = builder[-1][:-2]  # Remove last comma and space
        builder.append("}")
        return ''.join(builder)  # Return the string representation

    def rehash(self):
        old_buckets = self.buckets  # Store the old buckets
        self.buckets = [[] for _ in range(len(old_buckets) * 2)]  # Initialize new buckets with double the size
        self.size = 0  # Reset size to 0
        # Reinsert all nodes from old buckets into new buckets
        for nodes in old_buckets:
            for node in nodes:
                self.put(node.key, node.value)  # Reinsert each key-value pair


def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    hash_map = HashMap()  # Create a new instance of the hash map
    operations = int(data[0])  # Read the number of operations to perform
    # Loop through the number of operations
    for i in range(1, operations + 1):
        command = data[i].split()  # Read the command
        if command[0] == "PUT":  # Handle PUT command
            key = command[1]  # Read the key
            value = command[2]  # Read the value
            hash_map.put(key, value)  # Add the key-value pair to the hash map
        elif command[0] == "GET":  # Handle GET command
            key = command[1]  # Read the key
            value = hash_map.get(key)  # Retrieve the value
            print(value if value is not None else "NOT FOUND")  # Print the value or "NOT FOUND"
        elif command[0] == "REMOVE":  # Handle REMOVE command
            key = command[1]  # Read the key
            hash_map.remove(key)  # Remove the key-value pair from the hash map
        elif command[0] == "CONTAINS":  # Handle CONTAINS command
            key = command[1]  # Read the key
            print("YES" if hash_map.contains_key(key) else "NO")  # Print "YES" or "NO"
        elif command[0] == "SIZE":  # Handle SIZE command
            print(hash_map.get_size())  # Print the size of the hash map
        elif command[0] == "PRINT":  # Handle PRINT command
            print(hash_map)  # Print the string representation of the hash map
        else:
            print("INVALID COMMAND")  # Handle invalid commands


if __name__ == "__main__":
    main()

# <END-OF-CODE>
