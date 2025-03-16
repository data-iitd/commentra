
import sys

# Define a static inner class Node to represent a node in the singly linked list
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Initialize the head of the linked list to null
head = None

# Method to add a new node with given data to the end of the linked list
def addNode(data):
    global head
    newNode = Node(data) # Create a new Node with the given data

    if head == None: # If the linked list is empty
        head = newNode # Make the new Node the head
    else:
        temp = head # Initialize a temporary Node to traverse the linked list
        while temp.next!= None: # Traverse the linked list until the end is reached
            temp = temp.next
        temp.next = newNode # Attach the new Node to the end of the linked list

# Method to print the first 20 elements of the linked list
def printList():
    global head
    temp = head # Initialize a temporary Node to traverse the linked list
    count = 0 # Initialize a counter to keep track of the number of elements printed

    while temp!= None and count < 20: # Traverse the linked list and print the first 20 elements
        print(temp.data, end=" -> ")
        temp = temp.next
        count += 1

    if temp!= None: # If more than 20 elements are present in the linked list
        print("... (loop detected)") # Print a message indicating that a loop was detected
    else:
        print("null") # If the linked list is empty or contains fewer than 20 elements, print "null"

    print() # Print a newline character to separate the output from the previous command

# Method to create a loop in the linked list by connecting the nodes at the given positions
def createLoop(position1, position2):
    if position1 == 0 or position2 == 0: # Check if the positions are valid
        return

    node1 = head # Initialize two Node variables to traverse the linked list
    node2 = head

    count1 = 1 # Initialize two counters to keep track of the number of nodes traversed
    count2 = 1

    while count1 < position1 and node1!= None: # Traverse the linked list until the first node is reached
        node1 = node1.next
        count1 += 1

    while count2 < position2 and node2!= None: # Traverse the linked list until the second node is reached
        node2 = node2.next
        count2 += 1

    if node1!= None and node2!= None: # Check if both nodes are valid and not null
        node2.next = node1 # Connect the second node to the first node to create a loop

# Method to detect a loop in the linked list by using Floyd's cycle-finding algorithm
def detectLoop():
    sptr = head # Initialize two Node variables to traverse the linked list at different speeds
    fptr = head

    while fptr!= None and fptr.next!= None: # Traverse the linked list until the fast pointer reaches null or a loop is detected
        sptr = sptr.next # Move the slow pointer one node forward
        fptr = fptr.next.next # Move the fast pointer two nodes forward

        if sptr == fptr: # If the slow and fast pointers meet, a loop has been detected
            return True

    return False # If no loop was detected, return false

# Main method to read user input and execute the corresponding command
def main():
    while True: # Read user input until the end of the input stream is reached
        command = input().strip() # Read a line of user input and remove any leading or trailing whitespace

        if command.lower() == "exit": # If the user input is "exit", terminate the program
            break

        try: # Try to parse the user input as a command and execute it
            parts = command.split(" ")
            if parts[0].lower() == "add": # If the command is "add", add a new node to the linked list
                if len(parts) < 2: # Check if the command has the required number of arguments
                    print("Error: Missing value for add")
                    continue
                value = int(parts[1]) # Parse the value argument as an integer
                addNode(value) # Add the new node to the linked list
                print("Added: " + str(value)) # Print a message indicating that the node was added
            elif parts[0].lower() == "createloop": # If the command is "createLoop", create a loop in the linked list
                if len(parts) < 3: # Check if the command has the required number of arguments
                    print("Error: Missing positions for createLoop")
                    continue
                pos1 = int(parts[1]) # Parse the first position argument as an integer
                pos2 = int(parts[2]) # Parse the second position argument as an integer
                createLoop(pos1, pos2) # Create a loop in the linked list at the given positions
                print("Loop created between positions " + str(pos1) + " and " + str(pos2)) # Print a message indicating that the loop was created
            elif parts[0].lower() == "detectloop": # If the command is "detectLoop", detect a loop in the linked list
                print("Loop detected: " + str(detectLoop())) # Print the result of the detectLoop() method
            elif parts[0].lower() == "print": # If the command is "print", print the first 20 elements of the linked list
                printList() # Call the printList() method to print the linked list
            else: # If the command is not recognized, print an error message
                print("Unknown command: " + parts[0])
        except Exception as e: # Catch any exceptions that may be thrown during command execution
            print("Error: " + str(e)) # Print an error message indicating the cause of the exception

if __name__ == "__main__":
    main()

