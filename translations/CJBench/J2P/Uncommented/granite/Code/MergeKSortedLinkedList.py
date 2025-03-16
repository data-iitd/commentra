
import heapq
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
def mergeKList(lists, n):
    if lists is None or n == 0:
        return None
    minHeap = []
    for i in range(n):
        if lists[i] is not None:
            heapq.heappush(minHeap, (lists[i].data, lists[i]))
    dummy = Node(-1)
    curr = dummy
    while minHeap:
        smallest, smallestNode = heapq.heappop(minHeap)
        curr.next = smallestNode
        curr = smallestNode
        if smallestNode.next is not None:
            heapq.heappush(minHeap, (smallestNode.next.data, smallestNode.next))
    return dummy.next
if __name__ == "__main__":
    scanner = Scanner(System.in)
    k = scanner.nextInt()
    lists = [None] * k
    for i in range(k):
        n = scanner.nextInt()
        head = None
        tail = None
        for j in range(n):
            value = scanner.nextInt()
            newNode = Node(value)
            if head is None:
                head = newNode
                tail = newNode
            else:
                tail.next = newNode
                tail = newNode
        lists[i] = head
    mergedHead = mergeKList(lists, k)
    System.out.println("Merged sorted linked list:")
    current = mergedHead
    while current is not None:
        System.out.print(current.data + " ")
        current = current.next
    System.out.println()
    scanner.close()
