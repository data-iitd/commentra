
class Main:
    def __init__(self):
        self.mainQueue = []
        self.tempQueue = []

    def push(self, item):
        self.tempQueue.append(item)
        while len(self.mainQueue) > 0:
            self.tempQueue.append(self.mainQueue.pop())
        self.mainQueue, self.tempQueue = self.tempQueue, self.mainQueue

    def pop(self):
        if len(self.mainQueue) == 0:
            raise Exception("Stack is empty")
        return self.mainQueue.pop()

    def peek(self):
        if len(self.mainQueue) == 0:
            return None
        return self.mainQueue[len(self.mainQueue) - 1]

    def isEmpty(self):
        return len(self.mainQueue) == 0

    def size(self):
        return len(self.mainQueue)

# 