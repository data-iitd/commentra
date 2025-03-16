
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

    def __repr__(self):
        return str(self.key) + " " + str(self.info)

    def __eq__(self, other):
        return self.key == other.key

    def __ne__(self, other):
        return self.key!= other.key

    def __lt__(self, other):
        return self.key < other.key

    def __le__(self, other):
        return self.key <= other.key

    def __gt__(self, other):
        return self.key > other.key

    def __ge__(self, other):
        return self.key >= other.key

class Main(object):
    def __init__(self):
        self.maxHeap = []

    def insertElement(self, element):
        if element is None:
            raise ValueError("Cannot insert null element")
        heapq.heappush(self.maxHeap, element)

    def extractMax(self):
        if len(self.maxHeap) == 0:
            raise ValueError("Heap is empty")
        return heapq.heappop(self.maxHeap)

    def getMax(self):
        if len(self.maxHeap) == 0:
            raise ValueError("Heap is empty")
        return self.maxHeap[0]

    def size(self):
        return len(self.maxHeap)

    def isEmpty(self):
        return len(self.maxHeap) == 0

# 