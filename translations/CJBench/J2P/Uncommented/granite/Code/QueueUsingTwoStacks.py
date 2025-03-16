

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
    queue = Queue()
    for _ in range(operations):
        command = input().split()
        if command[0] == "INSERT":
            queue.insert(int(command[1]))
        elif command[0] == "REMOVE":
            print(queue.remove())
        elif command[0] == "PEEK_FRONT":
            print(queue.peekFront())
        elif command[0] == "PEEK_BACK":
            print(queue.peekBack())
        elif command[0] == "IS_EMPTY":
            print(queue.isEmpty())
        else:
            print("Invalid command")

