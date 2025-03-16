class Main:
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
        old_element = self.elements[index]
        self._fast_remove(index)
        self.mod_count += 1
        return old_element

    def _fast_remove(self, index):
        num_moved = self.size - index - 1
        if num_moved > 0:
            self.elements[index:self.size - 1] = self.elements[index + 1:self.size]
        self.elements[self.size - 1] = None
        self.size -= 1

    def get_size(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def _ensure_capacity(self, min_capacity):
        if min_capacity > len(self.elements):
            new_capacity = max(len(self.elements) * 2, min_capacity)
            self.elements = self.elements + [None] * (new_capacity - len(self.elements))

    def __str__(self):
        return str(self.elements[:self.size])

    def __iter__(self):
        self.iterator = MainIterator(self)
        return self.iterator

    class MainIterator:
        def __init__(self, main):
            self.main = main
            self.cursor = 0
            self.expected_mod_count = main.mod_count

        def __iter__(self):
            return self

        def __next__(self):
            if self.cursor >= self.main.size:
                raise StopIteration
            if self.main.mod_count != self.expected_mod_count:
                raise ConcurrentModificationError("Concurrent modification detected.")
            element = self.main.elements[self.cursor]
            self.cursor += 1
            return element


class MainDemo:
    @staticmethod
    def main():
        dynamic_array = Main()
        import sys
        input_lines = sys.stdin.readlines()
        for line in input_lines:
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

        print(f"Final array: {dynamic_array}")
        print(f"Array size: {dynamic_array.get_size()}")


if __name__ == "__main__":
    MainDemo.main()
