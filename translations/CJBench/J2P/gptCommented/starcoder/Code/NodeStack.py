
# Node class representing each element in the stack
class Node:
    def __init__(self, data):
        self.data = data
        self.previous = None


class Main:
    def __init__(self):
        self.head = None
        self.size = 0

    # Method to add an item to the top of the stack
    def push(self, item):
        newNode = Node(item)
        newNode.previous = self.head
        self.head = newNode
        self.size += 1

    # Method to remove and return the top item from the stack
    def pop(self):
        # Check if the stack is empty before popping
        if self.isEmpty():
            raise Exception("Cannot pop from an empty stack.")
        data = self.head.data
        self.head = self.head.previous
        self.size -= 1
        return data

    # Method to return the top item without removing it from the stack
    def peek(self):
        # Check if the stack is empty before peeking
        if self.isEmpty():
            raise Exception("Cannot peek from an empty stack.")
        return self.head.data

    # Method to check if the stack is empty
    def isEmpty(self):
        return self.head == None

    # Method to return the current size of the stack
    def size(self):
        return self.size


# Main method to run the stack operations based on user input
if __name__ == "__main__":
    scanner = Scanner(System.in)
    stack = Main()

    # Loop to continuously read commands until "exit" is entered
    while scanner.hasNextLine():
        command = scanner.nextLine().trim()
        if command.equalsIgnoreCase("exit"):
            break
        try:
            parts = command.split(" ")
            if parts[0] == "push":
                if len(parts) < 2:
                    print("Error: Missing value for push")
                    break
                value = int(parts[1])
                stack.push(value)
                print("Pushed: " + value)
            elif parts[0] == "pop":
                print("Popped: " + stack.pop())
            elif parts[0] == "peek":
                print("Top: " + stack.peek())
            elif parts[0] == "size":
                print("Size: " + stack.size())
            elif parts[0] == "isEmpty":
                print("Is empty: " + stack.isEmpty())
            else:
                print("Unknown command: " + parts[0])
        except Exception as e:
            print("Error: " + e.getMessage())
    scanner.close()

