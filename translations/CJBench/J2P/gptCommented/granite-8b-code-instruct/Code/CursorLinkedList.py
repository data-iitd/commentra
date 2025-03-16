
class Main:
    def __init__(self):
        self.os = 0  # Index of the first free node in the cursor space
        self.head = -1  # Index of the first node in the linked list
        self.cursorSpace = [None] * 100  # Array to hold the nodes
        self.count = 0  # Number of elements in the linked list
        self.CURSOR_SPACE_SIZE = 100  # Size of the cursor space

    # Method to print the elements of the linked list
    def printList(self):
        if self.head!= -1:  # Check if the list is not empty
            start = self.head  # Start from the head
            while start!= -1:  # Traverse until the end of the list
                element = self.cursorSpace[start].element  # Get the element
                print(element, end=" -> ")  # Print the element
                start = self.cursorSpace[start].next  # Move to the next node
        print("null")  # Indicate the end of the list

    # Method to find the index of a specific element in the list
    def indexOf(self, element):
        if element is None:
            raise Exception("Element cannot be null")  # Check for null
        current = self.head  # Start from the head
        index = 0  # Initialize index
        while current!= -1:  # Traverse the list
            if self.cursorSpace[current].element == element:  # Check for equality
                return index  # Return the index if found
            current = self.cursorSpace[current].next  # Move to the next node
            index += 1  # Increment index
        return -1  # Return -1 if not found

    # Method to get the element at a specific position
    def get(self, position):
        if position >= 0 and position < self.count:  # Check if position is valid
            start = self.head  # Start from the head
            counter = 0  # Initialize counter
            while start!= -1:  # Traverse the list
                if counter == position:  # Check if counter matches position
                    return self.cursorSpace[start].element  # Return the element
                start = self.cursorSpace[start].next  # Move to the next node
                counter += 1  # Increment counter
        return None  # Return null if position is invalid

    # Method to remove an element by its index
    def removeByIndex(self, index):
        if index >= 0 and index < self.count:  # Check if index is valid
            element = self.get(index)  # Get the element at the index
            self.remove(element)  # Remove the element

    # Method to remove a specific element from the list
    def remove(self, element):
        if element is None:
            raise Exception("Element cannot be null")  # Ensure element is not null
        if self.head == -1:
            return  # Return if the list is empty
        if self.cursorSpace[self.head].element == element:  # Check if head is the element
            self.free(self.head)  # Free the head node
            self.head = self.cursorSpace[self.head].next  # Update head to the next node
        else:
            prev = self.head  # Previous node
            current = self.cursorSpace[prev].next  # Current node
            while current!= -1:  # Traverse the list
                if self.cursorSpace[current].element == element:  # Check for equality
                    self.cursorSpace[prev].next = self.cursorSpace[current].next  # Bypass the current node
                    self.free(current)  # Free the current node
                    break  # Exit the loop
                prev = current  # Move previous to current
                current = self.cursorSpace[prev].next  # Move to the next node
        self.count -= 1  # Decrement the count of elements

    # Method to allocate a new node from the cursor space
    def alloc(self):
        availableNodeIndex = self.cursorSpace[self.os].next  # Get the next available node
        if availableNodeIndex == 0:
            raise Exception("Out of memory")  # Throw error if no space is available
        self.cursorSpace[self.os].next = self.cursorSpace[availableNodeIndex].next  # Update the free list
        self.cursorSpace[availableNodeIndex].next = -1  # Mark the node as used
        return availableNodeIndex  # Return the index of the allocated node

    # Method to free a node and return it to the cursor space
    def free(self, index):
        self.cursorSpace[index].element = None  # Clear the element
        self.cursorSpace[index].next = self.cursorSpace[self.os].next  # Link it back to the free list
        self.cursorSpace[self.os].next = index  # Update the free list head

    # Method to append an element to the end of the list
    def append(self, element):
        if element is None:
            raise Exception("Element cannot be null")  # Ensure element is not null
        availableIndex = self.alloc()  # Allocate a new node
        self.cursorSpace[availableIndex].element = element  # Set the element
        if self.head == -1:  # If the list is empty
            self.head = availableIndex  # Set head to the new node
        else:
            iterator = self.head  # Start from the head
            while self.cursorSpace[iterator].next!= -1:  # Traverse to the end
                iterator = self.cursorSpace[iterator].next  # Move to the next node
            self.cursorSpace[iterator].next = availableIndex  # Link the new node at the end
        self.count += 1  # Increment the count of elements

# Main method to interact with the user and execute commands
if __name__ == "__main__":
    list = Main()  # Create a new linked list
    while True:  # Loop until there is no more input
        command = input().strip()  # Read and trim the command
        if command == "exit":
            break  # Exit the loop on "exit" command
        try:
            parts = command.split(" ")  # Split command into parts
            if len(parts) < 1:
                raise Exception("Invalid command")  # Error for invalid command
            if parts[0] == "append":
                if len(parts) < 2:
                    raise Exception("Missing value for append")  # Error for missing value
                list.append(parts[1])  # Append the value to the list
                print("Appended:", parts[1])  # Confirmation message
            elif parts[0] == "get":
                if len(parts) < 2:
                    raise Exception("Missing index for get")  # Error for missing index
                index = int(parts[1])  # Parse the index
                value = list.get(index)  # Get the value at the index
                print("Value at index", index, ":", value)  # Display the value
            elif parts[0] == "removeByIndex":
                if len(parts) < 2:
                    raise Exception("Missing index for removeByIndex")  # Error for missing index
                index = int(parts[1])  # Parse the index
                list.removeByIndex(index)  # Remove the value at the index
                print("Removed value at index", index)  # Confirmation message
            elif parts[0] == "indexOf":
                if len(parts) < 2:
                    raise Exception("Missing value for indexOf")  # Error for missing value
                idx = list.indexOf(parts[1])  # Find the index of the value
                print("Index of", parts[1], ":", idx)  # Display the index
            elif parts[0] == "print":
                list.printList()  # Print the linked list
            else:
                raise Exception("Unknown command")  # Error for unknown command
        except Exception as e:
            print("Error:", e)  # Display any errors

