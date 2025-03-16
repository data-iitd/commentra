import heapq

class ListNode:
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
                heapq.heappush(min_heap, node)

        dummy = ListNode(-1)
        curr = dummy

        while min_heap:
            temp = heapq.heappop(min_heap)
            curr.next = temp
            curr = temp
            if temp.next:
                heapq.heappush(min_heap, temp.next)

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

    merged_head = Solution().mergeKLists(lists)
    print("Merged sorted linked list:")
    current = merged_head
    while current:
        print(current.data, end=" ")
        current = current.next
    print()

if __name__ == "__main__":
    main()

