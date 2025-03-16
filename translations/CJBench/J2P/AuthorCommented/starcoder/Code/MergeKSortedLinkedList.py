import heapq

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Main:
    def mergeKList(self, lists, n):
        if lists == None or n == 0:
            return None

        # Min Heap to store nodes based on their values for efficient retrieval of the smallest element.
        minHeap = []

        # Initialize the min-heap with the head of each non-null linked list
        for node in lists:
            if node!= None:
                heapq.heappush(minHeap, node)

        # Create a dummy node to simplify result list construction
        dummy = Node(-1)
        curr = dummy

        while len(minHeap) > 0:
            temp = heapq.heappop(minHeap)
            curr.next = temp
            curr = temp

            # Add the next node in the current list to the heap if it exists
            if temp.next!= None:
                heapq.heappush(minHeap, temp.next)

        return dummy.next

# 