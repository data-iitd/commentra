class Node:
    """Node represents an individual element in the linked list, containing data and a reference to the next node."""
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    """Main provides utility methods for creating and detecting loops (cycles) in a singly linked list."""
    def __init__(self):
        self.head = None

    def add_node(self, data):
        """Adds a new node to the linked list."""
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            temp = self.head
            while temp.next is not None:
                temp = temp.next
            temp.next = new_node

    def print_list(self):
        """Prints the linked list up to a specified limit to avoid infinite loops."""
        temp = self.head
        count = 0  # Limit output to 20 nodes for safety
        while temp is not None and count < 20:
            print(f"{temp.data} -> ", end="")
            temp = temp.next
            count += 1
        if temp is not None:
            print("... (loop detected)")
        else:
            print("null")

    def create_loop(self, position1, position2):
        """Creates a loop in a linked list by connecting the next pointer of a node at a specified starting position to another node at a specified destination position."""
        if position1 == 0 or position2 == 0:
            return

        node1 = self.head
        node2 = self.head

        count1 = 1
        count2 = 1

        while count1 < position1 and node1 is not None:
            node1 = node1.next
            count1 += 1

        while count2 < position2 and node2 is not None:
            node2 = node2.next
            count2 += 1

        if node1 is not None and node2 is not None:
            node2.next = node1

    def detect_loop(self):
        """Detects the presence of a loop in the linked list using Floyd's cycle-finding algorithm."""
        sptr = self.head
        fptr = self.head

        while fptr is not None and fptr.next is not None:
            sptr = sptr.next
            fptr = fptr.next.next
            if sptr == fptr:
                return True
        return False


def main():
    linked_list = LinkedList()
    print("Enter commands (add <value>, createLoop <pos1> <pos2>, detectLoop, print, exit):")

    while True:
        command = input().strip()

        if command == "":
            continue

        if command.lower() == "exit":
            break

        try:
            parts = command.split()
            if parts[0] == "add":
                if len(parts) < 2:
                    print("Error: Missing value for add")
                    continue
                value = int(parts[1])
                linked_list.add_node(value)
                print(f"Added: {value}")

            elif parts[0] == "createLoop":
                if len(parts) < 3:
                    print("Error: Missing positions for createLoop")
                    continue
                pos1 = int(parts[1])
                pos2 = int(parts[2])
                linked_list.create_loop(pos1, pos2)
                print(f"Loop created between positions {pos1} and {pos2}")

            elif parts[0] == "detectLoop":
                print(f"Loop detected: {linked_list.detect_loop()}")

            elif parts[0] == "print":
                linked_list.print_list()

            else:
                print(f"Unknown command: {parts[0]}")
        except Exception as e:
            print(f"Error: {e}")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
