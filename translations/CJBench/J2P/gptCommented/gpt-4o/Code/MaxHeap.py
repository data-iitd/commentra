class HeapElement:
    def __init__(self, key, info=None):
        self.key = key
        self.info = info

    def get_key(self):
        return self.key

    def __str__(self):
        return f"HeapElement(key={self.key}, info={self.info})"


class MaxHeap:
    def __init__(self):
        self.max_heap = []  # List to store the elements of the max heap

    def heapify_down(self, element_index):
        largest = element_index - 1  # Index of the current element
        left_child = 2 * element_index - 1  # Index of the left child
        right_child = 2 * element_index  # Index of the right child

        # Check if the left child exists and is greater than the current largest
        if left_child < len(self.max_heap) and self.max_heap[left_child].get_key() > self.max_heap[largest].get_key():
            largest = left_child  # Update largest to left child

        # Check if the right child exists and is greater than the current largest
        if right_child < len(self.max_heap) and self.max_heap[right_child].get_key() > self.max_heap[largest].get_key():
            largest = right_child  # Update largest to right child

        # If the largest is not the current element, swap and continue heapifying down
        if largest != element_index - 1:
            self.max_heap[element_index - 1], self.max_heap[largest] = self.max_heap[largest], self.max_heap[element_index - 1]
            self.heapify_down(largest + 1)  # Recursively heapify down

    def toggle_up(self, element_index):
        key = self.max_heap[element_index - 1].get_key()  # Get the key of the element to be moved up
        # Move the element up while it is greater than its parent
        while element_index > 1 and self.max_heap[element_index // 2 - 1].get_key() < key:
            self.max_heap[element_index - 1], self.max_heap[element_index // 2 - 1] = self.max_heap[element_index // 2 - 1], self.max_heap[element_index - 1]
            element_index //= 2  # Move to the parent's index

    def insert_element(self, element):
        if element is None:
            raise ValueError("Cannot insert null element")  # Validate input
        self.max_heap.append(element)  # Add the new element to the heap
        self.toggle_up(len(self.max_heap))  # Restore heap property by moving the new element up

    def extract_max(self):
        if not self.max_heap:
            raise IndexError("Heap is empty")  # Validate heap is not empty
        max_element = self.max_heap[0]  # Get the maximum element
        self.max_heap[0] = self.max_heap[-1]  # Replace max with the last element
        self.max_heap.pop()  # Remove the last element
        if self.max_heap:
            self.heapify_down(1)  # Restore heap property by moving down the new root
        return max_element  # Return the extracted maximum element

    def get_max(self):
        if not self.max_heap:
            raise IndexError("Heap is empty")  # Validate heap is not empty
        return self.max_heap[0]  # Return the maximum element

    def size(self):
        return len(self.max_heap)  # Return the number of elements in the heap

    def is_empty(self):
        return len(self.max_heap) == 0  # Return true if the heap is empty


def main():
    import sys

    heap = MaxHeap()  # Create a new instance of the heap

    # Loop to process user commands
    for line in sys.stdin:
        command = line.strip()  # Read the command
        if not command: break  # Exit on empty command
        parts = command.split()  # Split command into parts
        operation = parts[0]  # Get the operation type

        try:
            # Switch case to handle different heap operations
            if operation == "insert":
                key = float(parts[1])  # Parse the key
                info = parts[2] if len(parts) > 2 else None  # Optional info
                heap.insert_element(HeapElement(key, info))  # Insert the new element
                print(f"Inserted: {key}")  # Confirm insertion
            elif operation == "extractMax":
                print(f"Extracted Max: {heap.extract_max()}")  # Extract and display max
            elif operation == "getMax":
                print(f"Max Element: {heap.get_max()}")  # Display max without extraction
            elif operation == "size":
                print(f"Size: {heap.size()}")  # Display the size of the heap
            elif operation == "isEmpty":
                print(f"Is Empty: {heap.is_empty()}")  # Check if the heap is empty
            else:
                print(f"Unknown operation: {operation}")  # Handle unknown commands
        except Exception as e:
            print(f"Error: {e}")  # Handle exceptions


if __name__ == "__main__":
    main()

# <END-OF-CODE>
