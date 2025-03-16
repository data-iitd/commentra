import heapq

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Main:
    # Merge k sorted linked lists into one sorted linked list
    def mergeKList(self, lists):
        if not lists or len(lists) == 0:  # Base case: if the input is empty or null, return None
            return None

        min_heap = []  # Initialize the min heap
        # Initialize the min heap with the heads of the input linked lists
        for node in lists:
            if node:  # If the current linked list is not empty, add its head to the min heap
                heapq.heappush(min_heap, (node.data, node))

        dummy = Node(-1)  # Create a dummy node to store the head of the merged linked list
        curr = dummy  # Initialize a current node to traverse the merged linked list

        while min_heap:  # Merge the linked lists until the min heap is empty
            _, temp = heapq.heappop(min_heap)  # Get the node with the minimum data from the min heap
            curr.next = temp  # Connect the current node to the merged list with the new node
            curr = temp  # Move the current node to the next node
            if temp.next:  # If the current node has a next node, add it to the min heap
                heapq.heappush(min_heap, (temp.next.data, temp.next))

        return dummy.next  # Return the head of the merged linked list

if __name__ == "__main__":
    k = int(input("Enter the number of linked lists: "))  # Read the number of linked lists from the console
    lists = []  # Create a list to store the heads of the input linked lists

    for _ in range(k):  # Read the data of each node in the input linked lists and store them in the list
        n = int(input("Enter the number of nodes in the linked list: "))
        head = None
        tail = None
        for _ in range(n):
            value = int(input("Enter node value: "))
            new_node = Node(value)  # Create a new node with the given data
            if head is None:  # If the linked list is empty, set the head and tail to the new node
                head = new_node
                tail = new_node
            else:  # Otherwise, connect the new node to the tail of the linked list and update the tail
                tail.next = new_node
                tail = new_node
        lists.append(head)  # Store the head of the linked list in the list

    merged_head = Main().mergeKList(lists)  # Call the mergeKList method to merge the linked lists
    print("Merged sorted linked list:")  # Print the header for the output
    current = merged_head  # Initialize a current node to traverse the merged linked list
    while current:  # Print the data of each node in the merged linked list
        print(current.data, end=" ")
        current = current.next
    print()  # Print a newline character at the end of the output
# <END-OF-CODE>
