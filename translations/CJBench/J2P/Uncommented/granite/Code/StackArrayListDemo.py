

stack = []

def push(value):
    stack.append(value)
    print("Pushed", value)

def pop():
    if len(stack) == 0:
        raise IndexError("Stack is empty.")
    removed = stack.pop()
    print("Popped", removed)
    return removed

def peek():
    if len(stack) == 0:
        raise IndexError("Stack is empty.")
    top = stack[-1]
    print("Top element:", top)
    return top

def is_empty():
    return len(stack) == 0

def make_empty():
    stack.clear()
    print("Stack cleared.")

def size():
    size = len(stack)
    print("Stack size:", size)
    return size

operations = int(input("Enter the number of operations: "))
for i in range(operations):
    choice = int(input("Enter the choice (1-6): "))
    if choice == 1:
        value = int(input("Enter the value to push: "))
        push(value)
    elif choice == 2:
        try:
            pop()
        except IndexError:
            print("Stack is empty. Cannot pop.")
    elif choice == 3:
        try:
            peek()
        except IndexError:
            print("Stack is empty. Cannot peek.")
    elif choice == 4:
        size()
    elif choice == 5:
        make_empty()
    elif choice == 6:
        print("Is stack empty? ", is_empty())
    else:
        print("Invalid choice. Try again.")

print("