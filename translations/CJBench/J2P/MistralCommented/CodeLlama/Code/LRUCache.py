
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


class Main:
    def __init__(self, capacity):
        self.data = {}
        self.head = None
        self.tail = None
        self.capacity = capacity

    def get(self, key):
        if key not in self.data:
            return None
        entry = self.data[key]
        self.move_to_last(entry)
        return entry.get_value()

    def put(self, key, value):
        if key in self.data:
            entry = self.data[key]
            entry.set_value(value)
            self.move_to_last(entry)
            return
        if len(self.data) == self.capacity:
            self.data.pop(self.head.get_key())
            self.remove(self.head)
        entry = Entry(key, value)
        self.add_last(entry)
        self.data[key] = entry

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
        else:
            self.head = entry
        self.tail = entry


# Main method to read input and test the Main implementation
if __name__ == "__main__":
    capacity = int(input())
    operations = int(input())
    lru_cache = Main(capacity)
    for i in range(operations):
        operation = input()
        if operation == "PUT":
            key = int(input())
            value = input()
            lru_cache.put(key, value)
            print("Added: (" + str(key) + ", " + value + ")")
        else:
            key = int(input())
            result = lru_cache.get(key)
            print("Retrieved: " + (str(result) if result is not None else "null"))

# END-OF-CODE
