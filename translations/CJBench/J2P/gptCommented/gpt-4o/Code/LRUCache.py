class Entry:
    def __init__(self, key, value):
        self.key = key  # Key of the entry
        self.value = value  # Value of the entry
        self.prev = None  # Pointer to the previous entry
        self.next = None  # Pointer to the next entry

    def get_key(self):
        return self.key

    def get_value(self):
        return self.value

    def set_value(self, value):
        self.value = value

    def get_prev(self):
        return self.prev

    def set_prev(self, prev):
        self.prev = prev

    def get_next(self):
        return self.next

    def set_next(self, next):
        self.next = next


class LRUCache:
    def __init__(self, capacity):
        if capacity <= 0:
            raise ValueError("Capacity must be greater than 0.")
        self.capacity = capacity
        self.data = {}  # Map to store the key-value pairs
        self.head = None  # Pointer to the head of the doubly linked list
        self.tail = None  # Pointer to the tail of the doubly linked list

    def get(self, key):
        if key not in self.data:
            return None
        entry = self.data[key]
        self.move_to_last(entry)
        return entry.get_value()

    def put(self, key, value):
        if key in self.data:
            existing_entry = self.data[key]
            existing_entry.set_value(value)
            self.move_to_last(existing_entry)
            return
        if len(self.data) == self.capacity:
            self.data.pop(self.head.get_key())
            self.remove(self.head)
        new_entry = Entry(key, value)
        self.add_last(new_entry)
        self.data[key] = new_entry

    def move_to_last(self, entry):
        if entry == self.tail:
            return
        self.remove(entry)
        self.add_last(entry)

    def remove(self, entry):
        if entry.get_prev() is not None:
            entry.get_prev().set_next(entry.get_next())
        else:
            self.head = entry.get_next()
        if entry.get_next() is not None:
            entry.get_next().set_prev(entry.get_prev())
        else:
            self.tail = entry.get_prev()

    def add_last(self, entry):
        if self.tail is not None:
            self.tail.set_next(entry)
            entry.set_prev(self.tail)
        self.tail = entry
        if self.head is None:
            self.head = self.tail


def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    capacity = int(data[0])
    operations = int(data[1])
    
    lru_cache = LRUCache(capacity)
    
    for i in range(2, 2 + operations):
        operation = data[i].split()
        if operation[0] == "PUT":
            key = int(operation[1])
            value = operation[2]
            lru_cache.put(key, value)
            print(f"Added: ({key}, {value})")
        elif operation[0] == "GET":
            key = int(operation[1])
            result = lru_cache.get(key)
            print(f"Retrieved: {result if result is not None else 'null'}")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
