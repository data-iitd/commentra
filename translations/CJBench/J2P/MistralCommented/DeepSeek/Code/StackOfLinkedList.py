class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedListStack:
    def __init__(self):
        self.head = None
        self.size = 0

    def push(self, x):
        new_node = Node(x)
        new_node.next = self.head
        self.head = new_node
        self.size += 1

    def pop(self):
        if self.size == 0:
            raise Exception("Empty stack. Nothing to pop")
        value = self.head.data
        self.head = self.head.next
        self.size -= 1
        return value

    def peek(self):
        if self.size == 0:
            raise Exception("Empty stack. Nothing to peek")
        return self.head.data

    def is_empty(self):
        return self.size == 0

    def get_size(self):
        return self.size

    def make_empty(self):
        self.head = None
        self.size = 0

def main():
    stack = LinkedListStack()
    import sys
    input = sys.stdin.read
    data = input().split()
    operations = int(data[0])
    index = 1

    for i in range(operations):
        choice = int(data[index])
        index += 1
        if choice == 1:
            value = int(data[index])
            stack.push(value)
            print(f"Pushed {value}")
            index += 1
        elif choice == 2:
            try:
                popped = stack.pop()
                print(f"Popped {popped}")
            except Exception as e:
                print(str(e))
        elif choice == 3:
            try:
                peeked = stack.peek()
                print(f"Top element: {peeked}")
            except Exception as e:
                print(str(e))
        elif choice == 4:
            print(f"Stack size: {stack.get_size()}")
        elif choice == 5:
            print(f"Is stack empty? {stack.is_empty()}")
        elif choice == 6:
            stack.make_empty()
            print("Stack cleared.")
        else:
            print("Invalid choice.")

if __name__ == "__main__":
    main()
