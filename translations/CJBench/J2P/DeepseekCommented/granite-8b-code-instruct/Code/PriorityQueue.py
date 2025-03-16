
class Main:
    def __init__(self, size):
        self.maxSize = size + 1  # Add 1 to accommodate 1-based indexing
        self.queueArray = [0] * self.maxSize  # Initialize the array
        self.nItems = 0  # No items initially

    # Swim method to maintain the heap property by moving an item up
    def swim(self, pos):
        while pos > 1 and (self.queueArray[pos // 2] < self.queueArray[pos]):
            temp = self.queueArray[pos]
            self.queueArray[pos] = self.queueArray[pos // 2]
            self.queueArray[pos // 2] = temp
            pos = pos // 2

    # Sink method to maintain the heap property by moving an item down
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

    # Method to insert a new value into the priority queue
    def insert(self, value):
        if self.isFull():
            raise Exception("Queue is full")
        else:
            self.queueArray[self.nItems + 1] = value  # Insert the value at the end and increment nItems
            self.swim(self.nItems + 1)  # Swim the value up to maintain heap property
            self.nItems += 1

    # Method to remove and return the maximum value from the priority queue
    def remove(self):
        if self.isEmpty():
            raise Exception("Queue is Empty")
        else:
            max = self.queueArray[1]  # Get the maximum value
            temp = self.queueArray[1]
            self.queueArray[1] = self.queueArray[self.nItems]  # Replace the root with the last item
            self.queueArray[self.nItems] = temp
            self.queueArray[self.nItems] = 0  # Decrement nItems and clear the last position
            self.sink(1)  # Sink the new root down to maintain heap property
            self.nItems -= 1
            return max

    # Method to return the maximum value without removing it
    def peek(self):
        if self.isEmpty():
            raise Exception("Queue is Empty")
        return self.queueArray[1]

    # Method to check if the queue is empty
    def isEmpty(self):
        return (self.nItems == 0)

    # Method to check if the queue is full
    def isFull(self):
        return (self.nItems == self.maxSize - 1)

    # Method to get the number of items in the queue
    def getSize(self):
        return self.nItems

# Main method to allow user interaction via command line
if __name__ == "__main__":
    import sys
    size = int(input())
    pq = Main(size)
    while True:
        try:
            command = input().strip()
            if command.lower() == "exit":
                break
            parts = command.split()
            if len(parts) < 1:
                raise Exception("Error: Missing command")
            cmd = parts[0].lower()
            if cmd == "insert":
                if len(parts) < 2:
                    raise Exception("Error: Missing value for insert")
                value = int(parts[1])
                pq.insert(value)
                print("Inserted:", value)
            elif cmd == "remove":
                print("Removed:", pq.remove())
            elif cmd == "peek":
                print("Peek:", pq.peek())
            elif cmd == "getsize":
                print("Size:", pq.getSize())
            elif cmd == "isempty":
                print("Is empty:", pq.isEmpty())
            else:
                raise Exception("Error: Invalid command")
        except Exception as e:
            print("Error:", e)

# End of code