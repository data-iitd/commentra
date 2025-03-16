

class Queue:
    def __init__(self):
        self.inStack = []
        self.outStack = []

    def insert(self, x):
        self.inStack.append(x)

    def remove(self):
        if not self.outStack:
            while self.inStack:
                self.outStack.append(self.inStack.pop())
        if self.outStack:
            return self.outStack.pop()
        return "Queue is empty"

    def peek_front(self):
        if not self.outStack:
            while self.inStack:
                self.outStack.append(self.inStack.pop())
        if self.outStack:
            return self.outStack[-1]
        return "Queue is empty"

    def peek_back(self):
        if self.inStack:
            return self.inStack[-1]
        return "Queue is empty"

    def is_empty(self):
        return not self.inStack and not self.outStack

if __name__ == "__main__":
    operations = int(input())

    queue = Queue()

    for _ in range(operations):
        command = input().split()
        if command[0] == "INSERT":
            queue.insert(int(command[1]))
        elif command[0] == "REMOVE":
            print(queue.remove())
        elif command[0] == "PEEK_FRONT":
            print(queue.peek_front())
        elif command[0] == "PEEK_BACK":
            print(queue.peek_back())
        elif command[0] == "IS_EMPTY":
            print(queue.is_empty())
        else:
            print("Invalid command")

