def main():
    import sys
    from collections import defaultdict

    a = [0] * 5
    r = [0] * 5
    map = {}

    # Step 2: Reading input and storing remainders
    for i in range(5):
        a[i] = int(sys.stdin.readline().strip())
        r[i] = a[i] % 10
        b = 10
        if r[i] != 0:
            b = 10 - r[i]
            map[b] = a[i]

    # Step 3: Handling edge cases
    if len(map) == 0:
        ans = sum(a)
        print(ans)
        return

    # Step 4: Finding the maximum and adjusting values
    last = map[max(map)]
    idx = 0
    for i in range(5):
        if a[i] == last:
            idx = i

    ans = 0
    for i in range(5):
        if i != idx:
            if a[i] % 10 == 0:
                ans += a[i]
            else:
                ans += a[i] + (10 - r[i])

    ans += last
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
