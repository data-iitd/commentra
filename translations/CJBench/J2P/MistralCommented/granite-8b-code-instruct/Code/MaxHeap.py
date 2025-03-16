

import heapq

class HeapElement:
    def __init__(self, key, info=None):
        self.key = key
        self.info = info

    def __lt__(self, other):
        return self.key < other.key

    def __str__(self):
        return f"HeapElement(key={self.key}, info={self.info})"

class Main:
    def __init__(self):
        self.maxHeap = []

    def heapifyDown(self, elementIndex):
        largest = elementIndex - 1
        leftChild = 2 * elementIndex - 1
        rightChild = 2 * elementIndex

        # Find the index of the largest element among the current node, its left and right children
        if leftChild < len(self.maxHeap) and self.maxHeap[leftChild].key > self.maxHeap[largest].key:
            largest = leftChild
        if rightChild < len(self.maxHeap) and self.maxHeap[rightChild].key > self.maxHeap[largest].key:
            largest = rightChild

        # Swap elements if the largest element is not the current node
        if largest!= elementIndex - 1:
            self.maxHeap[elementIndex - 1], self.maxHeap[largest] = self.maxHeap[largest], self.maxHeap[elementIndex - 1]
            # Recursively call heapifyDown for the new largest node
            self.heapifyDown(largest + 1)

    def toggleUp(self, elementIndex):
        key = self.maxHeap[elementIndex - 1].key
        parentIndex = (elementIndex // 2) - 1

        # Continue swapping parent and child nodes until the current node is in its correct position
        while elementIndex > 1 and self.maxHeap[parentIndex].key < key:
            self.maxHeap[elementIndex - 1], self.maxHeap[parentIndex] = self.maxHeap[parentIndex], self.maxHeap[elementIndex - 1]
            elementIndex //= 2
            parentIndex = (elementIndex // 2) - 1

    def insertElement(self, element):
        if element is None:
            raise ValueError("Cannot insert null element")
        # Add the new element to the max heap
        heapq.heappush(self.maxHeap, element)
        # Call toggleUp method to move the new element to its correct position in the heap
        self.toggleUp(len(self.maxHeap))

    def extractMax(self):
        if len(self.maxHeap) == 0:
            raise ValueError("Heap is empty")
        # Store the maximum HeapElement in a variable
        max = self.maxHeap[0]
        # Replace the root node with the last node in the max heap and remove the last node
        self.maxHeap[0] = self.maxHeap.pop()
        # Call heapifyDown method to maintain heap property after extracting the maximum element
        self.heapifyDown(1)
        # Return the extracted maximum HeapElement
        return max

    def getMax(self):
        if len(self.maxHeap) == 0:
            raise ValueError("Heap is empty")
        # Return the maximum HeapElement stored at the root node
        return self.maxHeap[0]

    def size(self):
        return len(self.maxHeap)

    def isEmpty(self):
        return len(self.maxHeap) == 0

# Main method to read user input and perform the corresponding heap operations
if __name__ == "__main__":
    import sys

    heap = Main()
    for line in sys.stdin:
        parts = line.split()
        operation = parts[0]

        # Perform the specified heap operation based on the user input
        try:
            if operation == "insert":
                key = float(parts[1])
                info = parts[2] if len(parts) > 2 else None
                heap.insertElement(HeapElement(key, info))
                print(f"Inserted: {key}")
            elif operation == "extractMax":
                maxElement = heap.extractMax()
                print(f"Extracted Max: {maxElement}")
            elif operation == "getMax":
                maxElement = heap.getMax()
                print(f"Max Element: {maxElement}")
            elif operation == "size":
                size = heap.size()
                print(f"Size: {size}")
            elif operation == "isEmpty":
                isEmpty = heap.isEmpty()
                print(f"Is Empty: {isEmpty}")
            else:
                print(f"Unknown operation: {operation}")
        except Exception as e:
            print(f"Error: {e}")

