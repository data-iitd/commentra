import sys
from collections import TreeMap

def main():
    n = int(sys.stdin.readline().strip())
    map = TreeMap()
    for _ in range(n):
        num = int(sys.stdin.readline().strip())
        if map.get(map.lower_key(num)) is None:
            val = map.get(num, 0) + 1
            map[num] = val
        else:
            key = map.lower_key(num)
            val = map[key]
            if val == 1:
                del map[key]
            else:
                map[key] = val - 1
            val = map.get(num, 0) + 1
            map[num] = val
    ans = 0
    for key in map.keys():
        ans += map[key]
    print(ans)

if __name__ == "__main__":
    main()
