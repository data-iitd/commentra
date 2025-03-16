
class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

nil = Node(None)
nil.next = nil
nil.prev = nil

def list_search(key):
    cur = nil.next
    while cur!= nil and cur.key!= key:
        cur = cur.next
    return cur

def init():
    global nil
    nil = Node(None)
    nil.next = nil
    nil.prev = nil

def print_list():
    cur = nil.next
    is_first = True
    while True:
        if cur == nil:
            break
        if not is_first:
            print(" ", end="")
        print(cur.key, end="")
        cur = cur.next
        is_first = False
    print()

def delete_node(t):
    t.prev.next = t.next
    t.next.prev = t.prev
    del t

def delete_first():
    t = nil.next
    if t == nil:
        return
    delete_node(t)

def delete_last():
    t = nil.prev
    if t == nil:
        return
    delete_node(t)

def delete(key):
    t = list_search(key)
    if t == nil:
        return
    delete_node(t)

def insert(key):
    x = Node(key)
    x.next = nil.next
    nil.next.prev = x
    nil.next = x
    x.prev = nil

if __name__ == "__main__":
    n = int(input())
    init()
    for _ in range(n):
        com, key = input().split()
        key = int(key)
        if com[0] == "i":
            insert(key)
        elif com[0] == "d":
            if len(com) > 6:
                if com[6] == "F":
                    delete_first()
                elif com[6] == "L":
                    delete_last()
            else:
                delete(key)
    print_list()

