class Node:
    def __init__(self, element, next_index):
        self.element = element  # The value stored in the node
        self.next = next_index  # Index of the next node in the list


class Main:
    CURSOR_SPACE_SIZE = 100  # Size of the cursor space

    def __init__(self):
        self.cursor_space = [Node(None, i + 1) for i in range(self.CURSOR_SPACE_SIZE)]
        self.cursor_space[self.CURSOR_SPACE_SIZE - 1].next = 0  # Last node points to the first
        self.os = 0  # Index of the first free node in the cursor space
        self.head = -1  # Indicates the list is empty
        self.count = 0  # Number of elements in the linked list

    def print_list(self):
        if self.head != -1:  # Check if the list is not empty
            start = self.head  # Start from the head
            while start != -1:  # Traverse until the end of the list
                element = self.cursor_space[start].element  # Get the element
                print(f"{element} -> ", end="")  # Print the element
                start = self.cursor_space[start].next  # Move to the next node
        print("null")  # Indicate the end of the list

    def index_of(self, element):
        if element is None:
            raise ValueError("Element cannot be null")  # Check for null
        current = self.head  # Start from the head
        index = 0  # Initialize index
        while current != -1:  # Traverse the list
            if self.cursor_space[current].element == element:  # Check for equality
                return index  # Return the index if found
            current = self.cursor_space[current].next  # Move to the next node
            index += 1  # Increment index
        return -1  # Return -1 if not found

    def get(self, position):
        if 0 <= position < self.count:  # Check if position is valid
            start = self.head  # Start from the head
            counter = 0  # Initialize counter
            while start != -1:  # Traverse the list
                if counter == position:  # Check if counter matches position
                    return self.cursor_space[start].element  # Return the element
                start = self.cursor_space[start].next  # Move to the next node
                counter += 1  # Increment counter
        return None  # Return None if position is invalid

    def remove_by_index(self, index):
        if 0 <= index < self.count:  # Check if index is valid
            element = self.get(index)  # Get the element at the index
            self.remove(element)  # Remove the element

    def remove(self, element):
        if element is None:
            raise ValueError("Element cannot be null")  # Ensure element is not null
        if self.head == -1:
            return  # Return if the list is empty
        if self.cursor_space[self.head].element == element:  # Check if head is the element
            self.free(self.head)  # Free the head node
            self.head = self.cursor_space[self.head].next  # Update head to the next node
        else:
            prev = self.head  # Previous node
            current = self.cursor_space[prev].next  # Current node
            while current != -1:  # Traverse the list
                if self.cursor_space[current].element == element:  # Check for equality
                    self.cursor_space[prev].next = self.cursor_space[current].next  # Bypass the current node
                    self.free(current)  # Free the current node
                    break  # Exit the loop
                prev = current  # Move previous to current
                current = self.cursor_space[prev].next  # Move to the next node
        self.count -= 1  # Decrement the count of elements

    def alloc(self):
        available_node_index = self.cursor_space[self.os].next  # Get the next available node
        if available_node_index == 0:
            raise MemoryError("Out of memory")  # Throw error if no space is available
        self.cursor_space[self.os].next = self.cursor_space[available_node_index].next  # Update the free list
        self.cursor_space[available_node_index].next = -1  # Mark the node as used
        return available_node_index  # Return the index of the allocated node

    def free(self, index):
        self.cursor_space[index].element = None  # Clear the element
        self.cursor_space[index].next = self.cursor_space[self.os].next  # Link it back to the free list
        self.cursor_space[self.os].next = index  # Update the free list head

    def append(self, element):
        if element is None:
            raise ValueError("Element cannot be null")  # Ensure element is not null
        available_index = self.alloc()  # Allocate a new node
        self.cursor_space[available_index].element = element  # Set the element
        if self.head == -1:  # If the list is empty
            self.head = available_index  # Set head to the new node
        else:
            iterator = self.head  # Start from the head
            while self.cursor_space[iterator].next != -1:  # Traverse to the end
                iterator = self.cursor_space[iterator].next  # Move to the next node
            self.cursor_space[iterator].next = available_index  # Link the new node at the end
        self.count += 1  # Increment the count of elements


if __name__ == "__main__":
    list = Main()  # Create a new linked list
    while True:  # Loop until there is no more input
        command = input().strip()  # Read and trim the command
        if command == "":
            continue  # Skip empty commands
        if command.lower() == "exit":
            break  # Exit the loop on "exit" command
        try:
            parts = command.split(" ")  # Split command into parts
            if parts[0] == "append":
                if len(parts) < 2:
                    print("Error: Missing value for append")  # Error for missing value
                    continue
                list.append(parts[1])  # Append the value to the list
                print(f"Appended: {parts[1]}")  # Confirmation message
            elif parts[0] == "get":
                if len(parts) < 2:
                    print("Error: Missing index for get")  # Error for missing index
                    continue
                index = int(parts[1])  # Parse the index
                value = list.get(index)  # Get the value at the index
                print(f"Value at index {index}: {value}")  # Display the value
            elif parts[0] == "removeByIndex":
                if len(parts) < 2:
                    print("Error: Missing index for removeByIndex")  # Error for missing index
                    continue
                remove_index = int(parts[1])  # Parse the index
                list.remove_by_index(remove_index)  # Remove the value at the index
                print(f"Removed value at index {remove_index}")  # Confirmation message
            elif parts[0] == "indexOf":
                if len(parts) < 2:
                    print("Error: Missing value for indexOf")  # Error for missing value
                    continue
                idx = list.index_of(parts[1])  # Find the index of the value
                print(f"Index of {parts[1]}: {idx}")  # Display the index
            elif parts[0] == "print":
                list.print_list()  # Print the linked list
            else:
                print(f"Unknown command: {parts[0]}")  # Error for unknown command
        except Exception as e:
            print(f"Error: {e}")  # Display any errors
# <END-OF-CODE>
