
class Node:
    def __init__(self, key):
        self.key = key
        self.prev = None
        self.next = None

def initNode(key):
    return Node(key)

def deleteFirst(first, last):
    if first is not None and first.next is not None:
        first.next.prev = None
        first = first.next
    return first, last

def deleteLast(first, last):
    if last is not None and last.prev is not None:
        last.prev.next = None
        last = last.prev
    return first, last

def delete(first, last, key):
    if first is None:
        return first, last

    if first.key == key:
        first, last = deleteFirst(first, last)
        return first, last

    if last.key == key:
        first, last = deleteLast(first, last)
        return first, last

    for a in first:
        if a.key == key:
            a.prev.next = a.next
            a.next.prev = a.prev
            return first, last

    return first, last

def insert(first, last, key):
    n = initNode(key)
    n.next = first
    if first is not None:
        first.prev = n
    first = n
    if last is None:
        last = n
    return first, last

def rPrint(first):
    if first is None:
        return
    print(first.key, end=" ")
    rPrint(first.next)

def main():
    first = None
    last = None
    stdin = input()
    while stdin!= "":
        cmd = stdin
        stdin = input()
        if cmd == "deleteFirst":
            first, last = deleteFirst(first, last)
        elif cmd == "deleteLast":
            first, last = deleteLast(first, last)
        else:
            xcmd = cmd.split(" ")
            k = int(xcmd[1])
            if xcmd[0] == "delete":
                first, last = delete(first, last, k)
            elif xcmd[0] == "insert":
                first, last = insert(first, last, k)
    rPrint(first)

main()

