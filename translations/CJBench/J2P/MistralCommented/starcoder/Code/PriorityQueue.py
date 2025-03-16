
import sys

class Main:
    def __init__(self, size):
        self.maxSize = size + 1
        self.queueArray = [0] * self.maxSize
        self.nItems = 0

    # Swim function to bring element up in heap if it is less than its parent
    def swim(self, pos):
        while pos > 1 and (self.queueArray[pos / 2] < self.queueArray[pos]):
            temp = self.queueArray[pos]
            self.queueArray[pos] = self.queueArray[pos / 2]
            self.queueArray[pos / 2] = temp
            pos = pos / 2

    # Sink function to bring element down in heap if it is greater than its children
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

    # Insert function to add new element in the queue
    def insert(self, value):
        if self.isFull(): # Checking if queue is full before inserting new element
            raise Exception("Queue is full")
        else:
            self.queueArray[self.nItems + 1] = value # Adding new element at the end of the queue
            self.swim(self.nItems + 1) # Swimming up the new element to maintain heap property
            self.nItems += 1

    # Remove function to remove and return the maximum element from the queue
    def remove(self):
        if self.isEmpty(): # Checking if queue is empty before removing an element
            raise Exception("Queue is Empty")
        else:
            max = self.queueArray[1] # Storing the maximum element at the root of the heap
            temp = self.queueArray[1]
            self.queueArray[1] = self.queueArray[self.nItems] # Replacing the maximum element with the last element
            self.queueArray[self.nItems] = 0 # Decreasing the size of the queue by one
            self.nItems -= 1
            self.sink(1) # Sinking down the new root element to maintain heap property
            return max

    # Peek function to return the maximum element from the queue without removing it
    def peek(self):
        if self.isEmpty(): # Checking if queue is empty before returning the maximum element
            raise Exception("Queue is Empty")
        return self.queueArray[1] # Returning the maximum element at the root of the heap

    # Checking if the queue is empty or not
    def isEmpty(self):
        return (self.nItems == 0)

    # Checking if the queue is full or not
    def isFull(self):
        return (self.nItems == self.maxSize - 1)

    # Function to get the current size of the queue
    def getSize(self):
        return self.nItems

if __name__ == "__main__":
    size = int(raw_input())
    pq = Main(size)

    while True:
        command = raw_input().strip()
        if command.lower() == "exit":
            break

        parts = command.split(" ")
        try:
            if parts[0].lower() == "insert":
                if len(parts) < 2:
                    print "Error: Missing value for insert"
                    continue
                value = int(parts[1])
                pq.insert(value)
                print "Inserted: " + str(value)
            elif parts[0].lower() == "remove":
                print "Removed: " + str(pq.remove())
            elif parts[0].lower() == "peek":
                print "Peek: " + str(pq.peek())
            elif parts[0].lower() == "getSize":
                print "Size: " + str(pq.getSize())
            elif parts[0].lower() == "isEmpty":
                print "Is empty: " + str(pq.isEmpty())
            else:
                print "Error: Unknown command"
        except Exception as e:
            print "Error: " + e.message

