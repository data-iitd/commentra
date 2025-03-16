import sys

def main():
    a = list(map(int, sys.stdin.readline().split()))
    r = [0] * 5
    map = {}

    # Step 2: Reading input and storing remainders
    for i in range(len(a)):
        r[i] = a[i] % 10
        if r[i] != 0:
            map[10 - r[i]] = a[i]

    # Step 3: Handling edge cases
    if len(map) == 0:
        ans = 0
        for i in range(len(a)):
            ans += a[i]
        print(ans)
        return

    # Step 4: Finding the maximum and adjusting values
    last = map[max(map.keys())]
    idx = 0
    for i in range(len(a)):
        if a[i] == last:
            idx = i
    ans = 0
    for i in range(len(a)):
        if i != idx:
            if a[i] % 10 == 0:
                ans += a[i]
            else:
                ans += a[i] + (10 - r[i])
    ans += last
    print(ans)

if __name__ == "__main__":
    main()
