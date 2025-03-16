import sys
class Main:
    def __init__(self, size):
        self.maxSize = size + 1
        self.queueArray = [0] * self.maxSize
        self.nItems = 0
    def swim(self, pos):
        while pos > 1 and self.queueArray[pos / 2] < self.queueArray[pos]:
            temp = self.queueArray[pos]
            self.queueArray[pos] = self.queueArray[pos / 2]
            self.queueArray[pos / 2] = temp
            pos = pos / 2
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
        else:
            self.queueArray[self.nItems + 1] = value
            self.swim(self.nItems + 1)
            self.nItems += 1
    def remove(self):
        if self.isEmpty():
            raise Exception("Queue is Empty")
        else:
            max = self.queueArray[1]
            temp = self.queueArray[1]
            self.queueArray[1] = self.queueArray[self.nItems]
            self.queueArray[self.nItems] = temp
            self.queueArray[self.nItems] = 0
            self.sink(1)
            self.nItems -= 1
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
if __name__ == "__main__":
    size = int(raw_input("Enter the size of the priority queue: "))
    pq = Main(size)
    print "Enter commands (insert <value>, remove, peek, getSize, isEmpty, exit):"
    while True:
        command = raw_input().strip()
        if command.lower() == "exit":
            break
        parts = command.split(" ")
        try:
            if parts[0] == "insert":
                if len(parts) < 2:
                    print "Error: Missing value for insert"
                    continue
                value = int(parts[1])
                pq.insert(value)
                print "Inserted: " + str(value)
            elif parts[0] == "remove":
                print "Removed: " + str(pq.remove())
            elif parts[0] == "peek":
                print "Peek: " + str(pq.peek())
            elif parts[0] == "getSize":
                print "Size: " + str(pq.getSize())
            elif parts[0] == "isEmpty":
                print "Is empty: " + str(pq.isEmpty())
            else:
                print "Unknown command: " + parts[0]
        except Exception as e:
            print "Error: " + e.message
