
while True:
    try:
        m, f, r = map(int, input().split())
        if m == -1 or f == -1:
            print("F")
            continue
        if m + f >= 80:
            print("A")
            continue
        if m + f >= 65:
            print("B")
            continue
        if m + f >= 50 or r >= 50:
            print("C")
            continue
        if m + f >= 30:
            print("D")
            continue
        print("F")
    except EOFError:
        break
