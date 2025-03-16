
class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

class CircularDoublyLinkedList:
    def __init__(self):
        self.sentinel = Node(None)
        self.sentinel.next = self.sentinel
        self.sentinel.prev = self.sentinel
        self.count = 0

    def print_list(self):
        cur = self.sentinel.next
        snl = True
        while cur!= self.sentinel:
            if not snl:
                print(" ", end="")
            print(cur.key, end="")
            cur = cur.next
            snl = False
        print()

    def delete_first(self):
        t = self.sentinel.next
        self.sentinel.next = t.next
        t.next.prev = self.sentinel
        self.count -= 1

    def delete_last(self):
        delnode = self.sentinel.prev
        self.sentinel.prev = delnode.prev
        delnode.prev.next = self.sentinel
        self.count -= 1

    def delete(self, skey):
        judge = False
        n = self.sentinel.next
        while n!= self.sentinel:
            if n.key == skey:
                judge = True
                break
            n = n.next
        if judge:
            n = self.sentinel.next
            while n!= self.sentinel:
                if n.key == skey:
                    break
                n = n.next
            t = n.prev
            t.next = n.next
            t.next.prev = t
            self.count -= 1

    def insert(self, skey):
        new = Node(skey)
        if self.count == 0:
            new.next = self.sentinel
            self.sentinel.next = new
            new.prev = self.sentinel
            self.sentinel.prev = new
            self.count += 1
        else:
            new.next = self.sentinel.next
            self.sentinel.next.prev = new
            self.sentinel.next = new
            new.prev = self.sentinel
            self.count += 1

if __name__ == "__main__":
    n = int(input())
    cdl = CircularDoublyLinkedList()
    for i in range(n):
        com = input().split()
        if com[0] == "insert":
            cdl.insert(int(com[1]))
        elif com[0] == "deleteFirst":
            cdl.delete_first()
        elif com[0] == "deleteLast":
            cdl.delete_last()
        else:
            cdl.delete(int(com[1]))
    cdl.print_list()

