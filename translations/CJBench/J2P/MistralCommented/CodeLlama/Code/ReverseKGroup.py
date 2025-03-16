
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class Solution:
    def length(self, head):
        count = 0
        curr = head
        while curr:
            count += 1
            curr = curr.next
        return count

    def reverse(self, head, count, k):
        if count < k:
            return head
        prev = None
        count1 = 0
        curr = head
        next = None
        while curr and count1 < k:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
            count1 += 1
        if next:
            head.next = self.reverse(next, count - k, k)
        return prev

    def reverseKGroup(self, head, k):
        count = self.length(head)
        return self.reverse(head, count, k)

if __name__ == '__main__':
    scanner = input().split()
    n = int(scanner[0])
    if n <= 0:
        print("The linked list must contain at least one node.")
        exit()
    head = Node(int(scanner[1]))
    temp = head
    for i in range(2, n + 1):
        temp.next = Node(int(scanner[i]))
        temp = temp.next
    k = int(input())
    solution = Solution()
    head = solution.reverseKGroup(head, k)
    print("Modified linked list:")
    temp = head
    while temp:
        print(temp.value, end=" ")
        temp = temp.next
    print()
