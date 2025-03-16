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
    tail = dummy
    for value in values:
        tail.next = ListNode(value)
        tail = tail.next
    return dummy.next

# Main function to read input and print the merged list
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
        values = []
        for j in range(n):
            values.append(int(data[index]))
            index += 1
        lists.append(create_linked_list(values))
    
    solution = Solution()
    merged_head = solution.mergeKLists(lists)
    
    result = []
    while merged_head:
        result.append(merged_head.data)
        merged_head = merged_head.next
    
    print("Merged sorted linked list:")
    print(" ".join(map(str, result)))

if __name__ == "__main__":
    main()
