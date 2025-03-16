
def group(n):
    if n == 4 or n == 6 or n == 9 or n == 11:
        return "B"
    else:
        return "A"

def main():
    x, y = map(int, input().split())

    if x == 2 or y == 2:
        print("No")
        return

    xg = group(x)
    yg = group(y)

    if xg == yg:
        print("Yes")
    else:
        print("No")

