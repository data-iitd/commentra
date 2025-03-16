class Main:
    DEFAULT_CAPACITY = 16  # Default capacity for the array

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
        def __init__(self, main_instance):
            self.cursor = 0
            self.expected_mod_count = main_instance.mod_count
            self.main_instance = main_instance

        def __next__(self):
            if self.cursor >= self.main_instance.size:
                raise StopIteration
            if self.main_instance.mod_count != self.expected_mod_count:
                raise ConcurrentModificationError("Concurrent modification detected.")
            element = self.main_instance.elements[self.cursor]
            self.cursor += 1
            return element

        def has_next(self):
            if self.main_instance.mod_count != self.expected_mod_count:
                raise ConcurrentModificationError("Concurrent modification detected.")
            return self.cursor < self.main_instance.size


class MainDemo:
    @staticmethod
    def main():
        dynamic_array = Main()
        import sys
        input_lines = sys.stdin.readlines()
        operations = int(input_lines[0].strip())
        for i in range(1, operations + 1):
            command, *value = input_lines[i].strip().split()
            command = command.upper()
            if command == "ADD":
                dynamic_array.add(int(value[0]))
            elif command == "REMOVE":
                try:
                    dynamic_array.remove(int(value[0]))
                except IndexError as e:
                    print(f"Error: {e}")
            elif command == "GET":
                try:
                    print(f"Value at index {value[0]}: {dynamic_array.get(int(value[0]))}")
                except IndexError as e:
                    print(f"Error: {e}")
            else:
                print("Invalid command.")
        print("Final array:", dynamic_array)
        print("Array size:", dynamic_array.get_size())


if __name__ == "__main__":
    MainDemo.main()
