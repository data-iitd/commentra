class Entry:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

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
    def __init__(self, capacity: int):
        if capacity <= 0:
            raise ValueError("Capacity must be greater than 0.")
        self.capacity = capacity
        self.data = {}
        self.head = None
        self.tail = None

    def get(self, key: int) -> str:
        if key not in self.data:
            return "null"
        entry = self.data[key]
        self.move_to_last(entry)
        return entry.get_value()

    def put(self, key: int, value: str):
        if key in self.data:
            existing_entry = self.data[key]
            existing_entry.set_value(value)
            self.move_to_last(existing_entry)
            return
        if len(self.data) == self.capacity:
            del self.data[self.head.get_key()]
            self.remove(self.head)
        new_entry = Entry(key, value)
        self.add_last(new_entry)
        self.data[key] = new_entry

    def move_to_last(self, entry: Entry):
        if entry == self.tail:
            return
        self.remove(entry)
        self.add_last(entry)

    def remove(self, entry: Entry):
        if entry.get_prev():
            entry.get_prev().set_next(entry.get_next())
        else:
            self.head = entry.get_next()
        if entry.get_next():
            entry.get_next().set_prev(entry.get_prev())
        else:
            self.tail = entry.get_prev()

    def add_last(self, entry: Entry):
        if self.tail:
            self.tail.set_next(entry)
            entry.set_prev(self.tail)
        else:
            self.head = self.tail = entry


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    capacity = int(data[0])
    operations = int(data[1])
    lru_cache = LRUCache(capacity)
    for i in range(2, len(data), 2):
        operation = data[i]
        if operation == "PUT":
            key = int(data[i + 1])
            value = data[i + 2]
            lru_cache.put(key, value)
            print(f"Added: ({key}, {value})")
        elif operation == "GET":
            key = int(data[i + 1])
            result = lru_cache.get(key)
            print(f"Retrieved: {result}")


if __name__ == "__main__":
    main()
