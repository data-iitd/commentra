
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
    while True:
        if cur == nil:
            break
        if not is_first:
            print(" ", end="")
        print(cur.key, end="")
        cur = cur.next
        is_first = False
    print()

def delete_node(node):
    if node == nil:
        return
    node.prev.next = node.next
    node.next.prev = node.prev
    del node

def delete_first():
    node = nil.next
    if node == nil:
        return
    delete_node(node)

def delete_last():
    node = nil.prev
    if node == nil:
        return
    delete_node(node)

def delete_key(key):
    node = list_search(key)
    if node!= nil:
        delete_node(node)

def insert(key):
    node = Node(key)
    node.prev = nil
    node.next = nil.next
    node.next.prev = node
    nil.next = node

if __name__ == "__main__":
    n = int(input())
    init()
    np = 0
    nd = 0
    for i in range(n):
        com, key = input().split()
        if com == "insert":
            insert(int(key))
            np += 1
        elif com == "delete":
            if len(com) > 6:
                if com[6] == "F":
                    delete_first()
                elif com[6] == "L":
                    delete_last()
            else:
                delete_key(int(key))
            nd += 1
    print_list()

