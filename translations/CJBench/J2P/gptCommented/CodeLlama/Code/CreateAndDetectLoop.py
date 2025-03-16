
# Import the Scanner class from the java.util package
from java.util import Scanner

# Node class representing each element in the linked list
class Node:
    # Constructor to initialize a new node with data
    def __init__(self, data):
        self.data = data
        self.next = None # Initially, the next node is null

# Head of the linked list
head = None

# Method to add a new node with the specified data to the end of the list
def addNode(data):
    newNode = Node(data) # Create a new node
    if head == None: # If the list is empty
        head = newNode # Set the new node as the head
    else:
        temp = head # Start from the head
        # Traverse to the end of the list
        while temp.next != None:
            temp = temp.next
        temp.next = newNode # Link the new node at the end

# Method to print the linked list up to 20 nodes or indicate a loop
def printList():
    temp = head # Start from the head
    count = 0 # Counter to limit the number of printed nodes
    # Traverse the list and print each node's data
    while temp != None and count < 20:
        print(temp.data, end=" -> ")
        temp = temp.next # Move to the next node
        count += 1
    # Check if there are more nodes after the first 20
    if temp != None:
        print("... (loop detected)") # Indicate loop if exists
    else:
        print("null") # Indicate end of the list

# Method to create a loop in the linked list between two specified positions
def createLoop(position1, position2):
    # Return if either position is invalid
    if position1 == 0 or position2 == 0:
        return
    node1 = head # Pointer to find the first node for the loop
    node2 = head # Pointer to find the second node for the loop
    count1 = 1 # Counter for the first position
    count2 = 1 # Counter for the second position

    # Traverse to the first position
    while count1 < position1 and node1 != None:
        node1 = node1.next
        count1 += 1
    # Traverse to the second position
    while count2 < position2 and node2 != None:
        node2 = node2.next
        count2 += 1
    # Create a loop by linking the second node to the first node
    if node1 != None and node2 != None:
        node2.next = node1 # Create the loop

# Method to detect if there is a loop in the linked list using Floyd's cycle-finding algorithm
def detectLoop():
    sptr = head # Slow pointer
    fptr = head # Fast pointer
    # Traverse the list with two pointers
    while fptr != None and fptr.next != None:
        sptr = sptr.next # Move slow pointer by one
        fptr = fptr.next.next # Move fast pointer by two
        # If the two pointers meet, a loop is detected
        if sptr == fptr:
            return True # Loop detected
    return False # No loop detected

# Main method to execute the program
def main():
    scanner = Scanner(System.in) # Scanner for user input
    # Loop to process user commands
    while scanner.hasNextLine():
        command = scanner.nextLine().strip() # Read and strip the command
        if command == "": # Skip empty commands
            continue
        if command == "exit": # Exit command
            break
        try:
            parts = command.split(" ") # Split command into parts
            switch = parts[0] # Determine the command type
            if switch == "add": # Command to add a node
                if len(parts) < 2:
                    print("Error: Missing value for add")
                    break
                value = int(parts[1]) # Parse the value to add
                addNode(value) # Add the node
                print("Added: " + str(value)) # Confirmation message
            elif switch == "createLoop": # Command to create a loop
                if len(parts) < 3:
                    print("Error: Missing positions for createLoop")
                    break
                pos1 = int(parts[1]) # Parse the first position
                pos2 = int(parts[2]) # Parse the second position
                createLoop(pos1, pos2) # Create the loop
                print("Loop created between positions " + str(pos1) + " and " + str(pos2))
            elif switch == "detectLoop": # Command to detect a loop
                print("Loop detected: " + str(detectLoop())) # Output result of loop detection
            elif switch == "print": # Command to print the list
                printList() # Print the linked list
            else: # Handle unknown commands
                print("Unknown command: " + parts[0])
        except Exception as e: # Handle exceptions
            print("Error: " + str(e))
    scanner.close() # Close the scanner

# Call the main method to execute the program
main()

