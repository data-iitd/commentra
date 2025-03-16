

# Define the `node` structure
# This structure represents a node in a doubly linked list.
# It contains an integer key, and pointers to the previous and next nodes.
class node:
    def __init__(self, key):
        self.key = key
        self.prev = None
        self.next = None

# Recursive Print Function
# The `rPrint` method prints the keys of the nodes in the list from the current node to the last node.
def rPrint(n, buf):
    buf.write(str(n.key))
    if n.next!= None:
        buf.write(" ")
        rPrint(n.next, buf)
    return

# Delete Method
# The `Delete` method removes the current node from the list and adjusts the pointers of the surrounding nodes.
def Delete(n, first, last):
    if n.prev!= None and n.next!= None:
        #swap
        n.prev.next = n.next
        n.next.prev = n.prev
        return first, last
    if n.next == None and n.prev == None:
        return None, None
    if n.prev == None:
        first = n.next
        n.next.prev = None
    if n.next == None:
        last = n.prev
        n.prev.next = None
    return first, last

# Node Initialization
# The `initNode` function creates a new node with the given key.
def initNode(key):
    return node(key)

# Main Function
# The main function reads commands from standard input, performs operations on the doubly linked list, and prints the final list.
def main():
    import sys
    stdin = sys.stdin
    first = None
    last = None
    stdin.readline()
    for line in stdin:
        cmd = line.strip()
        if cmd == "deleteFirst":
            first, last = Delete(first, first, last)
        elif cmd == "deleteLast":
            first, last = Delete(last, first, last)
        else:
            xcmd = cmd.split(" ")
            k = int(xcmd[1])
            if xcmd[0] == "delete":
                a = first
                while a!= None:
                    if a.key == k:
                        first, last = Delete(a, first, last)
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
    rPrint(first, buf)
    print(buf.decode())

This code now includes comments that describe each logical block, making it easier to understand the structure and functionality of the Python code.