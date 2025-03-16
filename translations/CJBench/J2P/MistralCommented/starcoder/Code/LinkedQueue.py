
# Class definition for a generic linked list queue
class Main:

    # Inner class definition for a node in the queue
    class Node:
        def __init__(self, data):
            self.data = data
            self.next = None

    # Instance variables for the front and rear pointers, and the size of the queue
    front = None
    rear = None
    size = 0

    # Constructor for an empty queue
    def __init__(self):
        self.front = None
        self.rear = None
        self.size = 0

    # Check if the queue is empty
    def isEmpty(self):
        return self.size == 0

    # Add an element to the queue
    def enqueue(self, data):
        if data is None: # Check if the data is null
            raise ValueError("Cannot enqueue null data")

        newNode = self.Node(data) # Create a new node with the data

        if self.isEmpty(): # If the queue is empty
            self.front = newNode
        else:
            self.rear.next = newNode # Else, make the new node the next of the rear node

        self.rear = newNode # Update the rear pointer
        self.size += 1 # Increment the size of the queue

    # Remove and return the front element from the queue
    def dequeue(self):
        if self.isEmpty(): # Check if the queue is empty
            raise IndexError("Queue is empty")

        retValue = self.front.data # Store the data of the front node in a variable

        self.front = self.front.next # Update the front pointer to the next node

        self.size -= 1 # Decrement the size of the queue

        if self.isEmpty(): # If the queue is now empty
            self.rear = None # Set the rear pointer to null

        return retValue # Return the dequeued element

    # Return the front element of the queue without removing it
    def peekFront(self):
        if self.isEmpty(): # Check if the queue is empty
            raise IndexError("Queue is empty")

        return self.front.data # Return the data of the front node

    # Return the rear element of the queue without removing it
    def peekRear(self):
        if self.isEmpty(): # Check if the queue is empty
            raise IndexError("Queue is empty")

        return self.rear.data # Return the data of the rear node

    # Return the size of the queue
    def size(self):
        return self.size

    # Clear the queue
    def clear(self):
        self.front = None
        self.rear = None
        self.size = 0

    # Override the toString method to print the queue as a string
    def __str__(self):
        if self.isEmpty():
            return "[]"

        sb = "["
        current = self.front # Initialize a pointer to the front node

        while current!= None: # Traverse the queue and add each element to the string
            sb += str(current.data)
            if current.next!= None:
                sb += ", "
            current = current.next

        sb += ']' # Add the closing bracket
        return sb

# Main method for testing the queue implementation
if __name__ == "__main__":
    import sys # Import the sys module for reading input from the standard input

    queue = Main() # Create an instance of the queue for integers

    while True: # Read commands from the standard input until the end
        command = sys.stdin.readline().strip() # Read a command line

        if command.lower().strip() == "exit": # Check if the command is "exit"
            break # If so, exit the loop

        try:
            parts = command.split(" ") # Split the command into parts

            if parts[0].lower().strip() == "enqueue":
                if len(parts) < 2: # Check if the command has a required argument
                    print("Error: Missing value for enqueue")
                    continue
                value = int(parts[1]) # Parse the value from the argument
                queue.enqueue(value) # Enqueue the value
                print("Enqueued: " + str(value)) # Print a message
            elif parts[0].lower().strip() == "dequeue":
                print("Dequeued: " + str(queue.dequeue())) # Dequeue and print the front element
            elif parts[0].lower().strip() == "peekFront":
                print("Front element: " + str(queue.peekFront())) # Print the front element
            elif parts[0].lower().strip() == "peekRear":
                print("Rear element: " + str(queue.peekRear())) # Print the rear element
            elif parts[0].lower().strip() == "size":
                print("Size: " + str(queue.size())) # Print the size of the queue
            elif parts[0].lower().strip() == "isEmpty":
                print("Is empty: " + str(queue.isEmpty())) # Print whether the queue is empty or not
            elif parts[0].lower().strip() == "print":
                print(queue) # Print the entire queue
            else:
                print("Unknown command: " + parts[0]) # Print an error message for unknown commands
        except Exception as e: # Catch any exceptions and print an error message
            print("Error: " + str(e))

