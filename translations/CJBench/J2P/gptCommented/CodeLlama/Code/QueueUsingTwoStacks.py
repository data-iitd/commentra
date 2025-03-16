import sys

class Queue:
    # Declare two stacks to simulate queue behavior
    in_stack = []  # Stack for incoming elements
    out_stack = []  # Stack for outgoing elements

    # Constructor to initialize the stacks
    def __init__(self):
        self.in_stack = []
        self.out_stack = []

    # Method to insert an element into the queue
    def insert(self, x):
        self.in_stack.append(x)  # Push the element onto the inStack

    # Method to remove and return the front element of the queue
    def remove(self):
        # If outStack is empty, transfer elements from inStack to outStack
        if not self.out_stack:
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
        # If outStack is not empty, pop and return the top element
        if self.out_stack:
            return self.out_stack.pop()
        return "Queue is empty"  # Return message if queue is empty

    # Method to peek at the front element of the queue without removing it
    def peek_front(self):
        # If outStack is empty, transfer elements from inStack to outStack
        if not self.out_stack:
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
        # If outStack is not empty, return the top element without removing it
        if self.out_stack:
            return self.out_stack[-1]
        return "Queue is empty"  # Return message if queue is empty

    # Method to peek at the back element of the queue without removing it
    def peek_back(self):
        # Return the top element of inStack if it is not empty
        if self.in_stack:
            return self.in_stack[-1]
        return "Queue is empty"  # Return message if queue is empty

    # Method to check if the queue is empty
    def is_empty(self):
        return not self.in_stack and not self.out_stack  # Return true if both stacks are empty


# Main method to execute the program
def main():
    operations = int(sys.stdin.readline())  # Read the number of operations to perform
    queue = Queue()  # Create an instance of the queue

    # Loop through the number of operations
    for _ in range(operations):
        command = sys.stdin.readline().split()  # Read and split the command input
        if command[0] == "INSERT":
            queue.insert(int(command[1]))  # Insert the specified element
        elif command[0] == "REMOVE":
            print(queue.remove())  # Remove and print the front element
        elif command[0] == "PEEK_FRONT":
            print(queue.peek_front())  # Print the front element without removing it
        elif command[0] == "PEEK_BACK":
            print(queue.peek_back())  # Print the back element without removing it
        elif command[0] == "IS_EMPTY":
            print(queue.is_empty())  # Print whether the queue is empty
        else:
            print("Invalid command")  # Handle invalid commands


if __name__ == "__main__":
    main()


