
class Main:
    # Class to represent a key-value pair (node) in the hash map
    class Node:
        def __init__(self, key, val):
            self.key = key
            self.val = val

    # Constructor to initialize the hash map with 10 buckets
    def __init__(self):
        self.buckets = [[] for _ in range(10)]
        self.size = 0

    # Method to add a key-value pair to the hash map
    def put(self, key, val):
        # Calculate the hash index for the key
        hash = abs(hash(key)) % len(self.buckets)
        nodes = self.buckets[hash]

        # Check if the key already exists, and update the value if it does
        for node in nodes:
            if node.key == key:
                node.val = val
                return

        # If the key does not exist, add a new node with the key-value pair
        nodes.append(self.Node(key, val))
        self.size += 1

        # Check load factor and rehash if necessary
        if self.size / len(self.buckets) > 0.5:
            self.reHash()

    # Method to rehash the hash map when the load factor exceeds 0.5
    def reHash(self):
        # Store the old buckets for rehashing
        oldBuckets = self.buckets
        self.buckets = [[] for _ in range(len(oldBuckets) * 2)]
        self.size = 0

        # Reinsert all nodes from the old buckets into the new buckets
        for nodes in oldBuckets:
            for node in nodes:
                self.put(node.key, node.val)

    # Method to retrieve a value by its key
    def get(self, key):
        # Calculate the hash index for the key
        hash = abs(hash(key)) % len(self.buckets)
        nodes = self.buckets[hash]

        # Search for the key in the corresponding bucket
        for node in nodes:
            if node.key == key:
                return node.val

        return None

    # Method to remove a key-value pair from the hash map
    def remove(self, key):
        # Calculate the hash index for the key
        hash = abs(hash(key)) % len(self.buckets)
        nodes = self.buckets[hash]
        target = None

        # Search for the key in the corresponding bucket
        for node in nodes:
            if node.key == key:
                target = node
                break

        # Remove the node if it was found
        if target!= None:
            nodes.remove(target)
            self.size -= 1

    # Method to check if a key exists in the hash map
    def containsKey(self, key):
        return self.get(key)!= None

    # Method to get the current size of the hash map
    def size(self):
        return self.size

    # Override toString method to provide a string representation of the hash map
    def __str__(self):
        builder = []
        builder.append("{")

        # Iterate through each bucket and append key-value pairs to the string
        for nodes in self.buckets:
            for node in nodes:
                builder.append(node.key).append(" : ").append(node.val).append(", ")

        # Remove the trailing comma and space if there are any elements
        if len(builder) > 1:
            builder.pop()
            builder.pop()
        builder.append("}")
        return "".join(builder)


# Main method to execute the program
if __name__ == "__main__":
    map = Main() # Create a new hash map
    sc = Scanner(System.in) # Create a scanner for input
    operations = Integer.parseInt(sc.nextLine().trim()) # Read number of operations

    # Process each operation based on user input
    for i in range(operations):
        command = sc.nextLine().split(" ")
        if command[0].toUpperCase() == "PUT":
            map.put(command[1], command[2]) # Add key-value pair
        elif command[0].toUpperCase() == "GET":
            value = map.get(command[1]) # Retrieve value by key
            print(value!= None? value : "NOT FOUND") # Print result
        elif command[0].toUpperCase() == "REMOVE":
            map.remove(command[1]) # Remove key-value pair
        elif command[0].toUpperCase() == "CONTAINS":
            print(map.containsKey(command[1])? "YES" : "NO") # Check if key exists
        elif command[0].toUpperCase() == "SIZE":
            print(map.size()) # Print the size of the hash map
        elif command[0].toUpperCase() == "PRINT":
            print(map) # Print the entire hash map
        else:
            print("INVALID COMMAND") # Handle invalid commands
    sc.close() # Close the scanner

