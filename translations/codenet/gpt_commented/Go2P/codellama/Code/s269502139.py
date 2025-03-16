
#!/usr/bin/env python3

import sys

class Node:
    def __init__(self, key):
        self.key = key
        self.prev = None
        self.next = None

    def rprint(self):
        print(self.key, end=' ')
        if self.next is not None:
            self.next.rprint()

    def delete(self, first, last):
        if self.prev is not None and self.next is not None:
            self.prev.next = self.next
            self.next.prev = self.prev
            return first, last

        if self.next is None and self.prev is None:
            return None, None

        if self.prev is None:
            first = self.next
            self.next.prev = None

        if self.next is None:
            last = self.prev
            self.prev.next = None

        return first, last

first = None
last = None

for line in sys.stdin:
    cmd = line.strip()
    if cmd == "deleteFirst":
        first, last = first.delete(first, last)
    elif cmd == "deleteLast":
        first, last = last.delete(first, last)
    else:
        xcmd = cmd.split()
        k = int(xcmd[1])
        if xcmd[0] == "delete":
            for a in range(first):
                if first[a].key == k:
                    first, last = first[a].delete(first, last)
                    break
        elif xcmd[0] == "insert":
            n = Node(k)
            n.next = first
            if first is not None:
                first.prev = n
            first = n
            if last is None:
                last = n

buf = ""
first.rprint()
print(buf)

