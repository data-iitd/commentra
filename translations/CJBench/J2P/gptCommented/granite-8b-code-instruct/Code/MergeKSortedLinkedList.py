
import heapq

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def mergeKList(lists, n):
    if lists is None or n == 0:
        return None

    minHeap = []
    for i in range(n):
        if lists[i] is not None:
            heapq.heappush(minHeap, (lists[i].data, lists[i]))

    dummy = Node(-1)
    curr = dummy

    while len(minHeap) > 0:
        smallest, smallestNode = heapq.heappop(minHeap)
        curr.next = smallestNode
        curr = smallestNode

        if smallestNode.next is not None:
            heapq.heappush(minHeap, (smallestNode.next.data, smallestNode.next))

    return dummy.next

# Main method to execute the program
if __name__ == "__main__":
    scanner = input() # Read the number of linked lists
    k = int(scanner)
    lists = [None] * k # Array to hold the head nodes of the linked lists

    for i in range(k):
        scanner = input() # Read the number of nodes in the current list
        n = int(scanner)
        head = None
        tail = None

        for j in range(n):
            scanner = input() # Read the value for the new node
            value = int(scanner)
            newNode = Node(value)

            if head is None:
                head = newNode
                tail = newNode
            else:
                tail.next = newNode
                tail = newNode

        lists[i] = head # Store the head of the current linked list in the array

    mergedHead = mergeKList(lists, k)
    print("Merged sorted linked list:")

    current = mergedHead
    while current is not None:
        print(current.data, end=" ") # Print the data of each node
        current = current.next # Move to the next node

    print() # Print a new line after the merged list