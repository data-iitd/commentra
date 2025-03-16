class Node:
    """Node class representing each element in the linked list."""
    def __init__(self, data):
        self.data = data  # Data stored in the node
        self.next = None  # Initially, the next node is null


class LinkedList:
    """Linked list class to manage nodes."""
    def __init__(self):
        self.head = None  # Head of the linked list

    def add_node(self, data):
        """Add a new node with the specified data to the end of the list."""
        new_node = Node(data)  # Create a new node
        if self.head is None:  # If the list is empty
            self.head = new_node  # Set the new node as the head
        else:
            temp = self.head  # Start from the head
            # Traverse to the end of the list
            while temp.next is not None:
                temp = temp.next
            temp.next = new_node  # Link the new node at the end

    def print_list(self):
        """Print the linked list up to 20 nodes or indicate a loop."""
        temp = self.head  # Start from the head
        count = 0  # Counter to limit the number of printed nodes
        # Traverse the list and print each node's data
        while temp is not None and count < 20:
            print(f"{temp.data} -> ", end="")
            temp = temp.next  # Move to the next node
            count += 1
        # Check if there are more nodes after the first 20
        if temp is not None:
            print("... (loop detected)", end="")  # Indicate loop if exists
        else:
            print("null", end="")  # Indicate end of the list
        print()  # New line after printing the list

    def create_loop(self, position1, position2):
        """Create a loop in the linked list between two specified positions."""
        if position1 == 0 or position2 == 0:
            return  # Return if either position is invalid
        node1 = self.head  # Pointer to find the first node for the loop
        node2 = self.head  # Pointer to find the second node for the loop
        count1 = 1  # Counter for the first position
        count2 = 1  # Counter for the second position

        # Traverse to the first position
        while count1 < position1 and node1 is not None:
            node1 = node1.next
            count1 += 1
        # Traverse to the second position
        while count2 < position2 and node2 is not None:
            node2 = node2.next
            count2 += 1
        # Create a loop by linking the second node to the first node
        if node1 is not None and node2 is not None:
            node2.next = node1  # Create the loop

    def detect_loop(self):
        """Detect if there is a loop in the linked list using Floyd's cycle-finding algorithm."""
        sptr = self.head  # Slow pointer
        fptr = self.head  # Fast pointer
        # Traverse the list with two pointers
        while fptr is not None and fptr.next is not None:
            sptr = sptr.next  # Move slow pointer by one
            fptr = fptr.next.next  # Move fast pointer by two
            # If the two pointers meet, a loop is detected
            if sptr == fptr:
                return True  # Loop detected
        return False  # No loop detected


def main():
    linked_list = LinkedList()  # Create a linked list instance
    while True:
        command = input().strip()  # Read and trim the command
        if command == "":  # Skip empty commands
            continue
        if command.lower() == "exit":  # Exit command
            break
        try:
            parts = command.split(" ")  # Split command into parts
            if parts[0] == "add":  # Command to add a node
                if len(parts) < 2:
                    print("Error: Missing value for add")
                    continue
                value = int(parts[1])  # Parse the value to add
                linked_list.add_node(value)  # Add the node
                print(f"Added: {value}")  # Confirmation message
            elif parts[0] == "createLoop":  # Command to create a loop
                if len(parts) < 3:
                    print("Error: Missing positions for createLoop")
                    continue
                pos1 = int(parts[1])  # Parse the first position
                pos2 = int(parts[2])  # Parse the second position
                linked_list.create_loop(pos1, pos2)  # Create the loop
                print(f"Loop created between positions {pos1} and {pos2}")
            elif parts[0] == "detectLoop":  # Command to detect a loop
                print("Loop detected:", linked_list.detect_loop())  # Output result of loop detection
            elif parts[0] == "print":  # Command to print the list
                linked_list.print_list()  # Print the linked list
            else:  # Handle unknown commands
                print("Unknown command:", parts[0])
        except Exception as e:  # Handle exceptions
            print("Error:", str(e))


if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
