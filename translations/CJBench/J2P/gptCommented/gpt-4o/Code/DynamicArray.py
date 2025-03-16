class DynamicArray:
    # Default capacity for the dynamic array
    DEFAULT_CAPACITY = 16

    def __init__(self, capacity=None):
        if capacity is None:
            capacity = self.DEFAULT_CAPACITY
        if capacity < 0:
            raise ValueError("Capacity cannot be negative.")
        self.size = 0  # Current number of elements in the array
        self.mod_count = 0  # Modification count for tracking changes
        self.elements = [None] * capacity  # Create an array with the specified capacity

    # Method to add an element to the dynamic array
    def add(self, element):
        self.ensure_capacity(self.size + 1)  # Ensure there is enough capacity
        self.elements[self.size] = element  # Add the element
        self.size += 1  # Increment size
        self.mod_count += 1  # Increment modification count

    # Method to retrieve an element at a specific index
    def get(self, index):
        if index < 0 or index >= self.size:
            raise IndexError(f"Index: {index}, Size: {self.size}")
        return self.elements[index]  # Return the element at the specified index

    # Method to remove an element at a specific index
    def remove(self, index):
        if index < 0 or index >= self.size:
            raise IndexError(f"Index: {index}, Size: {self.size}")
        old_element = self.elements[index]  # Store the element to be removed
        self.fast_remove(index)  # Remove the element
        self.mod_count += 1  # Increment modification count
        return old_element  # Return the removed element

    # Method to get the current size of the dynamic array
    def get_size(self):
        return self.size  # Return the size

    # Method to check if the dynamic array is empty
    def is_empty(self):
        return self.size == 0  # Return true if size is 0, otherwise false

    # Method to ensure the array has enough capacity to accommodate new elements
    def ensure_capacity(self, min_capacity):
        if min_capacity > len(self.elements):
            new_capacity = max(len(self.elements) * 2, min_capacity)
            self.elements.extend([None] * (new_capacity - len(self.elements)))  # Resize the array

    # Method to remove an element quickly without shifting all elements
    def fast_remove(self, index):
        num_moved = self.size - index - 1  # Calculate number of elements to move
        if num_moved > 0:
            self.elements[index:index + num_moved] = self.elements[index + 1:index + 1 + num_moved]  # Shift elements
        self.elements[self.size - 1] = None  # Null out the last element
        self.size -= 1  # Decrement size

    # Override toString method to display the dynamic array
    def __str__(self):
        return str(self.elements[:self.size])  # Return a string representation of the array

    # Inner class for the custom iterator
    class DynamicArrayIterator:
        def __init__(self, dynamic_array):
            self.dynamic_array = dynamic_array
            self.cursor = 0  # Current position in the iteration
            self.expected_mod_count = dynamic_array.mod_count  # Expected modification count for fail-fast behavior

        # Method to check if there are more elements to iterate over
        def has_next(self):
            self.check_for_comodification()  # Check for concurrent modifications
            return self.cursor < self.dynamic_array.size  # Return true if there are more elements

        # Method to retrieve the next element in the iteration
        def next(self):
            self.check_for_comodification()  # Check for concurrent modifications
            if self.cursor >= self.dynamic_array.size:
                raise StopIteration()  # Throw exception if no more elements
            result = self.dynamic_array.elements[self.cursor]  # Return the current element
            self.cursor += 1  # Increment cursor
            return result

        # Method to check for concurrent modifications
        def check_for_comodification(self):
            if self.dynamic_array.mod_count != self.expected_mod_count:
                raise RuntimeError("Concurrent modification detected.")  # Throw exception if modification count has changed

    # Method to return an instance of the custom iterator
    def iterator(self):
        return self.DynamicArrayIterator(self)  # Return a new iterator instance


# Main class for demonstration
if __name__ == "__main__":
    import sys

    dynamic_array = DynamicArray()  # Create a new dynamic array instance
    operations = int(sys.stdin.readline().strip())  # Read the number of operations

    # Loop through the number of operations
    for _ in range(operations):
        input_line = sys.stdin.readline().strip().split()  # Read and split the input line
        command = input_line[0].upper()  # Get the command
        if command == "ADD":
            value = int(input_line[1])  # Parse the value to add
            dynamic_array.add(value)  # Add the value to the dynamic array
        elif command == "REMOVE":
            remove_index = int(input_line[1])  # Parse the index to remove
            try:
                dynamic_array.remove(remove_index)  # Attempt to remove the element
            except IndexError as e:
                print(f"Error: {e}")  # Handle index out of bounds
        elif command == "GET":
            get_index = int(input_line[1])  # Parse the index to get
            try:
                print(f"Value at index {get_index}: {dynamic_array.get(get_index)}")  # Retrieve and print the value
            except IndexError as e:
                print(f"Error: {e}")  # Handle index out of bounds
        else:
            print("Invalid command.")  # Handle invalid commands

    # Print the final state of the dynamic array and its size
    print(f"Final array: {dynamic_array}")
    print(f"Array size: {dynamic_array.get_size()}")

# <END-OF-CODE>
