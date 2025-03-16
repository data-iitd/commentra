
import queue

class Main:
    def __init__(self, size):
        self.maxSize = size + 1  # +1 to accommodate the unused index 0
        self.queueArray = [0] * self.maxSize  # Initialize the queue array
        self.nItems = 0  # Start with zero items

    def swim(self, pos):
        while pos > 1 and self.queueArray[pos // 2] < self.queueArray[pos]:
            temp = self.queueArray[pos]
            self.queueArray[pos] = self.queueArray[pos // 2]
            self.queueArray[pos // 2] = temp
            pos = pos // 2

    def sink(self, pos):
        while 2 * pos <= self.nItems:
            current = 2 * pos
            if current < self.nItems and self.queueArray[current] < self.queueArray[current + 1]:
                current += 1
            if self.queueArray[pos] >= self.queueArray[current]:
                break
            temp = self.queueArray[pos]
            self.queueArray[pos] = self.queueArray[current]
            self.queueArray[current] = temp
            pos = current

    def insert(self, value):
        if self.isFull():
            raise Exception("Queue is full")
        self.queueArray[self.nItems + 1] = value
        self.nItems += 1
        self.swim(self.nItems)

    def remove(self):
        if self.isEmpty():
            raise Exception("Queue is Empty")
        max = self.queueArray[1]
        temp = self.queueArray[1]
        self.queueArray[1] = self.queueArray[self.nItems]
        self.queueArray[self.nItems] = temp
        self.nItems -= 1
        self.sink(1)
        return max

    def peek(self):
        if self.isEmpty():
            raise Exception("Queue is Empty")
        return self.queueArray[1]

    def isEmpty(self):
        return self.nItems == 0

    def isFull(self):
        return self.nItems == self.maxSize - 1

    def getSize(self):
        return self.nItems

# Main method to run the priority queue operations based on user input
if __name__ == "__main__":
    size = int(input())  # Read the size of the queue from input
    pq = Main(size)  # Create a new priority queue

    # Loop to process user commands until "exit" is entered
    while True:
        command = input().strip()  # Read the command
        if command.lower() == "exit":
            break  # Exit the loop if the command is "exit"
        try:
            parts = command.split()  # Split the command into parts
            if parts[0].lower() == "insert":
                # Check if a value is provided for insertion
                if len(parts) < 2:
                    print("Error: Missing value for insert")
                    continue
                value = int(parts[1])  # Parse the value to insert
                pq.insert(value)  # Insert the value into the queue
                print("Inserted:", value)
            elif parts[0].lower() == "remove":
                # Remove and print the maximum value
                print("Removed:", pq.remove())
            elif parts[0].lower() == "peek":
                # Print the maximum value without removing it
                print("Peek:", pq.peek())
            elif parts[0].lower() == "getsize":
                # Print the current size of the queue
                print("Size:", pq.getSize())
            elif parts[0].lower() == "isempty":
                # Check and print if the queue is empty
                print("Is empty:", pq.isEmpty())
            else:
                # Handle unknown commands
                print("Error: Unknown command")
        except Exception as e:
            # Print any errors that occur during command processing
            print("Error:", e)

# 