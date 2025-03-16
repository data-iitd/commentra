
import heapq

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

def main():
    k = int(input())
    lists = [None] * k

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
        lists[i] = head

    mergedHead = mergeKList(lists, k)
    print("Merged sorted linked list:")
    current = mergedHead
    while current is not None:
        print(current.data, end=" ")
        current = current.next
    print()

if __name__ == "__main__":
    main()

