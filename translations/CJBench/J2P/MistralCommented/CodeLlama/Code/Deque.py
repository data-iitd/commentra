
class MainNode:
    def __init__(self, val):
        self.val = val
        self.next = None
        self.prev = None

    def get_value(self):
        return self.val

    def set_next(self, next_node):
        self.next = next_node

    def set_prev(self, prev_node):
        self.prev = prev_node


class Main:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def add_first(self, val):
        new_node = MainNode(val)

        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
        self.size += 1

    def add_last(self, val):
        new_node = MainNode(val)

        if self.tail is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
        self.size += 1

    def poll_first(self):
        if self.head is None:
            raise NoSuchElementException("Main is empty")

        old_head_val = self.head.get_value()

        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None
        self.size -= 1

        return old_head_val

    def poll_last(self):
        if self.tail is None:
            raise NoSuchElementException("Main is empty")

        old_tail_val = self.tail.get_value()

        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None
        self.size -= 1

        return old_tail_val

    def peek_first(self):
        return self.head.get_value() if self.head is not None else None

    def peek_last(self):
        return self.tail.get_value() if self.tail is not None else None

    def size(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def __str__(self):
        deque_string = "Head -> "
        curr_node = self.head
        while curr_node is not None:
            deque_string += str(curr_node.get_value())
            if curr_node.next is not None:
                deque_string += " <-> "
            curr_node = curr_node.next
        deque_string += " <- Tail"
        return deque_string


if __name__ == "__main__":
    deque = Main()

    while True:
        command = input().strip()
        if command == "exit":
            break
        try:
            parts = command.split(" ")
            if parts[0] == "addFirst":
                deque.add_first(int(parts[1]))
                print("Added to front:", parts[1])
            elif parts[0] == "addLast":
                deque.add_last(int(parts[1]))
                print("Added to rear:", parts[1])
            elif parts[0] == "pollFirst":
                print("Removed from front:", deque.poll_first())
            elif parts[0] == "pollLast":
                print("Removed from rear:", deque.poll_last())
            elif parts[0] == "peekFirst":
                print("Front element:", deque.peek_first())
            elif parts[0] == "peekLast":
                print("Rear element:", deque.peek_last())
            elif parts[0] == "size":
                print("Size:", deque.size())
            elif parts[0] == "isEmpty":
                print("Is empty:", deque.is_empty())
            elif parts[0] == "print":
                print(deque)
            else:
                print("Unknown command:", parts[0])
        except Exception as e:
            print("Error:", e)

    print("