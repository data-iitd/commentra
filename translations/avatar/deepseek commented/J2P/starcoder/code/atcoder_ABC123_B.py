import sys

def main():
    a = [int(x) for x in sys.stdin.readline().split()]
    r = [x % 10 for x in a]
    map = {}
    for i in range(5):
        if r[i]!= 0:
            b = 10 - r[i]
            if b in map:
                map[b] += a[i]
            else:
                map[b] = a[i]

    if len(map) == 0:
        ans = 0
        for i in range(5):
            ans += a[i]
        print(ans)
        return

    last = map[max(map.keys())]
    idx = 0
    for i in range(5):
        if a[i] == last:
            idx = i
    ans = 0
    for i in range(5):
        if i!= idx:
            if a[i] % 10 == 0:
                ans += a[i]
            else:
                ans += a[i] + (10 - r[i])
    ans += last
    print(ans)

if __name__ == "__main__":
    main()

