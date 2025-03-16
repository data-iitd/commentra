

class Main:
    def __init__(self, capacity=16):
        if capacity < 0:
            raise ValueError("Capacity cannot be negative.")
        self.size = 0
        self.mod_count = 0
        self.elements = [None] * capacity

    def add(self, element):
        if self.size == len(self.elements):
            self._resize(2 * len(self.elements))
        self.elements[self.size] = element
        self.size += 1
        self.mod_count += 1

    def get(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index out of range.")
        return self.elements[index]

    def remove(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index out of range.")
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

    def _resize(self, new_capacity):
        self.elements = self.elements[:self.size] + [None] * (new_capacity - self.size)

    def __str__(self):
        return str(self.elements[:self.size])

    def __iter__(self):
        return MainIterator(self)

class MainIterator:
    def __init__(self, main):
        self.main = main
        self.cursor = 0
        self.expected_mod_count = main.mod_count

    def __next__(self):
        if self.expected_mod_count!= self.main.mod_count:
            raise RuntimeError("Concurrent modification detected.")
        if self.cursor >= self.main.size:
            raise StopIteration
        element = self.main.elements[self.cursor]
        self.cursor += 1
        return element

if __name__ == "__main__":
    operations = int(input("Enter the number of operations: "))
    main = Main()

    for _ in range(operations):
        command, *args = input().split()
        if command == "ADD":
            value = int(args[0])
            main.add(value)
        elif command == "REMOVE":
            index = int(args[0])
            try:
                main.remove(index)
            except IndexError as e:
                print(f"Error: {e}")
        elif command == "GET":
            index = int(args[0])
            try:
                print(f"Value at index {index}: {main.get(index)}")
            except IndexError as e:
                print(f"Error: {e}")
        else:
            print("Invalid command.")

    print(f"Final array: {main}")
    print(f"Array size: {main.get_size()}")

