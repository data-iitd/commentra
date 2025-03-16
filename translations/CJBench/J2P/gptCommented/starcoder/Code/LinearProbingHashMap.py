
# <START-OF-CODE>

class Main:
    # Size of the hash table
    hsize = 0
    # Array to store keys
    keys = []
    # Array to store values
    values = []
    # Current number of elements in the hash table
    size = 0

    # Default constructor initializing with a default size
    def __init__(self):
        self.hsize = 16

    # Constructor that initializes the hash table with a specified size
    def __init__(self, size):
        self.hsize = size
        self.keys = [None] * size
        self.values = [None] * size

    # Method to insert a key-value pair into the hash table
    def put(self, key, value):
        # Return false if the key is null
        if key == None:
            return False
        # Resize the hash table if it is more than half full
        if self.size > self.hsize / 2:
            self.resize(2 * self.hsize)
        # Calculate the index for the key
        keyIndex = self.hash(key, self.hsize)
        # Handle collisions using linear probing
        for i in range(keyIndex, self.hsize):
            # Update the value if the key already exists
            if self.keys[i]!= None and self.keys[i] == key:
                self.values[i] = value
                return True
        # Insert the new key-value pair
        self.keys[keyIndex] = key
        self.values[keyIndex] = value
        self.size += 1
        return True

    # Method to retrieve a value associated with a key
    def get(self, key):
        # Return null if the key is null
        if key == None:
            return None
        # Search for the key using linear probing
        for i in range(self.hash(key, self.hsize), self.hsize):
            if self.keys[i]!= None and self.keys[i] == key:
                return self.values[i] # Return the associated value
        return None # Return null if the key is not found

    # Method to delete a key-value pair from the hash table
    def delete(self, key):
        # Return false if the key is null or does not exist
        if key == None or not self.contains(key):
            return False
        # Find the index of the key to be deleted
        i = self.hash(key, self.hsize)
        while self.keys[i]!= None and self.keys[i]!= key:
            i = (i + 1) % self.hsize
        # Remove the key and value
        self.keys[i] = None
        self.values[i] = None
        i = (i + 1) % self.hsize
        # Rehash the subsequent keys
        while self.keys[i]!= None:
            keyToRehash = self.keys[i]
            valueToRehash = self.values[i]
            self.keys[i] = None
            self.values[i] = None
            self.size -= 1
            self.put(keyToRehash, valueToRehash) # Reinsert the key-value pair
            i = (i + 1) % self.hsize
        self.size -= 1
        # Resize the hash table if it is less than one-eighth full
        if self.size > 0 and self.size <= self.hsize / 8:
            self.resize(self.hsize / 2)
        return True

    # Method to check if a key exists in the hash table
    def contains(self, key):
        return self.get(key)!= None

    # Method to return the current number of elements in the hash table
    def size(self):
        return self.size

    # Method to return an iterable collection of keys in the hash table
    def keys(self):
        listOfKeys = []
        for i in range(self.hsize):
            if self.keys[i]!= None:
                listOfKeys.append(self.keys[i]) # Add non-null keys to the list
        listOfKeys.sort() # Sort the keys
        return listOfKeys

    # Helper method to increment the index for linear probing
    def increment(self, i):
        return (i + 1) % self.hsize # Wrap around using modulo

    # Method to resize the hash table to a new size
    def resize(self, newSize):
        tmp = Main(newSize) # Create a new hash table
        for i in range(self.hsize):
            if self.keys[i]!= None:
                tmp.put(self.keys[i], self.values[i]) # Reinsert existing key-value pairs
        self.keys = tmp.keys # Update the keys array
        self.values = tmp.values # Update the values array
        self.hsize = newSize # Update the hash table size

    # Method to compute the hash index for a given key
    def hash(self, key, size):
        return (key.hashCode() & 0x7fffffff) % size # Ensure non-negative index

# Main method to run the program
if __name__ == "__main__":
    import sys
    scanner = sys.stdin
    initialSize = int(scanner.readline()) # Read initial size of the hash table
    hashMap = Main(initialSize) # Create a new hash map
    operations = int(scanner.readline()) # Read number of operations
    for i in range(operations):
        input = scanner.readline().split(" ")
        command = input[0].upper() # Read the command
        if command == "PUT":
            hashMap.put(input[1], input[2]) # Insert key-value pair
        elif command == "GET":
            value = hashMap.get(input[1]) # Retrieve value
            print(value!= None and value or "NOT FOUND")
        elif command == "DELETE":
            deleted = hashMap.delete(input[1]) # Delete key-value pair
            print(deleted and "DELETED" or "NOT FOUND")
        elif command == "CONTAINS":
            print(hashMap.contains(input[1]) and "YES" or "NO") # Check existence
        elif command == "SIZE":
            print(hashMap.size()) # Print current size
        elif command == "KEYS":
            for key in hashMap.keys():
                print(key, end=" ") # Print all keys
            print()
        else:
            print("INVALID COMMAND") # Handle invalid commands

# 