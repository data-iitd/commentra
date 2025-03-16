
import sys # Import the sys module to read user input

class Main: # Define a generic class named Main
    DEFAULT_CAPACITY = 10 # Set default capacity of the queue
    def __init__(self, capacity=DEFAULT_CAPACITY): # Constructor with an integer argument, initializes the queue with the given capacity
        if capacity <= 0: # Check if the capacity is less than or equal to zero
            raise Exception("Main capacity must be greater than 0") # Throw an exception if it is
        self.maxSize = capacity # Set the maxSize to the given capacity
        self.queueArray = [None] * capacity # Create an array of the given size to store the queue elements
        self.front = 0 # Set the front index to zero
        self.rear = -1 # Set the rear index to -1, indicating an empty queue
        self.nItems = 0 # Set the number of elements to zero

    #... (insert, remove, peekFront, peekRear, isEmpty, isFull, getSize, and print methods)

    def main(self): # Main method to run the program
        size = int(input()) # Read the size of the queue from the user
        queue = Main(size) # Create a new Main object with the given size

        while True: # Read user commands until the end of the input
            command = input().strip() # Read and trim the command string

            if command.lower() == "exit": # Check if the command is "exit"
                break # If it is, exit the loop and close the scanner

            parts = command.split(" ") # Split the command string into parts based on space

            if parts[0].lower() == "insert": # If the command is "insert", process the insertion
                if len(parts) < 2: # Check if the command has a value
                    print("Error: Missing value for insert") # Print an error message if it doesn't
                    break
                value = int(parts[1]) # Parse the value from the command
                if queue.insert(value): # Try to insert the value into the queue
                    print("Inserted: " + str(value)) # Print a success message if it's successful
                else:
                    print("Main is full") # Print a full message if the queue is full
            #... (other cases for "remove", "peekFront", "peekRear", "getSize", "isEmpty", and "print")

if __name__ == "__main__": # Check if the file is being run directly
    Main().main() # Run the main method if it is

# 