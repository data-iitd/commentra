class Node:
    def __init__(self, value):
        self.value = value  # Value of the node
        self.next = None  # Pointer to the next node


class LinkedList:
    def __init__(self):
        self.head = None  # Head pointer for the linked list
        self.tail = None  # Tail pointer for the linked list

    def insert(self, value):
        new_node = Node(value)  # Create a new node with the given value

        if self.head is None:  # If the list is empty
            self.head = new_node
            self.tail = new_node
        elif value < self.head.value:  # Insert at the beginning
            new_node.next = self.head
            self.head = new_node
        elif value > self.tail.value:  # Insert at the end
            self.tail.next = new_node
            self.tail = new_node
        else:  # Find the correct position to insert
            temp = self.head
            while temp.next is not None and temp.next.value < value:
                temp = temp.next
            new_node.next = temp.next
            temp.next = new_node
            if new_node.next is None:  # Update tail if inserted at the end
                self.tail = new_node

    def delete(self, value):
        if self.head is None:  # If the list is empty
            return False
        elif self.head.value == value:  # If the value to delete is at the head
            if self.head.next is None:  # If only one node
                self.head = None
                self.tail = None
            else:
                self.head = self.head.next
            return True
        else:
            temp = self.head
            while temp.next is not None:
                if temp.next.value == value:  # Found the value to delete
                    if temp.next == self.tail:  # Update tail if necessary
                        self.tail = temp
                    temp.next = temp.next.next  # Bypass the node
                    return True
                temp = temp.next
            return False  # Value not found

    def search(self, value):
        temp = self.head
        while temp is not None:  # Traverse the list to find the value
            if temp.value == value:
                return True  # Value found
            temp = temp.next
        return False  # Value not found

    def is_empty(self):
        return self.head is None  # Returns True if head is None

    def __str__(self):
        if self.head is not None:
            values = []
            temp = self.head
            while temp is not None:  # Traverse the list and collect values
                values.append(temp.value)
                temp = temp.next
            return "[" + ", ".join(map(str, values)) + "]"  # Return string representation
        else:
            return "[]"  # Return empty list representation


def main():
    linked_list = LinkedList()  # Create a new linked list

    while True:
        command = input().strip()  # Read the command
        if command == "":
            continue  # Skip empty commands
        if command.lower() == "exit":
            break  # Exit the loop on "exit" command
        try:
            parts = command.split(" ")  # Split command into parts
            if parts[0] == "insert":
                if len(parts) < 2:  # Check for missing value
                    print("Error: Missing value for insert")
                    continue
                insert_value = int(parts[1])  # Parse the value
                linked_list.insert(insert_value)  # Insert the value into the list
                print(f"Inserted: {insert_value}")
            elif parts[0] == "delete":
                if len(parts) < 2:  # Check for missing value
                    print("Error: Missing value for delete")
                    continue
                delete_value = int(parts[1])  # Parse the value
                deleted = linked_list.delete(delete_value)  # Attempt to delete the value
                print(f"Deleted: {delete_value}" if deleted else f"Value not found: {delete_value}")
            elif parts[0] == "search":
                if len(parts) < 2:  # Check for missing value
                    print("Error: Missing value for search")
                    continue
                search_value = int(parts[1])  # Parse the value
                found = linked_list.search(search_value)  # Search for the value
                print(f"Found: {search_value}" if found else f"Not found: {search_value}")
            elif parts[0] == "isEmpty":
                print("Is empty:", linked_list.is_empty())  # Check if the list is empty
            elif parts[0] == "print":
                print("List:", linked_list)  # Print the current state of the list
            else:
                print("Error: Unknown command")
        except Exception as e:
            print("Error:", e)

if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>
