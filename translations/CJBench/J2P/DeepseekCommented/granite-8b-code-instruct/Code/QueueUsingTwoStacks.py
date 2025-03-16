
class Queue:
    def __init__(self):
        self.in_stack = [] # Initialize the stack for incoming elements
        self.out_stack = [] # Initialize the stack for outgoing elements
    
    def insert(self, x):
        self.in_stack.append(x) # Add the element to the in_stack
    
    def remove(self):
        if not self.out_stack: # If out_stack is empty, transfer elements from in_stack
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
        if self.out_stack: # If out_stack is not empty, remove and return the top element
            return self.out_stack.pop()
        return "Queue is empty" # Return a message if the queue is empty
    
    def peek_front(self):
        if not self.out_stack: # If out_stack is empty, transfer elements from in_stack
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
        if self.out_stack: # If out_stack is not empty, return the top element without removing it
            return self.out_stack[-1]
        return "Queue is empty" # Return a message if the queue is empty
    
    def peek_back(self):
        if self.in_stack: # If in_stack is not empty, return the top element
            return self.in_stack[-1]
        return "Queue is empty" # Return a message if the queue is empty
    
    def is_empty(self):
        return not self.in_stack and not self.out_stack # Return true if both stacks are empty

# Main method to handle user input for queue operations
if __name__ == "__main__":
    import sys
    operations = int(input()) # Read the number of operations
    queue = Queue()
    for _ in range(operations):
        command = input().split() # Read each command
        if command[0] == "INSERT":
            queue.insert(int(command[1])) # Insert an integer
        elif command[0] == "REMOVE":
            print(queue.remove()) # Remove and print the element
        elif command[0] == "PEEK_FRONT":
            print(queue.peek_front()) # Peek and print the front element
        elif command[0] == "PEEK_BACK":
            print(queue.peek_back()) # Peek and print the back element
        elif command[0] == "IS_EMPTY":
            print(queue.is_empty()) # Check if the queue is empty and print the result
        else:
            print("Invalid command") # Print an error message for invalid commands

