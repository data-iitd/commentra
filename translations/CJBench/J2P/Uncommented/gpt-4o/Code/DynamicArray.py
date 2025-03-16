class DynamicArray:
    DEFAULT_CAPACITY = 16

    def __init__(self, capacity=None):
        if capacity is not None and capacity < 0:
            raise ValueError("Capacity cannot be negative.")
        self.size = 0
        self.mod_count = 0
        self.elements = [None] * (capacity if capacity is not None else self.DEFAULT_CAPACITY)

    def add(self, element):
        self.ensure_capacity(self.size + 1)
        self.elements[self.size] = element
        self.size += 1
        self.mod_count += 1

    def get(self, index):
        if index < 0 or index >= self.size:
            raise IndexError(f"Index: {index}, Size: {self.size}")
        return self.elements[index]

    def remove(self, index):
        if index < 0 or index >= self.size:
            raise IndexError(f"Index: {index}, Size: {self.size}")
        old_element = self.elements[index]
        self.fast_remove(index)
        self.mod_count += 1
        return old_element

    def get_size(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def ensure_capacity(self, min_capacity):
        if min_capacity > len(self.elements):
            new_capacity = max(len(self.elements) * 2, min_capacity)
            self.elements.extend([None] * (new_capacity - len(self.elements)))

    def fast_remove(self, index):
        num_moved = self.size - index - 1
        if num_moved > 0:
            self.elements[index:index + num_moved] = self.elements[index + 1:index + 1 + num_moved]
        self.elements[self.size - 1] = None
        self.size -= 1

    def __str__(self):
        return str(self.elements[:self.size])

    def __iter__(self):
        return DynamicArrayIterator(self)

class DynamicArrayIterator:
    def __init__(self, dynamic_array):
        self.dynamic_array = dynamic_array
        self.cursor = 0
        self.expected_mod_count = dynamic_array.mod_count

    def __iter__(self):
        return self

    def __next__(self):
        if self.dynamic_array.mod_count != self.expected_mod_count:
            raise RuntimeError("Concurrent modification detected.")
        if self.cursor >= self.dynamic_array.size:
            raise StopIteration
        result = self.dynamic_array.elements[self.cursor]
        self.cursor += 1
        return result

if __name__ == "__main__":
    import sys

    dynamic_array = DynamicArray()
    operations = int(sys.stdin.readline().strip())
    
    for _ in range(operations):
        input_line = sys.stdin.readline().strip().split()
        command = input_line[0].upper()
        
        if command == "ADD":
            value = int(input_line[1])
            dynamic_array.add(value)
        elif command == "REMOVE":
            remove_index = int(input_line[1])
            try:
                dynamic_array.remove(remove_index)
            except IndexError as e:
                print(f"Error: {e}")
        elif command == "GET":
            get_index = int(input_line[1])
            try:
                print(f"Value at index {get_index}: {dynamic_array.get(get_index)}")
            except IndexError as e:
                print(f"Error: {e}")
        else:
            print("Invalid command.")
    
    print(f"Final array: {dynamic_array}")
    print(f"Array size: {dynamic_array.get_size()}")

# <END-OF-CODE>
