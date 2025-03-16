class Node:
    def __init__(self, key):
        self.key = key
        self.prev = None
        self.next = None

    def rPrint(self, buf):
        buf.append(str(self.key))
        if self.next is not None:
            buf.append(" ")
            self.next.rPrint(buf)

    def delete(self, first, last):
        if self.prev is not None and self.next is not None:
            self.prev.next = self.next
            self.next.prev = self.prev
            return first, last

        if self.next is None and self.prev is None:
            return None, None

        if self.prev is None:
            first = self.next
            if first is not None:
                first.prev = None

        if self.next is None:
            last = self.prev
            if last is not None:
                last.next = None

        return first, last


def initNode(key):
    return Node(key)


def main():
    import sys
    input = sys.stdin.readline
    first = None
    last = None

    while True:
        try:
            cmd = input().strip()
        except EOFError:
            break

        if cmd == "deleteFirst":
            first, last = first.delete(first, last)
        elif cmd == "deleteLast":
            first, last = last.delete(first, last)
        else:
            xcmd = cmd.split()
            k = int(xcmd[1])
            k32 = int32(k)

            if xcmd[0] == "delete":
                current = first
                while current is not None:
                    if current.key == k32:
                        first, last = current.delete(first, last)
                        break
                    current = current.next
            elif xcmd[0] == "insert":
                n = initNode(k32)
                n.next = first
                if first is not None:
                    first.prev = n
                first = n
                if last is None:
                    last = n

    buf = []
    if first is not None:
        first.rPrint(buf)
    print(" ".join(buf))

