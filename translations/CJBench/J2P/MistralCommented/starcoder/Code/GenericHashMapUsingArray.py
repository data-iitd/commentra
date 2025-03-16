import java.util.LinkedList;
import java.util.Scanner;

# Class definition for the main class
class Main:

    # Declare instance variables
    size = 0
    buckets = None

    # Constructor for the Main class
    def __init__(self):
        self.initBuckets(16) # Initialize the buckets with a capacity of 16

    # Method to initialize the buckets with the given capacity
    def initBuckets(self, n):
        self.buckets = [LinkedList() for i in range(n)] # Create an array of LinkedLists with the given capacity

    # Method to put a key-value pair in the hash map
    def put(self, key, value):
        bucketIndex = self.hashFunction(key) # Calculate the index of the bucket where the key should be stored
        nodes = self.buckets[bucketIndex] # Get the LinkedList for the corresponding bucket

        # Search for the existing node with the same key
        for node in nodes:
            if node.key == key:
                node.value = value # If found, update the value of the existing node
                return

        # If the key is not found, add a new node to the bucket
        nodes.add(Node(key, value))
        self.size += 1

        # Check if the load factor exceeds 0.75 and resize the hash map if necessary
        if self.size / len(self.buckets) > 0.75:
            self.reHash()

    # Method to get the value associated with the given key
    def get(self, key):
        bucketIndex = self.hashFunction(key)
        nodes = self.buckets[bucketIndex]

        # Search for the node with the given key in the bucket
        for node in nodes:
            if node.key == key:
                return node.value

        # If the key is not found, return null
        return None

    # Method to remove a key-value pair from the hash map
    def remove(self, key):
        bucketIndex = self.hashFunction(key)
        nodes = self.buckets[bucketIndex]
        target = None

        # Search for the node with the given key in the bucket
        for node in nodes:
            if node.key == key:
                target = node
                break

        # If the node is found, remove it from the bucket and decrease the size
        if target!= None:
            nodes.remove(target)
            self.size -= 1

    # Method to check if the hash map contains a given key
    def containsKey(self, key):
        return self.get(key)!= None

    # Method to get the current size of the hash map
    def size(self):
        return self.size

    # Method to print the contents of the hash map in a readable format
    def __str__(self):
        builder = ""
        builder += "{"

        # Iterate through each bucket and add its contents to the StringBuilder
        for nodes in self.buckets:
            for node in nodes:
                builder += str(node.key) + " : " + str(node.value) + ", "

        # Remove the trailing comma and space if there are any
        if builder.length() > 1:
            builder = builder[:-2]

        # Close the curly braces and return the StringBuilder as a string
        builder += "}"
        return builder

    # Method to calculate the hash code for a given key and determine the index of the bucket
    def hashFunction(self, key):
        return key.hashCode() % len(self.buckets)

    # Method to resize the hash map when the load factor exceeds 0.75
    def reHash(self):
        oldBuckets = self.buckets # Save a reference to the old buckets
        self.initBuckets(len(oldBuckets) * 2) # Initialize new buckets with double the capacity
        self.size = 0 # Reset the size to 0

        # Iterate through each node in the old buckets and put it in the new hash map
        for nodes in oldBuckets:
            for node in nodes:
                self.put(node.key, node.value)

# Inner class definition for a Node with a key and a value
class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value

# Main method to run the hash map implementation
if __name__ == "__main__":
    scanner = Scanner(System.in) # Create a Scanner to read input from the console
    hashMap = Main() # Create an instance of the Main class

    operations = scanner.nextInt() # Read the number of operations from the input
    scanner.nextLine() # Consume the newline character

    # Process each operation in the input
    for i in range(operations):
        command = scanner.next() # Read the command from the input
        if command == "PUT": # Handle the PUT command
            key = scanner.next()
            value = scanner.next()
            hashMap.put(key, value)
        elif command == "GET": # Handle the GET command
            key = scanner.next()
            value = hashMap.get(key)
            print(value if value!= None else "NOT FOUND")
        elif command == "REMOVE": # Handle the REMOVE command
            key = scanner.next()
            hashMap.remove(key)
        elif command == "CONTAINS": # Handle the CONTAINS command
            key = scanner.next()
            print("YES" if hashMap.containsKey(key) else "NO")
        elif command == "SIZE": # Handle the SIZE command
            print(hashMap.size())
        elif command == "PRINT": # Handle the PRINT command
            print(hashMap)
        else:
            print("INVALID COMMAND") # Handle invalid commands

    scanner.close() # Close the Scanner when finished

