import java.util.NoSuchElementException;
import java.util.Scanner;

class Main:
    # Node class representing each element in the queue
    class Node:
        def __init__(self, data):
            self.data = data
            self.next = None

    # Front and rear pointers for the queue
    front = None # Points to the front of the queue
    rear = None
    size = 0 # Keeps track of the number of elements in the queue

    # Constructor to initialize the queue
    def __init__(self):
        self.front = None # Initially, the queue is empty
        self.rear = None
        self.size = 0 # Size is zero

    # Method to check if the queue is empty
    def isEmpty(self):
        return self.size == 0 # Returns true if size is zero

    # Method to add an element to the end of the queue
    def enqueue(self, data):
        if data == None:
            raise Exception("Cannot enqueue null data") # Prevent null data
        newNode = Node(data) # Create a new node with the given data
        if self.isEmpty():
            self.front = newNode # If the queue is empty, set front to the new node
        else:
            self.rear.next = newNode # Link the new node to the end of the queue
        self.rear = newNode # Update the rear to the new node
        self.size += 1 # Increment the size of the queue

    # Method to remove and return the front element of the queue
    def dequeue(self):
        if self.isEmpty():
            raise NoSuchElementException("Queue is empty") # Prevent dequeue from an empty queue
        retValue = self.front.data # Store the data of the front node
        self.front = self.front.next # Move the front pointer to the next node
        self.size -= 1 # Decrement the size of the queue
        if self.isEmpty():
            self.rear = None # If the queue is now empty, set rear to null
        return retValue # Return the dequeued value

    # Method to get the front element without removing it
    def peekFront(self):
        if self.isEmpty():
            raise NoSuchElementException("Queue is empty") # Prevent peek from an empty queue
        return self.front.data # Return the data of the front node

    # Method to get the rear element without removing it
    def peekRear(self):
        if self.isEmpty():
            raise NoSuchElementException("Queue is empty") # Prevent peek from an empty queue
        return self.rear.data # Return the data of the rear node

    # Method to get the current size of the queue
    def size(self):
        return self.size # Return the size of the queue

    # Method to clear the queue
    def clear(self):
        self.front = None # Set front to null
        self.rear = None # Set rear to null
        self.size = 0 # Reset size to zero

    # Method to return a string representation of the queue
    def __str__(self):
        if self.isEmpty():
            return "[]" # Return empty representation if the queue is empty
        sb = StringBuilder("[") # Start building the string
        current = self.front # Start from the front of the queue
        while current!= None:
            sb.append(current.data) # Append the current node's data
            if current.next!= None:
                sb.append(", ") # Append a comma if there is a next node
            current = current.next # Move to the next node
        sb.append(']') # Close the string representation
        return sb.toString() # Return the final string

# Main method to run the queue operations based on user input
if __name__ == "__main__":
    scanner = Scanner(System.in) # Create a scanner for user input
    queue = Main() # Create a new queue instance for integers

    # Loop to process user commands
    while scanner.hasNextLine():
        command = scanner.nextLine().trim() # Read the command from user input
        if command.equalsIgnoreCase("exit"):
            break # Exit the loop if the command is "exit"
        try:
            parts = command.split(" ") # Split the command into parts
            if parts[0] == "enqueue":
                if len(parts) < 2:
                    print("Error: Missing value for enqueue") # Error for missing value
                    break
                value = int(parts[1]) # Parse the value to enqueue
                queue.enqueue(value) # Enqueue the value
                print("Enqueued: " + value) # Confirm enqueue operation
            elif parts[0] == "dequeue":
                print("Dequeued: " + queue.dequeue()) # Dequeue and print the result
            elif parts[0] == "peekFront":
                print("Front element: " + queue.peekFront()) # Print the front element
            elif parts[0] == "peekRear":
                print("Rear element: " + queue.peekRear()) # Print the rear element
            elif parts[0] == "size":
                print("Size: " + queue.size()) # Print the current size of the queue
            elif parts[0] == "isEmpty":
                print("Is empty: " + queue.isEmpty()) # Check if the queue is empty
            elif parts[0] == "print":
                print(queue) # Print the string representation of the queue
            else:
                print("Unknown command: " + parts[0]) # Handle unknown commands
        except Exception as e:
            print("Error: " + e.getMessage()) # Print any errors encountered
    scanner.close() # Close the scanner when done

