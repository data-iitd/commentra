import heapq

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Main:
    # Method to merge k sorted linked lists
    def mergeKList(self, lists):
        # Check if the input lists are None or if there are no lists to merge
        if lists is None or len(lists) == 0:
            return None  # Return None if there are no lists

        # Create a min-heap to store the nodes of the linked lists
        min_heap = []
        
        # Add the head nodes of each linked list to the min-heap
        for node in lists:
            if node is not None:
                heapq.heappush(min_heap, (node.data, node))  # Push a tuple of (data, node)

        # Create a dummy node to simplify the merging process
        dummy = Node(-1)
        curr = dummy  # Pointer to build the merged linked list

        # While there are nodes in the min-heap, continue merging
        while min_heap:
            # Get the smallest node from the heap
            _, temp = heapq.heappop(min_heap)
            curr.next = temp  # Link the current node to the merged list
            curr = temp  # Move the current pointer to the newly added node

            # If there is a next node in the list, add it to the min-heap
            if temp.next is not None:
                heapq.heappush(min_heap, (temp.next.data, temp.next))

        # Return the head of the merged linked list, which is next to the dummy node
        return dummy.next

# Main method to execute the program
if __name__ == "__main__":
    merger = Main()  # Create an instance of the Main class
    k = int(input("Enter the number of linked lists: "))  # Read the number of linked lists
    lists = []  # List to hold the head nodes of the linked lists

    # Loop to read each linked list
    for i in range(k):
        n = int(input(f"Enter the number of nodes in list {i + 1}: "))  # Read the number of nodes in the current list
        head = None
        tail = None  # Initialize head and tail pointers for the list

        # Loop to read the values of the nodes
        for j in range(n):
            value = int(input(f"Enter value for node {j + 1}: "))  # Read the value for the new node
            new_node = Node(value)  # Create a new node

            # If this is the first node, set head and tail to the new node
            if head is None:
                head = new_node
                tail = new_node
            else:
                # Link the new node to the end of the list and update tail
                tail.next = new_node
                tail = new_node

        lists.append(head)  # Store the head of the current linked list in the list

    # Merge the k linked lists
    merged_head = merger.mergeKList(lists)
    print("Merged sorted linked list:")

    # Print the merged linked list
    current = merged_head
    while current is not None:
        print(current.data, end=" ")  # Print the data of each node
        current = current.next  # Move to the next node
    print()  # Print a new line after the merged list
