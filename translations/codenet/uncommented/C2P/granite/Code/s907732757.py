
class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

head = Node(0)
head.next = head
head.prev = head

def makeNode(a):
    x = Node(a)
    return x

def insert(a):
    x = makeNode(a)
    x.next = head.next
    head.next.prev = x
    head.next = x
    x.prev = head

def delete(a):
    x = head
    while x.next!= head:
        x = x.next
        if x.key == a:
            x.prev.next = x.next
            x.next.prev = x.prev
            del x
            break

def deleteFirst():
    x = head.next
    head.next = x.next
    x.next.prev = head
    del x

def deleteLast():
    x = head.prev
    head.prev = x.prev
    x.prev.next = head
    del x

n = int(input())
for i in range(n):
    op = input().split()
    if op[0] == "insert":
        a = int(op[1])
        insert(a)
    elif op[0] == "delete":
        a = int(op[1])
        delete(a)
    elif op[0] == "deleteFirst":
        deleteFirst()
    elif op[0] == "deleteLast":
        deleteLast()

x = head
while x.next!= head:
    print(x.next.key, end=" ")
    x = x.next
print()

