
# Create a new instance of LinkedListStack to use for stack operations
stack = LinkedListStack()

# Initialize a Scanner to read user input
scanner = Scanner(System.in)

# Read the number of operations to perform on the stack
operations = scanner.nextInt()

# Loop through the number of operations specified by the user
for i in range(operations):
    # Read the user's choice of operation
    choice = scanner.nextInt()
    if choice == 1:
        # Push a new value onto the stack
        value = scanner.nextInt()
        stack.push(value)
        print("Pushed " + value)
    elif choice == 2:
        # Pop the top value from the stack and handle potential exceptions
        try:
            popped = stack.pop()
            print("Popped " + popped)
        except NoSuchElementException as e:
            # Print error message if the stack is empty
            print(e.getMessage())
    elif choice == 3:
        # Peek at the top value of the stack without removing it
        try:
            peeked = stack.peek()
            print("Top element: " + peeked)
        except NoSuchElementException as e:
            # Print error message if the stack is empty
            print(e.getMessage())
    elif choice == 4:
        # Get and print the current size of the stack
        print("Stack size: " + stack.getSize())
    elif choice == 5:
        # Check if the stack is empty and print the result
        print("Is stack empty? " + stack.isEmpty())
    elif choice == 6:
        # Clear the stack of all elements
        stack.makeEmpty()
        print("Stack cleared.")
    else:
        # Handle invalid choices
        print("Invalid choice.")

# Close the scanner to prevent resource leaks
scanner.close()

