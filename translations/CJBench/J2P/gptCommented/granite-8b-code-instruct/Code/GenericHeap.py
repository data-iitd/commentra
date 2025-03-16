
import heapq

class Main:
    def __init__(self):
        self.data = []

    def add(self, item):
        if item is None:
            raise ValueError("Cannot insert None into the heap.")
        heapq.heappush(self.data, item)

    def remove(self):
        if len(self.data) == 0:
            raise ValueError("Heap is empty.")
        return heapq.heappop(self.data)

    def get(self):
        if len(self.data) == 0:
            raise ValueError("Heap is empty.")
        return self.data[0]

    def size(self):
        return len(self.data)

    def is_empty(self):
        return len(self.data) == 0

if __name__ == "__main__":
    import sys
    operations = int(input())
    heap = Main()
    for _ in range(operations):
        choice = int(input())
        if choice == 1:
            element = int(input())
            heap.add(element)
            print(f"Added: {element}")
        elif choice == 2:
            try:
                print(f"Removed: {heap.remove()}")
            except IndexError:
                print("Heap is empty.")
        elif choice == 3:
            try:
                print(f"Max element: {heap.get()}")
            except IndexError:
                print("Heap is empty.")
        elif choice == 4:
            print(f"Heap size: {heap.size()}")
        elif choice == 5:
            print(f"Heap is empty: {heap.is_empty()}")
        else:
            print("Invalid operation.")
    sys.exit(0)
