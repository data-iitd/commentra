
import heapq

class HeapElement:
    def __init__(self, key, info):
        self.key = key
        self.info = info

    def getKey(self):
        return self.key

    def getInfo(self):
        return self.info

    def __str__(self):
        return str(self.key) + " " + str(self.info)

class Main:
    # Initialize an empty max heap using a list
    maxHeap = []

    # Helper method to maintain heap property by swapping elements if condition is met
    def heapifyDown(self, elementIndex):
        largest = elementIndex - 1
        leftChild = 2 * elementIndex - 1
        rightChild = 2 * elementIndex

        # Find the index of the largest element among the current node, its left and right children
        if leftChild < len(self.maxHeap) and self.maxHeap[leftChild].getKey() > self.maxHeap[largest].getKey():
            largest = leftChild
        if rightChild < len(self.maxHeap) and self.maxHeap[rightChild].getKey() > self.maxHeap[largest].getKey():
            largest = rightChild

        # Swap elements if the largest element is not the current node
        if largest!= elementIndex - 1:
            temp = self.maxHeap[elementIndex - 1]
            self.maxHeap[elementIndex - 1] = self.maxHeap[largest]
            self.maxHeap[largest] = temp
            # Recursively call heapifyDown for the new largest node
            self.heapifyDown(largest + 1)

    # Helper method to move an element up in the heap until it reaches its correct position
    def toggleUp(self, elementIndex):
        key = self.maxHeap[elementIndex - 1].getKey()
        parentIndex = (elementIndex / 2) - 1

        # Continue swapping parent and child nodes until the current node is in its correct position
        while elementIndex > 1 and self.maxHeap[parentIndex].getKey() < key:
            temp = self.maxHeap[elementIndex - 1]
            self.maxHeap[elementIndex - 1] = self.maxHeap[parentIndex]
            self.maxHeap[parentIndex] = temp
            elementIndex /= 2
            parentIndex = (elementIndex / 2) - 1

    # Method to insert a new HeapElement into the max heap
    def insertElement(self, element):
        if element == None:
            raise Exception("Cannot insert null element")
        # Add the new element to the max heap
        self.maxHeap.append(element)
        # Call toggleUp method to move the new element to its correct position in the heap
        self.toggleUp(len(self.maxHeap))

    # Method to extract and return the maximum HeapElement from the max heap
    def extractMax(self):
        if len(self.maxHeap) == 0:
            raise Exception("Heap is empty")
        # Store the maximum HeapElement in a variable
        max = self.maxHeap[0]
        # Replace the root node with the last node in the max heap and remove the last node
        self.maxHeap[0] = self.maxHeap[len(self.maxHeap) - 1]
        self.maxHeap.remove(len(self.maxHeap) - 1)
        # Call heapifyDown method to maintain heap property after extracting the maximum element
        self.heapifyDown(1)
        # Return the extracted maximum HeapElement
        return max

    # Method to return the maximum HeapElement without extracting it from the max heap
    def getMax(self):
        if len(self.maxHeap) == 0:
            raise Exception("Heap is empty")
        # Return the maximum HeapElement stored at the root node
        return self.maxHeap[0]

    # Method to return the size of the max heap
    def size(self):
        return len(self.maxHeap)

    # Method to check if the max heap is empty
    def isEmpty(self):
        return len(self.maxHeap) == 0

# Main method to read user input and perform the corresponding heap operations
if __name__ == "__main__":
    heap = Main()
    while True:
        command = raw_input().strip()
        if command == "": break
        parts = command.split(" ")
        operation = parts[0]

        # Perform the specified heap operation based on the user input
        try:
            if operation == "insert":
                key = float(parts[1])
                info = parts[2] if len(parts) > 2 else None
                heap.insertElement(HeapElement(key, info))
                print "Inserted: " + str(key)
            elif operation == "extractMax":
                print "Extracted Max: " + str(heap.extractMax())
            elif operation == "getMax":
                print "Max Element: " + str(heap.getMax())
            elif operation == "size":
                print "Size: " + str(heap.size())
            elif operation == "isEmpty":
                print "Is Empty: " + str(heap.isEmpty())
            else:
                print "Unknown operation: " + operation
        except Exception as e:
            print "Error: " + e.message

