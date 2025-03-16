
# Import the Scanner class from the java.util package
from java.util import Scanner

# The Node class
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

# The Main class
class Main:
    # Calculates the length of the linked list
    def length(self, head):
        curr = head
        count = 0
        while curr is not None:
            curr = curr.next
            count += 1
        return count

    # Reverses the linked list in groups of k nodes
    def reverse(self, head, count, k):
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
            head.next = self.reverse(next, count - k, k)
        return prev

    # Reverses the linked list in groups of k nodes
    def reverseKGroup(self, head, k):
        count = self.length(head)
        return self.reverse(head, count, k)

# Main method for testing the Main functionality
if __name__ == "__main__":
    # Create a Scanner object
    scanner = Scanner(System.in)

    # Input the number of nodes
    n = scanner.nextInt()

    if n <= 0:
        print("The linked list must contain at least one node.")
        return

    # Input the linked list elements
    head = Node(scanner.nextInt())
    temp = head
    for i in range(1, n):
        temp.next = Node(scanner.nextInt())
        temp = temp.next

    # Input the value of k
    k = scanner.nextInt()

    # Reverse the linked list in groups of k
    reverseKGroup = Main()
    head = reverseKGroup.reverseKGroup(head, k)

    # Print the modified linked list
    print("Modified linked list:")
    temp = head
    while temp is not None:
        print(temp.value, end=" ")
        temp = temp.next
    print()
    scanner.close()

