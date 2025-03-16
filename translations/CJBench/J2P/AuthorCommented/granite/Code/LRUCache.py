

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
        self._remove(entry)
        self._add_last(entry)
        return entry.value

    def put(self, key, value):
        if key in self.data:
            entry = self.data[key]
            entry.value = value
            self._remove(entry)
            self._add_last(entry)
        else:
            if len(self.data) == self.capacity:
                self._remove(self.head)
            entry = Entry(key, value)
            self._add_last(entry)
            self.data[key] = entry

    def _remove(self, entry):
        if entry.prev:
            entry.prev.next = entry.next
        else:
            self.head = entry.next
        if entry.next:
            entry.next.prev = entry.prev
        else:
            self.tail = entry.prev

    def _add_last(self, entry):
        if self.tail:
            self.tail.next = entry
            entry.prev = self.tail
        else:
            self.head = entry
        self.tail = entry

class Entry:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

if __name__ == "__main__":
    import sys

    capacity = int(input())
    operations = int(input())
    lru_cache = Main(capacity)

    for _ in range(operations):
        operation = input().split()
        if operation[0] == "PUT":
            key, value = int(operation[1]), operation[2]
            lru_cache.put(key, value)
            print("Added: ({}, {})".format(key, value))
        else:
            key = int(operation[1])
            result = lru_cache.get(key)
            print("Retrieved: {}".format(result if result is not None else "null"))

