class Entry:
    def __init__(self, pre_entry, next_entry, key, value):
        self.pre_entry = pre_entry
        self.next_entry = next_entry
        self.key = key
        self.value = value

    def get_pre_entry(self):
        return self.pre_entry

    def set_pre_entry(self, pre_entry):
        self.pre_entry = pre_entry

    def get_next_entry(self):
        return self.next_entry

    def set_next_entry(self, next_entry):
        self.next_entry = next_entry

    def get_key(self):
        return self.key

    def get_value(self):
        return self.value

    def set_value(self, value):
        self.value = value


class Main:
    def __init__(self, capacity):
        if capacity <= 0:
            raise ValueError("Capacity must be greater than 0!")
        self.data = {}
        self.head = None
        self.tail = None
        self.capacity = capacity

    def get(self, key):
        if key not in self.data:
            return None
        entry = self.data[key]
        self.move_entry_to_last(entry)
        return entry.get_value()

    def put(self, key, value):
        if key in self.data:
            entry = self.data[key]
            entry.set_value(value)
            self.move_entry_to_last(entry)
            return
        if len(self.data) == self.capacity:
            del self.data[self.tail.get_key()]
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
        if entry.get_pre_entry() is not None:
            entry.get_pre_entry().set_next_entry(entry.get_next_entry())
        else:
            self.head = entry.get_next_entry()
        if entry.get_next_entry() is not None:
            entry.get_next_entry().set_pre_entry(entry.get_pre_entry())
        else:
            self.tail = entry.get_pre_entry()

    def add_new_entry(self, entry):
        if self.tail is not None:
            self.tail.set_next_entry(entry)
            entry.set_pre_entry(self.tail)
        self.tail = entry
        if self.head is None:
            self.head = self.tail

    def main(self):
        import sys
        input = sys.stdin.read
        data = input().split()
        index = 0
        capacity = int(data[index])
        index += 1
        operations = int(data[index])
        index += 1
        mru_cache = Main(capacity)
        for i in range(operations):
            operation = data[index]
            index += 1
            if operation == "PUT":
                key = int(data[index])
                index += 1
                value = data[index]
                index += 1
                mru_cache.put(key, value)
                print(f"Added: ({key}, {value})")
            elif operation == "GET":
                key = int(data[index])
                index += 1
                result = mru_cache.get(key)
                print(f"Retrieved: {result if result is not None else 'null'}")


if __name__ == "__main__":
    Main().main()
