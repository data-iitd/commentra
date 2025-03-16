def group(n):
    # The `group` function takes an integer `n` and returns "B" if `n` is 4, 6, 9, or 11, otherwise it returns "A".
    if n in {4, 6, 9, 11}:
        return "B"
    else:
        return "A"

def main():
    # Reads two integers `x` and `y` from the standard input.
    x, y = map(int, input().split())

    # Checks if either `x` or `y` is 2. If so, it prints "No" and returns immediately.
    if x == 2 or y == 2:
        print("No")
        return

    # Calls the `group` function for both `x` and `y` to determine their respective groups.
    xg = group(x)
    yg = group(y)

    # Compares the groups of `x` and `y`. If they are the same, it prints "Yes"; otherwise, it prints "No".
    if xg == yg:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
