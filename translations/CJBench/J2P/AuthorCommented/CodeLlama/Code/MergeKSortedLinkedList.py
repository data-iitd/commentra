
import heapq

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def mergeKLists(self, lists):
        if not lists:
            return None

        min_heap = []
        for node in lists:
            if node:
                heapq.heappush(min_heap, (node.data, node))

        dummy = Node(-1)
        curr = dummy

        while min_heap:
            _, node = heapq.heappop(min_heap)
            curr.next = node
            curr = node

            if node.next:
                heapq.heappush(min_heap, (node.next.data, node.next))

        return dummy.next

# Test program
if __name__ == "__main__":
    lists = [Node(1), Node(3), Node(2), Node(6), Node(7), Node(4), Node(5)]
    lists[0].next = Node(4)
    lists[1].next = Node(6)
    lists[2].next = Node(5)
    lists[3].next = Node(7)
    lists[4].next = Node(8)
    lists[5].next = Node(9)
    lists[6].next = Node(10)

    solution = Solution()
    result = solution.mergeKLists(lists)

    while result:
        print(result.data, end=" ")
        result = result.next

    print()

