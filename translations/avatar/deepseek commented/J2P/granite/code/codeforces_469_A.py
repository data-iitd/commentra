

import sys

def main():
    n = int(input())
    levels = int(input())
    arr = list(map(int, input().split()))
    level2 = int(input())
    level3 = levels + level2
    arr2 = arr + list(map(int, input().split()))
    arr3 = list(range(1, n + 1))
    count = 0
    for i in arr3:
        if i in arr2:
            count += 1
    if count == n:
        print("I become the guy.")
    else:
        print("Oh, my keyboard!")

if __name__ == "__main__":
    main()

