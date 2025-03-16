
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
        self.move_to_last(entry)
        return entry.value

    def put(self, key, value):
        if key in self.data:
            entry = self.data[key]
            entry.value = value
            self.move_to_last(entry)
            return

        if len(self.data) == self.capacity:
            self.data.pop(self.head.key)
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

    def __str__(self):
        return " ".join(str(entry.value) for entry in self.data.values())


class Entry:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

    def __str__(self):
        return f"({self.key}, {self.value})"


if __name__ == "__main__":
    capacity = int(input())
    operations = int(input())
    lru_cache = Main(capacity)

    for _ in range(operations):
        operation = input()
        if operation == "PUT":
            key = int(input())
            value = input()
            lru_cache.put(key, value)
            print(f"Added: {key} {value}")
        else:
            key = int(input())
            result = lru_cache.get(key)
            print(f"Retrieved: {result}")

    print(lru_cache)

