
class Main:
    # Dictionary to store the key-value pairs
    def __init__(self):
        self.map = {}
        self.size = 0 # Initialize size to 0

    # Method to add a key-value pair to the hash map
    def put(self, key, value):
        # Calculate the hash index for the key
        hash_index = abs(hash(key)) % 10
        if key in self.map:
            self.map[key] = value # Update the value if the key already exists
        else:
            self.map[key] = value
            self.size += 1 # Increment the size of the hash map
        
        # Check load factor and rehash if necessary
        if self.size / len(self.map) > 0.5:
            self.rehash()

    # Method to rehash the hash map when the load factor exceeds 0.5
    def rehash(self):
        # Store the old map for rehashing
        old_map = self.map
        self.map = {}
        self.size = 0 # Reset size for the new map
        
        # Create new map with double the size
        for i in range(20):
            self.map[i] = []
        
        # Reinsert all nodes from the old map into the new map
        for key, value in old_map.items():
            self.put(key, value)

    # Method to retrieve a value by its key
    def get(self, key):
        # Calculate the hash index for the key
        hash_index = abs(hash(key)) % 10
        if key in self.map:
            return self.map[key] # Return the value if the key is found
        return None # Return None if the key is not found

    # Method to remove a key-value pair from the hash map
    def remove(self, key):
        # Calculate the hash index for the key
        hash_index = abs(hash(key)) % 10
        if key in self.map:
            del self.map[key]
            self.size -= 1 # Decrement the size of the hash map

    # Method to check if a key exists in the hash map
    def containsKey(self, key):
        return key in self.map # Return true if the key is found

    # Method to get the current size of the hash map
    def size(self):
        return self.size # Return the size

    # Override __str__ method to provide a string representation of the hash map
    def __str__(self):
        result = "{"
        for key, value in self.map.items():
            result += str(key) + " : " + str(value) + ", "
        # Remove the trailing comma and space if there are any elements
        if len(result) > 1:
            result = result[:-2]
        result += "}"
        return result # Return the constructed string

# Main method to execute the program
if __name__ == "__main__":
    map = Main() # Create a new hash map
    operations = int(input().strip()) # Read number of operations
    
    # Process each operation based on user input
    for i in range(operations):
        command = input().strip().split(" ")
        if command[0].upper() == "PUT":
            map.put(command[1], command[2]) # Add key-value pair
        elif command[0].upper() == "GET":
            value = map.get(command[1]) # Retrieve value by key
            print(value if value is not None else "NOT FOUND") # Print result
        elif command[0].upper() == "REMOVE":
            map.remove(command[1]) # Remove key-value pair
        elif command[0].upper() == "CONTAINS":
            print("YES" if map.containsKey(command[1]) else "NO") # Check if key exists
        elif command[0].upper() == "SIZE":
            print(map.size()) # Print the size of the hash map
        elif command[0].upper() == "PRINT":
            print(map) # Print the entire hash map
        else:
            print("INVALID COMMAND") # Handle invalid commands