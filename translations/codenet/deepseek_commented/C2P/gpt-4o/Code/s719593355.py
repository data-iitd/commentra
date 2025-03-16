class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.nil = Node(None)  # Dummy node
        self.nil.next = self.nil
        self.nil.prev = self.nil

    def list_search(self, key):
        cur = self.nil.next
        while cur != self.nil and cur.key != key:
            cur = cur.next
        return cur

    def print_list(self):
        cur = self.nil.next
        is_first = True
        while True:
            if cur == self.nil:
                break
            if not is_first:
                print(" ", end="")
            print(cur.key, end="")
            cur = cur.next
            is_first = False
        print()

    def delete_node(self, t):
        t.prev.next = t.next
        t.next.prev = t.prev
        del t

    def delete_first(self):
        t = self.nil.next
        if t == self.nil:
            return
        self.delete_node(t)

    def delete_last(self):
        t = self.nil.prev
        if t == self.nil:
            return
        self.delete_node(t)

    def delete(self, key):
        t = self.list_search(key)
        if t == self.nil:
            return
        self.delete_node(t)

    def insert(self, key):
        x = Node(key)
        x.next = self.nil.next
        self.nil.next.prev = x
        self.nil.next = x
        x.prev = self.nil

def main():
    n = int(input())
    dll = DoublyLinkedList()

    for _ in range(n):
        command = input().split()
        com = command[0]
        key = int(command[1])

        if com[0] == 'i':  # Insert a new node with the specified key
            dll.insert(key)

        elif com[0] == 'd':  # Delete a node with the specified key or the first/last node
            if len(com) > 6:
                if com[6] == 'F':  # Delete the first node
                    dll.delete_first()
                elif com[6] == 'L':  # Delete the last node
                    dll.delete_last()
            else:
                dll.delete(key)

    dll.print_list()  # Print the final list

if __name__ == "__main__":
    main()

# <END-OF-CODE>
