class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.nil = Node(None)  # Sentinel node
        self.nil.next = self.nil
        self.nil.prev = self.nil

    def list_search(self, key):
        cur = self.nil.next
        while cur != self.nil:
            if cur.key == key:
                return cur
            cur = cur.next
        return None

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
        if t == self.nil:
            return
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

    def delete_key(self, key):
        t = self.list_search(key)
        if t is not None:
            self.delete_node(t)

    def insert(self, key):
        x = Node(key)
        x.prev = self.nil
        x.next = self.nil.next
        x.next.prev = x
        self.nil.next = x

def main():
    n = int(input())
    dll = DoublyLinkedList()
    size = 0
    np = 0
    nd = 0

    for _ in range(n):
        command = input().split()
        com = command[0]
        key = int(command[1])

        if com[0] == 'i':
            dll.insert(key)
            np += 1
            size += 1
        elif com[0] == 'd':
            if len(com) > 6:
                if com[6] == 'F':
                    dll.delete_first()
                elif com[6] == 'L':
                    dll.delete_last()
            else:
                dll.delete_key(key)
                nd += 1
            size -= 1

    dll.print_list()

if __name__ == "__main__":
    main()

# <END-OF-CODE>
