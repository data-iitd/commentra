

class Main:
    # Declare a private nested class Node with generic type T
    class Node:
        # Declare an element of generic type T and an integer next
        def __init__(self, element, next):
            self.element = element
            self.next = next

    # Declare instance variables for the linked list: an integer operating system stack index (os),
    # an integer head index, an array of Node objects named cursorSpace, an integer count,
    # a constant integer CURSOR_SPACE_SIZE, and an integer overflow size
    os = 0
    head = -1
    cursorSpace = [Node(None, i + 1) for i in range(100)]
    for i in range(99):
        cursorSpace[i].next = i + 1
    cursorSpace[99].next = 0
    count = 0
    CURSOR_SPACE_SIZE = 100
    OVERFLOW_SIZE = CURSOR_SPACE_SIZE + 1

    # Method to print the elements in the linked list
    def printList(self):
        # Check if the head index is not equal to -1
        if self.head!= -1:
            # Initialize start index to head
            start = self.head
            # Use a while loop to iterate through the linked list and print each element
            while start!= -1:
                # Get the element at the current index
                element = self.cursorSpace[start].element
                # Print the element followed by " -> "
                print(element, end=" -> ")
                # Update the start index to the next index
                start = self.cursorSpace[start].next
        # Print "null" at the end of the list
        print("null")

    # Method to find the index of a given element in the linked list
    def indexOf(self, element):
        # Check if the given element is None
        if element is None:
            # Throw a TypeError with the message "Element cannot be None"
            raise TypeError("Element cannot be None")
        # Initialize current index to head and index to 0
        current = self.head
        index = 0
        # Use a while loop to iterate through the linked list and find the index of the given element
        while current!= -1:
            # Check if the element at the current index is equal to the given element
            if self.cursorSpace[current].element == element:
                # Return the index
                return index
            # Update the current index to the next index and increment the index
            current = self.cursorSpace[current].next
            index += 1
        # If the given element is not found in the list, return -1
        return -1

    # Method to get the element at a given position in the linked list
    def get(self, position):
        # Check if the position is valid (i.e., within the bounds of the list)
        if position >= 0 and position < self.count:
            # Initialize start index to head and counter to 0
            start = self.head
            counter = 0
            # Use a while loop to iterate through the linked list and find the element at the given position
            while start!= -1:
                # Check if the counter is equal to the given position
                if counter == position:
                    # Return the element at the current index
                    return self.cursorSpace[start].element
                # Update the start index to the next index and increment the counter
                start = self.cursorSpace[start].next
                counter += 1
        # If the position is invalid, return None
        return None

    # Method to remove an element by index from the linked list
    def removeByIndex(self, index):
        # Check if the index is valid (i.e., within the bounds of the list)
        if index >= 0 and index < self.count:
            # Get the element to be removed using the get method
            element = self.get(index)
            # Remove the element using the remove method with the given element as an argument
            self.remove(element)

    # Method to remove an element with a given value from the linked list
    def remove(self, element):
        # Check if the given element is None
        if element is None:
            # Throw a TypeError with the message "Element cannot be None"
            raise TypeError("Element cannot be None")
        # Check if the head index is equal to -1 (i.e., the list is empty)
        if self.head == -1: return
        # Check if the element at the head index is equal to the given element
        if self.cursorSpace[self.head].element == element:
            # Free the head node and update the head index
            self.free(self.head)
            self.head = self.cursorSpace[self.head].next
        else:
            # Initialize previous index to head and current index to the next index of the head index
            prev = self.head
            current = self.cursorSpace[prev].next
            # Use a while loop to iterate through the linked list and find the node containing the given element
            while current!= -1:
                # Check if the element at the current index is equal to the given element
                if self.cursorSpace[current].element == element:
                    # Free the current node and update the previous node's next index to the next node of the current node
                    self.free(current)
                    self.cursorSpace[prev].next = self.cursorSpace[current].next
                    break
                # Update the previous and current indices
                prev = current
                current = self.cursorSpace[prev].next
        # Decrement the count by 1
        self.count -= 1

    # Method to allocate a new node in the cursorSpace array
    def alloc(self):
        # Get the index of the first available node in the cursorSpace array
        availableNodeIndex = self.cursorSpace[self.os].next
        # Check if the next index of the operating system stack index is 0 (i.e., the list is full)
        if availableNodeIndex == 0:
            # Throw an MemoryError with the default message
            raise MemoryError()
        # Free the next index of the operating system stack index and set it to the index of the available node
        self.cursorSpace[self.os].next = self.cursorSpace[availableNodeIndex].next
        # Set the next index of the available node to -1 and return its index
        self.cursorSpace[availableNodeIndex].next = -1
        return availableNodeIndex

    # Method to free a node in the cursorSpace array
    def free(self, index):
        # Set the element of the node at the given index to None
        self.cursorSpace[index].element = None
        # Set the next index of the node to the next available index in the cursorSpace array
        self.cursorSpace[index].next = self.cursorSpace[self.os].next
        # Set the next available index in the cursorSpace array to the index of the freed node
        self.cursorSpace[self.os].next = index

    # Method to append an element to the end of the linked list
    def append(self, element):
        # Check if the given element is None
        if element is None:
            # Throw a TypeError with the message "Element cannot be None"
            raise TypeError("Element cannot be None")
        # Allocate a new node for the given element using the alloc method
        availableIndex = self.alloc()
        # Set the element of the new node to the given element
        self.cursorSpace[availableIndex].element = element
        # If the list is empty, set the head index to the index of the new node
        if self.head == -1:
            self.head = availableIndex
        else:
            # Use a while loop to find the last node in the list and set its next index to the index of the new node
            iterator = self.head
            while self.cursorSpace[iterator].next!= -1:
                iterator = self.cursorSpace[iterator].next.next
            self.cursorSpace[iterator].next = availableIndex
        # Increment the count by 1
        self.count += 1

# Create an instance of the Main class with generic type String
list = Main()
# Create a Scanner object to read user input from the standard input stream
scanner = Scanner(System.in)
# Use a while loop to read user input and execute commands until the user enters the "exit" command
while scanner.hasNextLine():
    command = scanner.nextLine().trim()
    # Check if the command is empty
    if command.isEmpty():
        continue
    # Split the command into parts using the " " (space) character as a delimiter
    parts = command.split(" ")
    # Switch on the first part of the command (i.e., the command name)
    switch (parts[0].toLowerCase()) {
        case "append":
            // Check if the command has exactly two parts
            if (parts.length!= 2) {
                // Throw an IllegalArgumentException with the message "Invalid command format"
                throw new IllegalArgumentException("Invalid command format");
            }
            // Get the element from the second part of the command
            String element = parts[1];
            // Append the element to the end of the linked list using the append method
            list.append(element);
            break;
        case "remove":
            // Check if the command has exactly two parts
            if (parts.length!= 2) {
                // Throw an IllegalArgumentException with the message "Invalid command format"
                throw new IllegalArgumentException("Invalid command format");
            }
            // Get the element from the second part of the command
            String element = parts[1];
            // Remove the element from the linked list using the remove method
            list.remove(element);
            break;
        case "removebyindex":
            // Check if the command has exactly two parts
            if (parts.length!= 2) {
                // Throw an IllegalArgumentException with the message "Invalid command format"
                throw new IllegalArgumentE