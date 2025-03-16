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

        dummy = ListNode(-1)
        curr = dummy

        while min_heap:
            _, temp = heapq.heappop(min_heap)
            curr.next = temp
            curr = temp

            if temp.next:
                heapq.heappush(min_heap, (temp.next.data, temp.next))

        return dummy.next

# Helper function to create a linked list from a list of values
def create_linked_list(values):
    dummy = ListNode()
    tail = dummy
    for value in values:
        tail.next = ListNode(value)
        tail = tail.next
    return dummy.next

# Helper function to print a linked list
def print_linked_list(head):
    current = head
    while current:
        print(current.data, end=" ")
        current = current.next
    print()

# Main function to execute the program
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    k = int(data[0])
    index = 1
    lists = []

    for i in range(k):
        n = int(data[index])
        index += 1
        values = list(map(int, data[index:index + n]))
        index += n
        lists.append(create_linked_list(values))

    solution = Solution()
    merged_head = solution.mergeKLists(lists)
    print("Merged sorted linked list:")
    print_linked_list(merged_head)
