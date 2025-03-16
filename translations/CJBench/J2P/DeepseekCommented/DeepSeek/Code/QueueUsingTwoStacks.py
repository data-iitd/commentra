class Queue:
    def __init__(self):
        self.in_stack = []
        self.out_stack = []

    def insert(self, x):
        self.in_stack.append(x)

    def remove(self):
        if not self.out_stack:
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
        if self.out_stack:
            return self.out_stack.pop()
        return "Queue is empty"

    def peek_front(self):
        if not self.out_stack:
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
        if self.out_stack:
            return self.out_stack[-1]
        return "Queue is empty"

    def peek_back(self):
        if self.in_stack:
            return self.in_stack[-1]
        return "Queue is empty"

    def is_empty(self):
        return not (self.in_stack or self.out_stack)


def main():
    queue = Queue()
    import sys
    input = sys.stdin.read
    data = input().split()
    operations = int(data[0])
    index = 1
    for _ in range(operations):
        command = data[index:index+2]
        index += 2
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


main()
