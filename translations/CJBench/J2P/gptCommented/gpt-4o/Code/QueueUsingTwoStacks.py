class Queue:
    def __init__(self):
        self.in_stack = []  # Stack for incoming elements
        self.out_stack = []  # Stack for outgoing elements

    def insert(self, x):
        self.in_stack.append(x)  # Push the element onto the in_stack

    def remove(self):
        if not self.out_stack:  # If out_stack is empty, transfer elements from in_stack to out_stack
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
        if self.out_stack:  # If out_stack is not empty, pop and return the top element
            return self.out_stack.pop()
        return "Queue is empty"  # Return message if queue is empty

    def peek_front(self):
        if not self.out_stack:  # If out_stack is empty, transfer elements from in_stack to out_stack
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
        if self.out_stack:  # If out_stack is not empty, return the top element without removing it
            return self.out_stack[-1]
        return "Queue is empty"  # Return message if queue is empty

    def peek_back(self):
        if self.in_stack:  # Return the top element of in_stack if it is not empty
            return self.in_stack[-1]
        return "Queue is empty"  # Return message if queue is empty

    def is_empty(self):
        return not self.in_stack and not self.out_stack  # Return true if both stacks are empty


if __name__ == "__main__":
    import sys

    queue = Queue()  # Create an instance of the queue
    operations = int(sys.stdin.readline().strip())  # Read the number of operations to perform

    for _ in range(operations):
        command = sys.stdin.readline().strip().split()  # Read and split the command input
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

# <END-OF-CODE>
