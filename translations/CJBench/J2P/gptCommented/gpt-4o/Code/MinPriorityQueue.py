class MinHeap:
    def __init__(self, capacity):
        self.capacity = capacity
        self.size = 0
        self.heap = [0] * (capacity + 1)  # Heap is 1-indexed

    def insert(self, key):
        if self.is_full():
            raise Exception("Heap is full. Cannot insert new element.")
        self.size += 1
        self.heap[self.size] = key
        k = self.size

        while k > 1:
            if self.heap[k] < self.heap[k // 2]:
                # Swap if the current key is smaller than its parent
                self.heap[k], self.heap[k // 2] = self.heap[k // 2], self.heap[k]
            k = k // 2  # Move to the parent index

    def peek(self):
        if self.is_empty():
            raise Exception("Heap is empty. Cannot peek.")
        return self.heap[1]  # Return the root of the heap

    def is_empty(self):
        return self.size == 0  # Returns true if size is 0

    def is_full(self):
        return self.size == self.capacity  # Returns true if size equals capacity

    def print_heap(self):
        for i in range(1, self.size + 1):
            print(self.heap[i], end=" ")  # Print each element
        print()  # New line after printing all elements

    def heap_sort(self):
        sorted_elements = []
        while not self.is_empty():
            sorted_elements.append(self.delete())  # Delete elements one by one
        return sorted_elements

    def sink(self):
        k = 1  # Start from the root
        while 2 * k <= self.size:  # While there is at least one child
            min_index = k  # Assume current index is the smallest
            # Check left child
            if 2 * k <= self.size and self.heap[2 * k] < self.heap[min_index]:
                min_index = 2 * k  # Update minIndex if left child is smaller
            # Check right child
            if 2 * k + 1 <= self.size and self.heap[2 * k + 1] < self.heap[min_index]:
                min_index = 2 * k + 1  # Update minIndex if right child is smaller
            # If the current index is the smallest, break
            if min_index == k:
                break
            # Swap current index with the smallest child
            self.heap[k], self.heap[min_index] = self.heap[min_index], self.heap[k]
            k = min_index  # Move down to the smallest child

    def delete(self):
        if self.is_empty():
            raise Exception("Heap is empty. Cannot delete.")
        min_value = self.heap[1]  # Store the minimum element
        self.heap[1] = self.heap[self.size]  # Replace root with the last element
        self.size -= 1  # Decrease the size of the heap
        self.sink()  # Restore heap property
        return min_value  # Return the minimum element


def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    capacity = int(data[0])  # Read the capacity of the heap
    heap = MinHeap(capacity)  # Create a new heap with the specified capacity

    # Process commands
    for line in data[1:]:
        command = line.split()
        try:
            if command[0] == "insert":
                value = int(command[1])  # Read the value to insert
                heap.insert(value)  # Insert the value into the heap
                print(f"Inserted: {value}")
            elif command[0] == "delete":
                print(f"Deleted: {heap.delete()}")  # Delete and print the minimum element
            elif command[0] == "peek":
                print(f"Peek: {heap.peek()}")  # Print the minimum element without deleting
            elif command[0] == "print":
                print("Heap: ", end="")
                heap.print_heap()  # Print all elements in the heap
            elif command[0] == "isEmpty":
                print(f"Is Empty: {heap.is_empty()}")  # Check if the heap is empty
            elif command[0] == "exit":
                print("Exiting...")  # Exit the program
                return
            else:
                print(f"Unknown command: {command[0]}")  # Handle unknown commands
        except Exception as e:
            print(f"Error: {e}")  # Handle exceptions


if __name__ == "__main__":
    main()

# <END-OF-CODE>
