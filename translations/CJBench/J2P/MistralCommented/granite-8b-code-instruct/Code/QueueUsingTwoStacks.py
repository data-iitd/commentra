

class Main:
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

    def peekFront(self):
        if not self.outStack:
            while self.inStack:
                self.outStack.append(self.inStack.pop())
        if self.outStack:
            return self.outStack[-1]
        return "Queue is empty"

    def peekBack(self):
        if self.inStack:
            return self.inStack[-1]
        return "Queue is empty"

    def isEmpty(self):
        return not self.inStack and not self.outStack

if __name__ == "__main__":
    import sys
    operations = int(input())
    queue = Main()
    for _ in range(operations):
        command = input().split()
        cmd = command[0]
        if cmd == "INSERT":
            queue.insert(int(command[1]))
        elif cmd == "REMOVE":
            print(queue.remove())
        elif cmd == "PEEK_FRONT":
            print(queue.peekFront())
        elif cmd == "PEEK_BACK":
            print(queue.peekBack())
        elif cmd == "IS_EMPTY":
            print(queue.isEmpty())
        else:
            print("Invalid command")

