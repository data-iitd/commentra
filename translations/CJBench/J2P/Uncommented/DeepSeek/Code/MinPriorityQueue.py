class MinHeap:
    def __init__(self, capacity):
        self.capacity = capacity
        self.size = 0
        self.heap = [0] * (capacity + 1)

    def insert(self, key):
        if self.is_full():
            raise ValueError("Heap is full. Cannot insert new element.")
        self.heap[self.size + 1] = key
        k = self.size + 1
        while k > 1:
            if self.heap[k] < self.heap[k // 2]:
                self.heap[k], self.heap[k // 2] = self.heap[k // 2], self.heap[k]
            k = k // 2
        self.size += 1

    def peek(self):
        if self.is_empty():
            raise ValueError("Heap is empty. Cannot peek.")
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
            raise ValueError("Heap is empty. Cannot delete.")
        min_val = self.heap[1]
        self.heap[1] = self.heap[self.size]
        self.size -= 1
        self.sink()
        return min_val


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    capacity = int(data[0])
    queue = MinHeap(capacity)
    i = 1
    while i < len(data):
        command = data[i]
        i += 1
        try:
            if command == "insert":
                value = int(data[i])
                i += 1
                queue.insert(value)
                print(f"Inserted: {value}")
            elif command == "delete":
                print(f"Deleted: {queue.delete()}")
            elif command == "peek":
                print(f"Peek: {queue.peek()}")
            elif command == "print":
                print("Heap: ", end="")
                queue.print()
            elif command == "isEmpty":
                print(f"Is Empty: {queue.is_empty()}")
            elif command == "exit":
                print("Exiting...")
                break
            else:
                print(f"Unknown command: {command}")
        except Exception as e:
            print(f"Error: {e}")


main()
