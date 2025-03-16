
class Main:
    def __init__(self, capacity):
        self.capacity = capacity
        self.size = 0
        self.heap = [0] * (capacity + 1)

    def insert(self, key):
        if self.isFull():
            raise Exception("Main is full. Cannot insert new element.")
        self.heap[self.size + 1] = key
        k = self.size + 1
        while k > 1:
            if self.heap[k] < self.heap[k // 2]:
                self.heap[k], self.heap[k // 2] = self.heap[k // 2], self.heap[k]
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
            self.heap[k], self.heap[minIndex] = self.heap[minIndex], self.heap[k]
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
    scanner = input
    print("Enter the capacity of the Main:")
    capacity = int(scanner())
    queue = Main(capacity)
    print("Enter commands (insert <value>, delete, peek, print, isEmpty):")
    while True:
        command = scanner()
        try:
            if command == "insert":
                value = int(scanner())
                queue.insert(value)
                print("Inserted:", value)
            elif command == "delete":
                print("Deleted:", queue.delete())
            elif command == "peek":
                print("Peek:", queue.peek())
            elif command == "print":
                print("Heap:", end=" ")
                queue.print()
            elif command == "isEmpty":
                print("Is Empty:", queue.isEmpty())
            elif command == "exit":
                print("Exiting...")
                break
            else:
                print("Unknown command:", command)
        except Exception as e:
            print("Error:", e)

