class Node:
    """Node for the deque"""
    def __init__(self, val):
        self.val = val
        self.next = None
        self.prev = None


class Deque:
    """A double-ended queue (deque) implementation using a doubly linked list."""
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def add_first(self, val):
        """Adds the specified value to the head of the deque."""
        new_node = Node(val)
        if self.is_empty():
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
        self.size += 1

    def add_last(self, val):
        """Adds the specified value to the tail of the deque."""
        new_node = Node(val)
        if self.tail is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
        self.size += 1

    def poll_first(self):
        """Removes and returns the first (head) value in the deque."""
        if self.head is None:
            raise Exception("Deque is empty")
        old_head_val = self.head.val
        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None
        self.size -= 1
        return old_head_val

    def poll_last(self):
        """Removes and returns the last (tail) value in the deque."""
        if self.tail is None:
            raise Exception("Deque is empty")
        old_tail_val = self.tail.val
        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None
        self.size -= 1
        return old_tail_val

    def peek_first(self):
        """Returns the first (head) value of the deque WITHOUT removing."""
        return self.head.val if self.head is not None else None

    def peek_last(self):
        """Returns the last (tail) value of the deque WITHOUT removing."""
        return self.tail.val if self.tail is not None else None

    def get_size(self):
        """Returns the size of the deque."""
        return self.size

    def is_empty(self):
        """Returns whether or not the deque is empty."""
        return self.size == 0

    def __str__(self):
        """Returns a stringified deque in a pretty form."""
        deque_string = "Head -> "
        curr_node = self.head
        while curr_node is not None:
            deque_string += str(curr_node.val)
            if curr_node.next is not None:
                deque_string += " <-> "
            curr_node = curr_node.next
        deque_string += " <- Tail"
        return deque_string


def main():
    deque = Deque()
    print("Enter commands (add_first <value>, add_last <value>, poll_first, poll_last, peek_first, peek_last, size, is_empty, print, exit):")

    while True:
        command = input().strip()
        if command.lower() == "exit":
            break

        try:
            parts = command.split()
            if parts[0] == "add_first":
                add_first_value = int(parts[1])
                deque.add_first(add_first_value)
                print(f"Added to front: {add_first_value}")

            elif parts[0] == "add_last":
                add_last_value = int(parts[1])
                deque.add_last(add_last_value)
                print(f"Added to rear: {add_last_value}")

            elif parts[0] == "poll_first":
                print(f"Removed from front: {deque.poll_first()}")

            elif parts[0] == "poll_last":
                print(f"Removed from rear: {deque.poll_last()}")

            elif parts[0] == "peek_first":
                print(f"Front element: {deque.peek_first()}")

            elif parts[0] == "peek_last":
                print(f"Rear element: {deque.peek_last()}")

            elif parts[0] == "size":
                print(f"Size: {deque.get_size()}")

            elif parts[0] == "is_empty":
                print(f"Is empty: {deque.is_empty()}")

            elif parts[0] == "print":
                print(deque)

            else:
                print(f"Unknown command: {parts[0]}")
        except Exception as e:
            print(f"Error: {e}")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
