
import sys

def main():
    n = int(input())
    d = {}
    for _ in range(n):
        num = int(input())
        if num not in d:
            d[num] = 1
        else:
            d[num] += 1
            if d[num] == 2:
                del d[num]
    ans = 0
    for key in d:
        ans += d[key]
    print(ans)

if __name__ == "__main__":
    main()

