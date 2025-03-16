

class Main:
    def __init__(self, c):
        self.capacity = c
        self.size = 0
        self.heap = [0] * (c + 1)

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
            min_index = k
            if 2 * k <= self.size and self.heap[2 * k] < self.heap[min_index]:
                min_index = 2 * k
            if 2 * k + 1 <= self.size and self.heap[2 * k + 1] < self.heap[min_index]:
                min_index = 2 * k + 1
            if min_index == k:
                break
            temp = self.heap[k]
            self.heap[k] = self.heap[min_index]
            self.heap[min_index] = temp
            k = min_index

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

    print("Enter commands (insert <value>, delete, peek, print, isEmpty):")
    while True:
        command = input()
        if command == "exit":
            print("Exiting...")
            break
        try:
            command, *args = command.split()
            if command == "insert":
                value = int(args[0])
                queue.insert(value)
                print(f"Inserted: {value}")
            elif command == "delete":
                print(f"Deleted: {queue.delete()}")
            elif command == "peek":
                print(f"Peek: {queue.peek()}")
            elif command == "print":
                print("Heap:", end=" ")
                queue.print()
            elif command == "isEmpty":
                print(f"Is Empty: {queue.isEmpty()}")
            else:
                print(f"Unknown command: {command}")
        except Exception as e:
            print(f"Error: {e}")

