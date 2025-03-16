class Node:
    def __init__(self, key, value, frequency):
        self.key = key  # Key of the cache entry
        self.value = value  # Value of the cache entry
        self.frequency = frequency  # Access frequency of the cache entry
        self.previous = None  # Pointer to the previous node in the linked list
        self.next = None  # Pointer to the next node in the linked list


class LFUCache:
    def __init__(self, capacity):
        if capacity <= 0:
            raise ValueError("Capacity must be greater than zero.")
        self.capacity = capacity  # Maximum capacity of the cache
        self.cache = {}  # Dictionary to store key-node pairs for quick access
        self.head = None  # Head of the doubly linked list
        self.tail = None  # Tail of the doubly linked list

    def get(self, key):
        node = self.cache.get(key)  # Get the node associated with the key
        if node is None:
            return None  # Return None if the key is not found
        self.remove_node(node)  # Remove the node from its current position
        node.frequency += 1  # Increment the frequency of access
        self.add_node_with_updated_frequency(node)  # Reinsert the node based on updated frequency
        return node.value  # Return the value of the node

    def put(self, key, value):
        if key in self.cache:  # Check if the key already exists
            node = self.cache[key]  # Get the existing node
            node.value = value  # Update the value
            node.frequency += 1  # Increment the frequency
            self.remove_node(node)  # Remove the node from its current position
            self.add_node_with_updated_frequency(node)  # Reinsert the node based on updated frequency
        else:
            # If the cache is at capacity, remove the least frequently used node
            if len(self.cache) >= self.capacity:
                del self.cache[self.head.key]  # Remove the head node from the cache
                self.remove_node(self.head)  # Remove the head node from the linked list
            # Create a new node for the new key-value pair
            node = Node(key, value, 1)
            self.add_node_with_updated_frequency(node)  # Add the new node to the linked list
            self.cache[key] = node  # Add the new node to the cache

    def add_node_with_updated_frequency(self, node):
        if self.tail is not None and self.head is not None:  # Check if the list is not empty
            temp = self.head  # Start from the head of the list
            while temp is not None:
                # Find the correct position based on frequency
                if temp.frequency > node.frequency:
                    if temp == self.head:
                        # If the node is to be added at the head
                        node.next = temp
                        temp.previous = node
                        self.head = node  # Update head to new node
                        break
                    else:
                        # Insert the node in the middle of the list
                        node.next = temp
                        node.previous = temp.previous
                        temp.previous.next = node
                        temp.previous = node
                        break
                else:
                    temp = temp.next  # Move to the next node
                    if temp is None:
                        # If reached the end of the list, add to the tail
                        self.tail.next = node
                        node.previous = self.tail
                        node.next = None
                        self.tail = node  # Update tail to new node
                        break
        else:
            # If the list is empty, set head and tail to the new node
            self.tail = node
            self.head = self.tail

    def remove_node(self, node):
        if node.previous is not None:
            node.previous.next = node.next  # Bypass the node to remove it
        else:
            self.head = node.next  # Update head if removing the head node
        if node.next is not None:
            node.next.previous = node.previous  # Bypass the node to remove it
        else:
            self.tail = node.previous  # Update tail if removing the tail node


if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    capacity = int(data[0])  # Read the capacity of the cache
    operations = int(data[1])  # Read the number of operations to perform
    lfu_cache = LFUCache(capacity)  # Create an instance of LFU Cache

    # Loop through the operations
    for i in range(2, 2 + operations):
        operation = data[i].split()  # Read the operation type (PUT or GET)
        if operation[0] == "PUT":
            key = int(operation[1])  # Read the key for PUT operation
            value = operation[2]  # Read the value for PUT operation
            lfu_cache.put(key, value)  # Add the key-value pair to the cache
            print(f"Added: ({key}, {value})")
        elif operation[0] == "GET":
            key = int(operation[1])  # Read the key for GET operation
            result = lfu_cache.get(key)  # Retrieve the value from the cache
            print(f"Retrieved: {result if result is not None else 'null'}")  # Print the result

# <END-OF-CODE>
