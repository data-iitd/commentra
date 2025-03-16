
# Global variables
stack = [] # Stack to hold integers

# Function to push an integer onto the stack
def push(x):
    stack.append(x) # Append the value to the stack

# Function to pop an integer from the stack
def pop():
    return stack.pop() # Return the top value and remove it from the stack

# Read input until EOF
while True:
    try:
        s = input() # Read input string
        # Check for addition operation
        if s[0] == '+':
            b = pop() # Pop the top two values from the stack
            a = pop()
            push(a + b) # Push the result of addition back onto the stack
        # Check for subtraction operation
        elif s[0] == '-':
            b = pop() # Pop the top two values from the stack
            a = pop()
            push(a - b) # Push the result of subtraction back onto the stack
        # Check for multiplication operation
        elif s[0] == '*':
            b = pop() # Pop the top two values from the stack
            a = pop()
            push(a * b) # Push the result of multiplication back onto the stack
        # If the input is a number, convert it and push onto the stack
        else:
            push(int(s)) # Convert string to integer and push onto the stack
    except EOFError:
        break # Exit the loop when EOF is reached

# Print the final result which is the last remaining value in the stack
print(pop()) # Print the top value of the stack

