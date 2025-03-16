

class Main:
    def __init__(self, capacity=16):
        if capacity < 0:
            raise ValueError("Capacity cannot be negative.")
        self.size = 0
        self.modCount = 0
        self.elements = [None] * capacity

    def add(self, element):
        self._ensure_capacity(self.size + 1)
        self.elements[self.size] = element
        self.size += 1
        self.modCount += 1

    def get(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index out of range.")
        return self.elements[index]

    def remove(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index out of range.")
        old_element = self.elements[index]
        self._fast_remove(index)
        self.modCount += 1
        return old_element

    def _ensure_capacity(self, min_capacity):
        if min_capacity > len(self.elements):
            new_capacity = max(len(self.elements) * 2, min_capacity)
            self.elements = [None] * new_capacity

    def _fast_remove(self, index):
        num_moved = self.size - index - 1
        if num_moved > 0:
            self.elements[index:self.size - 1] = self.elements[index + 1:self.size]
        self.elements[self.size - 1] = None
        self.size -= 1

    def __str__(self):
        return str(self.elements[:self.size])

    def __iter__(self):
        return MainIterator(self)

class MainIterator:
    def __init__(self, main):
        self.main = main
        self.cursor = 0
        self.expected_mod_count = main.modCount

    def __next__(self):
        if self.main.modCount!= self.expected_mod_count:
            raise RuntimeError("Concurrent modification detected.")
        if self.cursor >= self.main.size:
            raise StopIteration
        element = self.main.elements[self.cursor]
        self.cursor += 1
        return element

if __name__ == "__main__":
    import sys
    operations = int(input())
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
    print(f"Array size: {main.size}")

