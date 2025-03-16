

class Main:
    # Constructor for the Main class with a given capacity
    def __init__(self, capacity):
        if capacity <= 0:
            raise ValueError("Capacity must be greater than zero.") # Throw a ValueError if capacity is not greater than zero
        self.capacity = capacity
        self.cache = {}
        self.head = None
        self.tail = None

    # Get method to retrieve the value associated with a given key
    def get(self, key):
        if key not in self.cache:
            return None
        node = self.cache[key]
        self.remove_node(node) # Remove the node from the list before updating its frequency
        node["frequency"] += 1 # Update the frequency of the node
        self.add_node_with_updated_frequency(node) # Add the node back to the list with its updated frequency
        return node["value"]

    # Put method to add or update a key-value pair in the cache
    def put(self, key, value):
        if key in self.cache:
            node = self.cache[key]
            node["value"] = value # Update the value of the existing node
            node["frequency"] += 1 # Increment the frequency of the existing node
            self.remove_node(node) # Remove the node from the list before adding it back with updated frequency
            self.add_node_with_updated_frequency(node) # Add the node back to the list with its updated frequency
        else:
            if len(self.cache) >= self.capacity:
                del self.cache[self.head["key"]] # Remove the least frequently used node from the cache
                self.remove_node(self.head) # Remove the node from the list
            node = {"key": key, "value": value, "frequency": 1} # Create a new node with the given key, value, and frequency of 1
            self.add_node_with_updated_frequency(node) # Add the new node to the list with its updated frequency
            self.cache[key] = node # Add the new node to the cache

    # Method to add a node to the list with its updated frequency
    def add_node_with_updated_frequency(self, node):
        if self.tail is not None and self.head is not None:
            temp = self.head # Initialize a temporary node to traverse the list
            while temp is not None:
                if temp["frequency"] > node["frequency"]: # Traverse the list to find the position to insert the new node
                    if temp == self.head:
                        node["next"] = temp
                        temp["previous"] = node
                        self.head = node
                        break
                    else:
                        node["next"] = temp
                        node["previous"] = temp["previous"]
                        temp["previous"]["next"] = node
                        temp["previous"] = node
                        break
                else:
                    temp = temp["next"] # Continue traversing the list if the current node's frequency is not greater than the new node's frequency
        else:
            self.tail = node # If the list is empty, set the new node as both the head and tail
            self.head = self.tail

    # Method to remove a node from the list
    def remove_node(self, node):
        if node["previous"] is not None:
            node["previous"]["next"] = node["next"] # Update the next pointer of the previous node
        else:
            self.head = node["next"] # Update the head if the removed node was the head
        if node["next"] is not None:
            node["next"]["previous"] = node["previous"] # Update the previous pointer of the next node
        else:
            self.tail = node["previous"] # Update the tail if the removed node was the tail

# Main method to read input and test the LFU cache implementation
if __name__ == "__main__":
    import sys
    capacity = int(sys.stdin.readline()) # Read the capacity of the cache from the input
    operations = int(sys.stdin.readline()) # Read the number of operations from the input
    lfu_cache = Main(capacity) # Create a new instance of the Main class with the given capacity
    for i in range(operations):
        operation = sys.stdin.readline().strip() # Read the operation type from the input
        if operation == "PUT":
            key, value = map(int, sys.stdin.readline().split()) # Read the key and value to be added or updated from the input
            lfu_cache.put(key, value) # Call the put method to add or update the key-value pair in the cache
            print("Added: ({}, {})".format(key, value)) # Print a message indicating that a key-value pair was added or updated
        else:
            key = int(sys.stdin.readline()) # Read the key to be retrieved from the input
            result = lfu_cache.get(key) # Call the get method to retrieve the value associated with the given key
            print("Retrieved: {}".format(result if result is not None else "null")) # Print the retrieved value or a null message if the key was not found in the cache

