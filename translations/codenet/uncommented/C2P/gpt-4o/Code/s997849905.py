class Node:
    def __init__(self, key=None):
        self.key = key
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = Node()  # Sentinel node
        self.head.next = self.head
        self.head.prev = self.head

    def print_list(self):
        cur = self.head.next
        snl = 1
        output = []
        while cur != self.head:
            if snl == 0:
                output.append(" ")
            output.append(str(cur.key))
            cur = cur.next
            snl = 0
        print("".join(output))

    def delete_first(self):
        if self.head.next == self.head:  # List is empty
            return
        t = self.head.next
        self.head.next = t.next
        t.next.prev = self.head

    def delete_last(self):
        if self.head.prev == self.head:  # List is empty
            return
        delnode = self.head.prev
        self.head.prev = delnode.prev
        delnode.prev.next = self.head
        del delnode

    def delete(self, skey):
        n = self.head.next
        while n != self.head:
            if n.key == skey:
                break
            n = n.next
        else:
            return  # Key not found

        # Delete the node
        n.prev.next = n.next
        n.next.prev = n.prev
        del n

    def insert(self, skey):
        new_node = Node(skey)
        if self.head.next == self.head:  # List is empty
            new_node.next = self.head
            new_node.prev = self.head
            self.head.next = new_node
            self.head.prev = new_node
        else:
            new_node.next = self.head.next
            new_node.prev = self.head
            self.head.next.prev = new_node
            self.head.next = new_node

def main():
    n = int(input())
    dll = DoublyLinkedList()
    for _ in range(n):
        command = input().strip()
        if command == "insert":
            key = int(input())
            dll.insert(key)
        elif command == "deleteFirst":
            dll.delete_first()
        elif command == "deleteLast":
            dll.delete_last()
        else:
            key = int(input())
            dll.delete(key)
    dll.print_list()

if __name__ == "__main__":
    main()

# <END-OF-CODE>
