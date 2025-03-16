class MinHeap:
    def __init__(self, capacity):
        self.capacity = capacity
        self.size = 0
        self.heap = [0] * (capacity + 1)

    def insert(self, key):
        if self.is_full():
            raise Exception("Heap is full. Cannot insert new element.")
        self.size += 1
        self.heap[self.size] = key
        self.heapify_up()

    def peek(self):
        if self.is_empty():
            raise Exception("Heap is empty. Cannot peek.")
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

    def heapify_up(self):
        k = self.size
        while k > 1 and self.heap[k] < self.heap[k // 2]:
            self.heap[k], self.heap[k // 2] = self.heap[k // 2], self.heap[k]
            k = k // 2

    def delete(self):
        if self.is_empty():
            raise Exception("Heap is empty. Cannot delete.")
        min_value = self.heap[1]
        self.heap[1] = self.heap[self.size]
        self.size -= 1
        self.heapify_down()
        return min_value

    def heapify_down(self):
        k = 1
        while 2 * k <= self.size:
            min_index = k
            if self.heap[2 * k] < self.heap[min_index]:
                min_index = 2 * k
            if 2 * k + 1 <= self.size and self.heap[2 * k + 1] < self.heap[min_index]:
                min_index = 2 * k + 1
            if min_index == k:
                break
            self.heap[k], self.heap[min_index] = self.heap[min_index], self.heap[k]
            k = min_index


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    capacity = int(data[index])
    index += 1
    queue = MinHeap(capacity)

    while index < len(data):
        command = data[index]
        index += 1
        try:
            if command == "insert":
                value = int(data[index])
                index += 1
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


if __name__ == "__main__":
    main()
