
top = 0
S = []

def push(x):
    global top
    S.append(x)
    top += 1

def pop():
    global top
    top -= 1
    return S.pop()

while True:
    s = input()
    if s == "+":
        b = pop()
        a = pop()
        push(a + b)
    elif s == "-":
        b = pop()
        a = pop()
        push(a - b)
    elif s == "*":
        b = pop()
        a = pop()
        push(a * b)
    else:
        push(int(s))
    if s == "