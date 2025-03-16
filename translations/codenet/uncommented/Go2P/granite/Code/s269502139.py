
import sys

class Node:
    def __init__(self, key):
        self.key = key
        self.prev = None
        self.next = None

    def rPrint(self, buf):
        buf.write(str(self.key))
        if self.next!= None:
            buf.write(" ")
            self.next.rPrint(buf)

    def delete(self, first, last):
        if self.prev!= None and self.next!= None:
            #swap
            self.prev.next = self.next
            self.next.prev = self.prev
            return first, last

        if self.next == None and self.prev == None:
            return None, None

        if self.prev == None:
            first = self.next
            self.next.prev = None
        if self.next == None:
            last = self.prev
            self.prev.next = None

        return first, last

def initNode(key):
    return Node(key)

if __name__ == "__main__":
    first, last = None, None
    for line in sys.stdin:
        if line == "deleteFirst\n":
            first, last = first.delete(first, last)
        elif line == "deleteLast\n":
            first, last = last.delete(first, last)
        else:
            xcmd = line.split()
            k = int(xcmd[1])
            if xcmd[0] == "delete":
                a = first
                while a!= None:
                    if a.key == k:
                        first, last = a.delete(first, last)
                        break
                    a = a.next
            elif xcmd[0] == "insert":
                n = initNode(k)
                n.next = first
                if first!= None:
                    first.prev = n
                first = n
                if last == None:
                    last = n

    buf = bytes()
    first.rPrint(buf)
    print(buf.decode())
