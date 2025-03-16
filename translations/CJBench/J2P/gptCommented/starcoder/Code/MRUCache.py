import collections

class Main:
    # Map to store the key-value pairs along with their linked list entries
    data = {}
    # Pointers to the head and tail of the doubly linked list
    head = None
    tail = None
    # Maximum capacity of the cache
    capacity = 0

    # Constructor to initialize the cache with a specified capacity
    def __init__(self, capacity):
        if capacity <= 0:
            raise Exception("Capacity must be greater than 0!")
        self.capacity = capacity

    # Method to retrieve a value by key
    def get(self, key):
        # Return null if the key does not exist in the cache
        if key not in self.data:
            return None
        # Get the entry associated with the key
        entry = self.data[key]
        # Move the accessed entry to the end of the linked list (most recently used)
        self.moveEntryToLast(entry)
        return entry.value

    # Method to add a new key-value pair or update an existing key
    def put(self, key, value):
        # If the key already exists, update its value and move it to the end
        if key in self.data:
            existingEntry = self.data[key]
            existingEntry.value = value
            self.moveEntryToLast(existingEntry)
            return
        # If the cache is at capacity, remove the least recently used entry
        if len(self.data) == self.capacity:
            del self.data[self.tail.key]
            self.remove(self.tail)
        # Create a new entry for the key-value pair
        newEntry = Entry(None, None, key, value)
        # Add the new entry to the linked list
        self.addNewEntry(newEntry)
        # Store the new entry in the map
        self.data[key] = newEntry

    # Helper method to move an entry to the end of the linked list
    def moveEntryToLast(self, entry):
        # If the entry is already the tail, no need to move it
        if self.tail == entry:
            return
        # Remove the entry from its current position
        self.remove(entry)
        # Add the entry to the end of the linked list
        self.addNewEntry(entry)

    # Helper method to remove an entry from the linked list
    def remove(self, entry):
        # Update the previous entry's next pointer if it exists
        if entry.preEntry!= None:
            entry.preEntry.nextEntry = entry.nextEntry
        else:
            # If there is no previous entry, update the head
            self.head = entry.nextEntry
        # Update the next entry's previous pointer if it exists
        if entry.nextEntry!= None:
            entry.nextEntry.preEntry = entry.preEntry
        else:
            # If there is no next entry, update the tail
            self.tail = entry.preEntry

    # Helper method to add a new entry to the end of the linked list
    def addNewEntry(self, entry):
        # If there is an existing tail, link it to the new entry
        if self.tail!= None:
            self.tail.nextEntry = entry
            entry.preEntry = self.tail
        # Update the tail to the new entry
        self.tail = entry
        # If the list was empty, set the head to the new entry
        if self.head == None:
            self.head = self.tail

    # Inner class representing an entry in the cache
    class Entry:
        preEntry = None # Pointer to the previous entry
        nextEntry = None # Pointer to the next entry
        key = None # Key of the entry
        value = None # Value of the entry

        # Constructor for the Entry class
        def __init__(self, preEntry, nextEntry, key, value):
            self.preEntry = preEntry
            self.nextEntry = nextEntry
            self.key = key
            self.value = value

# Main method to execute the program
if __name__ == "__main__":
    scanner = Scanner(System.in)
    # Read the capacity of the cache
    capacity = scanner.nextInt()
    # Read the number of operations to perform
    operations = scanner.nextInt()
    # Create an instance of the cache with the specified capacity
    mruCache = Main(capacity)
    
    # Loop through the number of operations
    for i in range(operations):
        operation = scanner.next()
        # Handle the PUT operation
        if operation.equals("PUT"):
            key = scanner.nextInt()
            value = scanner.next()
            mruCache.put(key, value)
            print("Added: (" + key + ", " + value + ")")
        # Handle the GET operation
        else if operation.equals("GET"):
            key = scanner.nextInt()
            result = mruCache.get(key)
            print("Retrieved: " + (result!= None? result : "null"))
    # Close the scanner to prevent resource leaks
    scanner.close()

