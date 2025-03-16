
import collections
import sys

# Initialize an empty hash map to store the data
data = {}

# Initialize head and tail pointers to null
head = None
tail = None

# Set the cache capacity
capacity = 0

# Define an inner static class for the cache entries
class Entry:
    # Initialize the previous and next pointers and the key-value pair
    preEntry = None
    nextEntry = None
    key = None
    value = None

    # Constructor initializes the entry with the given previous and next entries, key, and value
    def __init__(self, preEntry, nextEntry, key, value):
        self.preEntry = preEntry
        self.nextEntry = nextEntry
        self.key = key
        self.value = value

    # Get the previous entry
    def getPreEntry(self):
        return self.preEntry

    # Set the previous entry
    def setPreEntry(self, preEntry):
        self.preEntry = preEntry

    # Get the next entry
    def getNextEntry(self):
        return self.nextEntry

    # Set the next entry
    def setNextEntry(self, nextEntry):
        self.nextEntry = nextEntry

    # Get the key
    def getKey(self):
        return self.key

    # Get the value
    def getValue(self):
        return self.value

    # Set the value
    def setValue(self, value):
        self.value = value

# Initialize the cache with the given capacity
def __init__(self, capacity):
    if capacity <= 0: # Check if capacity is greater than 0
        raise Exception("Capacity must be greater than 0!")
    self.capacity = capacity

# Get the value associated with the given key
def get(self, key):
    if key not in data: # Check if the key is in the map
        return None
    entry = data[key] # Get the entry for the key
    moveEntryToLast(entry) # Move the entry to the last position
    return entry.getValue() # Return the value

# Add or update the value associated with the given key
def put(self, key, value):
    if key in data: # Check if the key already exists
        entry = data[key]
        entry.setValue(value) # Update the value
        moveEntryToLast(entry) # Move the entry to the last position
        return
    if len(data) == self.capacity: # Check if the cache is full
        del data[tail.getKey()] # Remove the least recently used entry
        remove(tail) # Remove the entry from the linked list
    entry = Entry(None, None, key, value) # Create a new entry
    addNewEntry(entry) # Add the entry to the linked list
    data[key] = entry # Add the entry to the hash map

# Move the given entry to the last position in the linked list
def moveEntryToLast(entry):
    if tail == entry: # If the entry is already at the last position, do nothing
        return
    remove(entry) # Remove the entry from its current position
    addNewEntry(entry) # Add the entry to the last position

# Remove the given entry from the linked list
def remove(entry):
    if entry.getPreEntry()!= None: # If the entry has a previous entry, update its next entry
        entry.getPreEntry().setNextEntry(entry.getNextEntry())
    else: # If the entry is the head, update the head
        head = entry.getNextEntry()
    if entry.getNextEntry()!= None: # If the entry has a next entry, update its previous entry
        entry.getNextEntry().setPreEntry(entry.getPreEntry())
    else: # If the entry is the tail, update the tail
        tail = entry.getPreEntry()

# Add the given entry to the last position in the linked list
def addNewEntry(entry):
    if tail!= None: # If there is a tail, add the new entry after it
        tail.setNextEntry(entry)
        entry.setPreEntry(tail)
    else: # If there is no tail, set the new entry as the head and tail
        head = tail = entry

# Main method reads input and calls the cache methods
def main():
    global capacity
    global data
    global head
    global tail
    capacity = int(sys.stdin.readline().strip()) # Read the cache capacity
    operations = int(sys.stdin.readline().strip()) # Read the number of operations
    mruCache = Main(capacity) # Create a new cache with the given capacity
    for i in range(operations): # Iterate through the operations
        operation = sys.stdin.readline().strip() # Read the operation type
        if operation == "PUT": # If the operation is a put, read the key and value and call put
            key = int(sys.stdin.readline().strip())
            value = sys.stdin.readline().strip()
            mruCache.put(key, value)
            print("Added: (" + str(key) + ", " + value + ")")
        elif operation == "GET": # If the operation is a get, read the key and call get
            key = int(sys.stdin.readline().strip())
            result = mruCache.get(key)
            print("Retrieved: " + (result!= None and result or "null"))

# Define the main method
if __name__ == "__main__":
    main()

