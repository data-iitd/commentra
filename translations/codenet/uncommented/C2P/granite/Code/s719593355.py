
class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

nil = Node(None)
nil.next = nil
nil.prev = nil

def listSearch(key):
    cur = nil.next
    while cur!= nil and cur.key!= key:
        cur = cur.next
    return cur

def init():
    global nil
    nil = Node(None)
    nil.next = nil
    nil.prev = nil

def printList():
    cur = nil.next
    isf = True
    while True:
        if cur == nil:
            break
        if isf == False:
            print(" ", end="")
        print(cur.key, end="")
        cur = cur.next
        isf = False
    print()

def deleteNode(t):
    t.prev.next = t.next
    t.next.prev = t.prev
    del t

def deleteFirst():
    t = nil.next
    if t == nil:
        return
    deleteNode(t)

def deleteLast():
    t = nil.prev
    if t == nil:
        return
    deleteNode(t)

def delete(key):
    t = listSearch(key)
    if t == nil:
        return
    deleteNode(t)

def insert(key):
    x = Node(key)
    x.next = nil.next
    nil.next.prev = x
    nil.next = x
    x.prev = nil

n = int(input())
init()
for i in range(n):
    com, key = input().split()
    key = int(key)
    if com[0] == 'i':
        insert(key)
    elif com[0] == 'd':
        if len(com) > 6:
            if com[6] == 'F':
                deleteFirst()
            elif com[6] == 'L':
                deleteLast()
        else:
            delete(key)

printList()

