
while True:
    try:
        a, b = map(int, input().split())
        x = a + b
        w = 0
        while x > 0:
            w += 1
            x //= 10
        print(w)
    except EOFError:
        break

