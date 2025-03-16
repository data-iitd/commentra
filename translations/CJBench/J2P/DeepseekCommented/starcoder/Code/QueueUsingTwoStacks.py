import sys
class Main:
    def __init__(self):
        self.inStack = []
        self.outStack = []
    def insert(self, x):
        self.inStack.append(x)
    def remove(self):
        if len(self.outStack) == 0:
            while len(self.inStack) > 0:
                self.outStack.append(self.inStack.pop())
        if len(self.outStack) > 0:
            return self.outStack.pop()
        return "Queue is empty"
    def peekFront(self):
        if len(self.outStack) == 0:
            while len(self.inStack) > 0:
                self.outStack.append(self.inStack.pop())
        if len(self.outStack) > 0:
            return self.outStack[len(self.outStack) - 1]
        return "Queue is empty"
    def peekBack(self):
        if len(self.inStack) > 0:
            return self.inStack[len(self.inStack) - 1]
        return "Queue is empty"
    def isEmpty(self):
        return len(self.inStack) == 0 and len(self.outStack) == 0
if __name__ == "__main__":
    main = Main()
    operations = int(sys.stdin.readline().strip())
    for i in range(operations):
        command = sys.stdin.readline().strip().split(" ")
        if command[0] == "INSERT":
            main.insert(int(command[1]))
        elif command[0] == "REMOVE":
            print(main.remove())
        elif command[0] == "PEEK_FRONT":
            print(main.peekFront())
        elif command[0] == "PEEK_BACK":
            print(main.peekBack())
        elif command[0] == "IS_EMPTY":
            print(main.isEmpty())
        else:
            print("Invalid command")
