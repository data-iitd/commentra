

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
    while cur!= nil:
        if cur.key == key:
            break
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
    while cur!= nil:
        if is_first:
            print("[%d] " % cur.key, end="")
            is_first = False
        else:
            print(" %d" % cur.key, end="")
        cur = cur.next
    print()

def delete_node(t):
    if t == nil:
        return
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

def delete_key(key):
    t = list_search(key)
    if t!= nil:
        delete_node(t)

def insert(key):
    x = Node(key)
    x.prev = nil
    x.next = nil.next
    nil.next.prev = x
    nil.next = x

if __name__ == "__main__":
    n = int(input())
    init()
    np = 0
    nd = 0
    for i in range(n):
        com, key = input().split()
        key = int(key)
        if com[0] == 'i':
            insert(key)
            np += 1
        elif com[0] == 'd':
            if len(com) > 6:
                if com[6] == 'F':
                    delete_first()
                elif com[6] == 'L':
                    delete_last()
            else:
                delete_key(key)
                nd += 1
    print_list()

