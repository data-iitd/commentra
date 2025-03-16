
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
        if self.tail is None:
            raise NoSuchElementException("Main is empty")

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
        return self.head.val if self.head is not None else None

    def peek_last(self):
        return self.tail.val if self.tail is not None else None

    def size(self):
        return self.size

    def is_empty(self):
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
    scanner = Scanner(System.in)
    deque = Main()
    print("Enter commands (addFirst <value>, addLast <value>, pollFirst, pollLast, peekFirst, peekLast, size, isEmpty, print, exit):")

    while scanner.hasNextLine():
        command = scanner.nextLine().strip()
        if command.equalsIgnoreCase("exit"):
            break

        try:
            parts = command.split(" ")
            match parts[0]:
                case "addFirst":
                    add_first_value = int(parts[1])
                    deque.add_first(add_first_value)
                    print(f"Added to front: {add_first_value}")
                    break

                case "addLast":
                    add_last_value = int(parts[1])
                    deque.add_last(add_last_value)
                    print(f"Added to rear: {add_last_value}")
                    break

                case "pollFirst":
                    print(f"Removed from front: {deque.poll_first()}")
                    break

                case "pollLast":
                    print(f"Removed from rear: {deque.poll_last()}")
                    break

                case "peekFirst":
                    print(f"Front element: {deque.peek_first()}")
                    break

                case "peekLast":
                    print(f"Rear element: {deque.peek_last()}")
                    break

                case "size":
                    print(f"Size: {deque.size()}")
                    break

                case "isEmpty":
                    print(f"Is empty: {deque.is_empty()}")
                    break

                case "print":
                    print(deque)
                    break

                default:
                    print(f"Unknown command: {parts[0]}")
        except Exception as e:
            print(f"Error: {e.getMessage()}")

    scanner.close()

