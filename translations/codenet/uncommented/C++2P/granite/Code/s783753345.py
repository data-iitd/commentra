
while True:
    a, S, b = input().split()
    if S == '+': print(int(a) + int(b))
    if S == '-': print(int(a) - int(b))
    if S == '*': print(int(a) * int(b))
    if S == '/': print(int(a) / int(b))
    if S == '?': break
