
class Main:

    # Declare instance variables
    hsize = 0
    keys = []
    values = []
    size = 0

    # Default constructor
    def __init__(self):
        self.hsize = 16

    # Constructor with specified size
    def __init__(self, size):
        self.hsize = size
        # Initialize keys and values arrays with specified size
        self.keys = [None] * size
        self.values = [None] * size

    # Put method to add a key-value pair to the hash map
    def put(self, key, value):
        if key == None:
            # Return false if key is null
            return False
        if self.size > self.hsize / 2:
            # If size is more than half of hash map size, resize the hash map
            self.resize(2 * self.hsize)
        keyIndex = self.hash(key, self.hsize)
        # Search for the index where the key already exists
        for i in range(keyIndex, self.hsize):
            if self.keys[i] == None:
                # If key doesn't exist, add it to the hash map and increment size
                self.keys[i] = key
                self.values[i] = value
                self.size += 1
                return True
            elif self.keys[i] == key:
                # If key already exists, update its value and return true
                self.values[i] = value
                return True
        # If key doesn't exist, add it to the hash map and increment size
        self.keys[keyIndex] = key
        self.values[keyIndex] = value
        self.size += 1
        return True

    # Get method to retrieve the value associated with a key
    def get(self, key):
        if key == None:
            # Return null if key is null
            return None
        for i in range(self.hash(key, self.hsize), self.hsize):
            if self.keys[i] == None:
                # If key is not found, return null
                return None
            elif self.keys[i] == key:
                # If key is found, return its value
                return self.values[i]
        # If key is not found, return null
        return None

    # Delete method to remove a key-value pair from the hash map
    def delete(self, key):
        if key == None or not self.contains(key):
            # Return false if key is null or not found in the hash map
            return False
        i = self.hash(key, self.hsize)
        # Find the index of the key in the hash map
        while self.keys[i]!= key:
            i = (i + 1) % self.hsize
        # Set keys and values at the index to null and increment i
        self.keys[i] = None
        self.values[i] = None
        i = (i + 1) % self.hsize
        # Rehash the deleted key and its corresponding value
        while self.keys[i]!= None:
            keyToRehash = self.keys[i]
            valToRehash = self.values[i]
            self.keys[i] = None
            self.values[i] = None
            self.size -= 1
            # Put the rehashed key-value pair back into the hash map
            self.put(keyToRehash, valToRehash)
            i = (i + 1) % self.hsize
        self.size -= 1
        # If size is less than or equal to one-eighth of the hash map size, resize it
        if self.size > 0 and self.size <= self.hsize / 8:
            self.resize(self.hsize / 2)
        # Return true if the key was successfully deleted
        return True

    # Check if a key exists in the hash map
    def contains(self, key):
        # Return true if the get method returns a non-null value
        return self.get(key)!= None

    # Get the size of the hash map
    def size(self):
        # Return the size instance variable
        return self.size

    # Get an iterable of all the keys in the hash map
    def keys(self):
        # Create an ArrayList to store the keys
        listOfKeys = []
        # Iterate through each index in the hash map and add the keys to the ArrayList
        for i in range(self.hsize):
            if self.keys[i]!= None:
                listOfKeys.append(self.keys[i])
        # Sort the keys in the ArrayList and return it
        listOfKeys.sort()
        return listOfKeys

    # Increment the index based on the hash map size
    def increment(self, i):
        return (i + 1) % self.hsize

    # Resize the hash map with a new size
    def resize(self, newSize):
        # Create a new Main object with the new size
        tmp = Main(newSize)
        # Iterate through each index in the old hash map and put the keys and values into the new hash map
        for i in range(self.hsize):
            if self.keys[i]!= None:
                tmp.put(self.keys[i], self.values[i])
        # Replace the old hash map instance variables with the new ones
        self.keys = tmp.keys
        self.values = tmp.values
        self.hsize = newSize

    # Hash a key based on its hash code and the hash map size
    def hash(self, key, size):
        return (key.hashCode() & 0x7fffffff) % size

# Main method to read input and perform hash map operations
if __name__ == "__main__":
    import sys
    import re
    # Read input from stdin
    lines = sys.stdin.read().splitlines()
    # The first line contains the initial size of the hash map
    initialSize = int(lines[0])
    # The second line contains the number of operations
    operations = int(lines[1])
    # Create a new Main object with the initial size
    hashMap = Main(initialSize)
    # Perform the specified number of operations
    for i in range(2, 2 + operations):
        # Split the input into an array of strings
        input = re.split("\s+", lines[i])
        command = input[0].upper()
        if command == "PUT":
            hashMap.put(input[1], input[2])
        elif command == "GET":
            value = hashMap.get(input[1])
            print(value if value!= None else "NOT FOUND")
        elif command == "DELETE":
            deleted = hashMap.delete(input[1])
            print("DELETED" if deleted else "NOT FOUND")
        elif command == "CONTAINS":
            print("YES" if hashMap.contains(input[1]) else "NO")
        elif command == "SIZE":
            print(hashMap.size())
        elif command == "KEYS":
            for key in hashMap.keys():
                print(key, end=" ")
            print()
        else:
            print("INVALID COMMAND")

