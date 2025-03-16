import heapq

class ListNode:
    def __init__(self, data=0, next=None):
        self.data = data
        self.next = next

class Solution:
    def mergeKLists(self, lists):
        if not lists:
            return None

        min_heap = []
        for node in lists:
            if node:
                heapq.heappush(min_heap, (node.data, node))

        dummy = ListNode()
        current = dummy

        while min_heap:
            _, temp = heapq.heappop(min_heap)
            current.next = temp
            current = temp

            if temp.next:
                heapq.heappush(min_heap, (temp.next.data, temp.next))

        return dummy.next

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    k = int(data[0])
    index = 1
    lists = []

    for i in range(k):
        n = int(data[index])
        index += 1
        head = None
        tail = None
        for j in range(n):
            value = int(data[index])
            index += 1
            new_node = ListNode(value)
            if not head:
                head = new_node
                tail = new_node
            else:
                tail.next = new_node
                tail = new_node
        lists.append(head)

    solution = Solution()
    merged_head = solution.mergeKLists(lists)

    current = merged_head
    while current:
        print(current.data, end=" ")
        current = current.next
    print()

if __name__ == "__main__":
    main()
