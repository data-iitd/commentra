class Main:
    def __init__(self):
        self.stack = []

    def push(self, value):
        self.stack.append(value)
        print("Pushed " + str(value))

    def pop(self):
        if self.isEmpty():
            raise IndexError("pop from empty list")
        removed = self.stack.pop()
        print("Popped " + str(removed))
        return removed

    def peek(self):
        if self.isEmpty():
            raise IndexError("peek from empty list")
        top = self.stack[-1]
        print("Top element: " + str(top))
        return top

    def isEmpty(self):
        return len(self.stack) == 0

    def makeEmpty(self):
        self.stack.clear()
        print("Stack cleared.")

    def size(self):
        size = len(self.stack)
        print("Stack size: " + str(size))
        return size


if __name__ == "__main__":
    stack = Main()
    import sys
    input = sys.stdin.read
    data = input().split()
    operations = int(data[0])
    index = 1
    for i in range(operations):
        choice = int(data[index])
        index += 1
        try:
            if choice == 1:
                value = int(data[index])
                index += 1
                stack.push(value)
            elif choice == 2:
                try:
                    stack.pop()
                except IndexError:
                    print("Stack is empty. Cannot pop.")
            elif choice == 3:
                try:
                    stack.peek()
                except IndexError:
                    print("Stack is empty. Cannot peek.")
            elif choice == 4:
                stack.size()
            elif choice == 5:
                stack.makeEmpty()
            elif choice == 6:
                print("Is stack empty? " + str(stack.isEmpty()))
            else:
                print("Invalid choice. Try again.")
        except IndexError:
            print("Invalid operation. Try again.")
