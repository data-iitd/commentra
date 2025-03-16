import collections

class Main:
    # A HashMap to store the entries in the cache
    data = {}
    # Reference to the most recently used entry
    head = None
    # Reference to the least recently used entry
    tail = None
    # The capacity of the cache
    capacity = 0

    # Constructor to initialize the cache with a given capacity
    def __init__(self, capacity):
        if capacity <= 0:
            raise Exception("Capacity must be greater than 0!")
        self.capacity = capacity

    # Method to retrieve a value from the cache based on the key
    def get(self, key):
        if key not in self.data:
            return None
        entry = self.data[key]
        self.moveEntryToLast(entry) # Move the accessed entry to the most recently used position
        return entry.value

    # Method to add or update an entry in the cache
    def put(self, key, value):
        if key in self.data:
            entry = self.data[key]
            entry.value = value # Update the value of the existing entry
            self.moveEntryToLast(entry) # Move the existing entry to the most recently used position
            return
        if len(self.data) == self.capacity:
            del self.data[self.tail.key] # Remove the least recently used entry
            self.remove(self.tail) # Remove the least recently used entry from the list
        entry = Entry(None, None, key, value)
        self.addNewEntry(entry) # Add the new entry to the cache
        self.data[key] = entry # Add the new entry to the HashMap

    # Helper method to move an entry to the most recently used position
    def moveEntryToLast(self, entry):
        if entry == self.tail:
            return # The entry is already the most recently used
        self.remove(entry) # Remove the entry from its current position
        self.addNewEntry(entry) # Add the entry to the most recently used position

    # Helper method to remove an entry from the cache
    def remove(self, entry):
        if entry.preEntry!= None:
            entry.preEntry.nextEntry = entry.nextEntry # Update the previous entry's next pointer
        else:
            self.head = entry.nextEntry # Update the head if the entry is the first one
        if entry.nextEntry!= None:
            entry.nextEntry.preEntry = entry.preEntry # Update the next entry's previous pointer
        else:
            self.tail = entry.preEntry # Update the tail if the entry is the last one

    # Helper method to add a new entry to the cache
    def addNewEntry(self, entry):
        if self.tail!= None:
            self.tail.nextEntry = entry # Set the next pointer of the current tail
            entry.preEntry = self.tail # Set the previous pointer of the new entry
        self.tail = entry # Update the tail to the new entry
        if self.head == None:
            self.head = self.tail # If the head is null, set it to the new entry

    # Private static class to represent each entry in the cache
    class Entry:
        preEntry = None # Reference to the previous entry
        nextEntry = None # Reference to the next entry
        key = None # The key of the entry
        value = None # The value of the entry

        # Constructor to initialize the entry
        def __init__(self, preEntry, nextEntry, key, value):
            self.preEntry = preEntry
            self.nextEntry = nextEntry
            self.key = key
            self.value = value

# Main method to read input and perform operations on the cache
if __name__ == "__main__":
    scanner = Scanner(System.in)
    capacity = scanner.nextInt()
    operations = scanner.nextInt()
    mruCache = Main(capacity)
    for i in range(operations):
        operation = scanner.next()
        if operation.equals("PUT"):
            key = scanner.nextInt()
            value = scanner.next()
            mruCache.put(key, value)
            print("Added: (" + key + ", " + value + ")")
        else if operation.equals("GET"):
            key = scanner.nextInt()
            result = mruCache.get(key)
            print("Retrieved: " + (result!= None? result : "null"))
    scanner.close()

