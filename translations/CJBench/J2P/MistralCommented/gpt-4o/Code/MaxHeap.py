class HeapElement:
    def __init__(self, key, info=None):
        self.key = key
        self.info = info

    def get_key(self):
        return self.key

    def __str__(self):
        return f"HeapElement(key={self.key}, info={self.info})"


class MaxHeap:
    def __init__(self):
        self.max_heap = []

    def heapify_down(self, element_index):
        largest = element_index - 1
        left_child = 2 * element_index - 1
        right_child = 2 * element_index

        if left_child < len(self.max_heap) and self.max_heap[left_child].get_key() > self.max_heap[largest].get_key():
            largest = left_child
        if right_child < len(self.max_heap) and self.max_heap[right_child].get_key() > self.max_heap[largest].get_key():
            largest = right_child

        if largest != element_index - 1:
            self.max_heap[element_index - 1], self.max_heap[largest] = self.max_heap[largest], self.max_heap[element_index - 1]
            self.heapify_down(largest + 1)

    def toggle_up(self, element_index):
        key = self.max_heap[element_index - 1].get_key()
        parent_index = (element_index // 2) - 1

        while element_index > 1 and self.max_heap[parent_index].get_key() < key:
            self.max_heap[element_index - 1], self.max_heap[parent_index] = self.max_heap[parent_index], self.max_heap[element_index - 1]
            element_index //= 2
            parent_index = (element_index // 2) - 1

    def insert_element(self, element):
        if element is None:
            raise ValueError("Cannot insert null element")
        self.max_heap.append(element)
        self.toggle_up(len(self.max_heap))

    def extract_max(self):
        if not self.max_heap:
            raise Exception("Heap is empty")
        max_element = self.max_heap[0]
        self.max_heap[0] = self.max_heap[-1]
        self.max_heap.pop()
        self.heapify_down(1)
        return max_element

    def get_max(self):
        if not self.max_heap:
            raise Exception("Heap is empty")
        return self.max_heap[0]

    def size(self):
        return len(self.max_heap)

    def is_empty(self):
        return len(self.max_heap) == 0


def main():
    import sys
    input = sys.stdin.read
    commands = input().strip().splitlines()
    heap = MaxHeap()

    for command in commands:
        if not command.strip():
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


if __name__ == "__main__":
    main()

# <END-OF-CODE>
