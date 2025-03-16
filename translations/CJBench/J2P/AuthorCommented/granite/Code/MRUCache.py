

class Main:
    def __init__(self, capacity):
        if capacity <= 0:
            raise ValueError("Capacity must be greater than 0!")
        self.capacity = capacity
        self.data = {}
        self.head = None
        self.tail = None

    def get(self, key):
        if key not in self.data:
            return None
        entry = self.data[key]
        self.move_entry_to_last(entry)
        return entry.value

    def put(self, key, value):
        if key in self.data:
            existing_entry = self.data[key]
            existing_entry.value = value
            self.move_entry_to_last(existing_entry)
            return
        if len(self.data) == self.capacity:
            evicted_key = self.tail.key
            del self.data[evicted_key]
            self.remove(self.tail)
        new_entry = Entry(None, None, key, value)
        self.add_new_entry(new_entry)
        self.data[key] = new_entry

    def move_entry_to_last(self, entry):
        if self.tail == entry:
            return
        self.remove(entry)
        self.add_new_entry(entry)

    def remove(self, entry):
        if entry.pre_entry is not None:
            entry.pre_entry.next_entry = entry.next_entry
        else:
            self.head = entry.next_entry
        if entry.next_entry is not None:
            entry.next_entry.pre_entry = entry.pre_entry
        else:
            self.tail = entry.pre_entry

    def add_new_entry(self, entry):
        if self.tail is not None:
            self.tail.next_entry = entry
            entry.pre_entry = self.tail
        self.tail = entry
        if self.head is None:
            self.head = self.tail

class Entry:
    def __init__(self, pre_entry, next_entry, key, value):
        self.pre_entry = pre_entry
        self.next_entry = next_entry
        self.key = key
        self.value = value

if __name__ == "__main__":
    import sys
    capacity = int(sys.stdin.readline())
    operations = int(sys.stdin.readline())
    mru_cache = Main(capacity)

    for _ in range(operations):
        operation = sys.stdin.readline().strip()
        if operation == "PUT":
            key, value = map(int, sys.stdin.readline().split())
            mru_cache.put(key, value)
            print(f"Added: ({key}, {value})")
        elif operation == "GET":
            key = int(sys.stdin.readline())
            result = mru_cache.get(key)
            print(f"Retrieved: {result if result is not None else 'null'}")

