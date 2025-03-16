class Main:
    def __init__(self, c):
        self.capacity = c
        self.size = 0
        self.heap = [0] * (c + 1)

    def insert(self, key):
        if self.is_full():
            raise Exception("Main is full. Cannot insert new element.")
        self.heap[self.size + 1] = key
        k = self.size + 1
        while k > 1:
            if self.heap[k] < self.heap[k // 2]:
                self.heap[k], self.heap[k // 2] = self.heap[k // 2], self.heap[k]
            k = k // 2
        self.size += 1

    def peek(self):
        if self.is_empty():
            raise Exception("Main is empty. Cannot peek.")
        return self.heap[1]

    def is_empty(self):
        return self.size == 0

    def is_full(self):
        return self.size == self.capacity

    def print(self):
        for i in range(1, self.size + 1):
            print(self.heap[i], end=" ")
        print()

    def heap_sort(self):
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

            self.heap[k], self.heap[min_index] = self.heap[min_index], self.heap[k]

            k = min_index

    def delete(self):
        if self.is_empty():
            raise Exception("Main is empty. Cannot delete.")
        min_val = self.heap[1]
        self.heap[1] = self.heap[self.size]
        self.size -= 1
        self.sink()
        return min_val


if __name__ == "__main__":
    import sys

    capacity = int(input("Enter the capacity of the Main: "))
    queue = Main(capacity)

    while True:
        command = input().strip()

        if command == "exit":
            print("Exiting...")
            break

        try:
            parts = command.split()
            if parts[0] == "insert":
                value = int(parts[1])
                queue.insert(value)
                print(f"Inserted: {value}")
            elif parts[0] == "delete":
                print(f"Deleted: {queue.delete()}")
            elif parts[0] == "peek":
                print(f"Peek: {queue.peek()}")
            elif parts[0] == "print":
                print("Heap: ", end="")
                queue.print()
            elif parts[0] == "isEmpty":
                print(f"Is Empty: {queue.is_empty()}")
            else:
                print(f"Unknown command: {command}")
        except Exception as e:
            print(f"Error: {e}")
