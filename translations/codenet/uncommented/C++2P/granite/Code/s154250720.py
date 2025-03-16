
import sys

def main():
    n = int(input())
    maps = [int(x) for x in input().split()]
    num = maps[:]
    maps.sort()
    m = n // 2
    for i in range(n):
        if num[i] <= maps[m]:
            print(maps[m+1])
        else:
            print(maps[m])

if __name__ == "__main__":
    main()

