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
            self.data.pop(self.head.key)
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
        if entry.prev:
            entry.prev.next = entry.next
        else:
            self.head = entry.next
        if entry.next:
            entry.next.prev = entry.prev
        else:
            self.tail = entry.prev

    def add_last(self, entry):
        if self.tail:
            self.tail.next = entry
            entry.prev = self.tail
        else:
            self.head = self.tail = entry

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
