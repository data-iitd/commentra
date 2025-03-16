
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

    def reverseKGroup(self, head, k):
        count = self.length(head)
        return self.reverse(head, count, k)

if __name__ == "__main__":
    n = int(input("Enter the number of nodes in the linked list: "))
    if n <= 0:
        print("The linked list must contain at least one node.")
        exit()
    head = Node(int(input("Enter the value of the first node: ")))
    temp = head
    for i in range(1, n):
        temp.next = Node(int(input("Enter the value of node " + str(i + 1) + ": ")))
        temp = temp.next
    k = int(input("Enter the value of k: "))
    main = Main()
    head = main.reverseKGroup(head, k)
    print("Modified linked list:")
    temp = head
    while temp is not None:
        print(temp.value, end=" ")
        temp = temp.next
    print()

