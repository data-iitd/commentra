
import sys

class HeapElement:
    def __init__(self, key, info=None):
        self.key = key
        self.info = info

    def __str__(self):
        return str(self.key)

class MaxHeap:
    def __init__(self):
        self.heap = []

    def size(self):
        return len(self.heap)

    def is_empty(self):
        return self.size() == 0

    def parent(self, i):
        return (i - 1) // 2

    def left(self, i):
        return 2 * i + 1

    def right(self, i):
        return 2 * i + 2

    def has_left(self, i):
        return self.left(i) < self.size()

    def has_right(self, i):
        return self.right(i) < self.size()

    def swap(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

    def heapify_down(self, i):
        while self.has_left(i):
            j = self.left(i)
            if self.has_right(i) and self.heap[j].key < self.heap[j + 1].key:
                j = self.right(i)
            if self.heap[i].key >= self.heap[j].key:
                return
            self.swap(i, j)
            i = j

    def heapify_up(self, i):
        while i > 0 and self.heap[self.parent(i)].key < self.heap[i].key:
            self.swap(i, self.parent(i))
            i = self.parent(i)

    def insert_element(self, element):
        if element is None:
            raise ValueError("Cannot insert null element")
        self.heap.append(element)
        self.heapify_up(self.size() - 1)

    def extract_max(self):
        if self.is_empty():
            raise ValueError("Heap is empty")
        max = self.heap[0]
        self.heap[0] = self.heap[self.size() - 1]
        self.heap.pop()
        self.heapify_down(0)
        return max

    def get_max(self):
        if self.is_empty():
            raise ValueError("Heap is empty")
        return self.heap[0]

def main():
    heap = MaxHeap()
    while True:
        command = input().strip()
        if command == "":
            break
        parts = command.split()
        operation = parts[0]

        # Perform the specified heap operation based on the user input
        try:
            if operation == "insert":
                key = float(parts[1])
                info = parts[2] if len(parts) > 2 else None
                heap.insert_element(HeapElement(key, info))
                print("Inserted:", key)
            elif operation == "extractMax":
                print("Extracted Max:", heap.extract_max())
            elif operation == "getMax":
                print("Max Element:", heap.get_max())
            elif operation == "size":
                print("Size:", heap.size())
            elif operation == "isEmpty":
                print("Is Empty:", heap.is_empty())
            else:
                print("Unknown operation:", operation)
        except Exception as e:
            print("Error:", e)

if __name__ == "__main__":
    main()

