
class Main:
    def __init__(self, capacity):
        self.capacity = capacity
        self.size = 0
        self.heap = [0] * (capacity + 1)  # Heap is 1-indexed

    def insert(self, key):
        # Check if the heap is full before inserting
        if self.is_full():
            raise Exception("Main is full. Cannot insert new element.")
        # Place the new key at the end of the heap
        self.heap[self.size + 1] = key
        k = self.size + 1
        # Bubble up the new key to maintain heap property
        while k > 1:
            if self.heap[k] < self.heap[k // 2]:
                # Swap if the current key is smaller than its parent
                temp = self.heap[k]
                self.heap[k] = self.heap[k // 2]
                self.heap[k // 2] = temp
            k = k // 2  # Move to the parent index
        self.size += 1  # Increase the size of the heap

    def peek(self):
        # Check if the heap is empty before peeking
        if self.is_empty():
            raise Exception("Main is empty. Cannot peek.")
        return self.heap[1]  # Return the root of the heap

    def is_empty(self):
        return self.size == 0  # Returns true if size is 0

    def is_full(self):
        return self.size == self.capacity  # Returns true if size equals capacity

    def print(self):
        for i in range(1, self.size + 1):
            print(self.heap[i], end=" ")  # Print each element
        print()  # New line after printing all elements

    def heap_sort(self):
        for i in range(1, self.size + 1):
            self.delete()  # Delete elements one by one

    def sink(self):
        k = 1  # Start from the root
        while 2 * k <= self.size:  # While there is at least one child
            min_index = k  # Assume current index is the smallest
            # Check left child
            if 2 * k <= self.size and self.heap[2 * k] < self.heap[min_index]:
                min_index = 2 * k  # Update min_index if left child is smaller
            # Check right child
            if 2 * k + 1 <= self.size and self.heap[2 * k + 1] < self.heap[min_index]:
                min_index = 2 * k + 1  # Update min_index if right child is smaller
            # If the current index is the smallest, break
            if min_index == k:
                break
            # Swap current index with the smallest child
            temp = self.heap[k]
            self.heap[k] = self.heap[min_index]
            self.heap[min_index] = temp
            k = min_index  # Move down to the smallest child

    def delete(self):
        # Check if the heap is empty before deleting
        if self.is_empty():
            raise Exception("Main is empty. Cannot delete.")
        min = self.heap[1]  # Store the minimum element
        self.heap[1] = self.heap[self.size]  # Replace root with the last element
        self.size -= 1  # Decrease the size of the heap
        self.sink()  # Restore heap property
        return min  # Return the minimum element

# Main method to run the program
if __name__ == "__main__":
    capacity = int(input())  # Read the capacity of the heap
    queue = Main(capacity)  # Create a new heap with the specified capacity

    # Process commands until the user decides to exit
    while True:
        command = input()  # Read the command
        try:
            if command == "insert":
                value = int(input())  # Read the value to insert
                queue.insert(value)  # Insert the value into the heap
                print("Inserted:", value)
            elif command == "delete":
                print("Deleted:", queue.delete())  # Delete and print the minimum element
            elif command == "peek":
                print("Peek:", queue.peek())  # Print the minimum element without deleting
            elif command == "print":
                print("Heap:", end=" ")
                queue.print()  # Print all elements in the heap
            elif command == "isEmpty":
                print("Is Empty:", queue.is_empty())  # Check if the heap is empty
            elif command == "exit":
                print("Exiting...")  # Exit the program
                break
            else:
                print("Unknown command:", command)  # Handle unknown commands
        except Exception as e:
            print("Error:", e)  # Handle exceptions

