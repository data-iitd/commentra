
import heapq

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Main:
    def mergeKList(self, lists, n):
        if lists is None or n == 0:
            return None

        # Min Heap to store nodes based on their values for efficient retrieval of the smallest element.
        minHeap = []

        # Initialize the min-heap with the head of each non-null linked list
        for node in lists:
            if node is not None:
                heapq.heappush(minHeap, node)

        # Create a dummy node to simplify result list construction
        dummy = Node(-1)
        curr = dummy

        while minHeap:
            temp = heapq.heappop(minHeap)
            curr.next = temp
            curr = temp

            # Add the next node in the current list to the heap if it exists
            if temp.next is not None:
                heapq.heappush(minHeap, temp.next)

        return dummy.next

if __name__ == "__main__":
    scanner = input()
    k = int(scanner)

    # Read each linked list
    lists = []
    for i in range(k):
        n = int(input())
        head = None
        tail = None
        for j in range(n):
            value = int(input())
            newNode = Node(value)
            if head is None:
                head = newNode
                tail = newNode
            else:
                tail.next = newNode
                tail = newNode
        lists.append(head)

    # Merge the K sorted linked lists
    merger = Main()
    mergedHead = merger.mergeKList(lists, k)

    # Print the merged linked list
    print("Merged sorted linked list:")
    current = mergedHead
    while current is not None:
        print(current.data, end=" ")
        current = current.next
    print()