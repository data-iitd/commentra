
import sys

# Represents a node in a singly linked list
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

# Calculates the length of the linked list
def length(head):
    curr = head
    count = 0
    while curr is not None:
        curr = curr.next
        count += 1
    return count

# Reverses a sublist of the linked list of size k
def reverse(head, count, k):
    if count < k:
        return head
    prev = None
    count1 = 0
    curr = head
    next = None
    while curr is not None and count1 < k:
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next
        count1 += 1
    if next is not None:
        head.next = reverse(next, count - k, k)
    return prev

# Reverses the linked list in groups of k
def reverseKGroup(head, k):
    count = length(head)
    return reverse(head, count, k)

# Main method to run the program
def main():
    # Read the number of nodes in the linked list
    n = int(sys.stdin.readline())
    if n <= 0:
        print("The linked list must contain at least one node.")
        return
    # Create the linked list from the input
    head = Node(int(sys.stdin.readline()))
    temp = head
    for i in range(1, n):
        temp.next = Node(int(sys.stdin.readline()))
        temp = temp.next
    # Read the group size k
    k = int(sys.stdin.readline())
    reverseKGroup = reverseKGroup(head, k)
    # Print the modified linked list
    print("Modified linked list:")
    temp = reverseKGroup
    while temp is not None:
        print(temp.value, end=" ")
        temp = temp.next
    print()

if __name__ == "__main__":
    main()

