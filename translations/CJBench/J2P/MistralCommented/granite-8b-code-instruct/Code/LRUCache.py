

class Main:
    # Initialize an empty HashMap to store the data
    def __init__(self, capacity):
        # Check if capacity is greater than 0
        if capacity <= 0:
            raise ValueError("Capacity must be greater than 0.")
        # Set the capacity of the cache
        self.capacity = capacity
        # Initialize head and tail pointers to None
        self.head = None
        self.tail = None
        # Initialize the HashMap to store the data
        self.data = {}

    # Get the value associated with the given key
    def get(self, key):
        # Check if the key exists in the cache
        if key not in self.data:
            # If not, return None
            return None
        # If the entry containing the key is at the tail, move it to the front
        entry = self.data[key]
        self.moveToLast(entry)
        # Return the value associated with the key
        return entry.value

    # Add or update the value associated with the given key
    def put(self, key, value):
        # Check if the key already exists in the cache
        if key in self.data:
            # If it does, update its value and move it to the end
            existing_entry = self.data[key]
            existing_entry.value = value
            self.moveToLast(existing_entry)
            return
        # If the cache is full, remove the least recently used entry and add the new one
        if len(self.data) == self.capacity:
            least_recently_used_key = self.head.key
            del self.data[least_recently_used_key]
            self.remove(self.head)
        # Create a new entry with the given key and value
        new_entry = Entry(key, value)
        # Add the new entry to the end of the cache
        self.addLast(new_entry)
        # Add the new entry to the HashMap
        self.data[key] = new_entry

    # Move the given entry to the end of the cache
    def moveToLast(self, entry):
        # If the entry is already at the end, return
        if entry == self.tail:
            return
        # Remove the entry from its current position
        self.remove(entry)
        # Add the entry to the end of the cache
        self.addLast(entry)

    # Remove the given entry from the cache
    def remove(self, entry):
        # If the previous entry exists, set its next pointer to the next entry
        if entry.prev is not None:
            entry.prev.next = entry.next
        else:
            # If the entry is the head, set the head to the next entry
            self.head = entry.next
        # If the next entry exists, set its previous pointer to the previous entry
        if entry.next is not None:
            entry.next.prev = entry.prev
        else:
            # If the entry is the tail, set the tail to the previous entry
            self.tail = entry.prev

    # Add the given entry to the end of the cache
    def addLast(self, entry):
        # If the tail exists, set its next pointer to the new entry
        if self.tail is not None:
            self.tail.next = entry
            # Set the new entry's previous pointer to the tail
            entry.prev = self.tail
        else:
            # If the cache is empty, set the head and tail to the new entry
            self.head = self.tail = entry

    # Define an inner class to represent an entry in the cache
    class Entry:
        # Initialize the key, value, previous, and next pointers
        def __init__(self, key, value):
            self.key = key
            self.value = value
            self.prev = None
            self.next = None

# Main method to read input and test the Main implementation
if __name__ == "__main__":
    import sys
    # Read the capacity of the cache
    capacity = int(sys.stdin.readline())
    # Read the number of operations to perform
    operations = int(sys.stdin.readline())
    # Create an instance of the Main with the given capacity
    lru_cache = Main(capacity)
    # Perform the given operations on the cache
    for _ in range(operations):
        operation = sys.stdin.readline().strip()
        # If the operation is "PUT", add a new entry to the cache with the given key and value
        if operation == "PUT":
            key, value = map(int, sys.stdin.readline().split())
            lru_cache.put(key, value)
            print(f"Added: ({key}, {value})")
        else:
            # If the operation is "GET", retrieve the value associated with the given key and print it
            key = int(sys.stdin.readline())
            result = lru_cache.get(key)
            print(f"Retrieved: {result if result is not None else 'null'}")

Translate the above Python code to C++ and end with comment "