
# Node class representing each element in the linked list
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

# Method to calculate the length of the linked list
def length(head):
    curr = head
    count = 0
    while curr is not None:
        curr = curr.next
        count += 1
    return count

# Method to reverse the linked list in groups of k nodes
def reverse(head, count, k):
    # If the remaining nodes are less than k, return the head as is
    if count < k:
        return head

    prev = None
    count1 = 0
    curr = head
    next = None

    # Reverse k nodes in the current group
    while curr is not None and count1 < k:
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next
        count1 += 1

    # Recursively reverse the next groups and link them
    if next is not None:
        head.next = reverse(next, count - k, k)
    return prev

# Method to initiate the reversal of the linked list in k-sized groups
def reverseKGroup(head, k):
    count = length(head)
    return reverse(head, count, k)

# Main method to execute the program
def main():
    n = int(input("Enter the number of nodes: "))

    # Check if the number of nodes is valid
    if n <= 0:
        print("The linked list must contain at least one node.")
        return

    # Create the head of the linked list
    head = Node(int(input("Enter the value of the head node: ")))
    temp = head

    # Build the linked list from the input values
    for i in range(1, n):
        temp.next = Node(int(input("Enter the value of node " + str(i + 1) + ": ")))
        temp = temp.next

    k = int(input("Enter the value of k: "))
    reverseKGroup(head, k)

    # Print the modified linked list
    print("Modified linked list:")
    temp = head
    while temp is not None:
        print(temp.value, end=" ")
        temp = temp.next
    print()

if __name__ == "__main__":
    main()

