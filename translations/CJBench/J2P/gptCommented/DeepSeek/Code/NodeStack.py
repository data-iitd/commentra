class Node:
    def __init__(self, data):
        self.data = data
        self.previous = None


class Main:
    def __init__(self):
        self.head = None
        self.size = 0

    def push(self, item):
        new_node = Node(item)
        new_node.previous = self.head
        self.head = new_node
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
        return self.head is None

    def size(self):
        return self.size


if __name__ == "__main__":
    import sys
    stack = Main()
    for line in sys.stdin:
        command = line.strip()
        if command == "exit":
            break
        parts = command.split()
        try:
            if parts[0] == "push":
                if len(parts) < 2:
                    print("Error: Missing value for push")
                    continue
                value = int(parts[1])
                stack.push(value)
                print(f"Pushed: {value}")
            elif parts[0] == "pop":
                print(f"Popped: {stack.pop()}")
            elif parts[0] == "peek":
                print(f"Top: {stack.peek()}")
            elif parts[0] == "size":
                print(f"Size: {stack.size()}")
            elif parts[0] == "isEmpty":
                print(f"Is empty: {stack.isEmpty()}")
            else:
                print(f"Unknown command: {parts[0]}")
        except Exception as e:
            print(f"Error: {e}")
