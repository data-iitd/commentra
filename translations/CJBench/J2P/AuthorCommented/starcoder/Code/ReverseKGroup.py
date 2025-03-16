import sys

# Node class
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

# Main class
class Main:
    def __init__(self):
        pass

    # Calculates the length of the linked list.
    def length(self, head):
        curr = head
        count = 0
        while curr!= None:
            curr = curr.next
            count += 1
        return count

    # Reverses the linked list in groups of k nodes.
    def reverse(self, head, count, k):
        if count < k:
            return head
        prev = None
        count1 = 0
        curr = head
        next = None
        while curr!= None and count1 < k:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
            count1 += 1

        if next!= None:
            head.next = self.reverse(next, count - k, k)
        return prev

    # Reverses the linked list in groups of k nodes.
    def reverseKGroup(self, head, k):
        count = self.length(head)
        return self.reverse(head, count, k)

# Main function
if __name__ == '__main__':
    # Input the number of nodes
    n = int(input())

    if n <= 0:
        print("The linked list must contain at least one node.")
        sys.exit()

    # Input the linked list elements
    head = Node(int(input()))
    temp = head
    for i in range(1, n):
        temp.next = Node(int(input()))
        temp = temp.next

    # Input the value of k
    k = int(input())

    # Reverse the linked list in groups of k
    reverseKGroup = Main()
    head = reverseKGroup.reverseKGroup(head, k)

    # Print the modified linked list
    print("Modified linked list:")
    temp = head
    while temp!= None:
        print(temp.value, end=" ")
        temp = temp.next
    print()

