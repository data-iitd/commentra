class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class Main:
    def length(self, head):
        curr = head
        count = 0
        while curr:
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

    def main(self):
        import sys
        input = sys.stdin.read
        data = input().split()

        n = int(data[0])

        if n <= 0:
            print("The linked list must contain at least one node.")
            return

        head = Node(int(data[1]))
        temp = head
        for i in range(2, n + 1):
            temp.next = Node(int(data[i]))
            temp = temp.next

        k = int(data[n + 1])

        reverseKGroup = Main()
        head = reverseKGroup.reverseKGroup(head, k)

        print("Modified linked list:")
        temp = head
        while temp:
            print(temp.value, end=" ")
            temp = temp.next
        print()


Main().main()
