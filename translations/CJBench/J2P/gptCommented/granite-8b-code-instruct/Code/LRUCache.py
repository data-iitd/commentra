
class Main:
    def __init__(self, capacity):
        if capacity <= 0:
            raise ValueError("Capacity must be greater than 0.")
        self.capacity = capacity
        self.data = {}
        self.head = None
        self.tail = None

    def get(self, key):
        if key not in self.data:
            return None
        entry = self.data[key]
        self.moveToLast(entry)
        return entry.value

    def put(self, key, value):
        if key in self.data:
            existing_entry = self.data[key]
            existing_entry.value = value
            self.moveToLast(existing_entry)
        elif len(self.data) == self.capacity:
            least_recently_used_key = next(iter(self.data))
            del self.data[least_recently_used_key]
            self.remove(self.head)
        new_entry = Entry(key, value)
        self.addLast(new_entry)
        self.data[key] = new_entry

    def moveToLast(self, entry):
        if entry == self.tail:
            return
        self.remove(entry)
        self.addLast(entry)

    def remove(self, entry):
        if entry.prev is not None:
            entry.prev.next = entry.next
        else:
            self.head = entry.next
        if entry.next is not None:
            entry.next.prev = entry.prev
        else:
            self.tail = entry.prev

    def addLast(self, entry):
        if self.tail is not None:
            self.tail.next = entry
            entry.prev = self.tail
        self.tail = entry
        if self.head is None:
            self.head = self.tail

    class Entry:
        def __init__(self, key, value):
            self.key = key
            self.value = value
            self.prev = None
            self.next = None

# Main method to run the cache operations
if __name__ == "__main__":
    import sys
    capacity = int(input())
    operations = int(input())
    lru_cache = Main(capacity)
    for _ in range(operations):
        operation = input()
        if operation == "PUT":
            key, value = map(int, input().split())
            lru_cache.put(key, value)
            print(f"Added: ({key}, {value})")
        elif operation == "GET":
            key = int(input())
            result = lru_cache.get(key)
            print(f"Retrieved: {result if result is not None else 'null'}")

# End of code
