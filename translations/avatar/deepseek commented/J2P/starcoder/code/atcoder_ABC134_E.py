import sys

def main():
    n = int(sys.stdin.readline())
    map = {}
    while n > 0:
        num = int(sys.stdin.readline())
        if map.get(num) is None:
            map[num] = 1
        else:
            map[num] += 1
        n -= 1
    ans = 0
    for key in map.keys():
        ans += map[key]
    print(ans)

if __name__ == "__main__":
    main()

