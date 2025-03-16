
import heapq
class HeapElement(object):
    def __init__(self, key, info):
        self.key = key
        self.info = info
    def getKey(self):
        return self.key
    def getInfo(self):
        return self.info
    def __str__(self):
        return str(self.key) + " " + str(self.info)
class Main(object):
    def __init__(self):
        self.maxHeap = []
    def heapifyDown(self, elementIndex):
        largest = elementIndex - 1
        leftChild = 2 * elementIndex - 1
        rightChild = 2 * elementIndex
        if leftChild < len(self.maxHeap) and self.maxHeap[leftChild].getKey() > self.maxHeap[largest].getKey():
            largest = leftChild
        if rightChild < len(self.maxHeap) and self.maxHeap[rightChild].getKey() > self.maxHeap[largest].getKey():
            largest = rightChild
        if largest!= elementIndex - 1:
            temp = self.maxHeap[elementIndex - 1]
            self.maxHeap[elementIndex - 1] = self.maxHeap[largest]
            self.maxHeap[largest] = temp
            self.heapifyDown(largest + 1)
    def toggleUp(self, elementIndex):
        key = self.maxHeap[elementIndex - 1].getKey()
        while elementIndex > 1 and self.maxHeap[(elementIndex / 2) - 1].getKey() < key:
            temp = self.maxHeap[elementIndex - 1]
            self.maxHeap[elementIndex - 1] = self.maxHeap[(elementIndex / 2) - 1]
            self.maxHeap[(elementIndex / 2) - 1] = temp
            elementIndex /= 2
    def insertElement(self, element):
        if element == None:
            raise Exception("Cannot insert null element")
        self.maxHeap.append(element)
        self.toggleUp(len(self.maxHeap))
    def extractMax(self):
        if len(self.maxHeap) == 0:
            raise Exception("Heap is empty")
        max = self.maxHeap[0]
        self.maxHeap[0] = self.maxHeap[len(self.maxHeap) - 1]
        self.maxHeap.pop()
        if len(self.maxHeap) > 0:
            self.heapifyDown(1)
        return max
    def getMax(self):
        if len(self.maxHeap) == 0:
            raise Exception("Heap is empty")
        return self.maxHeap[0]
    def size(self):
        return len(self.maxHeap)
    def isEmpty(self):
        return len(self.maxHeap) == 0
if __name__ == "__main__":
    heap = Main()
    while True:
        command = raw_input().strip()
        if command == "": break
        parts = command.split(" ")
        operation = parts[0]
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

