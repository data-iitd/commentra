
import sys

class Main:
    # Maximum size of the priority queue
    maxSize = 0
    # Array to hold the elements of the priority queue
    queueArray = []
    # Current number of items in the priority queue
    nItems = 0

    # Constructor to initialize the priority queue with a given size
    def __init__(self, size):
        self.maxSize = size + 1 # +1 to accommodate the unused index 0
        self.queueArray = [0] * self.maxSize # Initialize the queue array
        self.nItems = 0 # Start with zero items

    # Method to maintain the heap property by swimming up the newly added element
    def swim(self, pos):
        # Continue until the position is valid and the parent is less than the current node
        while pos > 1 and self.queueArray[pos / 2] < self.queueArray[pos]:
            # Swap the current node with its parent
            temp = self.queueArray[pos]
            self.queueArray[pos] = self.queueArray[pos / 2]
            self.queueArray[pos / 2] = temp
            pos = pos / 2 # Move up to the parent's position

    # Method to maintain the heap property by sinking down the removed element
    def sink(self, pos):
        # Continue until the position is valid for sinking
        while 2 * pos <= self.nItems:
            current = 2 * pos # Left child position
            # Check if the right child exists and is greater than the left child
            if current < self.nItems and self.queueArray[current] < self.queueArray[current + 1]:
                current += 1 # Move to the right child
            # If the current node is greater than or equal to the largest child, break
            if self.queueArray[pos] >= self.queueArray[current]:
                break
            # Swap the current node with the largest child
            temp = self.queueArray[pos]
            self.queueArray[pos] = self.queueArray[current]
            self.queueArray[current] = temp
            pos = current # Move down to the child's position

    # Method to insert a new value into the priority queue
    def insert(self, value):
        # Check if the queue is full
        if self.isFull():
            raise RuntimeError("Queue is full")
        else:
            # Insert the new value and swim it up to maintain heap property
            self.queueArray[self.nItems + 1] = value
            self.swim(self.nItems + 1)
            self.nItems += 1

    # Method to remove and return the maximum value from the priority queue
    def remove(self):
        # Check if the queue is empty
        if self.isEmpty():
            raise RuntimeError("Queue is Empty")
        else:
            # Store the maximum value to return
            max = self.queueArray[1]
            # Swap the root with the last element
            temp = self.queueArray[1]
            self.queueArray[1] = self.queueArray[self.nItems]
            self.queueArray[self.nItems] = temp
            self.queueArray[self.nItems] = 0 # Remove the last element
            # Sink the new root to maintain heap property
            self.sink(1)
            self.nItems -= 1
            return max # Return the maximum value

    # Method to peek at the maximum value without removing it
    def peek(self):
        # Check if the queue is empty
        if self.isEmpty():
            raise RuntimeError("Queue is Empty")
        return self.queueArray[1] # Return the maximum value

    # Method to check if the queue is empty
    def isEmpty(self):
        return self.nItems == 0 # Return true if there are no items

    # Method to check if the queue is full
    def isFull(self):
        return self.nItems == self.maxSize - 1 # Return true if the queue is full

    # Method to get the current size of the queue
    def getSize(self):
        return self.nItems # Return the number of items in the queue

    # Main method to run the priority queue operations based on user input
    def main(self):
        scanner = sys.stdin # Create a scanner to read user input
        size = int(scanner.readline().strip()) # Read the size of the queue from input
        pq = Main(size) # Create a new priority queue

        # Loop to process user commands until "exit" is entered
        while True:
            command = scanner.readline().strip() # Read the command
            if command == "exit":
                break # Exit the loop if the command is "exit"
            try:
                parts = command.split(" ") # Split the command into parts
                if parts[0] == "insert":
                    # Check if a value is provided for insertion
                    if len(parts) < 2:
                        print("Error: Missing value for insert")
                        continue
                    value = int(parts[1]) # Parse the value to insert
                    pq.insert(value) # Insert the value into the queue
                    print("Inserted: " + str(value))
                elif parts[0] == "remove":
                    # Remove and print the maximum value
                    print("Removed: " + str(pq.remove()))
                elif parts[0] == "peek":
                    # Print the maximum value without removing it
                    print("Peek: " + str(pq.peek()))
                elif parts[0] == "getSize":
                    # Print the current size of the queue
                    print("Size: " + str(pq.getSize()))
                elif parts[0] == "isEmpty":
                    # Check and print if the queue is empty
                    print("Is empty: " + str(pq.isEmpty()))
                else:
                    # Handle unknown commands
                    print("Error: Unknown command")
            except Exception as e:
                # Print any errors that occur during command processing
                print("Error: " + str(e))

if __name__ == "__main__":
    Main().main()
    print("