

import heapq

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def merge_k_lists(lists, n):
    if lists is None or n == 0: # Base case: if the input is empty or null, return None
        return None

    min_heap = [] # Initialize an empty min heap to store the heads of the input linked lists
    for i in range(n):
        if lists[i] is not None: # If the current linked list is not empty, add its head to the min heap
            heapq.heappush(min_heap, (lists[i].data, lists[i]))

    dummy = Node(-1) # Create a dummy node to store the head of the merged linked list
    curr = dummy # Initialize a current node to traverse the merged linked list

    while min_heap: # Merge the linked lists until the min heap is empty
        data, node = heapq.heappop(min_heap) # Get the node with the minimum data from the min heap
        curr.next = node # Connect the current node to the merged list with the new node
        curr = node # Move the current node to the next node
        if node.next is not None: # If the current node has a next node, add it to the min heap
            heapq.heappush(min_heap, (node.next.data, node.next))

    return dummy.next # Return the head of the merged linked list

if __name__ == "__main__":
    k = int(input("Enter the number of linked lists: ")) # Read the number of linked lists from the console
    lists = [None] * k # Create an array to store the heads of the input linked lists

    for i in range(k): # Read the data of each node in the input linked lists and store them in the array
        n = int(input("Enter the number of nodes in linked list " + str(i) + ": "))
        head = None
        tail = None
        for j in range(n):
            value = int(input("Enter the data of node " + str(j) + " in linked list " + str(i) + ": "))
            node = Node(value) # Create a new node with the given data
            if head is None: # If the linked list is empty, set the head and tail to the new node
                head = node
                tail = node
            else: # Otherwise, connect the new node to the tail of the linked list and update the tail
                tail.next = node
                tail = node
        lists[i] = head # Store the head of the linked list in the array

    merged_head = merge_k_lists(lists, k) # Call the merge_k_lists function to merge the linked lists
    print("Merged sorted linked list:") # Print the header for the output
    current = merged_head # Initialize a current node to traverse the merged linked list
    while current is not None: # Print the data of each node in the merged linked list
        print(current.data, end=" ")
        current = current.next
    print() # Print a newline character at the end of the output

Translate the above Python code to C++ and end with comment "