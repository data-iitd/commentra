
import sys

class Main:
    def __init__(self, capacity):
        self.heap = [0] * (capacity + 1)
        self.capacity = capacity
        self.size = 0

    def insert(self, key):
        if self.isFull():
            raise Exception("Main is full. Cannot insert new element.")
        self.heap[self.size + 1] = key
        k = self.size + 1
        while k > 1:
            if self.heap[k] < self.heap[k // 2]:
                temp = self.heap[k]
                self.heap[k] = self.heap[k // 2]
                self.heap[k // 2] = temp
            k = k // 2
        self.size += 1

    def peek(self):
        if self.isEmpty():
            raise Exception("Main is empty. Cannot peek.")
        return self.heap[1]

    def isEmpty(self):
        return self.size == 0

    def isFull(self):
        return self.size == self.capacity

    def print(self):
        for i in range(1, self.size + 1):
            print(self.heap[i], end=" ")
        print()

    def heapSort(self):
        for i in range(1, self.size + 1):
            self.delete()

    def sink(self):
        k = 1
        while 2 * k <= self.size:
            minIndex = k
            if 2 * k <= self.size and self.heap[2 * k] < self.heap[minIndex]:
                minIndex = 2 * k
            if 2 * k + 1 <= self.size and self.heap[2 * k + 1] < self.heap[minIndex]:
                minIndex = 2 * k + 1

            if minIndex == k:
                break

            temp = self.heap[k]
            self.heap[k] = self.heap[minIndex]
            self.heap[minIndex] = temp

            k = minIndex

    def delete(self):
        if self.isEmpty():
            raise Exception("Main is empty. Cannot delete.")
        min = self.heap[1]
        self.heap[1] = self.heap[self.size]
        self.size -= 1
        self.sink()
        return min

if __name__ == "__main__":
    capacity = int(input("Enter the capacity of the Main: "))
    queue = Main(capacity)

    while True:
        command = input("Enter commands (insert <value>, delete, peek, print, isEmpty): ")
        if command == "exit":
            break

        parts = command.split()
        if len(parts) == 0:
            continue

        try:
            if parts[0] == "insert":
                value = int(parts[1])
                queue.insert(value)
                print("Inserted: " + str(value))
            elif parts[0] == "delete":
                print("Deleted: " + str(queue.delete()))
            elif parts[0] == "peek":
                print("Peek: " + str(queue.peek()))
            elif parts[0] == "print":
                print("Heap: ", end="")
                queue.print()
            elif parts[0] == "isEmpty":
                print("Is Empty: " + str(queue.isEmpty()))
            else:
                print("Unknown command: " + parts[0])
        except Exception as e:
            print("Error: " + str(e))

