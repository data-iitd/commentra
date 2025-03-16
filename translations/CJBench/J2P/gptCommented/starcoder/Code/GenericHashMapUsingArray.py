import java.util.LinkedList;
import java.util.Scanner;

class Main:
    # Size of the hash map
    size = 0
    # Array of linked lists to store the buckets
    buckets = None

    # Constructor to initialize the hash map with a default bucket size
    def __init__(self):
        self.initBuckets(16) # Initialize buckets with a size of 16

    # Method to initialize the buckets with linked lists
    def initBuckets(self, n):
        self.buckets = [LinkedList() for i in range(n)] # Create an array of linked lists
        for i in range(n):
            self.buckets[i] = LinkedList() # Initialize each bucket as a new linked list

    # Method to add a key-value pair to the hash map
    def put(self, key, value):
        bucketIndex = self.hashFunction(key) # Get the index of the bucket for the key
        nodes = self.buckets[bucketIndex] # Get the linked list at that bucket
        # Check if the key already exists in the bucket
        for node in nodes:
            if node.key == key:
                node.value = value # Update the value if the key exists
                return
        # Add a new node if the key does not exist
        nodes.add(Node(key, value))
        self.size += 1 # Increment the size of the hash map
        # Check load factor and rehash if necessary
        if self.size / len(self.buckets) > 0.75:
            self.reHash() # Rehash if the load factor exceeds 0.75

    # Method to retrieve a value by key
    def get(self, key):
        bucketIndex = self.hashFunction(key) # Get the index of the bucket for the key
        nodes = self.buckets[bucketIndex] # Get the linked list at that bucket
        # Search for the key in the bucket
        for node in nodes:
            if node.key == key:
                return node.value # Return the value if the key is found
        return None # Return null if the key is not found

    # Method to remove a key-value pair from the hash map
    def remove(self, key):
        bucketIndex = self.hashFunction(key) # Get the index of the bucket for the key
        nodes = self.buckets[bucketIndex] # Get the linked list at that bucket
        target = None # Variable to hold the target node for removal
        # Search for the key in the bucket
        for node in nodes:
            if node.key == key:
                target = node # Found the target node
                break
        # Remove the target node if it exists
        if target!= None:
            nodes.remove(target) # Remove the node from the linked list
            self.size -= 1 # Decrement the size of the hash map

    # Method to check if a key exists in the hash map
    def containsKey(self, key):
        return self.get(key)!= None # Return true if the key is found, false otherwise

    # Method to get the current size of the hash map
    def size(self):
        return self.size # Return the size of the hash map

    # Method to convert the hash map to a string representation
    def __str__(self):
        builder = StringBuilder()
        builder.append("{") # Start of the string representation
        # Iterate through each bucket and its nodes
        for nodes in self.buckets:
            for node in nodes:
                builder.append(node.key).append(" : ").append(node.value).append(", ") # Append key-value pairs
        # Remove the trailing comma and space if there are any elements
        if builder.length() > 1:
            builder.setLength(builder.length() - 2)
        builder.append("}") # End of the string representation
        return builder.toString() # Return the string representation

    # Hash function to determine the bucket index for a given key
    def hashFunction(self, key):
        return key.hashCode() % len(self.buckets) # Return the index using modulo operation

    # Method to rehash the hash map when the load factor exceeds the threshold
    def reHash(self):
        oldBuckets = self.buckets # Store the old buckets
        self.initBuckets(len(oldBuckets) * 2) # Initialize new buckets with double the size
        self.size = 0 # Reset size to 0
        # Reinsert all nodes from old buckets into new buckets
        for nodes in oldBuckets:
            for node in nodes:
                self.put(node.key, node.value) # Reinsert each key-value pair

# Inner class to represent a key-value pair (node)
class Node:
    def __init__(self, key, value):
        self.key = key # Initialize key
        self.value = value # Initialize value

# Main method to run the hash map operations
if __name__ == "__main__":
    scanner = Scanner(System.in) # Create a scanner for input
    hashMap = Main() # Create a new instance of the hash map
    operations = scanner.nextInt() # Read the number of operations to perform
    scanner.nextLine() # Consume the newline character
    # Loop through the number of operations
    for i in range(operations):
        command = scanner.next() # Read the command
        if command == "PUT": # Handle PUT command
            key = scanner.next() # Read the key
            value = scanner.next() # Read the value
            hashMap.put(key, value) # Add the key-value pair to the hash map
        elif command == "GET": # Handle GET command
            key = scanner.next() # Read the key
            value = hashMap.get(key) # Retrieve the value
            print(value!= None? value : "NOT FOUND") # Print the value or "NOT FOUND"
        elif command == "REMOVE": # Handle REMOVE command
            key = scanner.next() # Read the key
            hashMap.remove(key) # Remove the key-value pair from the hash map
        elif command == "CONTAINS": # Handle CONTAINS command
            key = scanner.next() # Read the key
            print(hashMap.containsKey(key)? "YES" : "NO") # Print "YES" or "NO"
        elif command == "SIZE": # Handle SIZE command
            print(hashMap.size()) # Print the size of the hash map
        elif command == "PRINT": # Handle PRINT command
            print(hashMap) # Print the string representation of the hash map
        else:
            print("INVALID COMMAND") # Handle invalid commands
    scanner.close() # Close the scanner

