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

# Helper function to create a linked list from input
def create_linked_list(values):
    dummy = ListNode(0)
    current = dummy
    for value in values:
        current.next = ListNode(value)
        current = current.next
    return dummy.next

# Helper function to print a linked list
def print_linked_list(head):
    current = head
    while current:
        print(current.data, end=" ")
        current = current.next
    print()

# Main function to read input and execute the merge operation
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
        values = list(map(int, data[index:index + n]))
        index += n
        lists.append(create_linked_list(values))
    
    solution = Solution()
    merged_head = solution.mergeKLists(lists)
    
    print("Merged sorted linked list:")
    print_linked_list(merged_head)

if __name__ == "__main__":
    main()
