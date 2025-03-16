class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class Main:
    def length(self, head):
        curr = head
        count = 0
        while curr is not None:
            curr = curr.next
            count += 1
        return count

    def reverse(self, head, count, k):
        if count < k:
            return head
        prev = None
        count1 = 0
        curr = head
        next_node = None
        while curr is not None and count1 < k:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
            count1 += 1

        if next_node is not None:
            head.next = self.reverse(next_node, count - k, k)
        return prev

    def reverseKGroup(self, head, k):
        count = self.length(head)
        return self.reverse(head, count, k)

if __name__ == "__main__":
    n = int(input("Enter the number of nodes: "))

    if n <= 0:
        print("The linked list must contain at least one node.")
    else:
        # Input the linked list elements
        head = Node(int(input("Enter node value: ")))
        temp = head
        for i in range(1, n):
            temp.next = Node(int(input("Enter node value: ")))
            temp = temp.next

        # Input the value of k
        k = int(input("Enter the value of k: "))

        # Reverse the linked list in groups of k
        reverse_k_group = Main()
        head = reverse_k_group.reverseKGroup(head, k)

        # Print the modified linked list
        print("Modified linked list:")
        temp = head
        while temp is not None:
            print(temp.value, end=" ")
            temp = temp.next
        print()

# <END-OF-CODE>
