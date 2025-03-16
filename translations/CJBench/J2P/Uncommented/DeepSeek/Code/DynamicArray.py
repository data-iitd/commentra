class DynamicArray:
    DEFAULT_CAPACITY = 16

    def __init__(self, capacity=DEFAULT_CAPACITY):
        if capacity < 0:
            raise ValueError("Capacity cannot be negative.")
        self.size = 0
        self.mod_count = 0
        self.elements = [None] * capacity

    def add(self, element):
        self._ensure_capacity(self.size + 1)
        self.elements[self.size] = element
        self.size += 1
        self.mod_count += 1

    def get(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index out of bounds.")
        return self.elements[index]

    def remove(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index out of bounds.")
        removed_element = self.elements[index]
        self._fast_remove(index)
        self.mod_count += 1
        return removed_element

    def get_size(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def _ensure_capacity(self, min_capacity):
        if min_capacity > len(self.elements):
            new_capacity = max(len(self.elements) * 2, min_capacity)
            self.elements = self.elements + [None] * (new_capacity - len(self.elements))

    def _fast_remove(self, index):
        num_moved = self.size - index - 1
        if num_moved > 0:
            self.elements[index:] = self.elements[index + 1:]
        self.elements[self.size - 1] = None
        self.size -= 1

    def __str__(self):
        return str(self.elements[:self.size])

    def __iter__(self):
        return self.MainIterator(self)

    class MainIterator:
        def __init__(self, dynamic_array):
            self.cursor = 0
            self.expected_mod_count = dynamic_array.mod_count
            self.dynamic_array = dynamic_array

        def __next__(self):
            if self.cursor >= self.dynamic_array.size:
                raise StopIteration
            if self.expected_mod_count != self.dynamic_array.mod_count:
                raise ConcurrentModificationError("Concurrent modification detected.")
            element = self.dynamic_array.elements[self.cursor]
            self.cursor += 1
            return element

        def has_next(self):
            if self.expected_mod_count != self.dynamic_array.mod_count:
                raise ConcurrentModificationError("Concurrent modification detected.")
            return self.cursor < self.dynamic_array.size


class ConcurrentModificationError(Exception):
    pass


class MainDemo:
    @staticmethod
    def main():
        dynamic_array = DynamicArray()
        import sys
        for line in sys.stdin:
            parts = line.strip().split()
            command = parts[0].upper()
            if command == "ADD":
                value = int(parts[1])
                dynamic_array.add(value)
            elif command == "REMOVE":
                index = int(parts[1])
                try:
                    dynamic_array.remove(index)
                except IndexError as e:
                    print(f"Error: {e}")
            elif command == "GET":
                index = int(parts[1])
                try:
                    print(f"Value at index {index}: {dynamic_array.get(index)}")
                except IndexError as e:
                    print(f"Error: {e}")
            else:
                print("Invalid command.")
        print("Final array:", dynamic_array)
        print("Array size:", dynamic_array.get_size())


if __name__ == "__main__":
    MainDemo.main()
