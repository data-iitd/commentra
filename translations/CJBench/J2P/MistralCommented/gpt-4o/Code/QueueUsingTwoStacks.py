class Main:
    def __init__(self):
        # Initialize two stacks for input and output elements
        self.in_stack = []
        self.out_stack = []

    def insert(self, x):
        # Push the given object into the input stack
        self.in_stack.append(x)

    def remove(self):
        # If the output stack is empty, transfer all elements from input stack to output stack
        if not self.out_stack:
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
        # If there is an element in the output stack, pop it and return it
        if self.out_stack:
            return self.out_stack.pop()
        # If the queue is empty, return a message
        return "Queue is empty"

    def peek_front(self):
        # If the output stack is empty, transfer all elements from input stack to output stack
        if not self.out_stack:
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
        # If there is an element in the output stack, return a reference to it without popping it
        if self.out_stack:
            return self.out_stack[-1]
        # If the queue is empty, return a message
        return "Queue is empty"

    def peek_back(self):
        # If the input stack is not empty, return a reference to the top element
        if self.in_stack:
            return self.in_stack[-1]
        # If the queue is empty, return a message
        return "Queue is empty"

    def is_empty(self):
        # Return true if both input and output stacks are empty
        return not self.in_stack and not self.out_stack

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    queue = Main()  # Create an instance of the Main class
    operations = int(data[0])  # Read the number of operations from the standard input

    for i in range(1, operations + 1):
        command = data[i].split()  # Read a line from the standard input and split it into words
        cmd = command[0]  # Get the command name

        if cmd == "INSERT":
            queue.insert(int(command[1]))
        elif cmd == "REMOVE":
            print(queue.remove())
        elif cmd == "PEEK_FRONT":
            print(queue.peek_front())
        elif cmd == "PEEK_BACK":
            print(queue.peek_back())
        elif cmd == "IS_EMPTY":
            print(queue.is_empty())
        else:
            print("Invalid command")

# <END-OF-CODE>
