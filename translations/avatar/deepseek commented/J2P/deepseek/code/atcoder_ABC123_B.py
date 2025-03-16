import sys
from collections import defaultdict

def main():
    a = []
    r = []
    map = defaultdict(int)

    # Step 2: Reading input and storing remainders
    for _ in range(5):
        a.append(int(input()))
        r.append(a[-1] % 10)
        b = 10
        if r[-1] != 0:
            b = 10 - r[-1]
            map[b] = a[-1]

    # Step 3: Handling edge cases
    if not map:
        ans = sum(a)
        print(ans)
        return

    # Step 4: Finding the maximum and adjusting values
    last = map[max(map)]
    idx = a.index(last)
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
