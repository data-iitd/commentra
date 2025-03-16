class MinHeap:
    def __init__(self, capacity):
        self.capacity = capacity
        self.size = 0
        self.heap = [0] * (capacity + 1)  # Allocate memory for the heap array with given capacity

    def insert(self, key):
        if self.is_full():  # Check if the heap is full before inserting a new element
            raise Exception("MinHeap is full. Cannot insert new element.")
        self.size += 1
        self.heap[self.size] = key  # Add the new element to the last position of the heap
        k = self.size  # Initialize the index of the newly added element

        while k > 1:  # Perform the heapify operation to maintain the heap property
            if self.heap[k] < self.heap[k // 2]:
                self.heap[k], self.heap[k // 2] = self.heap[k // 2], self.heap[k]  # Swap
            k //= 2

    def peek(self):
        if self.is_empty():  # Check if the heap is empty before returning the minimum element
            raise Exception("MinHeap is empty. Cannot peek.")
        return self.heap[1]  # Return the minimum element, which is the first element in the heap

    def is_empty(self):
        return self.size == 0  # Return true if the size of the heap is zero, indicating an empty heap

    def is_full(self):
        return self.size == self.capacity  # Return true if the size of the heap reaches the given capacity, indicating a full heap

    def print_heap(self):
        for i in range(1, self.size + 1):
            print(self.heap[i], end=" ")  # Print each element in the heap, starting from the first element
        print()  # Print a newline character after printing all the elements

    def heap_sort(self):
        sorted_array = []
        while not self.is_empty():
            sorted_array.append(self.delete())  # Delete the minimum element from the heap after each iteration
        return sorted_array

    def sink(self):
        k = 1  # Initialize the index of the root node
        while 2 * k <= self.size:  # Continue the sink operation until the last level of the heap is reached
            min_index = k  # Initialize the index of the minimum element
            if 2 * k <= self.size and self.heap[2 * k] < self.heap[min_index]:
                min_index = 2 * k  # Update the index of the minimum element if a left child exists and its value is smaller
            if 2 * k + 1 <= self.size and self.heap[2 * k + 1] < self.heap[min_index]:
                min_index = 2 * k + 1  # Update the index of the minimum element if a right child exists and its value is smaller
            if min_index == k:  # If the minimum element is already at the current position, break the loop
                break
            self.heap[k], self.heap[min_index] = self.heap[min_index], self.heap[k]  # Swap
            k = min_index  # Move to the next level of the heap

    def delete(self):
        if self.is_empty():  # Check if the heap is empty before deleting an element
            raise Exception("MinHeap is empty. Cannot delete.")
        min_value = self.heap[1]  # Store the minimum element in a variable
        self.heap[1] = self.heap[self.size]  # Replace the minimum element with the last element of the heap
        self.size -= 1  # Decrement the size of the heap after successful deletion
        self.sink()  # Perform the sink operation to maintain the heap property after deletion
        return min_value  # Return the deleted minimum element


def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    capacity = int(data[0])  # Read the capacity of the heap from the user input
    queue = MinHeap(capacity)  # Create a new instance of the MinHeap class with the given capacity

    for line in data[1:]:
        command = line.split()  # Read the command from the user input
        try:
            if command[0] == "insert":
                value = int(command[1])
                queue.insert(value)
                print(f"Inserted: {value}")
            elif command[0] == "delete":
                print(f"Deleted: {queue.delete()}")
            elif command[0] == "peek":
                print(f"Peek: {queue.peek()}")
            elif command[0] == "print":
                print("Heap: ", end="")
                queue.print_heap()
            elif command[0] == "isEmpty":
                print(f"Is Empty: {queue.is_empty()}")
            elif command[0] == "exit":
                print("Exiting...")
                return
            else:
                print(f"Unknown command: {command[0]}")
        except Exception as e:
            print(f"Error: {e}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
