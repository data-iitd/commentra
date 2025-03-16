import heapq

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Main:
    def merge_k_lists(self, lists):
        if not lists or len(lists) == 0:
            return None

        # Min Heap to store nodes based on their values for efficient retrieval of the smallest element.
        min_heap = []
        
        # Initialize the min-heap with the head of each non-null linked list
        for node in lists:
            if node is not None:
                heapq.heappush(min_heap, (node.data, node))

        # Create a dummy node to simplify result list construction
        dummy = Node(-1)
        curr = dummy

        while min_heap:
            # Get the smallest node from the heap
            value, temp = heapq.heappop(min_heap)
            curr.next = temp
            curr = temp

            # Add the next node in the current list to the heap if it exists
            if temp.next is not None:
                heapq.heappush(min_heap, (temp.next.data, temp.next))

        return dummy.next

if __name__ == "__main__":
    merger = Main()

    # Read the number of linked lists
    k = int(input("Enter the number of linked lists: "))

    # Read each linked list
    lists = []
    for _ in range(k):
        n = int(input("Enter the number of elements in the linked list: "))
        head = None
        tail = None
        for _ in range(n):
            value = int(input("Enter the value: "))
            new_node = Node(value)
            if head is None:
                head = new_node
                tail = new_node
            else:
                tail.next = new_node
                tail = new_node
        lists.append(head)

    # Merge the K sorted linked lists
    merged_head = merger.merge_k_lists(lists)

    # Print the merged linked list
    print("Merged sorted linked list:")
    current = merged_head
    while current is not None:
        print(current.data, end=" ")
        current = current.next
    print()

# <END-OF-CODE>
