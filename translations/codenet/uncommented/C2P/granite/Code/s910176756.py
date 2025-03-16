
a, op, b = input().split()
while True:
    if op == '+':
        c = int(a) + int(b)
        print(c)
    elif op == '-':
        c = int(a) - int(b)
        print(c)
    elif op == '*':
        c = int(a) * int(b)
        print(c)
    elif op == '/':
        c = int(a) / int(b)
        print(c)
    else:
        break
    a, op, b = input().split()
