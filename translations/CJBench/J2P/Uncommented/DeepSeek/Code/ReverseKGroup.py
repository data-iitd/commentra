class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

def length(head):
    curr = head
    count = 0
    while curr:
        curr = curr.next
        count += 1
    return count

def reverse(head, count, k):
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
        head.next = reverse(next, count - k, k)
    return prev

def reverseKGroup(head, k):
    count = length(head)
    return reverse(head, count, k)

def main():
    n = int(input())
    if n <= 0:
        print("The linked list must contain at least one node.")
        return
    values = list(map(int, input().split()))
    head = Node(values[0])
    temp = head
    for i in range(1, n):
        temp.next = Node(values[i])
        temp = temp.next
    k = int(input())
    head = reverseKGroup(head, k)
    print("Modified linked list:")
    temp = head
    while temp:
        print(temp.value, end=" ")
        temp = temp.next
    print()

main()
