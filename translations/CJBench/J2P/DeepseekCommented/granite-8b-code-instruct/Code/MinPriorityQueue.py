
class Main:
    def __init__(self, c):
        self.capacity = c
        self.size = 0
        self.heap = [0] * (c + 1)  # +1 because heap[0] is not used

    def insert(self, key):
        if self.isFull():
            raise Exception("Heap is full. Cannot insert new element.")
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
            raise Exception("Heap is empty. Cannot peek.")
        return self.heap[1]  # The minimum element is at the root of the heap

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
            raise Exception("Heap is empty. Cannot delete.")
        min = self.heap[1]  # The minimum element is at the root
        self.heap[1] = self.heap[self.size]  # Replace the root with the last element
        self.size -= 1  # Decrement the size of the heap
        self.sink()  # Maintain the heap property
        return min

if __name__ == "__main__":
    capacity = int(input())
    queue = Main(capacity)
    while True:
        try:
            command = input().split()
            if command[0] == "insert":
                value = int(command[1])
                queue.insert(value)
                print("Inserted:", value)
            elif command[0] == "delete":
                print("Deleted:", queue.delete())
            elif command[0] == "peek":
                print("Peek:", queue.peek())
            elif command[0] == "print":
                print("Heap:", end=" ")
                queue.print()
            elif command[0] == "isEmpty":
                print("Is Empty:", queue.isEmpty())
            elif command[0] == "exit":
                print("Exiting...")
                break
            else:
                print("Unknown command:", command[0])
        except Exception as e:
            print("Error:", e)

