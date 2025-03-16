import collections

class Main:
    # Map to store the key-value pairs and maintain the order of access
    data = collections.OrderedDict()
    # Pointers to the head and tail of the doubly linked list
    head = None
    tail = None
    # Maximum capacity of the cache
    capacity = 0

    # Constructor to initialize the cache with a specified capacity
    def __init__(self, capacity):
        if capacity <= 0:
            raise Exception("Capacity must be greater than 0.")
        self.capacity = capacity

    # Method to retrieve a value by key
    def get(self, key):
        # Return null if the key does not exist
        if key not in self.data:
            return None
        # Get the entry and move it to the end (most recently used)
        entry = self.data[key]
        self.moveToLast(entry)
        return entry.value

    # Method to add or update a key-value pair in the cache
    def put(self, key, value):
        # If the key already exists, update its value and move it to the end
        if key in self.data:
            entry = self.data[key]
            entry.value = value
            self.moveToLast(entry)
            return
        # If the cache is at capacity, remove the least recently used entry
        if len(self.data) == self.capacity:
            self.data.popitem(last=False)
        # Create a new entry and add it to the cache
        entry = Entry(key, value)
        self.addLast(entry)
        self.data[key] = entry

    # Helper method to move an entry to the end of the linked list
    def moveToLast(self, entry):
        # If the entry is already the tail, do nothing
        if entry == self.tail:
            return
        # Remove the entry from its current position and add it to the end
        self.remove(entry)
        self.addLast(entry)

    # Helper method to remove an entry from the linked list
    def remove(self, entry):
        # Update the previous entry's next pointer
        if entry.prev!= None:
            entry.prev.next = entry.next
        else:
            self.head = entry.next # Update head if removing the first entry
        # Update the next entry's previous pointer
        if entry.next!= None:
            entry.next.prev = entry.prev
        else:
            self.tail = entry.prev # Update tail if removing the last entry

    # Helper method to add an entry to the end of the linked list
    def addLast(self, entry):
        # Link the new entry to the current tail
        if self.tail!= None:
            self.tail.next = entry
            entry.prev = self.tail
        self.tail = entry # Update the tail to the new entry
        # If the list was empty, set the head to the new entry
        if self.head == None:
            self.head = self.tail

    # Inner class representing an entry in the cache
    class Entry:
        key = None # Key of the entry
        value = None # Value of the entry
        prev = None # Pointer to the previous entry
        next = None # Pointer to the next entry

        # Constructor to create a new entry
        def __init__(self, key, value):
            self.key = key
            self.value = value

# Main method to run the cache operations
if __name__ == "__main__":
    # Read the capacity of the cache
    capacity = int(input())
    # Read the number of operations to perform
    operations = int(input())
    # Create an instance of the LRU cache
    lruCache = Main(capacity)
    
    # Process each operation
    for i in range(operations):
        operation = input()
        if operation.upper() == "PUT":
            # Read key and value for PUT operation
            key = int(input())
            value = input()
            lruCache.put(key, value)
            print("Added: (" + str(key) + ", " + value + ")")
        elif operation.upper() == "GET":
            # Read key for GET operation
            key = int(input())
            result = lruCache.get(key)
            print("Retrieved: " + (result!= None and result or "null"))

