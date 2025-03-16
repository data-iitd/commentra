
class MainNode:
    def __init__(self, val):
        self.val = val
        self.next = None
        self.prev = None

class Main:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def addFirst(self, val):
        new_node = MainNode(val)
        if self.isEmpty():
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
        self.size += 1

    def addLast(self, val):
        new_node = MainNode(val)
        if self.tail is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
        self.size += 1

    def pollFirst(self):
        if self.head is None:
            raise IndexError("Main is empty")
        old_head_val = self.head.val
        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None
        self.size -= 1
        return old_head_val

    def pollLast(self):
        if self.tail is None:
            raise IndexError("Main is empty")
        old_tail_val = self.tail.val
        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None
        self.size -= 1
        return old_tail_val

    def peekFirst(self):
        return self.head.val if self.head is not None else None

    def peekLast(self):
        return self.tail.val if self.tail is not None else None

    def size(self):
        return self.size

    def isEmpty(self):
        return self.size == 0

    def __str__(self):
        deque_string = "Head -> "
        curr_node = self.head
        while curr_node is not None:
            deque_string += str(curr_node.val)
            if curr_node.next is not None:
                deque_string += " <-> "
            curr_node = curr_node.next
        deque_string += " <- Tail"
        return deque_string

if __name__ == "__main__":
    import sys
    deque = Main()
    for line in sys.stdin:
        command = line.strip()
        if command.lower() == "exit":
            break
        try:
            parts = command.split()
            if parts[0].lower() == "addfirst":
                val = int(parts[1])
                deque.addFirst(val)
                print(f"Added to front: {val}")
            elif parts[0].lower() == "addlast":
                val = int(parts[1])
                deque.addLast(val)
                print(f"Added to rear: {val}")
            elif parts[0].lower() == "pollfirst":
                print(f"Removed from front: {deque.pollFirst()}")
            elif parts[0].lower() == "polllast":
                print(f"Removed from rear: {deque.pollLast()}")
            elif parts[0].lower() == "peekfirst":
                print(f"Front element: {deque.peekFirst()}")
            elif parts[0].lower() == "peeklast":
                print(f"Rear element: {deque.peekLast()}")
            elif parts[0].lower() == "size":
                print(f"Size: {deque.size()}")
            elif parts[0].lower() == "isempty":
                print(f"Is empty: {deque.isEmpty()}")
            elif parts[0].lower() == "print":
                print(deque)
            else:
                print(f"Unknown command: {parts[0]}")
        except Exception as e:
            print(f"Error: {e}")

