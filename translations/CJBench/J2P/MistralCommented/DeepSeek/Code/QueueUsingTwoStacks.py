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


if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    queue = Queue()
    operations = int(data[0])

    for i in range(1, operations + 1):
        cmd = data[i]
        if cmd == "INSERT":
            queue.insert(int(data[i + 1]))
            i += 1
        elif cmd == "REMOVE":
            print(queue.remove())
        elif cmd == "PEEK_FRONT":
            print(queue.peek_front())
        elif cmd == "PEEK_BACK":
            print(queue.peek_back())
        elif cmd == "IS_EMPTY":
            print(queue.is_empty())
        i += 1
