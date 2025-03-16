
# Class definition for the Main class
class Main:
    # Node class inner definition
    class Node:
        def __init__(self, value):
            self.value = value
            self.next = None

    # Instance variables for head and tail nodes
    head = None
    tail = None

    # Constructor for Main class
    def __init__(self):
        # Initialize head and tail to null
        self.head = None
        self.tail = None

    # Method to insert a new node with given value
    def insert(self, value):
        newNode = self.Node(value) # Create a new node with the given value

        # Base case: If the list is empty
        if self.head == None:
            self.head = newNode # Make the new node as the head
            self.tail = newNode # Make the new node as the tail
        else:
            # If the new value is less than the head value
            if value < self.head.value:
                newNode.next = self.head # Make the new node's next as the head
                self.head = newNode # Make the new node as the new head
            elif value > self.tail.value: # If the new value is greater than the tail value
                self.tail.next = newNode # Make the new node's next as the tail's next
                self.tail = newNode # Make the new node as the new tail
            else: # If the new value is between two nodes
                temp = self.head # Initialize a temporary node to traverse the list
                while temp.next!= None and temp.next.value < value:
                    temp = temp.next # Move to the next node
                newNode.next = temp.next # Make the new node's next as the next node of the current node
                temp.next = newNode # Make the current node's next as the new node
                if newNode.next == None: # If the new node is the last node
                    self.tail = newNode # Make the new node as the new tail

    # Method to delete a node with the given value
    def delete(self, value):
        # Base case: If the list is empty
        if self.head == None:
            return False

        # If the head node itself holds the given value
        if self.head.value == value:
            if self.head.next == None: # If the list has only one node
                self.head = None
                self.tail = None
            else: # If the list has more than one node
                self.head = self.head.next
            return True

        temp = self.head # Initialize a temporary node to traverse the list
        while temp.next!= None:
            if temp.next.value == value: # If the next node holds the given value
                if temp.next == self.tail: # If the deleted node is the last node
                    self.tail = temp # Make the previous node as the new tail
                temp.next = temp.next.next # Make the current node's next as the next node of the deleted node
                return True
            temp = temp.next # Move to the next node
        return False # If the given value is not present in the list

    # Method to search for a node with the given value
    def search(self, value):
        temp = self.head # Initialize a temporary node to traverse the list
        while temp!= None:
            if temp.value == value: # If the current node holds the given value
                return True
            temp = temp.next # Move to the next node
        return False # If the given value is not present in the list

    # Method to check if the list is empty
    def isEmpty(self):
        return self.head == None

    # Overridden toString method to print the list
    def __str__(self):
        if self.head!= None:
            sb = "["
            temp = self.head
            while temp!= None:
                sb += str(temp.value)
                if temp.next!= None:
                    sb += ", "
                temp = temp.next
            sb += "]"
            return sb
        else:
            return "[]"

# Main method to take user input and perform operations
if __name__ == "__main__":
    list = Main() # Create an instance of the Main class
    scanner = Scanner(System.in) # Initialize a Scanner object to read user input

    while scanner.hasNextLine():
        command = scanner.nextLine().trim() # Read the user command

        if command.isEmpty(): # If the command is empty
            continue # Skip the current iteration

        if command.equalsIgnoreCase("exit"): # If the command is "exit"
            break # Exit the while loop

        try:
            parts = command.split(" ") # Split the command into parts
            operation = parts[0] # Get the operation name

            if operation == "insert": # If the operation is "insert"
                if len(parts) < 2: # If the command is missing the value
                    print("Error: Missing value for insert")
                    break
                insertValue = int(parts[1]) # Get the value to be inserted
                list.insert(insertValue) # Insert the new node
                print("Inserted: " + insertValue) # Print the message
            elif operation == "delete": # If the operation is "delete"
                if len(parts) < 2: # If the command is missing the value
                    print("Error: Missing value for delete")
                    break
                deleteValue = int(parts[1]) # Get the value to be deleted
                deleted = list.delete(deleteValue) # Delete the node
                print(deleted? "Deleted: " + deleteValue : "Value not found: " + deleteValue) # Print the message
            elif operation == "search": # If the operation is "search"
                if len(parts) < 2: # If the command is missing the value
                    print("Error: Missing value for search")
                    break
                searchValue = int(parts[1]) # Get the value to be searched
                found = list.search(searchValue) # Search for the node
                print(found? "Found: " + searchValue : "Not found: " + searchValue) # Print the message
            elif operation == "isEmpty": # If the operation is "isEmpty"
                print("Is empty: " + list.isEmpty()) # Print the message
            elif operation == "print": # If the operation is "print"
                print("List: " + list) # Print the list
            else: # If the operation is not recognized
                print("Error: Unknown operation")
        except Exception as e: # If there is an exception
            print("Error: " + e.getMessage()) # Print the error message

    scanner.close() # Close the Scanner object

