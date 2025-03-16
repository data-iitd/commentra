class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.nil = Node(None)
        self.nil.next = self.nil
        self.nil.prev = self.nil

    def insert(self, key):
        new_node = Node(key)
        new_node.next = self.nil.next
        self.nil.next.prev = new_node
        self.nil.next = new_node
        new_node.prev = self.nil

    def delete_first(self):
        if self.nil.next == self.nil:
            return
        t = self.nil.next
        self.nil.next = t.next
        t.next.prev = self.nil

    def delete_last(self):
        if self.nil.next == self.nil:
            return
        delnode = self.nil.prev
        delnode.prev.next = self.nil
        self.nil.prev = delnode.prev

    def delete(self, key):
        t = self.nil.next
        while t != self.nil:
            if t.key == key:
                t.prev.next = t.next
                t.next.prev = t.prev
                return
            t = t.next

    def print_list(self):
        cur = self.nil.next
        snl = True
        while cur != self.nil:
            if not snl:
                print(" ", end="")
            print(cur.key, end="")
            cur = cur.next
            snl = False
        print()

def main():
    n = int(input())
    dll = DoublyLinkedList()
    for _ in range(n):
        com = input().split()
        if com[0] == "insert":
            key = int(com[1])
            dll.insert(key)
        elif com[0] == "deleteFirst":
            dll.delete_first()
        elif com[0] == "deleteLast":
            dll.delete_last()
        elif com[0] == "delete":
            key = int(com[1])
            dll.delete(key)
    dll.print_list()

if __name__ == "__main__":
    main()
