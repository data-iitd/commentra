
# Definition of the Node class for the linked list
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Class to merge k sorted linked lists
class Main:
    # Method to merge k sorted linked lists
    def mergeKList(self, lists, n):
        # Check if the input lists are null or if there are no lists to merge
        if lists == None or n == 0:
            return None # Return null if there are no lists

        # Create a min-heap (priority queue) to store the nodes of the linked lists
        minHeap = []

        # Add the head nodes of each linked list to the min-heap
        for node in lists:
            if node!= None:
                minHeap.append(node) # Only add non-null nodes

        # Create a dummy node to simplify the merging process
        dummy = Node(-1)
        curr = dummy # Pointer to build the merged linked list

        # While there are nodes in the min-heap, continue merging
        while len(minHeap) > 0:
            # Get the smallest node from the heap
            temp = minHeap.pop(0)
            curr.next = temp # Link the current node to the merged list
            curr = temp # Move the current pointer to the newly added node

            # If there is a next node in the list, add it to the min-heap
            if temp.next!= None:
                minHeap.append(temp.next)

        # Return the head of the merged linked list, which is next to the dummy node
        return dummy.next

    # Main method to execute the program
    def main(self):
        scanner = Scanner(System.in) # Create a scanner for input
        merger = Main() # Create an instance of the Main class
        k = scanner.nextInt() # Read the number of linked lists
        lists = [None] * k # Array to hold the head nodes of the linked lists

        # Loop to read each linked list
        for i in range(k):
            n = scanner.nextInt() # Read the number of nodes in the current list
            head = None # Initialize head and tail pointers for the list

            # Loop to read the values of the nodes
            for j in range(n):
                value = scanner.nextInt() # Read the value for the new node
                newNode = Node(value) # Create a new node

                # If this is the first node, set head and tail to the new node
                if head == None:
                    head = newNode
                    tail = newNode
                else:
                    # Link the new node to the end of the list and update tail
                    tail.next = newNode
                    tail = newNode

            lists[i] = head # Store the head of the current linked list in the array

        # Merge the k linked lists
        mergedHead = merger.mergeKList(lists, k)
        print("Merged sorted linked list:")

        # Print the merged linked list
        current = mergedHead
        while current!= None:
            print(current.data, end=" ") # Print the data of each node
            current = current.next # Move to the next node
        print() # Print a new line after the merged list
        scanner.close() # Close the scanner

# 