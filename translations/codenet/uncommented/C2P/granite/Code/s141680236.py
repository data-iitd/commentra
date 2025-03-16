
kinbo = []

def push(chonda):
    kinbo.append(chonda)

def pop():
    chonda = kinbo.pop()
    return chonda

while True:
    null = input()
    if null == "+":
        chonda = pop()
        yamagami = pop()
        push(chonda + yamagami)
    elif null == "-":
        yamagami = pop()
        chonda = pop()
        push(chonda - yamagami)
    elif null == "*":
        chonda = pop()
        yamagami = pop()
        push(chonda * yamagami)
    else:
        push(int(null))

print(pop())

