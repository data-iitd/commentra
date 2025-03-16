
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
        self.capacity = capacity
        self.data = {}
        self.head = None
        self.tail = None

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
            self.data.pop(self.tail.get_key())
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
        scanner = Scanner(sys.stdin)
        capacity = scanner.nextInt()
        operations = scanner.nextInt()
        mru_cache = Main(capacity)
        for i in range(operations):
            operation = scanner.next()
            if operation == "PUT":
                key = scanner.nextInt()
                value = scanner.next()
                mru_cache.put(key, value)
                print("Added: (" + str(key) + ", " + value + ")")
            else:
                key = scanner.nextInt()
                result = mru_cache.get(key)
                print("Retrieved: " + (str(result) if result is not None else "null"))
        scanner.close()


if __name__ == "__main__":
    mru_cache = Main(3)
    mru_cache.put(1, "A")
    mru_cache.put(2, "B")
    mru_cache.put(3, "C")
    mru_cache.put(4, "D")
    print(mru_cache.get(1))
    print(mru_cache.get(2))
    print(mru_cache.get(3))
    print(mru_cache.get(4))
    print(mru_cache.get(5))
    mru_cache.put(5, "E")
    print(mru_cache.get(1))
    print(mru_cache.get(2))
    print(mru_cache.get(3))
    print(mru_cache.get(4))
    print(mru_cache.get(5))
    mru_cache.put(6, "F")
    print(mru_cache.get(1))
    print(mru_cache.get(2))
    print(mru_cache.get(3))
    print(mru_cache.get(4))
    print(mru_cache.get(5))
    print(mru_cache.get(6))
    mru_cache.put(7, "G")
    print(mru_cache.get(1))
    print(mru_cache.get(2))
    print(mru_cache.get(3))
    print(mru_cache.get(4))
    print(mru_cache.get(5))
    print(mru_cache.get(6))
    print(mru_cache.get(7))
    mru_cache.put(8, "H")
    print(mru_cache.get(1))
    print(mru_cache.get(2))
    print(mru_cache.get(3))
    print(mru_cache.get(4))
    print(mru_cache.get(5))
    print(mru_cache.get(6))
    print(mru_cache.get(7))
    print(mru_cache.get(8))
    mru_cache.put(9, "I")
    print(mru_cache.get(1))
    print(mru_cache.get(2))
    print(mru_cache.get(3))
    print(mru_cache.get(4))
    print(mru_cache.get(5))
    print(mru_cache.get(6))
    print(mru_cache.get(7))
    print(mru_cache.get(8))
    print(mru_cache.get(9))
    mru_cache.put(10, "J")
    print(mru_cache.get(1))
    print(mru_cache.get(2))
    print(mru_cache.get(3))
    print(mru_cache.get(4))
    print(mru_cache.get(5))
    print(mru_cache.get(6))
    print(mru_cache.get(7))
    print(mru_cache.get(8))
    print(mru_cache.get(9))
    print(mru_cache.get(10))
    mru_cache.put(11, "K")
    print(mru_cache.get(1))
    print(mru_cache.get(2))
    print(mru_cache.get(3))
    print(mru_cache.get(4))
    print(mru_cache.get(5))
    print(mru_cache.get(6))
    print(mru_cache.get(7))
    print(mru_cache.get(8))
    print(mru_cache.get(9))
    print(mru_cache.get(10))
    print(mru_cache.get(11))
    mru_cache.put(12, "L")
    print(mru_cache.get(1))
    print(mru_cache.get(2))
    print(mru_cache.get(3))
    print(mru_cache.get(4))
    print(mru_cache.get(5))
    print(mru_cache.get(6))
    print(mru_cache.get(7))
    print(mru_cache.get(8))
    print(mru_cache.get(9))
    print(mru_cache.get(10))
    print(mru_cache.get(11))
    print(mru_cache.get(12))
    mru_cache.put(13, "M")
    print(mru_cache.get(1))
    print(mru_cache.get(2))
    print(mru_cache.get(3))
    print(mru_cache.get(4))
    print(mru_cache.get(5))
    print(mru_cache.get(6))
    print(mru_cache.get(7))
    print(mru_cache.get(8))
    print(mru_cache.get(9))
    print(mru_cache.get(10))
    print(mru_cache.get(11))
    print(mru_cache.get(12))
    print(mru_cache.get(13))
    mru_cache.put(14, "N")
    print(mru_cache.get(1))
    print(mru_cache.get(2))
    print(mru_cache.get(3))
    print(mru_cache.get(4))
    print(mru_cache.get(5))
    print(mru_cache.get(6))
    print(mru_cache.get(7))
    print(mru_cache.get(8))
    print(mru_cache.get(9))
    print(mru_cache.get(10))
    print(mru_cache.get(11))
    print(mru_cache.get(12))
    print(mru_cache.get(13))
    print(mru_cache.get(14))
    mru_cache.put(15, "O")
    print(mru_cache.get(1))
    print(mru_cache.get(2))
    print(mru_cache.get(3))
    print(mru_cache.get(4))
    print(mru_cache.get(5))
    print(mru_cache.get(6))
    print(mru_cache.get(7))
    print(mru_cache.get(8))
    print(mru_cache.get(9))
    print(mru_cache.get(10))
    print(mru_cache.get(11))
    print(mru_cache.get(12))
    print(mru_cache.get(13))
    print(mru_cache.get(14))
    print(mru_cache.get(15))
    mru_cache.put(16, "P")
    print(mru_cache.get(1))
    print(mru_cache.get(2))
    print(mru_cache.get(3))
    print(mru_cache.get(4))
    print(mru_cache.get(5))
    print(mru_cache.get(6))
    print(mru_cache.get(7))
    print(mru_cache.get(8))
    print(mru_cache.get(9))
    print(mru_cache.get(10))
    print(mru_cache.get(11))
    print(mru_cache.get(12))
    print(mru_cache.get(13))
    print(mru_cache.get(14))
    print(mru_cache.get(15))
    print(mru_cache.get(16))
    mru_cache.put(17, "Q")
    print(mru_cache.get(1))
    print(mru_cache.get(2))
    print(mru_cache.get(3))
    print(mru_cache.get(4))
    print(mru_cache.get(5))
    print(mru_cache.get(6))
    print(mru_cache.get(7))
    print(mru_cache.get(8))
    print(mru_cache.get(9))
    print(mru_cache.get(10))
    print(mru_cache.get(11))
    print(mru_cache.get(12))
    print(mru_cache.get(13))
    print(mru_cache.get(14))
    print(mru_cache.get(15))
    print(mru_cache.get(16))
    print(mru_cache.get(17))
    mru_cache.put(18, "R")
    print(mru_cache.get(1))
    print(mru_cache.get(2))
    print(mru_cache.get(3))
    print(mru_cache.get(4))
    print(mru_cache.get(5))
    print(mru_cache.get(6))
    print(mru_cache.get(7))
    print(mru_cache.get(8))
    print(mru_cache.get(9))
    print(mru_cache.get(10))
    print(mru_cache.get(11))
    print(mru_cache.get(12))
    print(mru_cache.get(13))
    print(mru_cache.get(14))
    print(mru_cache.get(15))
    print(mru_cache.get(16))
    print(mru_cache.get(17))
    print(mru_cache.get(18))
    mru_cache.put(19, "S")
    print(mru_cache.get(1))
    print(mru_cache.get(2))
    print(mru_cache.get(3))
    print(mru_cache.get(4))
    print(mru_cache.get(5))
    print(mru_cache.get(6))
    print(mru_cache.get(7))
    print(mru_cache.get(8))
    print(mru_cache.get(9))
    print(mru_cache.get(10))
    print(mru_cache.get(11))
    print(mru_cache.get(12))
    print(mru_cache.get(13))
    print(mru_cache.get(14))
    print(mru_cache.get(15))
    print(mru_cache.get(16))
    print(mru_cache.get(17))
    print(mru_cache.get(18))
    print(mru_cache.get(19))
    mru_cache.put(20, "T")
    print(mru_cache.get(1))
    print(mru_cache.get(2))
    print(mru_cache.get(3))
    print(mru_cache.get(4))
    print(mru_cache.get(5))
    print(mru_cache.get(6))
    print(mru_cache.get(7))
    print(mru_cache.get(8))
    print(mru_cache.get(9))
    print(mru_cache.get(10))
    print(mru_cache.get(11))
    print(mru_cache.get(12))
    print(mru_cache.get(13))
    print(mru_cache.get(14))
    print(mru_cache.get(15))
    print(mru_cache.get(16))
    print(mru_cache.get(17))
    print(mru_cache.get(18))
    print(mru_cache.get(19))
    print(mru_cache.get(20))
    mru_cache.put(21, "U")
    print(mru_cache.get(1))
    print(mru_cache.get(2))
    print(mru_cache.get(3))
    print(mru_cache.get(4))
    print(mru_cache.get(5))
    print(mru_cache.get(6))
    print(mru_cache.get(7))
    print(mru_cache.get(8))
    print(mru_cache.get(9))
    print(mru_cache.get(10))
    print(mru_cache.get(11))
    print(mru_cache.get(12))
    print(mru_cache.get(13))
    print(mru_cache.get(14))
    print(mru_cache.get(15))
    print(mru_cache.get(16))
    print(mru_cache.get(17))
    print(mru_cache.get(18))
    print(mru_cache.get(19))
    print(mru_cache.get(20))
    print(mru_cache.get(21))
    mru_c