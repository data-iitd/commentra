

import sys

def main():
    n, k = map(int, sys.stdin.readline().split())
    arr = list(map(int, sys.stdin.readline().split()))
    arr.sort()
    count = 0
    set = set()
    for i in range(n):
        if arr[i] % k!= 0:
            count += 1
            set.add(arr[i])
        elif arr[i] // k not in set:
            count += 1
            set.add(arr[i])
    print(count)

if __name__ == "__main__":
    main()

These comments should provide a clear understanding of the code's functionality and logic.