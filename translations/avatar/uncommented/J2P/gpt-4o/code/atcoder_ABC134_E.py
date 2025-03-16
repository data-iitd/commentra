from collections import defaultdict
import sys

def main():
    n = int(sys.stdin.readline().strip())
    map = defaultdict(int)

    for _ in range(n):
        num = int(sys.stdin.readline().strip())
        if not any(k < num for k in map.keys()):
            map[num] += 1
        else:
            key = max(k for k in map.keys() if k < num)
            val = map[key]
            if val == 1:
                del map[key]
            else:
                map[key] -= 1
            map[num] += 1

    ans = sum(map.values())
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
