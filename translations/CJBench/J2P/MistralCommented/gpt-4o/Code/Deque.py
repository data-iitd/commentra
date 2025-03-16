class Node:
    def __init__(self, val):
        self.val = val  # Value of the node
        self.next = None  # Reference to the next node
        self.prev = None  # Reference to the previous node

    def get_value(self):
        return self.val  # Getter for the value of the node


class DoublyLinkedList:
    def __init__(self):
        self.head = None  # Head reference for the doubly linked list
        self.tail = None  # Tail reference for the doubly linked list
        self.size = 0  # Size of the doubly linked list

    def add_first(self, val):
        new_node = Node(val)  # Create a new node with the given value

        if self.is_empty():  # If the doubly linked list is empty
            self.head = new_node  # Set head and tail to the new node
            self.tail = new_node
        else:  # If the doubly linked list is not empty
            new_node.next = self.head  # Set the next reference of the new node to the current head
            self.head.prev = new_node  # Set the prev reference of the current head to the new node
            self.head = new_node  # Set head to the new node
        self.size += 1  # Increment the size of the doubly linked list

    def add_last(self, val):
        new_node = Node(val)  # Create a new node with the given value

        if self.tail is None:  # If the doubly linked list is empty
            self.head = new_node
            self.tail = new_node
        else:  # If the doubly linked list is not empty
            new_node.prev = self.tail  # Set the prev reference of the new node to the current tail
            self.tail.next = new_node  # Set the next reference of the current tail to the new node
            self.tail = new_node  # Set tail to the new node
        self.size += 1  # Increment the size of the doubly linked list

    def poll_first(self):
        if self.head is None:  # If the doubly linked list is empty
            raise Exception("Doubly linked list is empty")

        old_head_val = self.head.get_value()  # Get the value of the current head node

        if self.head == self.tail:  # If the doubly linked list has only one node
            self.head = None
            self.tail = None
        else:  # If the doubly linked list has more than one node
            self.head = self.head.next  # Set head to the next node
            self.head.prev = None  # Set the prev reference of the new head to None
        self.size -= 1  # Decrement the size of the doubly linked list

        return old_head_val  # Return the value of the removed node

    def poll_last(self):
        if self.tail is None:  # If the doubly linked list is empty
            raise Exception("Doubly linked list is empty")

        old_tail_val = self.tail.get_value()  # Get the value of the current tail node

        if self.head == self.tail:  # If the doubly linked list has only one node
            self.head = None
            self.tail = None
        else:  # If the doubly linked list has more than one node
            self.tail = self.tail.prev  # Set tail to the previous node
            self.tail.next = None  # Set the next reference of the new tail to None
        self.size -= 1  # Decrement the size of the doubly linked list

        return old_tail_val  # Return the value of the removed node

    def peek_first(self):
        return self.head.get_value() if self.head is not None else None  # Return the value of the current head node if it exists, otherwise return None

    def peek_last(self):
        return self.tail.get_value() if self.tail is not None else None  # Return the value of the current tail node if it exists, otherwise return None

    def get_size(self):
        return self.size  # Return the size of the doubly linked list

    def is_empty(self):
        return self.size == 0  # Check if the doubly linked list is empty

    def __str__(self):
        deque_string = "Head -> "
        curr_node = self.head
        while curr_node is not None:
            deque_string += str(curr_node.get_value())
            if curr_node.next is not None:
                deque_string += " <-> "
            curr_node = curr_node.next
        deque_string += " <- Tail"
        return deque_string  # Override the toString method to print the doubly linked list in a readable format


def main():
    import sys

    deque = DoublyLinkedList()  # Create an instance of the DoublyLinkedList class for integers

    for line in sys.stdin:
        command = line.strip()
        if command.lower() == "exit":
            break
        try:
            parts = command.split(" ")
            if parts[0] == "addFirst":
                add_first_value = int(parts[1])
                deque.add_first(add_first_value)  # Add a new node to the front of the doubly linked list
                print(f"Added to front: {add_first_value}")
            elif parts[0] == "addLast":
                add_last_value = int(parts[1])
                deque.add_last(add_last_value)  # Add a new node to the end of the doubly linked list
                print(f"Added to rear: {add_last_value}")
            elif parts[0] == "pollFirst":
                print(f"Removed from front: {deque.poll_first()}")  # Remove and print the node at the front of the doubly linked list
            elif parts[0] == "pollLast":
                print(f"Removed from rear: {deque.poll_last()}")  # Remove and print the node at the end of the doubly linked list
            elif parts[0] == "peekFirst":
                print(f"Front element: {deque.peek_first()}")  # Print the value of the node at the front of the doubly linked list without removing it
            elif parts[0] == "peekLast":
                print(f"Rear element: {deque.peek_last()}")  # Print the value of the node at the end of the doubly linked list without removing it
            elif parts[0] == "size":
                print(f"Size: {deque.get_size()}")  # Print the size of the doubly linked list
            elif parts[0] == "isEmpty":
                print(f"Is empty: {deque.is_empty()}")  # Print whether the doubly linked list is empty or not
            elif parts[0] == "print":
                print(deque)  # Print the doubly linked list in a readable format
            else:
                print(f"Unknown command: {parts[0]}")  # Print an error message for unknown commands
        except Exception as e:
            print(f"Error: {e}")  # Print an error message for any exceptions thrown


if __name__ == "__main__":
    main()

# <END-OF-CODE>
