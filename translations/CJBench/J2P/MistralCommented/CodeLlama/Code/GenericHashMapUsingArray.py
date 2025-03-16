
# Import the necessary libraries
from collections import LinkedList

# Class definition for the main class
class Main:

    # Declare instance variables
    def __init__(self):
        self.size = 0
        self.buckets = [LinkedList() for _ in range(16)]

    # Method to put a key-value pair in the hash map
    def put(self, key, value):
        bucket_index = self.hash_function(key)
        nodes = self.buckets[bucket_index]

        # Search for the existing node with the same key
        for node in nodes:
            if node.key == key:
                node.value = value
                return

        # If the key is not found, add a new node to the bucket
        nodes.append(Node(key, value))
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
            if node.key == key:
                return node.value

        # If the key is not found, return None
        return None

    # Method to remove a key-value pair from the hash map
    def remove(self, key):
        bucket_index = self.hash_function(key)
        nodes = self.buckets[bucket_index]
        target = None

        # Search for the node with the given key in the bucket
        for node in nodes:
            if node.key == key:
                target = node
                break

        # If the node is found, remove it from the bucket and decrease the size
        if target is not None:
            nodes.remove(target)
            self.size -= 1

    # Method to check if the hash map contains a given key
    def contains_key(self, key):
        return self.get(key) is not None

    # Method to get the current size of the hash map
    def size(self):
        return self.size

    # Method to print the contents of the hash map in a readable format
    def __str__(self):
        builder = "{"

        # Iterate through each bucket and add its contents to the builder
        for nodes in self.buckets:
            for node in nodes:
                builder += str(node.key) + " : " + str(node.value) + ", "

        # Remove the trailing comma and space if there are any
        if len(builder) > 1:
            builder = builder[:-2]

        # Close the curly braces and return the builder as a string
        builder += "}"
        return builder

    # Method to calculate the hash code for a given key and determine the index of the bucket
    def hash_function(self, key):
        return hash(key) % len(self.buckets)

    # Method to resize the hash map when the load factor exceeds 0.75
    def re_hash(self):
        old_buckets = self.buckets
        self.buckets = [LinkedList() for _ in range(len(old_buckets) * 2)]
        self.size = 0

        # Iterate through each node in the old buckets and put it in the new hash map
        for nodes in old_buckets:
            for node in nodes:
                self.put(node.key, node.value)

    # Inner class definition for a Node with a key and a value
    class Node:
        def __init__(self, key, value):
            self.key = key
            self.value = value


# Main method to run the hash map implementation
if __name__ == "__main__":
    hash_map = Main()

    # Read the number of operations from the input
    operations = int(input())

    # Process each operation in the input
    for _ in range(operations):
        command = input().split()
        if command[0] == "PUT":
            hash_map.put(command[1], command[2])
        elif command[0] == "GET":
            print(hash_map.get(command[1]) or "NOT FOUND")
        elif command[0] == "REMOVE":
            hash_map.remove(command[1])
        elif command[0] == "CONTAINS":
            print("YES" if hash_map.contains_key(command[1]) else "NO")
        elif command[0] == "SIZE":
            print(hash_map.size())
        elif command[0] == "PRINT":
            print(hash_map)
        else:
            print("INVALID COMMAND")

# End of code
