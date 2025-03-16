
class Main:
    def __init__(self, capacity):
        if capacity <= 0:
            raise ValueError("Capacity must be greater than 0.")
        self.capacity = capacity
        self.data = {} # Stores the entries in the cache
        self.head = None # Head of the doubly linked list
        self.tail = None # Tail of the doubly linked list

    def get(self, key):
        if key not in self.data: # Check if the key exists in the cache
            return None
        entry = self.data[key]
        self.moveToLast(entry) # Move the accessed entry to the end of the list
        return entry.value

    def put(self, key, value):
        if key in self.data: # Check if the key already exists
            existing_entry = self.data[key]
            existing_entry.value = value # Update the value
            self.moveToLast(existing_entry) # Move the existing entry to the end
            return
        if len(self.data) == self.capacity: # Check if the cache is full
            del self.data[self.head.key] # Remove the least recently used entry
            self.remove(self.head) # Remove the entry from the list
        new_entry = Entry(key, value)
        self.addLast(new_entry) # Add the new entry to the end of the list
        self.data[key] = new_entry # Add the entry to the map

    def moveToLast(self, entry):
        if entry == self.tail: # If the entry is already at the end, do nothing
            return
        self.remove(entry) # Remove the entry from its current position
        self.addLast(entry) # Add the entry to the end of the list

    def remove(self, entry):
        if entry.prev is not None: # Update the previous entry's next pointer
            entry.prev.next = entry.next
        else: # If the entry is the head, update the head
            self.head = entry.next
        if entry.next is not None: # Update the next entry's previous pointer
            entry.next.prev = entry.prev
        else: # If the entry is the tail, update the tail
            self.tail = entry.prev

    def addLast(self, entry):
        if self.tail is not None: # If the list is not empty, update the tail's next pointer
            self.tail.next = entry
            entry.prev = self.tail
        self.tail = entry # Update the tail to the new entry
        if self.head is None: # If the list is empty, set the head to the new entry
            self.head = self.tail

    class Entry:
        def __init__(self, key, value):
            self.key = key
            self.value = value
            self.prev = None # Previous entry in the list
            self.next = None # Next entry in the list

if __name__ == "__main__":
    import sys
    capacity = int(input())
    operations = int(input())
    lru_cache = Main(capacity)
    for _ in range(operations):
        operation = input()
        if operation == "PUT":
            key = int(input())
            value = input()
            lru_cache.put(key, value)
            print("Added: ({}, {})".format(key, value))
        elif operation == "GET":
            key = int(input())
            result = lru_cache.get(key)
            print("Retrieved: {}".format(result if result is not None else "null"))

# 