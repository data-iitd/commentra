while True:
    try:
        a, b, c, d, e, f = map(int, input().split())
    except EOFError:
        break

    y = (c * d - f * a) / (b * d - e * a)
    x = (c * e - f * b) / (a * e - d * b)

    if 0 < y <= 0.0005:
        y = 0
    if 0 < x <= 0.0005:
        x = 0

    print(f"{x:.3f} {y:.3f}")

# <END-OF-CODE>
