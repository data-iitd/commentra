import sys

class HeapElement:
    def __init__(self, key, info=None):
        self.key = key
        self.info = info

    def __str__(self):
        return f"{self.key} {self.info}"

class Main:
    def __init__(self):
        self.maxHeap = []

    def heapifyDown(self, elementIndex):
        largest = elementIndex - 1
        leftChild = 2 * elementIndex - 1
        rightChild = 2 * elementIndex
        if leftChild < len(self.maxHeap) and self.maxHeap[leftChild].key > self.maxHeap[largest].key:
            largest = leftChild
        if rightChild < len(self.maxHeap) and self.maxHeap[rightChild].key > self.maxHeap[largest].key:
            largest = rightChild
        if largest != elementIndex - 1:
            temp = self.maxHeap[elementIndex - 1]
            self.maxHeap[elementIndex - 1] = self.maxHeap[largest]
            self.maxHeap[largest] = temp
            self.heapifyDown(largest + 1)

    def toggleUp(self, elementIndex):
        key = self.maxHeap[elementIndex - 1].key
        while elementIndex > 1 and self.maxHeap[(elementIndex / 2) - 1].key < key:
            temp = self.maxHeap[elementIndex - 1]
            self.maxHeap[elementIndex - 1] = self.maxHeap[(elementIndex / 2) - 1]
            self.maxHeap[(elementIndex / 2) - 1] = temp
            elementIndex /= 2

    def insertElement(self, element):
        if element is None:
            raise ValueError("Cannot insert null element")
        self.maxHeap.append(element)
        self.toggleUp(len(self.maxHeap))

    def extractMax(self):
        if len(self.maxHeap) == 0:
            raise ValueError("Heap is empty")
        max = self.maxHeap[0]
        self.maxHeap[0] = self.maxHeap[len(self.maxHeap) - 1]
        self.maxHeap.pop()
        if len(self.maxHeap) > 0:
            self.heapifyDown(1)
        return max

    def getMax(self):
        if len(self.maxHeap) == 0:
            raise ValueError("Heap is empty")
        return self.maxHeap[0]

    def size(self):
        return len(self.maxHeap)

    def isEmpty(self):
        return len(self.maxHeap) == 0

def main():
    heap = Main()
    while True:
        command = input().strip()
        if command == "":
            break
        parts = command.split(" ")
        operation = parts[0]
        try:
            if operation == "insert":
                key = float(parts[1])
                info = parts[2] if len(parts) > 2 else None
                heap.insertElement(HeapElement(key, info))
                print(f"Inserted: {key}")
            elif operation == "extractMax":
                print(f"Extracted Max: {heap.extractMax()}")
            elif operation == "getMax":
                print(f"Max Element: {heap.getMax()}")
            elif operation == "size":
                print(f"Size: {heap.size()}")
            elif operation == "isEmpty":
                print(f"Is Empty: {heap.isEmpty()}")
            else:
                print(f"Unknown operation: {operation}")
        except Exception as e:
            print(f"Error: {e}")

if __name__ == "__main__":
    main()

