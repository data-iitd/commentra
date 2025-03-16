import heapq
class Main:
    def mergeKList(self, lists, n):
        if lists == None or n == 0:
            return None
        minHeap = []
        for node in lists:
            if node!= None:
                heapq.heappush(minHeap, node)
        dummy = Node(-1)
        curr = dummy
        while len(minHeap) > 0:
            temp = heapq.heappop(minHeap)
            curr.next = temp
            curr = temp
            if temp.next!= None:
                heapq.heappush(minHeap, temp.next)
        return dummy.next

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

if __name__ == "__main__":
    scanner = Scanner(System.in)
    merger = Main()
    k = scanner.nextInt()
    lists = []
    for i in range(k):
        n = scanner.nextInt()
        head = None
        tail = None
        for j in range(n):
            value = scanner.nextInt()
            newNode = Node(value)
            if head == None:
                head = newNode
                tail = newNode
            else:
                tail.next = newNode
                tail = newNode
        lists.append(head)
    mergedHead = merger.mergeKList(lists, k)
    print("Merged sorted linked list:")
    current = mergedHead
    while current!= None:
        print(current.data, end=" ")
        current = current.next
    print()
    scanner.close()

