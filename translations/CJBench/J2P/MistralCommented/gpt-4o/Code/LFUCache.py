class Node:
    def __init__(self, key, value, frequency):
        self.key = key
        self.value = value
        self.frequency = frequency
        self.previous = None
        self.next = None


class LFUCache:
    def __init__(self, capacity):
        if capacity <= 0:
            raise ValueError("Capacity must be greater than zero.")
        self.capacity = capacity
        self.cache = {}
        self.head = None
        self.tail = None

    def get(self, key):
        node = self.cache.get(key)
        if node is None:
            return None
        self.remove_node(node)
        node.frequency += 1
        self.add_node_with_updated_frequency(node)
        return node.value

    def put(self, key, value):
        if key in self.cache:
            node = self.cache[key]
            node.value = value
            node.frequency += 1
            self.remove_node(node)
            self.add_node_with_updated_frequency(node)
        else:
            if len(self.cache) >= self.capacity:
                del self.cache[self.head.key]
                self.remove_node(self.head)
            node = Node(key, value, 1)
            self.add_node_with_updated_frequency(node)
            self.cache[key] = node

    def add_node_with_updated_frequency(self, node):
        if self.tail is not None and self.head is not None:
            temp = self.head
            while temp is not None:
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
        else:
            self.tail = node
            self.head = self.tail

    def remove_node(self, node):
        if node.previous is not None:
            node.previous.next = node.next
        else:
            self.head = node.next
        if node.next is not None:
            node.next.previous = node.previous
        else:
            self.tail = node.previous


if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    capacity = int(data[0])  # Read the capacity of the cache from the input
    operations = int(data[1])  # Read the number of operations from the input
    lfu_cache = LFUCache(capacity)  # Create a new instance of the LFUCache class with the given capacity
    
    for i in range(2, 2 + operations):
        operation = data[i].split()  # Read the operation type from the input
        if operation[0] == "PUT":
            key = int(operation[1])  # Read the key and value to be added or updated from the input
            value = operation[2]
            lfu_cache.put(key, value)  # Call the put method to add or update the key-value pair in the cache
            print(f"Added: ({key}, {value})")  # Print a message indicating that a key-value pair was added or updated
        elif operation[0] == "GET":
            key = int(operation[1])  # Read the key to be retrieved from the input
            result = lfu_cache.get(key)  # Call the get method to retrieve the value associated with the given key
            print(f"Retrieved: {result if result is not None else 'null'}")  # Print the retrieved value or a null message if the key was not found in the cache

# <END-OF-CODE>
