class Node:
    def __init__(self, key, value):
        self.key = key  # Key of the node
        self.value = value  # Value of the node
        self.next = None  # Reference to the next node

class LinkedList:
    def __init__(self):
        self.head = None  # Head of the linked list

    def insert(self, key, value):
        existing_node = self.find_key(key)  # Check if key already exists
        if existing_node is not None:
            existing_node.value = value  # Update value if key exists
            return False  # Return false as no new node was added
        # Create a new node and insert it at the head
        new_node = Node(key, value)
        new_node.next = self.head
        self.head = new_node
        return True  # Return true as a new node was added

    def delete(self, key):
        if self.head is None:
            return False  # Return false if the list is empty
        # Check if the head needs to be removed
        if (key is None and self.head.key is None) or (self.head.key is not None and self.head.key == key):
            self.head = self.head.next  # Remove the head
            return True  # Return true as the key was found and removed
        # Traverse the list to find the key
        current = self.head
        while current.next is not None:
            if (key is None and current.next.key is None) or (current.next.key is not None and current.next.key == key):
                current.next = current.next.next  # Remove the node
                return True  # Return true as the key was found and removed
            current = current.next  # Move to the next node
        return False  # Return false if the key was not found

    def find_key(self, key):
        current = self.head  # Start from the head
        while current is not None:
            # Check if the current node's key matches the search key
            if (key is None and current.key is None) or (current.key is not None and current.key == key):
                return current  # Return the found node
            current = current.next  # Move to the next node
        return None  # Return null if the key was not found

    def display(self):
        elements = []
        current = self.head  # Start from the head
        while current is not None:
            elements.append(f"{current.key}={current.value}")  # Append key-value pair
            current = current.next  # Move to the next node
        return " -> ".join(elements) if elements else "null"  # Return the string representation or "null" if empty

class HashTable:
    def __init__(self, hash_size):
        self.hash_size = hash_size  # Size of the hash table
        self.buckets = [LinkedList() for _ in range(hash_size)]  # Initialize each bucket as a new LinkedList
        self.size = 0  # Initialize size to zero

    def compute_hash(self, key):
        if key is None:
            return 0  # Handle null keys
        hash_index = hash(key) % self.hash_size  # Compute hash code
        return hash_index if hash_index >= 0 else hash_index + self.hash_size  # Ensure non-negative index

    def insert(self, key, value):
        hash_index = self.compute_hash(key)  # Compute the hash index
        if self.buckets[hash_index].insert(key, value):  # Insert the key-value pair into the corresponding bucket
            self.size += 1  # Increment size if insertion was successful

    def delete(self, key):
        hash_index = self.compute_hash(key)  # Compute the hash index
        if self.buckets[hash_index].delete(key):  # Delete the key from the corresponding bucket
            self.size -= 1  # Decrement size if deletion was successful

    def search(self, key):
        hash_index = self.compute_hash(key)  # Compute the hash index
        node = self.buckets[hash_index].find_key(key)  # Find the node in the bucket
        return node.value if node is not None else None  # Return value or None if not found

    def display(self):
        for i in range(self.hash_size):
            print(f"Bucket {i}: {self.buckets[i].display()}")  # Display all key-value pairs in the hash table

    def current_size(self):
        return self.size  # Return the number of elements

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    hash_size = int(data[0])  # Read the size of the hash table
    hash_map = HashTable(hash_size)  # Create a new hash table
    operations = int(data[1])  # Read the number of operations

    # Perform operations based on user input
    for i in range(2, 2 + operations):
        input_line = data[i].split()  # Read the operation and its arguments
        operation = input_line[0]
        if operation == "PUT":
            hash_map.insert(input_line[1], input_line[2])  # Insert key-value pair
        elif operation == "GET":
            value = hash_map.search(input_line[1])  # Search for the value
            print(value if value is not None else "NOT FOUND")  # Print the result
        elif operation == "REMOVE":
            hash_map.delete(input_line[1])  # Remove the key
        elif operation == "CONTAINS":
            print("YES" if hash_map.search(input_line[1]) is not None else "NO")  # Check if key exists
        elif operation == "SIZE":
            print(hash_map.current_size())  # Print the current size
        elif operation == "PRINT":
            hash_map.display()  # Display all key-value pairs
        else:
            print("Invalid operation")  # Handle invalid operations
# <END-OF-CODE>
