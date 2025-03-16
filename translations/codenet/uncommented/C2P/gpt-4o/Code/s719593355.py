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
        command, key = input().split()
        key = int(key)

        if command[0] == 'i':
            dll.insert(key)
        elif command[0] == 'd':
            if len(command) > 6:
                if command[6] == 'F':
                    dll.delete_first()
                elif command[6] == 'L':
                    dll.delete_last()
            else:
                dll.delete(key)

    dll.print_list()

if __name__ == "__main__":
    main()

# <END-OF-CODE>
