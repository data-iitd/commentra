
# <START-OF-CODE>

import sys

def main():
    n = int(sys.stdin.readline())
    map = {}
    while n > 0:
        num = int(sys.stdin.readline())
        if map.get(num) is None:
            val = map.get(num, 0)
            map[num] = val + 1
        else:
            key = map.get(num)
            val = map.get(key)
            if val == 1:
                map.pop(key)
            else:
                map[key] = val - 1
            val = map.get(num, 0)
            map[num] = val + 1
        n -= 1
    ans = 0
    for key in map.keys():
        val = map.get(key)
        ans += val
    print(ans)

if __name__ == '__main__':
    main()

# 