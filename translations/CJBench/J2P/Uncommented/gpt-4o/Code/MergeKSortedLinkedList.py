import heapq

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Main:
    def mergeKList(self, lists):
        if not lists or len(lists) == 0:
            return None
        
        min_heap = []
        for node in lists:
            if node is not None:
                heapq.heappush(min_heap, (node.data, node))
        
        dummy = Node(-1)
        curr = dummy
        
        while min_heap:
            _, temp = heapq.heappop(min_heap)
            curr.next = temp
            curr = temp
            if temp.next is not None:
                heapq.heappush(min_heap, (temp.next.data, temp.next))
        
        return dummy.next

if __name__ == "__main__":
    merger = Main()
    k = int(input())
    lists = []
    for _ in range(k):
        n = int(input())
        head = None
        tail = None
        for _ in range(n):
            value = int(input())
            new_node = Node(value)
            if head is None:
                head = new_node
                tail = new_node
            else:
                tail.next = new_node
                tail = new_node
        lists.append(head)
    
    merged_head = merger.mergeKList(lists)
    print("Merged sorted linked list:")
    current = merged_head
    while current is not None:
        print(current.data, end=" ")
        current = current.next
    print()

# <END-OF-CODE>
