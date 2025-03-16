
import heapq

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Main:
    # Merge k sorted linked lists into one sorted linked list
    def mergeKList(self, lists, n):
        if lists == None or n == 0: # Base case: if the input is empty or null, return null
            return None

        minHeap = [] # Initialize the min heap with the heads of the input linked lists
        for node in lists:
            if node!= None: # If the current linked list is not empty, add its head to the min heap
                heapq.heappush(minHeap, (node.data, node))

        dummy = Node(-1) # Create a dummy node to store the head of the merged linked list
        curr = dummy # Initialize a current node to traverse the merged linked list

        while len(minHeap) > 0: # Merge the linked lists until the min heap is empty
            data, temp = heapq.heappop(minHeap) # Get the node with the minimum data from the min heap
            curr.next = temp # Connect the current node to the merged list with the new node
            curr = temp # Move the current node to the next node
            if temp.next!= None: # If the current node has a next node, add it to the min heap
                heapq.heappush(minHeap, (temp.next.data, temp.next))

        return dummy.next # Return the head of the merged linked list

    def printList(self, head):
        current = head
        while current!= None:
            print(current.data, end=" ")
            current = current.next
        print()

if __name__ == "__main__":
    scanner = Scanner(System.in) # Initialize a Scanner object to read input from the console

    k = scanner.nextInt() # Read the number of linked lists from the console
    lists = [None] * k # Create an array to store the heads of the input linked lists

    for i in range(k): # Read the data of each node in the input linked lists and store them in the array
        n = scanner.nextInt()
        head = None
        tail = None
        for j in range(n):
            value = scanner.nextInt()
            newNode = Node(value) # Create a new node with the given data
            if head == None: # If the linked list is empty, set the head and tail to the new node
                head = newNode
                tail = newNode
            else: # Otherwise, connect the new node to the tail of the linked list and update the tail
                tail.next = newNode
                tail = newNode
        lists[i] = head # Store the head of the linked list in the array

    mergedHead = Main().mergeKList(lists, k) # Call the mergeKList method to merge the linked lists
    print("Merged sorted linked list:") # Print the header for the output
    Main().printList(mergedHead) # Print the data of each node in the merged linked list
    scanner.close() # Close the Scanner object

