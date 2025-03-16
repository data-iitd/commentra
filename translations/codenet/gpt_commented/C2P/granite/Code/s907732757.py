
class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = Node(0)
        self.head.next = self.head
        self.head.prev = self.head

    def insert(self, a):
        new_node = Node(a)
        new_node.next = self.head.next
        self.head.next.prev = new_node
        self.head.next = new_node
        new_node.prev = self.head

    def delete(self, a):
        x = self.head
        while x.next!= self.head:
            x = x.next
            if x.key == a:
                x.prev.next = x.next
                x.next.prev = x.prev
                del x
                break

    def delete_first(self):
        x = self.head.next
        self.head.next = x.next
        x.next.prev = self.head

    def delete_last(self):
        x = self.head.prev
        self.head.prev = x.prev
        x.prev.next = self.head
        del x

# Read the number of operations to perform
n = int(input())
dll = DoublyLinkedList()
for i in range(n):
    # Read the operation command
    op = input()
    if op == "insert":
        # Read the value to insert
        a = int(input())
        dll.insert(a)
    elif op == "delete":
        # Read the value to delete
        a = int(input())
        dll.delete(a)
    elif op == "deleteFirst":
        dll.delete_first()
    elif op == "deleteLast":
        dll.delete_last()

# Print the remaining elements in the list
x = dll.head
while x.next!= dll.head:
    print(x.next.key, end=" ")
    x = x.next
print()

