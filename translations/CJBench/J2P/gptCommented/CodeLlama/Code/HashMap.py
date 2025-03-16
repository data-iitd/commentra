
# Import the Scanner class from the java.util package
from java.util import Scanner

# Define the Main class
class Main:
    # Define the hash table size
    hashSize = 0
    # Define the array of linked lists to handle collisions
    buckets = []
    # Define the current number of elements in the hash table
    size = 0

    # Constructor to initialize the hash table with a given size
    def __init__(self, hashSize):
        self.hashSize = hashSize
        # Initialize each bucket as a new LinkedList
        for i in range(hashSize):
            self.buckets.append(LinkedList())
        self.size = 0 # Initialize size to zero

    # Method to compute the hash index for a given key
    def computeHash(self, key):
        if key is None:
            return 0 # Handle null keys
        hash = hash(key) % self.hashSize # Compute hash code
        return hash if hash >= 0 else hash + self.hashSize # Ensure non-negative index

    # Method to insert a key-value pair into the hash table
    def insert(self, key, value):
        hash = self.computeHash(key) # Compute the hash index
        # Insert the key-value pair into the corresponding bucket
        if self.buckets[hash].insert(key, value):
            self.size += 1 # Increment size if insertion was successful

    # Method to delete a key-value pair from the hash table
    def delete(self, key):
        hash = self.computeHash(key) # Compute the hash index
        # Delete the key from the corresponding bucket
        if self.buckets[hash].delete(key):
            self.size -= 1 # Decrement size if deletion was successful

    # Method to search for a value by its key
    def search(self, key):
        hash = self.computeHash(key) # Compute the hash index
        node = self.buckets[hash].findKey(key) # Find the node in the bucket
        return node.getValue() if node is not None else None # Return value or None if not found

    # Method to display all key-value pairs in the hash table
    def display(self):
        for i in range(self.hashSize):
            print(f"Bucket {i}: {self.buckets[i].display()}")

    # Method to get the current size of the hash table
    def size(self):
        return self.size # Return the number of elements

# Inner class representing a linked list to handle collisions
class LinkedList:
    # Define the head of the linked list
    head = None

    # Method to insert a key-value pair into the linked list
    def insert(self, key, value):
        existingNode = self.findKey(key) # Check if key already exists
        if existingNode is not None:
            existingNode.setValue(value) # Update value if key exists
            return False # Return False as no new node was added
        # Create a new node and insert it at the head
        newNode = Node(key, value)
        newNode.setNext(self.head)
        self.head = newNode
        return True # Return True as a new node was added

    # Method to delete a key from the linked list
    def delete(self, key):
        if self.head is None:
            return False # Return False if the list is empty
        # Check if the head needs to be removed
        if (key is None and self.head.getKey() is None) or (self.head.getKey() is not None and self.head.getKey().equals(key)):
            self.head = self.head.getNext() # Remove the head
            return True # Return True as the key was found and removed
        # Traverse the list to find the key
        current = self.head
        while current.getNext() is not None:
            if (key is None and current.getNext().getKey() is None) or (current.getNext().getKey() is not None and current.getNext().getKey().equals(key)):
                current.setNext(current.getNext().getNext()) # Remove the node
                return True # Return True as the key was found and removed
            current = current.getNext() # Move to the next node
        return False # Return False if the key was not found

    # Method to find a node by its key
    def findKey(self, key):
        current = self.head # Start from the head
        while current is not None:
            # Check if the current node's key matches the search key
            if (key is None and current.getKey() is None) or (current.getKey() is not None and current.getKey().equals(key)):
                return current # Return the found node
            current = current.getNext() # Move to the next node
        return None # Return None if the key was not found

    # Method to display all key-value pairs in the linked list
    def display(self):
        sb = "" # Initialize an empty string
        current = self.head # Start from the head
        while current is not None:
            sb += str(current.getKey()) + "=" + str(current.getValue()) # Append key-value pair
            current = current.getNext() # Move to the next node
            if current is not None:
                sb += " -> " # Append arrow if there are more nodes
        return sb # Return the string representation or "null" if empty

# Inner class representing a node in the linked list
class Node:
    # Define the key of the node
    key = None
    # Define the value of the node
    value = None
    # Define the reference to the next node
    next = None

    # Constructor to create a new node
    def __init__(self, key, value):
        self.key = key
        self.value = value

    # Getter for the key
    def getKey(self):
        return self.key

    # Getter for the value
    def getValue(self):
        return self.value

    # Setter for the value
    def setValue(self, value):
        self.value = value

    # Getter for the next node
    def getNext(self):
        return self.next

    # Setter for the next node
    def setNext(self, next):
        self.next = next

# Main method to run the hash table operations
def main():
    scanner = Scanner(System.in) # Create a new scanner to read input from the command line
    hashSize = scanner.nextInt() # Read the size of the hash table
    hashMap = Main(hashSize) # Create a new hash table
    operations = scanner.nextInt() # Read the number of operations
    scanner.nextLine() # Consume the newline character

    # Perform operations based on user input
    for i in range(operations):
        input = scanner.nextLine().split(" ") # Read the operation and its arguments
        if input[0] == "PUT":
            hashMap.insert(input[1], input[2]) # Insert key-value pair
        elif input[0] == "GET":
            value = hashMap.search(input[1]) # Search for the value
            print(value if value is not None else "NOT FOUND") # Print the result
        elif input[0] == "REMOVE":
            hashMap.delete(input[1]) # Remove the key
        elif input[0] == "CONTAINS":
            print("YES" if hashMap.search(input[1]) is not None else "NO") # Check if key exists
        elif input[0] == "SIZE":
            print(hashMap.size()) # Print the current size
        elif input[0] == "PRINT":
            hashMap.display() # Display all key-value pairs
        else:
            print("Invalid operation") # Handle invalid operations
    scanner.close() # Close the scanner

# End of code



