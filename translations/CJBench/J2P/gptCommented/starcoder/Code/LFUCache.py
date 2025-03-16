import collections
import sys

# Node class representing each entry in the cache
class Node:
    def __init__(self, key, value, frequency):
        self.key = key
        self.value = value
        self.frequency = frequency
        self.previous = None
        self.next = None

# LFU Cache class
class LFUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.cache = {}
        self.minFrequency = 0
        self.head = None
        self.tail = None

    # Method to retrieve a value by key from the cache
    def get(self, key):
        if key in self.cache:
            node = self.cache[key]
            self.removeNode(node)
            node.frequency += 1
            self.addNodeWithUpdatedFrequency(node)
            return node.value
        else:
            return None

    # Method to add or update a key-value pair in the cache
    def put(self, key, value):
        if self.capacity == 0:
            return
        if key in self.cache:
            node = self.cache[key]
            node.value = value
            self.removeNode(node)
            node.frequency += 1
            self.addNodeWithUpdatedFrequency(node)
        else:
            if len(self.cache) == self.capacity:
                self.cache.pop(self.head.key)
                self.removeNode(self.head)
            node = Node(key, value, 1)
            self.addNodeWithUpdatedFrequency(node)
            self.cache[key] = node

    # Method to add a node to the linked list based on its frequency
    def addNodeWithUpdatedFrequency(self, node):
        if self.tail!= None and self.head!= None:
            temp = self.head
            while temp!= None:
                if temp.frequency > node.frequency:
                    if temp == self.head:
                        # If the node is to be added at the head
                        node.next = temp
                        temp.previous = node
                        self.head = node
                        break
                    else:
                        # Insert the node in the middle of the list
                        node.next = temp
                        node.previous = temp.previous
                        temp.previous.next = node
                        temp.previous = node
                        break
                else:
                    temp = temp.next
                    if temp == None:
                        # If reached the end of the list, add to the tail
                        self.tail.next = node
                        node.previous = self.tail
                        node.next = None
                        self.tail = node
                        break
        else:
            # If the list is empty, set head and tail to the new node
            self.tail = node
            self.head = self.tail

    # Method to remove a node from the linked list
    def removeNode(self, node):
        if node.previous!= None:
            node.previous.next = node.next
        else:
            self.head = node.next
        if node.next!= None:
            node.next.previous = node.previous
        else:
            self.tail = node.previous

# Main method to run the LFU Cache operations
def main():
    capacity = int(sys.stdin.readline().strip()) # Read the capacity of the cache
    operations = int(sys.stdin.readline().strip()) # Read the number of operations to perform
    lfuCache = LFUCache(capacity) # Create an instance of LFU Cache

    # Loop through the operations
    for i in range(operations):
        operation = sys.stdin.readline().strip() # Read the operation type (PUT or GET)
        if operation.startswith("PUT"):
            key, value = operation.split(" ")[1].split(",") # Read the key and value for PUT operation
            lfuCache.put(int(key), value) # Add the key-value pair to the cache
            print("Added: (" + key + ", " + value + ")")
        else:
            key = operation.split(" ")[1] # Read the key for GET operation
            result = lfuCache.get(int(key)) # Retrieve the value from the cache
            print("Retrieved: " + (result!= None and result or "null")) # Print the result

if __name__ == "__main__":
    main()

