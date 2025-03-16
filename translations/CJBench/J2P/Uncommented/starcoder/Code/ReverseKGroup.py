# <START-OF-CODE>
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class Main:
    def length(self, head):
        curr = head
        count = 0
        while curr!= None:
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
        while curr!= None and count1 < k:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
            count1 += 1
        if next!= None:
            head.next = self.reverse(next, count - k, k)
        return prev

    def reverseKGroup(self, head, k):
        count = self.length(head)
        return self.reverse(head, count, k)

if __name__ == '__main__':
    n = int(input())
    if n <= 0:
        print("The linked list must contain at least one node.")
        return
    head = Node(int(input()))
    temp = head
    for i in range(1, n):
        temp.next = Node(int(input()))
        temp = temp.next
    k = int(input())
    reverseKGroup = Main()
    head = reverseKGroup.reverseKGroup(head, k)
    print("Modified linked list:")
    temp = head
    while temp!= None:
        print(temp.value, end=" ")
        temp = temp.next
    print()
# 