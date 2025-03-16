class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class Main:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, value):
        new_node = Node(value)

        if self.head is None:  # If the list is empty
            self.head = new_node
            self.tail = new_node
        else:
            if value < self.head.value:  # If the new value is less than the head value
                new_node.next = self.head
                self.head = new_node
            elif value > self.tail.value:  # If the new value is greater than the tail value
                self.tail.next = new_node
                self.tail = new_node
            else:  # If the new value is between two nodes
                temp = self.head
                while temp.next is not None and temp.next.value < value:
                    temp = temp.next
                new_node.next = temp.next
                temp.next = new_node
                if new_node.next is None:  # If the new node is the last node
                    self.tail = new_node

    def delete(self, value):
        if self.head is None:  # If the list is empty
            return False

        if self.head.value == value:  # If the head node holds the given value
            if self.head.next is None:  # If the list has only one node
                self.head = None
                self.tail = None
            else:  # If the list has more than one node
                self.head = self.head.next
            return True

        temp = self.head
        while temp.next is not None:
            if temp.next.value == value:  # If the next node holds the given value
                if temp.next == self.tail:  # If the deleted node is the last node
                    self.tail = temp
                temp.next = temp.next.next  # Remove the node
                return True
            temp = temp.next
        return False  # If the given value is not present in the list

    def search(self, value):
        temp = self.head
        while temp is not None:
            if temp.value == value:  # If the current node holds the given value
                return True
            temp = temp.next
        return False  # If the given value is not present in the list

    def is_empty(self):
        return self.head is None

    def __str__(self):
        if self.head is not None:
            values = []
            temp = self.head
            while temp is not None:
                values.append(temp.value)
                temp = temp.next
            return "[" + ", ".join(map(str, values)) + "]"
        else:
            return "[]"


def main():
    list_instance = Main()  # Create an instance of the Main class

    while True:
        command = input().strip()  # Read the user command

        if command == "":  # If the command is empty
            continue  # Skip the current iteration

        if command.lower() == "exit":  # If the command is "exit"
            break  # Exit the while loop

        try:
            parts = command.split()  # Split the command into parts
            operation = parts[0]  # Get the operation name

            if operation == "insert":  # If the operation is "insert"
                if len(parts) < 2:  # If the command is missing the value
                    print("Error: Missing value for insert")
                    continue
                insert_value = int(parts[1])  # Get the value to be inserted
                list_instance.insert(insert_value)  # Insert the new node
                print(f"Inserted: {insert_value}")  # Print the message
            elif operation == "delete":  # If the operation is "delete"
                if len(parts) < 2:  # If the command is missing the value
                    print("Error: Missing value for delete")
                    continue
                delete_value = int(parts[1])  # Get the value to be deleted
                deleted = list_instance.delete(delete_value)  # Delete the node
                print("Deleted: " + str(delete_value) if deleted else "Value not found: " + str(delete_value))  # Print the message
            elif operation == "search":  # If the operation is "search"
                if len(parts) < 2:  # If the command is missing the value
                    print("Error: Missing value for search")
                    continue
                search_value = int(parts[1])  # Get the value to be searched
                found = list_instance.search(search_value)  # Search for the node
                print("Found: " + str(search_value) if found else "Not found: " + str(search_value))  # Print the message
            elif operation == "isEmpty":  # If the operation is "isEmpty"
                print("Is empty: " + str(list_instance.is_empty()))  # Print the message
            elif operation == "print":  # If the operation is "print"
                print("List: " + str(list_instance))  # Print the list
            else:  # If the operation is not recognized
                print("Error: Unrecognized operation")
        except Exception as e:  # If there is an exception
            print("Error: " + str(e))  # Print the error message


if __name__ == "__main__":
    main()

# <END-OF-CODE>
