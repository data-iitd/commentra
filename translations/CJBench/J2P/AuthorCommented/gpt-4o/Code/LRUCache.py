class LRUCache:
    class Entry:
        def __init__(self, key, value):
            self.key = key
            self.value = value
            self.prev = None
            self.next = None

    def __init__(self, capacity: int):
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
        self.move_to_last(entry)
        return entry.value

    def put(self, key, value):
        if key in self.data:
            existing_entry = self.data[key]
            existing_entry.value = value
            self.move_to_last(existing_entry)
            return

        if len(self.data) == self.capacity:
            del self.data[self.head.key]
            self.remove(self.head)

        new_entry = self.Entry(key, value)
        self.add_last(new_entry)
        self.data[key] = new_entry

    def move_to_last(self, entry):
        if entry == self.tail:
            return
        self.remove(entry)
        self.add_last(entry)

    def remove(self, entry):
        if entry.prev is not None:
            entry.prev.next = entry.next
        else:
            self.head = entry.next

        if entry.next is not None:
            entry.next.prev = entry.prev
        else:
            self.tail = entry.prev

    def add_last(self, entry):
        if self.tail is not None:
            self.tail.next = entry
            entry.prev = self.tail
        self.tail = entry
        if self.head is None:
            self.head = self.tail

if __name__ == "__main__":
    import sys

    capacity = int(sys.stdin.readline().strip())
    operations = int(sys.stdin.readline().strip())
    lru_cache = LRUCache(capacity)

    for _ in range(operations):
        operation = sys.stdin.readline().strip()
        if operation.startswith("PUT"):
            _, key, value = operation.split()
            key = int(key)
            lru_cache.put(key, value)
            print(f"Added: ({key}, {value})")
        elif operation.startswith("GET"):
            _, key = operation.split()
            key = int(key)
            result = lru_cache.get(key)
            print(f"Retrieved: {result if result is not None else 'null'}")

# <END-OF-CODE>
