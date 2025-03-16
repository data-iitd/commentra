class Main:
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
        return len(self.in_stack) == 0 and len(self.out_stack) == 0

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().strip().splitlines()
    
    queue = Main()
    operations = int(data[0])
    
    for i in range(1, operations + 1):
        command = data[i].split()
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

# <END-OF-CODE>
