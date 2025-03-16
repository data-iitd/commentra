

# Initialize stack top and array kinbo
top = 0
kinbo = []

def push(chonda):
    # Increment top and push element chonda into kinbo array
    global top
    kinbo.append(chonda)
    top += 1

def pop():
    # Decrement top and return the top element
    global top
    top -= 1
    return kinbo[top]

if __name__ == "__main__":
    chonda, yamagami = 0, 0
    while True:
        try:
            # Read input strings from standard input
            null = input()
            if null[0] == '+':
                # Pop two elements from the stack
                yamagami = pop()
                chonda = pop()
                # Add the popped elements and push the result onto the stack
                push(chonda + yamagami)
            elif null[0] == '-':
                # Pop two elements from the stack
                yamagami = pop()
                chonda = pop()
                # Subtract the second popped element from the first popped element and push the result onto the stack
                push(chonda - yamagami)
            elif null[0] == '*':
                # Pop two elements from the stack
                chonda = pop()
                yamagami = pop()
                # Multiply the popped elements and push the result onto the stack
                push(chonda * yamagami)
            else:
                # If the first character of the input string is not an operator, convert it to an integer and push it onto the stack
                push(int(null))
        except EOFError:
            # Print the top element of the stack, which is the final result
            print(pop())
            break

