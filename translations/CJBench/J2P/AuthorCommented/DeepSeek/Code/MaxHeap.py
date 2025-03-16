class HeapElement:
    def __init__(self, key, info=None):
        self.key = key
        self.info = info

    def get_key(self):
        return self.key

    def __str__(self):
        return f"({self.key}, {self.info})"


class Main:
    def __init__(self, elements=None):
        if elements is None:
            elements = []
        self.maxHeap = elements
        self.build_heap()

    def build_heap(self):
        for i in range(len(self.maxHeap) // 2, 0, -1):
            self.heapify_down(i)

    def heapify_down(self, element_index):
        largest = element_index - 1
        left_child = 2 * element_index - 1
        right_child = 2 * element_index

        if left_child < len(self.maxHeap) and self.maxHeap[left_child].get_key() > self.maxHeap[largest].get_key():
            largest = left_child

        if right_child < len(self.maxHeap) and self.maxHeap[right_child].get_key() > self.maxHeap[largest].get_key():
            largest = right_child

        if largest != element_index - 1:
            self.maxHeap[element_index - 1], self.maxHeap[largest] = self.maxHeap[largest], self.maxHeap[element_index - 1]
            self.heapify_down(largest + 1)

    def toggle_up(self, element_index):
        key = self.maxHeap[element_index - 1].get_key()
        while element_index > 1 and self.maxHeap[(element_index // 2) - 1].get_key() < key:
            self.maxHeap[element_index - 1], self.maxHeap[(element_index // 2) - 1] = self.maxHeap[(element_index // 2) - 1], self.maxHeap[element_index - 1]
            element_index //= 2

    def insert_element(self, element):
        if element is None:
            raise ValueError("Cannot insert null element")
        self.maxHeap.append(element)
        self.toggle_up(len(self.maxHeap))

    def extract_max(self):
        if not self.maxHeap:
            raise ValueError("Heap is empty")

        max_element = self.maxHeap[0]
        self.maxHeap[0] = self.maxHeap[-1]
        self.maxHeap.pop()

        if self.maxHeap:
            self.heapify_down(1)

        return max_element

    def get_max(self):
        if not self.maxHeap:
            raise ValueError("Heap is empty")
        return self.maxHeap[0]

    def size(self):
        return len(self.maxHeap)

    def is_empty(self):
        return len(self.maxHeap) == 0


if __name__ == "__main__":
    import sys

    heap = Main()
    for line in sys.stdin:
        command = line.strip()
        if not command:
            break

        parts = command.split()
        operation = parts[0]

        try:
            if operation == "insert":
                key = float(parts[1])
                info = parts[2] if len(parts) > 2 else None
                heap.insert_element(HeapElement(key, info))
                print(f"Inserted: {key}")
            elif operation == "extractMax":
                print(f"Extracted Max: {heap.extract_max()}")
            elif operation == "getMax":
                print(f"Max Element: {heap.get_max()}")
            elif operation == "size":
                print(f"Size: {heap.size()}")
            elif operation == "isEmpty":
                print(f"Is Empty: {heap.is_empty()}")
            else:
                print(f"Unknown operation: {operation}")
        except Exception as e:
            print(f"Error: {e}")
