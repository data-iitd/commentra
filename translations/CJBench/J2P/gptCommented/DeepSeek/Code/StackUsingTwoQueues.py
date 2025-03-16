class StackUsingQueues:
    def __init__(self):
        self.main_queue = []
        self.temp_queue = []

    def push(self, item):
        self.temp_queue.append(item)
        while self.main_queue:
            self.temp_queue.append(self.main_queue.pop(0))
        self.main_queue, self.temp_queue = self.temp_queue, self.main_queue

    def pop(self):
        if not self.main_queue:
            raise NoSuchElementException("Stack is empty")
        return self.main_queue.pop(0)

    def peek(self):
        if not self.main_queue:
            return None
        return self.main_queue[0]

    def is_empty(self):
        return not self.main_queue

    def size(self):
        return len(self.main_queue)


# Main function to run the program
def main():
    stack = StackUsingQueues()
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    operations = data[1:]

    for i in range(n):
        operation = operations[i]
        if operation == "push":
            value = int(operations[i + 1])
            stack.push(value)
            print(f"Pushed: {value}")
            i += 1
        elif operation == "pop":
            try:
                print(f"Popped: {stack.pop()}")
            except NoSuchElementException as e:
                print(f"Error: {e}")
        elif operation == "peek":
            top = stack.peek()
            if top is not None:
                print(f"Top element: {top}")
            else:
                print("Stack is empty")
        elif operation == "isEmpty":
            print(f"Is stack empty? {stack.is_empty()}")
        elif operation == "size":
            print(f"Stack size: {stack.size()}")
        else:
            print("Invalid operation")


if __name__ == "__main__":
    main()
