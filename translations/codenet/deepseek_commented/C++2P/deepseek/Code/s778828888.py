def main():
    n, m, x = map(int, input().split())
    a = [0] * 105  # Initialize array to keep track of positions

    positions = list(map(int, input().split()))
    for pos in positions:
        a[pos] = 1  # Mark the positions in array a

    ansl = 0
    ansr = 0
    for i in range(x, n + 1):  # Calculate the number of marked positions to the right of x
        ansr += a[i]
    for i in range(x, -1, -1):  # Calculate the number of marked positions to the left of x
        ansl += a[i]

    print(min(ansl, ansr))  # Print the minimum of the left and right distances


if __name__ == "__main__":
    main()
