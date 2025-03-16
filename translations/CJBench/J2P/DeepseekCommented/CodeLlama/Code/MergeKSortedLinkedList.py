import heapq
import sys

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def mergeKList(lists, n):
    if lists is None or n == 0:
        return None
    minHeap = []
    for node in lists:
        if node is not None:
            heapq.heappush(minHeap, node)
    dummy = Node(-1)
    curr = dummy
    while minHeap:
        temp = heapq.heappop(minHeap)
        curr.next = temp
        curr = temp
        if temp.next is not None:
            heapq.heappush(minHeap, temp.next)
    return dummy.next

if __name__ == "__main__":
    scanner = sys.stdin
    merger = Merger()
    k = int(scanner.readline())
    lists = [None] * k
    for i in range(k):
        n = int(scanner.readline())
        head = None
        tail = None
        for j in range(n):
            value = int(scanner.readline())
            newNode = Node(value)
            if head is None:
                head = newNode
                tail = newNode
            else:
                tail.next = newNode
                tail = newNode
        lists[i] = head
    mergedHead = merger.mergeKList(lists, k)
    print("Merged sorted linked list:")
    current = mergedHead
    while current is not None:
        print(current.data, end=" ")
        current = current.next
    print()
    scanner.close()
