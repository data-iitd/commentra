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
        k = self.size
        while k > 1:
            if self.heap[k] < self.heap[k // 2]:
                self.heap[k], self.heap[k // 2] = self.heap[k // 2], self.heap[k]
            k //= 2

    def peek(self):
        if self.is_empty():
            raise Exception("Heap is empty. Cannot peek.")
        return self.heap[1]

    def is_empty(self):
        return self.size == 0

    def is_full(self):
        return self.size == self.capacity

    def print_heap(self):
        for i in range(1, self.size + 1):
            print(self.heap[i], end=" ")
        print()

    def heap_sort(self):
        sorted_array = []
        for _ in range(self.size):
            sorted_array.append(self.delete())
        return sorted_array

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
            raise Exception("Heap is empty. Cannot delete.")
        min_value = self.heap[1]
        self.heap[1] = self.heap[self.size]
        self.size -= 1
        self.sink()
        return min_value


def main():
    capacity = int(input("Enter the capacity of the Heap: "))
    heap = MinHeap(capacity)
    print("Enter commands (insert <value>, delete, peek, print, isEmpty, exit):")
    while True:
        command = input().strip().split()
        try:
            if command[0] == "insert":
                value = int(command[1])
                heap.insert(value)
                print(f"Inserted: {value}")
            elif command[0] == "delete":
                print(f"Deleted: {heap.delete()}")
            elif command[0] == "peek":
                print(f"Peek: {heap.peek()}")
            elif command[0] == "print":
                print("Heap: ", end="")
                heap.print_heap()
            elif command[0] == "isEmpty":
                print(f"Is Empty: {heap.is_empty()}")
            elif command[0] == "exit":
                print("Exiting...")
                break
            else:
                print(f"Unknown command: {command[0]}")
        except Exception as e:
            print(f"Error: {e}")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
