class Node:
    def __init__(self, key):
        self.key = key
        self.prev = None
        self.next = None

    def r_print(self, buf):
        buf.append(str(self.key))
        if self.next is not None:
            self.next.r_print(buf)

    def delete(self, first, last):
        # Base case: if node is the first and last node
        if self.prev is None and self.next is None:
            return None, None

        # Base case: if node is the first node
        if self.prev is None:
            first = self.next
            if self.next is not None:
                self.next.prev = None
            return first, last

        # Base case: if node is the last node
        if self.next is None:
            last = self.prev
            self.prev.next = None
            return first, last

        # General case: swap the pointers of previous and next nodes
        self.prev.next = self.next
        self.next.prev = self.prev
        return first, last


def init_node(key):
    return Node(key)


def main():
    import sys
    input = sys.stdin.read
    data = input().strip().splitlines()

    first = None
    last = None

    for cmd in data:
        if cmd == "deleteFirst":
            if first is not None:
                first, last = first.delete(first, last)
        elif cmd == "deleteLast":
            if last is not None:
                first, last = last.delete(first, last)
        else:
            xcmd = cmd.split()
            k = int(xcmd[1])
            if xcmd[0] == "delete":
                a = first
                while a is not None:
                    if a.key == k:
                        first, last = a.delete(first, last)
                        break
                    a = a.next
            elif xcmd[0] == "insert":
                n = init_node(k)
                n.next = first
                if first is not None:
                    first.prev = n
                first = n
                if last is None:
                    last = n

    # Print the linked list in reverse order
    buf = []
    if first is not None:
        first.r_print(buf)
    print(" ".join(buf))


if __name__ == "__main__":
    main()
# <END-OF-CODE>
