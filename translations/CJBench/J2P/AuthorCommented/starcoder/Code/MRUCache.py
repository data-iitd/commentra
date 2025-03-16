
import collections
import sys

class Main:
    def __init__(self, capacity):
        if capacity <= 0:
            raise ValueError("Capacity must be greater than 0!")
        self.capacity = capacity
        self.data = collections.OrderedDict()
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
            entry = self.data[key]
            entry.value = value
            self.move_entry_to_last(entry)
            return
        if len(self.data) == self.capacity:
            self.data.popitem(last=False)
            self.remove(self.tail)
        entry = Entry(None, None, key, value)
        self.add_new_entry(entry)
        self.data[key] = entry

    def move_entry_to_last(self, entry):
        if self.tail == entry:
            return
        self.remove(entry)
        self.add_new_entry(entry)

    def remove(self, entry):
        if entry.pre_entry!= None:
            entry.pre_entry.next_entry = entry.next_entry
        else:
            self.head = entry.next_entry
        if entry.next_entry!= None:
            entry.next_entry.pre_entry = entry.pre_entry
        else:
            self.tail = entry.pre_entry

    def add_new_entry(self, entry):
        if self.tail!= None:
            self.tail.next_entry = entry
            entry.pre_entry = self.tail
        self.tail = entry
        if self.head == None:
            self.head = self.tail

class Entry:
    def __init__(self, pre_entry, next_entry, key, value):
        self.pre_entry = pre_entry
        self.next_entry = next_entry
        self.key = key
        self.value = value

if __name__ == "__main__":
    capacity = int(sys.stdin.readline().strip())
    operations = int(sys.stdin.readline().strip())
    mru_cache = Main(capacity)
    for i in range(operations):
        operation = sys.stdin.readline().strip()
        if operation == "PUT":
            key = int(sys.stdin.readline().strip())
            value = sys.stdin.readline().strip()
            mru_cache.put(key, value)
            print("Added: (" + str(key) + ", " + value + ")")
        elif operation == "GET":
            key = int(sys.stdin.readline().strip())
            result = mru_cache.get(key)
            print("Retrieved: " + (result!= None and result or "null"))

