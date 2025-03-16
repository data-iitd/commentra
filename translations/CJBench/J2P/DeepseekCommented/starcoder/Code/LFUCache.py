import collections
import sys

# Represents a node in the LFU cache
class Node:
    def __init__(self, key, value, frequency):
        self.key = key
        self.value = value
        self.frequency = frequency
        self.previous = None
        self.next = None

# Represents the LFU cache
class LFUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.cache = {}
        self.head = None
        self.tail = None

    # Method to get the value associated with the key
    def get(self, key):
        if key in self.cache:
            node = self.cache[key]
            self.remove_node(node)
            node.frequency += 1
            self.add_node_with_updated_frequency(node)
            return node.value
        else:
            return None

    # Method to add or update a key-value pair in the cache
    def put(self, key, value):
        if key in self.cache:
            node = self.cache[key]
            node.value = value
            node.frequency += 1
            self.remove_node(node)
            self.add_node_with_updated_frequency(node)
        else:
            if len(self.cache) >= self.capacity:
                self.cache.pop(self.head.key)
                self.remove_node(self.head)
            node = Node(key, value, 1)
            self.add_node_with_updated_frequency(node)
            self.cache[key] = node

    # Method to add a node to the list based on its frequency
    def add_node_with_updated_frequency(self, node):
        if self.tail!= None and self.head!= None:
            temp = self.head
            while temp!= None:
                if temp.frequency > node.frequency:
                    if temp == self.head:
                        node.next = temp
                        temp.previous = node
                        self.head = node
                        break
                    else:
                        node.next = temp
                        node.previous = temp.previous
                        temp.previous.next = node
                        temp.previous = node
                        break
                else:
                    temp = temp.next
                    if temp == None:
                        self.tail.next = node
                        node.previous = self.tail
                        node.next = None
                        self.tail = node
                        break
        else:
            self.tail = node
            self.head = self.tail

    # Method to remove a node from the list
    def remove_node(self, node):
        if node.previous!= None:
            node.previous.next = node.next
        else:
            self.head = node.next
        if node.next!= None:
            node.next.previous = node.previous
        else:
            self.tail = node.previous

# Main method to read input and perform operations on the cache
if __name__ == "__main__":
    capacity = int(sys.stdin.readline().strip())
    operations = int(sys.stdin.readline().strip())
    lfuCache = LFUCache(capacity)
    for i in range(operations):
        operation = sys.stdin.readline().strip()
        if operation.startswith("PUT"):
            key, value = map(int, sys.stdin.readline().strip().split())
            lfuCache.put(key, value)
            print("Added: (" + str(key) + ", " + str(value) + ")")
        else:
            key = int(sys.stdin.readline().strip())
            result = lfuCache.get(key)
            print("Retrieved: " + (str(result) if result!= None else "null"))

