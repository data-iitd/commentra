class Node:
    """Node structure for a doubly linked list."""
    def __init__(self, key):
        self.key = key
        self.prev = None
        self.next = None

    def r_print(self, buf):
        """Recursive print function to print keys from the current node to the last node."""
        buf.append(str(self.key))
        if self.next is not None:
            self.next.r_print(buf)

    def delete(self, first, last):
        """Delete the current node from the list and adjust pointers."""
        if self.prev is not None and self.next is not None:
            # Node is in the middle
            self.prev.next = self.next
            self.next.prev = self.prev
            return first, last

        if self.next is None and self.prev is None:
            return None, None  # Node is the only node

        if self.prev is None:
            # Node is the first node
            first = self.next
            self.next.prev = None

        if self.next is None:
            # Node is the last node
            last = self.prev
            self.prev.next = None

        return first, last


def init_node(key):
    """Initialize a new node with the given key."""
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
                current = first
                while current is not None:
                    if current.key == k:
                        first, last = current.delete(first, last)
                        break
                    current = current.next
            elif xcmd[0] == "insert":
                n = init_node(k)
                n.next = first
                if first is not None:
                    first.prev = n
                first = n
                if last is None:
                    last = n

    buf = []
    if first is not None:
        first.r_print(buf)
    print(" ".join(buf))


if __name__ == "__main__":
    main()

# <END-OF-CODE>
