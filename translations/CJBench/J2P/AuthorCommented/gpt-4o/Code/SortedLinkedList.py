class Node:
    """Node represents an element in the sorted linked list."""
    def __init__(self, value):
        self.value = value
        self.next = None


class SortedLinkedList:
    """
    The SortedLinkedList class represents a singly linked list that maintains its elements in sorted order.
    Elements are ordered based on their natural ordering, with smaller elements at the head and larger elements toward the tail.
    The class provides methods for inserting, deleting, and searching elements, as well as checking if the list is empty.
    """

    def __init__(self):
        """Initializes an empty sorted linked list."""
        self.head = None
        self.tail = None

    def insert(self, value):
        """Inserts a new integer into the list, maintaining sorted order."""
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        elif value < self.head.value:
            new_node.next = self.head
            self.head = new_node
        elif value > self.tail.value:
            self.tail.next = new_node
            self.tail = new_node
        else:
            temp = self.head
            while temp.next is not None and temp.next.value < value:
                temp = temp.next
            new_node.next = temp.next
            temp.next = new_node
            if new_node.next is None:
                self.tail = new_node

    def delete(self, value):
        """Deletes the first occurrence of a specified integer in the list."""
        if self.head is None:
            return False
        elif self.head.value == value:
            if self.head.next is None:
                self.head = None
                self.tail = None
            else:
                self.head = self.head.next
            return True
        else:
            temp = self.head
            while temp.next is not None:
                if temp.next.value == value:
                    if temp.next == self.tail:
                        self.tail = temp
                    temp.next = temp.next.next
                    return True
                temp = temp.next
            return False

    def search(self, value):
        """Searches for a specified integer in the list."""
        temp = self.head
        while temp is not None:
            if temp.value == value:
                return True
            temp = temp.next
        return False

    def is_empty(self):
        """Checks if the list is empty."""
        return self.head is None

    def __str__(self):
        """Returns a string representation of the sorted linked list."""
        if self.head is not None:
            elements = []
            temp = self.head
            while temp is not None:
                elements.append(temp.value)
                temp = temp.next
            return "[" + ", ".join(map(str, elements)) + "]"
        else:
            return "[]"


def main():
    """Main function to interact with the sorted linked list."""
    linked_list = SortedLinkedList()
    print("Enter commands (insert <value>, delete <value>, search <value>, isEmpty, print, exit):")
    
    while True:
        command = input().strip()
        if command == "":
            continue
        if command.lower() == "exit":
            break

        try:
            parts = command.split()
            if parts[0] == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert")
                    continue
                insert_value = int(parts[1])
                linked_list.insert(insert_value)
                print(f"Inserted: {insert_value}")

            elif parts[0] == "delete":
                if len(parts) < 2:
                    print("Error: Missing value for delete")
                    continue
                delete_value = int(parts[1])
                deleted = linked_list.delete(delete_value)
                print(f"Deleted: {delete_value}" if deleted else f"Value not found: {delete_value}")

            elif parts[0] == "search":
                if len(parts) < 2:
                    print("Error: Missing value for search")
                    continue
                search_value = int(parts[1])
                found = linked_list.search(search_value)
                print(f"Found: {search_value}" if found else f"Not found: {search_value}")

            elif parts[0] == "isEmpty":
                print("Is empty:", linked_list.is_empty())

            elif parts[0] == "print":
                print("List:", linked_list)

            else:
                print("Unknown command:", parts[0])
        except Exception as e:
            print("Error:", e)


if __name__ == "__main__":
    main()

# <END-OF-CODE>
