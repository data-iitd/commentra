
a, op, b = input().split()
a = int(a)
b = int(b)

while True:
    if op == '+':
        c = a + b
        print(c)
    elif op == '-':
        c = a - b
        print(c)
    elif op == '*':
        c = a * b
        print(c)
    elif op == '/':
        c = a / b
        print(c)
    else:
        break

    a, op, b = input().split()
    a = int(a)
    b = int(b)

