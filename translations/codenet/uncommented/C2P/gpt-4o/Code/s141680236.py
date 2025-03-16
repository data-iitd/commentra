def push(value):
    global top, stack
    top += 1
    stack[top] = value

def pop():
    global top, stack
    value = stack[top]
    top -= 1
    return value

top = -1
stack = [0] * 1000

while True:
    try:
        null = input()
        if null == '+':
            chonda = pop()
            yamagami = pop()
            push(chonda + yamagami)
        elif null == '-':
            yamagami = pop()
            chonda = pop()
            push(chonda - yamagami)
        elif null == '*':
            chonda = pop()
            yamagami = pop()
            push(chonda * yamagami)
        else:
            push(int(null))
    except EOFError:
        break

print(pop())

# <END-OF-CODE>
