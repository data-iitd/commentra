def check(x, y):
    if y % 2 == 0:
        t = int(0.5 * y) - x
        if t >= 0 and (x - t) >= 0:
            return "Yes"
    return "No"


if __name__ == "__main__":
    x, y = map(int, input().split())
    print(check(x, y))

