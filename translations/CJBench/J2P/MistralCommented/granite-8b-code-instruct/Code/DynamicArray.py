

class Main:
    def __init__(self, capacity=16):
        if capacity < 0:
            raise ValueError("Capacity cannot be negative.")
        self.size = 0
        self.modCount = 0
        self.elements = [None] * capacity
        # Initialize the array with the given capacity.

    def add(self, element):
        self._ensure_capacity(self.size + 1)
        self.elements[self.size] = element
        self.size += 1
        self.modCount += 1  # Increment the modification counter.

    def get(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index out of range.")
        return self.elements[index]
        # Return the element at the specified index.

    def remove(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index out of range.")
        old_element = self.elements[index]
        self._fast_remove(index)
        self.modCount += 1  # Increment the modification counter.
        return old_element
        # Remove the element at the specified index and return it.

    def get_size(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def _ensure_capacity(self, min_capacity):
        if min_capacity > len(self.elements):
            new_capacity = max(len(self.elements) * 2, min_capacity)
            self.elements = [None] * new_capacity
            # Increase the capacity of the array if needed.

    def _fast_remove(self, index):
        num_moved = self.size - index - 1
        if num_moved > 0:
            self.elements[index:index + num_moved] = self.elements[index + 1:self.size]
        self.elements[self.size - 1] = None  # Set the removed element to None.
        self.size -= 1

    def __str__(self):
        return str(self.elements[:self.size])
        # Return a string representation of the underlying array.

    def __iter__(self):
        return MainIterator(self)
        # Return an iterator to traverse the elements in this list.

class MainIterator:
    def __init__(self, main):
        self.main = main
        self.cursor = 0
        self.expected_mod_count = main.modCount
        # Initialize the cursor and the expected modification counter.

    def has_next(self):
        if self.main.modCount!= self.expected_mod_count:
            raise RuntimeError("Concurrent modification detected.")
        return self.cursor < self.main.size
        # Check if there are more elements to iterate.

    def next(self):
        if self.main.modCount!= self.expected_mod_count:
            raise RuntimeError("Concurrent modification detected.")
        if self.cursor >= self.main.size:
            raise StopIteration("No more elements.")
        element = self.main.elements[self.cursor]
        self.cursor += 1
        return element
        # Return the next element and increment the cursor.

# Demonstrate the usage of the Main class by reading commands from the standard input.
if __name__ == "__main__":
    import sys
    main = Main()
    operations = int(input())
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

# Translate the above Python code to Java and end with comment "