
class Main:
    # Initialize an empty hash map with a given capacity
    def __init__(self):
        self.buckets = [[] for _ in range(10)]
        self.size = 0

    # Put a key-value pair into the hash map
    def put(self, key, value):
        hash = abs(hash(key)) % len(self.buckets) # Calculate the hash code of the key and find the index of the bucket
        nodes = self.buckets[hash] # Get the linked list of the corresponding bucket

        for node in nodes: # Search for the existing node with the same key in the bucket
            if node[0] == key:
                node[1] = value # Update the value of the existing node
                return

        nodes.append([key, value]) # Add a new node to the bucket if the key is not found
        self.size += 1

        if self.size / len(self.buckets) > 0.5: # Check if the load factor exceeds 0.5 and resize the hash map if necessary
            self.reHash()

    # Resize the hash map and rehash all the key-value pairs
    def reHash(self):
        oldBuckets = self.buckets # Save the old hash map
        self.buckets = [[] for _ in range(len(oldBuckets) * 2)]
        self.size = 0

        for nodes in oldBuckets: # Transfer all the nodes from the old hash map to the new one
            for node in nodes:
                self.put(node[0], node[1])

    # Get the value of a key from the hash map
    def get(self, key):
        hash = abs(hash(key)) % len(self.buckets) # Calculate the hash code of the key and find the index of the bucket
        nodes = self.buckets[hash] # Get the linked list of the corresponding bucket

        for node in nodes: # Search for the node with the matching key in the bucket
            if node[0] == key:
                return node[1] # Return the value if found

        return None # Return null if not found

    # Remove a key-value pair from the hash map
    def remove(self, key):
        hash = abs(hash(key)) % len(self.buckets) # Calculate the hash code of the key and find the index of the bucket
        nodes = self.buckets[hash] # Get the linked list of the corresponding bucket

        target = None # Initialize a variable to store the target node to be removed

        for node in nodes: # Search for the node with the matching key in the bucket
            if node[0] == key:
                target = node # Set the target node
                break

        if target!= None: # Remove the target node if found
            nodes.remove(target)
            self.size -= 1

    # Check if a key exists in the hash map
    def containsKey(self, key):
        return self.get(key)!= None # Return true if the get method returns a non-null value

    # Get the current size of the hash map
    def size(self):
        return self.size

    # Override the toString method to print the hash map in a readable format
    def __str__(self):
        builder = []
        builder.append("{")

        for nodes in self.buckets: # Iterate through all the buckets and print their contents
            for node in nodes:
                builder.append(str(node[0])).append(" : ").append(str(node[1])).append(", ")

        if len(builder) > 1: # Remove the last comma and space if there are multiple buckets
            builder.pop()
            builder.pop()

        builder.append("}") # Add the curly braces to enclose the hash map
        return "".join(builder)

# Main method to read commands from the standard input and perform the corresponding operations
if __name__ == "__main__":
    map = Main() # Create a new instance of the hash map
    sc = Scanner(System.in) # Initialize a scanner to read commands from the standard input

    operations = int(sc.nextLine().strip()) # Read the number of operations

    for i in range(operations): # Perform each operation in the given order
        command = sc.nextLine().split(" ")
        if command[0].upper() == "PUT":
            map.put(command[1], command[2])
        elif command[0].upper() == "GET":
            value = map.get(command[1])
            print(value if value!= None else "NOT FOUND")
        elif command[0].upper() == "REMOVE":
            map.remove(command[1])
        elif command[0].upper() == "CONTAINS":
            print("YES" if map.containsKey(command[1]) else "NO")
        elif command[0].upper() == "SIZE":
            print(map.size())
        elif command[0].upper() == "PRINT":
            print(map)
        else:
            print("INVALID COMMAND")

    sc.close() # Close the scanner after all the operations are completed

