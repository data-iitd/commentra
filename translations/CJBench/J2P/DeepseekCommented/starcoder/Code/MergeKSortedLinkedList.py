import heapq
class Main:
    # This method merges k sorted linked lists into one sorted linked list.
    def mergeKList(self, lists, n):
        if lists == None or n == 0:
            return None
        # A priority queue (min-heap) is used to store the heads of the k linked lists.
        minHeap = []
        for node in lists:
            if node!= None:
                # Add the head of each non-null linked list to the min-heap.
                heapq.heappush(minHeap, node)
        # Create a dummy node to help with the merging process.
        dummy = Node(-1)
        curr = dummy
        while len(minHeap) > 0:
            # Extract the node with the smallest value from the min-heap.
            temp = heapq.heappop(minHeap)
            # Link the current node to the extracted node.
            curr.next = temp
            # Move the current node pointer to the extracted node.
            curr = temp
            # If the extracted node has a next node, add it to the min-heap.
            if temp.next!= None:
                heapq.heappush(minHeap, temp.next)
        # Return the merged linked list starting from the next node of the dummy node.
        return dummy.next
    class Node:
        def __init__(self, data):
            self.data = data
            self.next = None
# The main method is the entry point of the program.
if __name__ == "__main__":
    scanner = Scanner(System.in)
    merger = Main()
    k = scanner.nextInt()
    lists = []
    for i in range(k):
        n = scanner.nextInt()
        head = None
        tail = None
        for j in range(n):
            value = scanner.nextInt()
            newNode = Node(value)
            if head == None:
                head = newNode
                tail = newNode
            else:
                tail.next = newNode
                tail = newNode
        lists.append(head)
    mergedHead = merger.mergeKList(lists, k)
    print("Merged sorted linked list:")
    current = mergedHead
    while current!= None:
        print(current.data, end=" ")
        current = current.next
    print()
    scanner.close()
