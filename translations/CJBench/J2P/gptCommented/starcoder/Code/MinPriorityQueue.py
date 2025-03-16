import sys

class Main:
    # Array to represent the heap
    heap = []
    # Maximum capacity of the heap
    capacity = 0
    # Current size of the heap
    size = 0

    # Constructor to initialize the heap with a given capacity
    def __init__(self, c):
        self.capacity = c
        self.size = 0
        self.heap = [0] * (c + 1) # Heap is 1-indexed

    # Method to insert a new key into the heap
    def insert(self, key):
        # Check if the heap is full before inserting
        if self.isFull():
            raise Exception("Main is full. Cannot insert new element.")
        # Place the new key at the end of the heap
        self.heap[self.size + 1] = key
        k = self.size + 1

        # Bubble up the new key to maintain heap property
        while k > 1:
            if self.heap[k] < self.heap[k / 2]:
                # Swap if the current key is smaller than its parent
                temp = self.heap[k]
                self.heap[k] = self.heap[k / 2]
                self.heap[k / 2] = temp
            k = k / 2 # Move to the parent index
        self.size += 1 # Increase the size of the heap

    # Method to get the minimum element without removing it
    def peek(self):
        # Check if the heap is empty before peeking
        if self.isEmpty():
            raise Exception("Main is empty. Cannot peek.")
        return self.heap[1] # Return the root of the heap

    # Method to check if the heap is empty
    def isEmpty(self):
        return self.size == 0 # Returns true if size is 0

    # Method to check if the heap is full
    def isFull(self):
        return self.size == self.capacity # Returns true if size equals capacity

    # Method to print the elements of the heap
    def print(self):
        for i in range(1, self.size + 1):
            print(self.heap[i], end=" ") # Print each element
        print() # New line after printing all elements

    # Method to perform heap sort by deleting all elements
    def heapSort(self):
        for i in range(1, self.size + 1):
            self.delete() # Delete elements one by one

    # Method to maintain the heap property after deletion
    def sink(self):
        k = 1 # Start from the root
        while 2 * k <= self.size: # While there is at least one child
            minIndex = k # Assume current index is the smallest
            # Check left child
            if 2 * k <= self.size and self.heap[2 * k] < self.heap[minIndex]:
                minIndex = 2 * k # Update minIndex if left child is smaller
            # Check right child
            if 2 * k + 1 <= self.size and self.heap[2 * k + 1] < self.heap[minIndex]:
                minIndex = 2 * k + 1 # Update minIndex if right child is smaller
            # If the current index is the smallest, break
            if minIndex == k:
                break
            # Swap current index with the smallest child
            temp = self.heap[k]
            self.heap[k] = self.heap[minIndex]
            self.heap[minIndex] = temp
            k = minIndex # Move down to the smallest child

    # Method to delete and return the minimum element from the heap
    def delete(self):
        # Check if the heap is empty before deleting
        if self.isEmpty():
            raise Exception("Main is empty. Cannot delete.")
        min = self.heap[1] # Store the minimum element
        self.heap[1] = self.heap[self.size] # Replace root with the last element
        self.size -= 1 # Decrease the size of the heap
        self.sink() # Restore heap property
        return min # Return the minimum element

# Main method to run the program
if __name__ == "__main__":
    capacity = int(sys.stdin.readline()) # Read the capacity of the heap
    queue = Main(capacity) # Create a new heap with the specified capacity

    # Process commands until the user decides to exit
    while True:
        command = sys.stdin.readline().strip() # Read the command
        try:
            if command == "insert":
                value = int(sys.stdin.readline()) # Read the value to insert
                queue.insert(value) # Insert the value into the heap
                print("Inserted: " + str(value))
            elif command == "delete":
                print("Deleted: " + str(queue.delete())) # Delete and print the minimum element
            elif command == "peek":
                print("Peek: " + str(queue.peek())) # Print the minimum element without deleting
            elif command == "print":
                print("Heap: ", end="")
                queue.print() # Print all elements in the heap
            elif command == "isEmpty":
                print("Is Empty: " + str(queue.isEmpty())) # Check if the heap is empty
            elif command == "exit":
                print("Exiting...") # Exit the program
                break
            else:
                print("Unknown command: " + command) # Handle unknown commands
        except Exception as e:
            print("Error: " + str(e)) # Handle exceptions

