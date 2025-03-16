
import sys

class Main:
    # Initialize the heap with given capacity
    def __init__(self, c):
        self.capacity = c
        self.size = 0
        self.heap = [0] * (c + 1) # Allocate memory for the heap array with given capacity

    # Insert a new element into the heap
    def insert(self, key):
        if self.isFull(): # Check if the heap is full before inserting a new element
            raise Exception("Main is full. Cannot insert new element.")
        self.heap[self.size + 1] = key # Add the new element to the last position of the heap
        k = self.size + 1 # Initialize the index of the newly added element

        while k > 1: # Perform the heapify operation to maintain the heap property
            if self.heap[k] < self.heap[k // 2]:
                temp = self.heap[k]
                self.heap[k] = self.heap[k // 2]
                self.heap[k // 2] = temp
            k = k // 2
        self.size += 1 # Increment the size of the heap after successful insertion

    # Return the minimum element from the heap
    def peek(self):
        if self.isEmpty(): # Check if the heap is empty before returning the minimum element
            raise Exception("Main is empty. Cannot peek.")
        return self.heap[1] # Return the minimum element, which is the first element in the heap

    # Check if the heap is empty
    def isEmpty(self):
        return self.size == 0 # Return true if the size of the heap is zero, indicating an empty heap

    # Check if the heap is full
    def isFull(self):
        return self.size == self.capacity # Return true if the size of the heap reaches the given capacity, indicating a full heap

    # Print the elements of the heap
    def print(self):
        for i in range(1, self.size + 1):
            print(self.heap[i], end=" ") # Print each element in the heap, starting from the first element
        print() # Print a newline character after printing all the elements

    # Sort the elements of the heap using heap sort algorithm
    def heapSort(self):
        for i in range(1, self.size + 1):
            self.delete() # Delete the minimum element from the heap after each iteration

    # Perform the sink operation to maintain the heap property
    def sink(self):
        k = 1 # Initialize the index of the root node
        while 2 * k <= self.size: # Continue the sink operation until the last level of the heap is reached
            minIndex = k # Initialize the index of the minimum element
            if 2 * k <= self.size and self.heap[2 * k] < self.heap[minIndex]:
                minIndex = 2 * k # Update the index of the minimum element if a left child exists and its value is smaller
            if 2 * k + 1 <= self.size and self.heap[2 * k + 1] < self.heap[minIndex]:
                minIndex = 2 * k + 1 # Update the index of the minimum element if a right child exists and its value is smaller
            if minIndex == k: # If the minimum element is already at the current position, break the loop
                break
            temp = self.heap[k] # Swap the elements if the minimum element is not at the current position
            self.heap[k] = self.heap[minIndex]
            self.heap[minIndex] = temp
            k = minIndex # Move to the next level of the heap

    # Delete and return the minimum element from the heap
    def delete(self):
        if self.isEmpty(): # Check if the heap is empty before deleting an element
            raise Exception("Main is empty. Cannot delete.")
        min = self.heap[1] # Store the minimum element in a variable
        self.heap[1] = self.heap[self.size] # Replace the minimum element with the last element of the heap
        self.size -= 1 # Decrement the size of the heap after successful deletion
        self.sink() # Perform the sink operation to maintain the heap property after deletion
        return min # Return the deleted minimum element

# Main method to read user input and perform the required operations
if __name__ == "__main__":
    scanner = sys.stdin # Initialize the Scanner object to read user input

    capacity = int(scanner.readline()) # Read the capacity of the heap from the user input
    queue = Main(capacity) # Create a new instance of the Main class with the given capacity

    while True: # Read user input until the end of the file is reached
        command = scanner.readline().strip() # Read the command from the user input
        if command == "exit":
            break
        try:
            if command == "insert":
                value = int(scanner.readline())
                queue.insert(value)
                print("Inserted: " + str(value))
            elif command == "delete":
                print("Deleted: " + str(queue.delete()))
            elif command == "peek":
                print("Peek: " + str(queue.peek()))
            elif command == "print":
                print("Heap: ", end="")
                queue.print()
            elif command == "isEmpty":
                print("Is Empty: " + str(queue.isEmpty()))
            else:
                print("Unknown command: " + command)
        except Exception as e:
            print("Error: " + str(e))

