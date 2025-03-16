
class Node:
    def __init__(self, data):
        self.data = data
        self.previous = None


class Main:
    def __init__(self):
        self.head = None
        self.size = 0

    def push(self, item):
        newNode = Node(item)
        newNode.previous = self.head
        self.head = newNode
        self.size += 1

    def pop(self):
        if self.isEmpty():
            raise Exception("Cannot pop from an empty stack.")
        data = self.head.data
        self.head = self.head.previous
        self.size -= 1
        return data

    def peek(self):
        if self.isEmpty():
            raise Exception("Cannot peek from an empty stack.")
        return self.head.data

    def isEmpty(self):
        return self.head == None

    def size(self):
        return self.size


if __name__ == "__main__":
    stack = Main()

    print("Enter commands (push <value>, pop, peek, size, isEmpty, exit):")
    while True:
        command = input().strip()
        if command.lower() == "exit":
            break

        parts = command.split(" ")
        try:
            if parts[0] == "push":
                if len(parts) < 2:
                    print("Error: Missing value for push")
                    continue
                value = int(parts[1])
                stack.push(value)
                print("Pushed: " + str(value))
            elif parts[0] == "pop":
                print("Popped: " + str(stack.pop()))
            elif parts[0] == "peek":
                print("Top: " + str(stack.peek()))
            elif parts[0] == "size":
                print("Size: " + str(stack.size()))
            elif parts[0] == "isEmpty":
                print("Is empty: " + str(stack.isEmpty()))
            else:
                print("Unknown command: " + parts[0])
        except Exception as e:
            print("Error: " + str(e))

