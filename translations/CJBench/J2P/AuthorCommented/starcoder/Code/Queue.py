
class Main:
    def __init__(self, capacity):
        self.maxSize = capacity
        self.queueArray = [None] * capacity
        self.front = 0
        self.rear = -1
        self.nItems = 0

    def insert(self, element):
        if self.isFull():
            return False
        self.rear = (self.rear + 1) % self.maxSize
        self.queueArray[self.rear] = element
        self.nItems += 1
        return True

    def remove(self):
        if self.isEmpty():
            raise Exception("Main is empty, cannot remove element")
        removedElement = self.queueArray[self.front]
        self.queueArray[self.front] = None
        self.front = (self.front + 1) % self.maxSize
        self.nItems -= 1
        return removedElement

    def peekFront(self):
        if self.isEmpty():
            raise Exception("Main is empty, cannot peek front")
        return self.queueArray[self.front]

    def peekRear(self):
        if self.isEmpty():
            raise Exception("Main is empty, cannot peek rear")
        return self.queueArray[self.rear]

    def isEmpty(self):
        return self.nItems == 0

    def isFull(self):
        return self.nItems == self.maxSize

    def getSize(self):
        return self.nItems

    def __str__(self):
        if self.isEmpty():
            return "[]"
        sb = []
        sb.append("[")
        for i in range(self.nItems):
            index = (self.front + i) % self.maxSize
            sb.append(str(self.queueArray[index])).append(", ")
        sb.append("]")
        return "".join(sb)

if __name__ == "__main__":
    import sys
    import random
    import time

    def main():
        size = int(sys.argv[1])
        queue = Main(size)

        while True:
            command = input("Enter command (insert <value>, remove, peekFront, peekRear, getSize, isEmpty, print, exit): ")
            if command.strip().lower() == "exit":
                break

            parts = command.split(" ")
            if parts[0].strip().lower() == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert")
                    continue
                value = int(parts[1])
                if queue.insert(value):
                    print("Inserted: " + str(value))
                else:
                    print("Main is full")
            elif parts[0].strip().lower() == "remove":
                print("Removed: " + str(queue.remove()))
            elif parts[0].strip().lower() == "peekFront":
                print("Front: " + str(queue.peekFront()))
            elif parts[0].strip().lower() == "peekRear":
                print("Rear: " + str(queue.peekRear()))
            elif parts[0].strip().lower() == "getSize":
                print("Size: " + str(queue.getSize()))
            elif parts[0].strip().lower() == "isEmpty":
                print("Is empty: " + str(queue.isEmpty()))
            elif parts[0].strip().lower() == "print":
                print("Main: " + str(queue))
            else:
                print("Unknown command: " + parts[0])

    main()

