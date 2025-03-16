class Node:
    def __init__(self, key):
        self.key = key  # The value of the node
        self.prev = None  # Pointer to the previous node
        self.next = None  # Pointer to the next node

    def r_print(self, buf):
        buf.append(str(self.key))  # Append the current node's key to the buffer
        if self.next is not None:
            buf.append(" ")  # Add a space if there is a next node
            self.next.r_print(buf)  # Recursively print the next node


    def delete(self, first, last):
        if self.prev is not None and self.next is not None:
            # Node is in the middle; update pointers of adjacent nodes
            self.prev.next = self.next
            self.next.prev = self.prev
            return first, last  # Return unchanged first and last pointers

        if self.next is None and self.prev is None:
            # Node is the only node in the list
            return None, None  # Return None for both first and last

        if self.prev is None:
            # Node is the first node
            first = self.next  # Update first to the next node
            self.next.prev = None  # Set the previous pointer of the new first node to None

        if self.next is None:
            # Node is the last node
            last = self.prev  # Update last to the previous node
            self.prev.next = None  # Set the next pointer of the new last node to None

        return first, last  # Return updated first and last pointers


def main():
    import sys
    input = sys.stdin.read
    data = input().strip().splitlines()  # Read all input at once and split into lines

    first = None  # Initialize pointers for the first and last nodes of the list
    last = None

    # Loop to process each command from the input
    for cmd in data[1:]:  # Skip the first line of input
        if cmd == "deleteFirst":
            if first is not None:
                first, last = first.delete(first, last)
        elif cmd == "deleteLast":
            if last is not None:
                first, last = last.delete(first, last)
        else:
            xcmd = cmd.split()  # Split the command into parts
            k = int(xcmd[1])  # Convert the second part to an integer
            k32 = k  # In Python, int can be used directly

            if xcmd[0] == "delete":
                # Command to delete a node with a specific key
                a = first
                while a is not None:
                    if a.key == k32:
                        first, last = a.delete(first, last)  # Delete the node and update first and last
                        break
                    a = a.next
            elif xcmd[0] == "insert":
                # Command to insert a new node at the beginning of the list
                n = Node(k32)  # Initialize a new node
                n.next = first  # Set the new node's next pointer to the current first node
                if first is not None:
                    first.prev = n  # Update the previous pointer of the current first node

                first = n  # Update first to the new node
                if last is None:
                    last = n  # If the list was empty, set last to the new node

    buf = []
    if first is not None:
        first.r_print(buf)  # Print the keys of the linked list starting from the first node
    print(''.join(buf))  # Output the result


if __name__ == "__main__":
    main()

# <END-OF-CODE>
